#include "../include/hexagon.h"


// Реализация класса Hexagon

// Конструктор, принимающий центр и радиус
Hexagon::Hexagon(const Points& center, double radius) : center(center), radius(radius) {}

// Конструктор копирования
Hexagon::Hexagon(const Hexagon &hexagon) : center(hexagon.center), radius(hexagon.radius) {}

// Конструктор перемещения
Hexagon::Hexagon(Hexagon &&hexagon) noexcept : center(std::move(hexagon.center)), radius(hexagon.radius) {}

// Оператор присваивания копированием
Hexagon& Hexagon::operator=(const Hexagon &hexagon) {
    if (this != &hexagon) {  // Проверка на самоприсваивание
        center = hexagon.center;
        radius = hexagon.radius;
    }
    return *this;
}

// Оператор присваивания перемещением
Hexagon& Hexagon::operator=(Hexagon &&hexagon) noexcept {
    if (this != &hexagon) {  // Проверка на самоприсваивание
        center = std::move(hexagon.center);
        radius = hexagon.radius;
    }
    return *this;
}

// Оператор сравнения на равенство
bool Hexagon::operator==(const Hexagon &other) {
    return center == other.center && radius == other.radius;
}

double Hexagon::square() const{
    return static_cast<double>(*this);

}

// Переопределение оператора для получения площади
Hexagon::operator double() const {
    return (3 * std::sqrt(3) / 2) * radius * radius;  // Площадь шестиугольника
}

// Переопределение метода для получения геометрического центра
Points Hexagon::geometricalCenter() const {
    return center;  // Геометрический центр шестиугольника совпадает с его центром
}

// Дружественная функция для вывода шестиугольника в поток
std::ostream& operator<<(std::ostream &stream, const Hexagon &hexagon) {
    stream << "Hexagon: " << hexagon.center << " " << hexagon.radius;
    return stream;
}

// Дружественная функция для ввода шестиугольника из потока
std::istream& operator>>(std::istream &stream, Hexagon &hexagon) {
    stream >> hexagon.center >> hexagon.radius;
    return stream;
}
