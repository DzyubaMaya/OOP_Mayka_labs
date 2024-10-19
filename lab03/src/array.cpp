#include "../include/array.h"
#include "../include/figure.h"
#include "array.h"


void FigureArray::setCapacity(size_t value) {
    data = reallocate(data, pSize, value);// Перераспределяем память под новый размер
    capacity = value;
}


Figure** FigureArray::reallocate(Figure** oldData, size_t oldSize, size_t newSize) {
    Figure** data = new Figure* [newSize];
    // Копируем элементы из старого массива в новый
    for (size_t i = 0; i < std::min(oldSize, newSize); i++) {
        data[i] = oldData[i];
    }
    // Освобождаем память, занятую старым массивом, если он не был nullptr
    if (oldData != nullptr) {
        delete [] oldData;
    }
    return data;
}


FigureArray::FigureArray() : pSize(0), capacity(0), data(nullptr) { }


FigureArray::FigureArray(size_t n) : pSize(n), capacity(n) {
    data = reallocate(nullptr, 0, n);
}


FigureArray::~FigureArray() {
    // Освобождаем память, занятую массивом указателей
    delete [] data;
}

// Реализация конструктора копирования
FigureArray::FigureArray(const FigureArray& other) {
    data = reallocate(nullptr, 0, other.size());
    // Копируем элементы из другого массива
    for (size_t i = 0; i < other.size(); i++) {
        data[i] = other.data[i];
    }
    // Копируем размер и вместимость
    pSize = other.size();
    capacity = other.capacity;
}

// Реализация конструктора перемещения
FigureArray::FigureArray(FigureArray&& other) {
    // Перемещаем указатель на массив указателей
    data = other.data;
    // Копируем размер и вместимость
    pSize = other.size();
    capacity = other.capacity;
    // Обнуляем указатель в перемещаемом объекте
    other.data = nullptr;
}

// Реализация оператора доступа к элементу массива по индексу (для изменения)
Figure* & FigureArray::operator[] (size_t ind) {
    return data[ind];
}

// Реализация оператора доступа к элементу массива по индексу (для чтения)
Figure* const & FigureArray::operator[] (size_t ind) const {
    return data[ind];
}

// Реализация метода для получения текущего размера массива
size_t FigureArray::size() const {
    return pSize;
}

// Реализация метода для изменения размера массива
void FigureArray::resize(size_t newSize) {
    // Если новый размер больше текущей вместимости, увеличиваем вместимость
    if (newSize > capacity) {
        setCapacity(newSize);
    }
    
    pSize = newSize;
}

// Реализация метода для добавления элемента в конец массива
void FigureArray::pushBack(Figure* figure) {
    // Увеличиваем размер массива на 1
    resize(pSize + 1);
    // Добавляем элемент в конец массива
    (*this)[pSize - 1] = figure;
}

// Реализация метода для удаления элемента по индексу
void FigureArray::erase(size_t ind) {
    // Сдвигаем элементы после удаляемого влево
    for (size_t i = ind + 1; i < pSize; i++) {
        data[i - 1] = data[i];
    }
    // Уменьшаем текущий размер массива, если индекс корректен
    if (ind < pSize) {
        pSize--;
    }
}


