#include <iostream>
#include "allocator.h"
#include "queue.h"

#include <iostream>
#include "allocator.h"
#include "queue.h"

int main() {
    std::cout << "Testing MyQueue with int:\n";
    MyMemoryResource memoryResource; // Создаем объект менеджера памяти
    MyQueue<int> intQueue(&memoryResource); // Создаем очередь для целых чисел

    // Добавляем элементы в очередь
    for (int i = 1; i <= 5; ++i) {
        intQueue.push(i);
    }

    // Используем итератор для вывода элементов очереди
    for (auto it = intQueue.begin(); it != intQueue.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    std::cout << "Testing MyQueue with std::string:\n";
    MyQueue<std::string> stringQueue(&memoryResource); // Создаем очередь для строк

    // Добавляем элементы в очередь
    stringQueue.push("Hello");
    stringQueue.push("World");
    stringQueue.push("!");

    // Используем итератор для вывода элементов очереди
    for (auto it = stringQueue.begin(); it != stringQueue.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}































