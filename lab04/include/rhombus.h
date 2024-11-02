#pragma once

#include "figure.h"
#include <vector>
#include <iostream>
#include <stdexcept>


// Шаблонный класс Rhombus, наследующий от шаблонного класса Figure
template <typename T>
class Rhombus : public Figure<T>
{
protected:
    std::vector<Point<T>> points; // четыре точки ромба
    
public:
    Rhombus() = default;
    Rhombus(const std::vector<Point<T>>& points); // конструктор, принимающий четыре точки
    Rhombus(const Rhombus<T> &rhombus);            // копирование
    Rhombus(Rhombus<T> &&rhombus) noexcept;        // перемещение
    Rhombus<T> &operator=(const Rhombus<T> &rhombus); 
    Rhombus<T> &operator=(Rhombus<T> &&rhombus) noexcept; 
    bool operator==(const Rhombus<T> &other) const;    // сравнение

    operator T() const;                   // Переопределение метода для получения площади
    Point<T> geometricalCenter() const override; // Виртуальный метод для получения геометрического центра
    T square() const override;

    bool isRhombus(const std::vector<Point<T>>& points) const; // Проверка, что точки образуют ромб
    T distance(const Point<T>& p1, const Point<T>& p2) const; // Вычисление расстояния между точками

    template <typename K>
    friend std::ostream &operator << (std::ostream &stream, const Rhombus<K> &rhombus);
    template <typename K>
    friend std::istream &operator >> (std::istream &stream, Rhombus<K> &rhombus);
};

// Конструктор, принимающий четыре точки для инициализации ромба
template <typename T>
Rhombus<T>::Rhombus(const std::vector<Point<T>>& points) {
    if (points.size() != 4) {
        throw std::invalid_argument("Ромб должен быть инициализирован четырьмя точками.");
    }
    if (!isRhombus(points)) {
        throw std::invalid_argument("Данные точки не образуют ромб.");
    }
    this->points = points;
}

// Конструктор копирования
template <typename T>
Rhombus<T>::Rhombus(const Rhombus<T> &rhombus) : points(rhombus.points) {}

// Конструктор перемещения
template <typename T>
Rhombus<T>::Rhombus(Rhombus<T> &&rhombus) noexcept : points(std::move(rhombus.points)) {}

// Реализация виртуального метода для получения геометрического центра
template <typename T>
Point<T> Rhombus<T>::geometricalCenter() const {
    T centerX = (points[0].getX() + points[1].getX() + points[2].getX() + points[3].getX()) / 4;
    T centerY = (points[0].getY() + points[1].getY() + points[2].getY() + points[3].getY()) / 4;
    return Point<T>(centerX, centerY);
}

template <typename T>
T Rhombus<T>::square() const {
    return static_cast<T>(*this);
}

template <typename T>
Rhombus<T>::operator T() const {
    T d1 = distance(points[0], points[2]); // Длина диагонали по оси X
    T d2 = distance(points[1], points[3]); // Длина диагонали по оси Y
    return (d1 * d2) / 2; // Площадь ромба
}

template <typename T>
Rhombus<T> &Rhombus<T>::operator=(const Rhombus<T> &other) {
    points = other.points;
    return *this;
}

template <typename T>
Rhombus<T> &Rhombus<T>::operator=(Rhombus<T> &&other) noexcept {
    points = std::move(other.points);
    return *this;
}

// Реализация виртуального оператора сравнения на равенство
template <typename T>
bool Rhombus<T>::operator==(const Rhombus<T> &other) const {
    return points == other.points;
}

// Проверка, что точки образуют ромб
template <typename T>
bool Rhombus<T>::isRhombus(const std::vector<Point<T>>& points) const {
    T side1 = distance(points[0], points[1]);
    T side2 = distance(points[1], points[2]);
    T side3 = distance(points[2], points[3]);
    T side4 = distance(points[3], points[0]);

    return side1 == side2 && side2 == side3 && side3 == side4;
}

// Вычисление расстояния между точками
template <typename T>
T Rhombus<T>::distance(const Point<T>& p1, const Point<T>& p2) const {
    return std::sqrt(std::pow(p1.getX() - p2.getX(), 2) + std::pow(p1.getY() - p2.getY(), 2));
}

template <typename T>
std::ostream &operator << (std::ostream &stream, const Rhombus<T> &rhombus) {
    for (const auto& point : rhombus.points){
        stream << point << " ";
    }
    return stream;
}

template <typename T>
std::istream &operator>>(std::istream &stream, Rhombus<T> &rhombus) {
    std::vector<Point<T>> points(4);
    for (int i = 0; i < 4; ++i) {
        stream >> points[i];
    }
    rhombus = Rhombus<T>(points);
    return stream;
}