#include "../include/points.h"

// Конструктор по умолчанию, инициализирующий координаты нулевыми значениями
Points::Points() : _x(0.0), _y(0.0) {}

// Конструктор с параметрами, инициализирующий координаты заданными значениями
Points::Points(double x, double y) : _x(x), _y(y) {}

// Конструктор копирования
Points::Points(const Points &other) : _x(other._x), _y(other._y) {}

// Конструктор перемещения
Points::Points(Points &&other) noexcept : _x(other._x), _y(other._y)
{
    other._x = 0.0; // Обнуляем координаты в другом объекте
    other._y = 0.0;
}

// Метод для получения значения координаты X
double Points::getX() const
{
    return _x;
}

// Метод для получения значения координаты Y
double Points::getY() const
{
    return _y;
}

// Оператор присваивания копированием
Points &Points::operator=(const Points &other)
{
    if (this != &other)
    { // Проверка на самоприсваивание
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

// Оператор присваивания перемещением
Points &Points::operator=(Points &&other) noexcept
{
    if (this != &other)
    { // Проверка на самоприсваивание
        _x = other._x;
        _y = other._y;
        other._x = 0.0; // Обнуляем координаты в другом объекте
        other._y = 0.0;
    }
    return *this;
}

// Оператор сравнения на равенство
bool Points::operator==(const Points &other) const
{
    return (_x == other._x) && (_y == other._y);
}

// Оператор сравнения на "меньше"
bool Points::operator<(const Points &other) const
{
    if (_x < other._x)
        return true;
    if (_x == other._x && _y < other._y)
        return true;
    return false;
}

// Метод для вывода координат в поток
std::ostream &Points::print(std::ostream &os) const
{
    os << "(" << _x << ", " << _y << ")";
    return os;
}

// Дружественная функция для вывода координат в поток с использованием оператора <<
std::ostream &operator<<(std::ostream &os, const Points &points)
{
    return points.print(os);
}

std::istream& operator>>(std::istream& is, Points& points){
  is >> points._x >> points._y;
  return is;
}
