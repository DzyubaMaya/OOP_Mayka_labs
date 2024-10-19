#pragma once

#include "figure.h"

// Класс Hexagon
class Hexagon : public Figure
{
private:
    Points center; // Центр шестиугольника
    double radius; // Радиус описанной окружности
public:
    Hexagon() = default;
    Hexagon(const Points &center, double radius);
    Hexagon(const Hexagon &hexagon);
    Hexagon(Hexagon &&hexagon) noexcept;
    Hexagon &operator=(const Hexagon &hexagon);
    Hexagon &operator=(Hexagon &&hexagon) noexcept;
    bool operator==(const Hexagon &other);

    operator double() const;
    Points geometricalCenter() const override;
    double square() const override;

    friend std::ostream &operator<<(std::ostream &stream, const Hexagon &hexagon);
    friend std::istream &operator>>(std::istream &stream, Hexagon &hexagon);
};
