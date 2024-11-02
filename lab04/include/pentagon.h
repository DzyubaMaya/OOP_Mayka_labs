#pragma once

#include "figure.h"

// Шаблонный класс Pentagon, наследующий от шаблонного класса Figure
template <typename T>
class Pentagon : public Figure<T> {
private:
    Point<T> center; // Центр пятиугольника
    T radius; // Радиус описанной окружности
public:
    Pentagon() = default;
    Pentagon(const Point<T>& center, T radius); // центр и радиус
    Pentagon(const Pentagon<T> &pentagon);
    Pentagon(Pentagon<T> &&pentagon) noexcept;
    Pentagon<T>& operator=(const Pentagon<T> &pentagon);
    Pentagon<T>& operator=(Pentagon<T> &&pentagon) noexcept;
    bool operator==(const Pentagon<T> &other);
    
    operator T() const; // площадь
    Point<T> geometricalCenter() const override; // геометрический центр
    T square() const override;
    
    template <typename K>
    friend std::ostream& operator<<(std::ostream &stream, const Pentagon<K> &pentagon);

    
    template <typename K>
    friend std::istream& operator>>(std::istream &stream, Pentagon<K> &pentagon);
};

// Конструктор, принимающий центр и радиус
template <typename T>
Pentagon<T>::Pentagon(const Point<T>& center, T radius) : center(center), radius(radius) {}

// Конструктор копирования
template <typename T>
Pentagon<T>::Pentagon(const Pentagon<T> &pentagon) : center(pentagon.center), radius(pentagon.radius) {}

// Конструктор перемещения
template <typename T>
Pentagon<T>::Pentagon(Pentagon<T> &&pentagon) noexcept : center(std::move(pentagon.center)), radius(std::move(pentagon.radius)) {}

// Оператор присваивания копированием
template <typename T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T> &pentagon) {
    std::cout << "copy" << std::endl;
    if (this != &pentagon) {  // Проверка на самоприсваивание
        center = pentagon.center;
        radius = pentagon.radius;
    }
    return *this;
}

// Оператор присваивания перемещением
template <typename T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T> &&pentagon) noexcept {
    std::cout << "move" << std::endl;
    if (this != &pentagon) {  // Проверка на самоприсваивание
        center = std::move(pentagon.center);
        radius = std::move(pentagon.radius);
    }
    return *this;
}

// Оператор сравнения 
template <typename T>
bool Pentagon<T>::operator==(const Pentagon<T> &other) {
    return center == other.center && radius == other.radius;
}

// Переопределение оператора для получения площади
template <typename T>
Pentagon<T>::operator T() const {
    return (5.0 / 2.0) * radius * radius * std::sin(2 * M_PI / 5);  // Площадь пятиугольника
}

// Переопределение метода для получения геометрического центра
template <typename T>
Point<T> Pentagon<T>::geometricalCenter() const {
    return center;  // Геометрический центр пятиугольника совпадает с его центром
}

template <typename T>
T Pentagon<T>::square() const {
    return static_cast<T>(*this);
}

template <typename T>
std::ostream& operator<<(std::ostream &stream, const Pentagon<T> &pentagon) {
    stream << "Pentagon: " << pentagon.center << " " << pentagon.radius;
    return stream;
}

template <typename T>
std::istream& operator>>(std::istream &stream, Pentagon<T> &pentagon) {
    stream >> pentagon.center >> pentagon.radius;
    return stream;
}