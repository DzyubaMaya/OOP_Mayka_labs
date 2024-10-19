#include "../include/pentagon.h"



// Реализация класса Pentagon
Pentagon::Pentagon(const Points& center, double radius) : center(center), radius(radius) {} // Конструктор, принимающий центр и радиус
Pentagon::Pentagon(const Pentagon &pentagon) : center(pentagon.center), radius(pentagon.radius) {} // Конструктор копирования
Pentagon::Pentagon(Pentagon &&pentagon) noexcept : center(std::move(pentagon.center)), radius(pentagon.radius) {}// Конструктор перемещения

// Оператор присваивания копированием
Pentagon& Pentagon::operator=(const Pentagon &pentagon) {
    if (this != &pentagon) {  // Проверка на самоприсваивание
        center = pentagon.center;
        radius = pentagon.radius;
    }
    return *this;
}

// Оператор присваивания перемещением
Pentagon& Pentagon::operator=(Pentagon &&pentagon) noexcept {
    if (this != &pentagon) {  // Проверка на самоприсваивание
        center = std::move(pentagon.center);
        radius = pentagon.radius;
    }
    return *this;
}

// Оператор сравнения 
bool Pentagon::operator==(const Pentagon &other) {
    return center == other.center && radius == other.radius;
}

// Переопределение оператора для получения площади
Pentagon::operator double() const {
    return (5.0 / 2.0) * radius * radius * std::sin(2 * M_PI / 5);  // Площадь пятиугольника
}

 // Переопределение метода для получения геометрического центра
Points Pentagon::geometricalCenter() const {
    return center;  // Геометрический центр пятиугольника совпадает с его центром
}

double Pentagon::square() const{
    return static_cast<double>(*this);

}

// функция для вывода пятиугольника в поток
std::ostream& operator<<(std::ostream &stream, const Pentagon &pentagon) {
    stream << "Pentagon: " << pentagon.center << " " << pentagon.radius;
    return stream;
}

//  функция для ввода пятиугольника из потока
std::istream& operator>>(std::istream &stream, Pentagon &pentagon) {
    stream >> pentagon.center >> pentagon.radius;
    return stream;
}


