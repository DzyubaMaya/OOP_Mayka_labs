#pragma once
#include <memory_resource>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>

template <typename T>
class MyQueue {
public:
    // Узел для хранения данных
    struct Node {
        T data;          // Данные, хранящиеся в узле
        Node* next;      // Указатель на следующий узел
        Node* prev;      // Указатель на предыдущий узел

        // Конструктор для узла
        Node(const T& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
            : data(value), next(nextNode), prev(prevNode) {}
    };

    // Конструктор, принимающий указатель на memory_resource
    MyQueue(std::pmr::memory_resource* mr = std::pmr::get_default_resource()) 
        : allocator(mr), head(nullptr), tail(nullptr), _size(0) {}



    // Проверка на пустоту очереди
    bool empty() const {
        return head == nullptr;
    }

    // Получение размера очереди
    size_t size() const {
        return _size;
    }

    // Добавление элемента в начало очереди (новая голова)
    void push(const T& value) {
        Node* newNode = allocator.allocate(1); // Выделяем память для нового узла
        new(newNode) Node(value, head, nullptr); // Конструируем новый узел на выделенной памяти
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
        if (!tail) {  // Если (очередь была пуста) хвоста нет все такое, устанавливаем хвост на новый узел
            tail = head;
        }
        ++_size;
    }

    // Удаление элемента из конца очереди (хвост) и возвращение его значения
    T pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node* last = tail;
        T value = last->data;

        // Если хвост и голова совпадают (очередь содержит только один элемент)
        if (tail == head) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        last->~Node();
        allocator.deallocate(last, 1);
        --_size;
        return value;
    }

    // Получение элемента из конца очереди (хвост)
    T& back() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return tail->data;
    }

    // Очистка очереди
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            temp->~Node();
            allocator.deallocate(temp, 1);
        }
        _size = 0;
        tail = nullptr;
    }

    // Деструктор
    ~MyQueue() {
        clear();
    }

    // Итератор для очереди
    class Iterator {
        friend class MyQueue;

    private:
        Node* current; //текущий узел в очереди

    public:
        using difference_type = int;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = std::forward_iterator_tag;

        // Конструктор, инициализирующий итератор.
        Iterator(Node* node) : current(node) {}

        // Оператор инкремента (префиксный), перемещающий итератор к следующему элементу.
        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        // Оператор инкремента (постфиксный), перемещающий итератор к следующему элементу.
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        // Оператор разыменования, возвращающий элемент контейнера по текущему итератору.
        reference operator*() const {
            return current->data;
        }

        // Оператор доступа к членам через указатель, возвращающий элемент контейнера по текущему итератору.
        pointer operator->() const {
            return &(current->data);
        }

        // Оператор неравенства, сравнивающий текущий итератор с другим.
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        // Оператор равенства, сравнивающий текущий итератор с другим.
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };

    // Методы для получения итераторов
    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

private:
    // Аллокатор, использующий memory_resource
    std::pmr::polymorphic_allocator<Node> allocator;

    // Указатели на голову и хвост очереди
    Node* head;
    Node* tail;

    size_t _size; //текущее количество элементов очереди

    
};


