#include "../include/rhombus.h"
#include <cmath>
#include <stdexcept>

// Конструктор, принимающий четыре точки для инициализации ромба
Rhombus::Rhombus(const std::vector<Points>& points) {
    if (points.size() != 4) {
        throw std::invalid_argument("Ромб должен быть инициализирован четырьмя точками.");
    }
    if (!isRhombus(points)) {
        throw std::invalid_argument("Данные точки не образуют ромб.");
    }
    this->points = points;
}

// Конструктор копирования
Rhombus::Rhombus(const Rhombus &rhombus) : points(rhombus.points) {}

// Конструктор перемещения
Rhombus::Rhombus(Rhombus &&rhombus) noexcept : points(std::move(rhombus.points)) {}

// Реализация виртуального метода для получения геометрического центра
Points Rhombus::geometricalCenter() const {
    double centerX = (points[0].getX() + points[1].getX() + points[2].getX() + points[3].getX()) / 4;
    double centerY = (points[0].getY() + points[1].getY() + points[2].getY() + points[3].getY()) / 4;
    return Points(centerX, centerY);
}

double Rhombus::square() const {
    return static_cast<double>(*this);
}

// Реализация чисто виртуального оператора для получения площади
Rhombus::operator double() const {
    double d1 = distance(points[0], points[2]); // Длина диагонали по оси X
    double d2 = distance(points[1], points[3]); // Длина диагонали по оси Y
    return (d1 * d2) / 2; // Площадь ромба
}

// Реализация чисто виртуального оператора присваивания копированием
Rhombus &Rhombus::operator=(const Rhombus &other) {
    points = other.points;
    return *this;
}

// Реализация виртуального оператора присваивания перемещением
Rhombus &Rhombus::operator=(Rhombus &&other) noexcept {
    points = std::move(other.points);
    return *this;
}

// Реализация виртуального оператора сравнения на равенство
bool Rhombus::operator==(const Rhombus &other) const {
    return points == other.points;
}

// Реализация виртуального метода для чтения из потока
std::ostream &operator<<(std::ostream &stream, const Rhombus &rhombus) {
    for (const auto& point : rhombus.points) {
        stream << point << " ";
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, Rhombus &rhombus) {
    std::vector<Points> points(4);
    for (int i = 0; i < 4; ++i) {
        stream >> points[i];
    }
    rhombus = Rhombus(points);
    return stream;
}

// Проверка, что точки образуют ромб
bool Rhombus::isRhombus(const std::vector<Points>& points) const {
    double side1 = distance(points[0], points[1]);
    double side2 = distance(points[1], points[2]);
    double side3 = distance(points[2], points[3]);
    double side4 = distance(points[3], points[0]);

    return side1 == side2 && side2 == side3 && side3 == side4;
}

// Вычисление расстояния между точками
double Rhombus::distance(const Points& p1, const Points& p2) const {
    return std::sqrt(std::pow(p1.getX() - p2.getX(), 2) + std::pow(p1.getY() - p2.getY(), 2));
}