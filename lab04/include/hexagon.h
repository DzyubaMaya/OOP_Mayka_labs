#pragma once

#include "figure.h"

// Шаблонный класс Hexagon, наследующий от шаблонного класса Figure
template <typename T>
class Hexagon : public Figure<T> {
private:
    Point<T> center; // Центр шестиугольника
    T radius; // Радиус описанной окружности
public:
    Hexagon() = default;
    Hexagon(const Point<T>& center, T radius); // центр и радиус
    Hexagon(const Hexagon<T> &hexagon);
    Hexagon(Hexagon<T> &&hexagon) noexcept;
    Hexagon<T>& operator=(const Hexagon<T> &hexagon);
    Hexagon<T>& operator=(Hexagon<T> &&hexagon) noexcept;
    bool operator==(const Hexagon<T> &other);
    
    operator T() const; // площадь
    Point<T> geometricalCenter() const override; // геометрический центр
    T square() const override;
    
    template <typename K>
    friend std::ostream& operator<< (std::ostream &stream, const Hexagon<T> &hexagon);
    template <typename K>
    friend std::istream& operator>> (std::istream &stream, Hexagon<T> &hexagon);
};

// Конструктор, принимающий центр и радиус
template <typename T>
Hexagon<T>::Hexagon(const Point<T> &center, T radius) : center(center), radius(radius) {}

// Конструктор копирования
template <typename T>
Hexagon<T>::Hexagon(const Hexagon<T> &hexagon) : center(hexagon.center), radius(hexagon.radius) {}

// Конструктор перемещения
template <typename T>
Hexagon<T>::Hexagon(Hexagon<T> &&hexagon) noexcept : center(std::move(hexagon.center)), radius(std::move(hexagon.radius)) {}

// Оператор присваивания копированием
template <typename T>
Hexagon<T> &Hexagon<T>::operator=(const Hexagon<T> &hexagon) {
    if (this != &hexagon) {
        center = hexagon.center;
        radius = hexagon.radius;
    }
    return *this;
}

// Оператор присваивания перемещением
template <typename T>
Hexagon<T> &Hexagon<T>::operator=(Hexagon<T> &&hexagon) noexcept {
    if (this != &hexagon) {
        center = std::move(hexagon.center);
        radius = std::move(hexagon.radius);
    }
    return *this;
}

// Оператор сравнения
template <typename T>
bool Hexagon<T>::operator==(const Hexagon<T> &other) {
    return center == other.center && radius == other.radius;
}

// Оператор преобразования к типу T
template <typename T>
Hexagon<T>::operator T() const {
    return square();
}

// Метод для вычисления геометрического центра
template <typename T>
Point<T> Hexagon<T>::geometricalCenter() const {
    return center;
}

// Метод для вычисления площади
template <typename T>
T Hexagon<T>::square() const {
    return 3 * std::sqrt(3) * radius * radius / 2;
}

template <typename T>
std::ostream& operator<<(std::ostream &stream, const Hexagon<T> &hexagon) {
    stream << "Hexagon(center: " << hexagon.center << ", radius: " << hexagon.radius << ")";
    return stream;
}

template <typename T>
std::istream& operator>>(std::istream &stream, Hexagon<T> &hexagon) {
    stream >> hexagon.center >> hexagon.radius;
    return stream;
}