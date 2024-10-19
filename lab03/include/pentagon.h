#pragma once

#include "figure.h"
// Класс Pentagon
class Pentagon : public Figure {
private:
    Points center; // Центр пятиугольника
    double radius; // Радиус описанной окружности
public:
    Pentagon() = default;
    Pentagon(const Points& center, double radius); // центр и радиус
    Pentagon(const Pentagon &pentagon);
    Pentagon(Pentagon &&pentagon)noexcept;
    Pentagon& operator=(const Pentagon &pentagon);
    Pentagon& operator=(Pentagon &&pentagon)noexcept;
    bool operator==(const Pentagon &other);
    
    operator double () const; //  площадь
    Points geometricalCenter() const override; //геометрический центр
    double square() const override;
    
    friend std::ostream& operator<<(std::ostream &stream, const Pentagon &pentagon);
    friend std::istream& operator>>(std::istream &stream, Pentagon &pentagon);
};