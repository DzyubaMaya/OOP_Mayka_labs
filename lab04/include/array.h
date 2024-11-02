#pragma once

#include <initializer_list>
#include <ostream>
#include <memory>
#include <type_traits>
#include "figure.h"  

// Шаблонный класс Array для хранения объектов любого типа T
template <class T>
class FigureArray {
private:
    size_t pSize, capacity; // Текущий размер массива и Вместимость массива 
    std::unique_ptr<T[]> data; // Умный указатель на массив элементов типа T 

    void setCapacity(size_t value);  // Метод для изменения вместимости массива
    static std::unique_ptr<T[]> reallocate(std::unique_ptr<T[]> oldData, size_t oldSize, size_t newSize); 

public:
    FigureArray();
    FigureArray(size_t n);
    ~FigureArray() {
        if constexpr (std::is_pointer<T>::value) {
            for(size_t i=0;i<pSize;++i)
                delete data[i];
        } 
    } // Деструктор по умолчанию, так как unique_ptr сам управляет памятью

    FigureArray(const FigureArray&); // Конструктор копирования
    FigureArray(FigureArray&&) noexcept; // Конструктор перемещения

    T& operator[] (size_t ind);  // Оператор доступа к элементу массива по индексу (для изменения)
    const T& operator[] (size_t ind) const; // Оператор доступа к элементу массива по индексу (для чтения)

    size_t size() const;
    void resize(size_t newSize);
    void pushBack(const T& figure); // Метод для добавления элемента в конец массива
    void erase(size_t ind);// Метод для удаления элемента по индексу

    FigureArray& operator=(const FigureArray&); // Оператор присваивания копированием
    FigureArray& operator=(FigureArray&&) noexcept; // Оператор присваивания перемещением
};

// Метод для изменения вместимости массива
template <class T>
void FigureArray<T>::setCapacity(size_t value) {
    data = reallocate(std::move(data), pSize, value);// Перераспределяем память под новый размер
    capacity = value;
}

// Статический метод для перераспределения памяти под массив указателей
template <class T>
std::unique_ptr<T[]> FigureArray<T>::reallocate(std::unique_ptr<T[]> oldData, size_t oldSize, size_t newSize) {
    std::unique_ptr<T[]> data(new T[newSize]);
    // Копируем элементы из старого массива в новый
    for (size_t i = 0; i < std::min(oldSize, newSize); i++) {
        data[i] = std::move(oldData[i]);
    }
    return data;
}

// Конструктор по умолчанию
template <class T>
FigureArray<T>::FigureArray() : pSize(0), capacity(0), data(nullptr) { }

// Конструктор с параметром размера
template <class T>
FigureArray<T>::FigureArray(size_t n) : pSize(n), capacity(n) {
    data = std::unique_ptr<T[]>(new T[n]);
}

// Реализация конструктора копирования
template <class T>
FigureArray<T>::FigureArray(const FigureArray& other) : pSize(other.pSize), capacity(other.capacity) {
    data = std::unique_ptr<T[]>(new T[capacity]);
    // Копируем элементы из другого массива
    for (size_t i = 0; i < pSize; i++) {
        data[i] = other.data[i];
    }
}

// Реализация конструктора перемещения
template <class T>
FigureArray<T>::FigureArray(FigureArray&& other) noexcept : pSize(other.pSize), capacity(other.capacity), data(std::move(other.data)) {
    other.pSize = 0;
    other.capacity = 0;
}

// Реализация оператора доступа к элементу массива по индексу (для изменения)
template <class T>
T& FigureArray<T>::operator[] (size_t ind) {
    return data[ind];
}

// Реализация оператора доступа к элементу массива по индексу (для чтения)
template <class T>
const T& FigureArray<T>::operator[] (size_t ind) const {
    return data[ind];
}

// Реализация метода для получения текущего размера массива
template <class T>
size_t FigureArray<T>::size() const {
    return pSize;
}

// Реализация метода для изменения размера массива
template <class T>
void FigureArray<T>::resize(size_t newSize) {
    // Если новый размер больше текущей вместимости, увеличиваем вместимость
    if (newSize > capacity) {
        setCapacity(newSize);
    }
    pSize = newSize;
}

// Реализация метода для добавления элемента в конец массива
template <class T>
void FigureArray<T>::pushBack(const T& figure) {
    // Увеличиваем размер массива на 1
    resize(pSize + 1);
    // Добавляем элемент в конец массива
    data[pSize - 1] = figure;
}

// Реализация метода для удаления элемента по индексу
template <class T>
void FigureArray<T>::erase(size_t ind) {
    // Сдвигаем элементы после удаляемого влево
    for (size_t i = ind + 1; i < pSize; i++) {
        data[i - 1] = std::move(data[i]);
    }
    // Уменьшаем текущий размер массива, если индекс корректен
    if (ind < pSize) {
        pSize--;
    }
}

// Реализация оператора присваивания копированием
template <class T>
FigureArray<T>& FigureArray<T>::operator=(const FigureArray& other) {
    if (this != &other) {
        pSize = other.pSize;
        capacity = other.capacity;
        data = std::unique_ptr<T[]>(new T[capacity]);
        // Копируем элементы из другого массива
        for (size_t i = 0; i < pSize; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Реализация оператора присваивания перемещением
template <class T>
FigureArray<T>& FigureArray<T>::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        pSize = other.pSize;
        capacity = other.capacity;
        data = std::move(other.data);
        other.pSize = 0;
        other.capacity = 0;
    }
    return *this;
}