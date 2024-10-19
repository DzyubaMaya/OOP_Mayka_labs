#pragma once

#include <iostream>
#include <cmath>


// Константа для сравнения чисел с плавающей точкой
const double EPS = 1e-6;
inline const double PI = 3.14159265358979323846;

class Points {
protected:
    double _x;  
    double _y;  
    

public:
    Points();
    Points(double x, double y);
    Points(const Points& other);
    Points(Points&& other) noexcept;

    
    double getX() const;//значение координаты X
    double getY() const;//значение координаты Y

    Points& operator=(const Points& other);
    Points& operator=(Points&& other) noexcept;

    bool operator==(const Points& other) const; //сравнение - равенство
    bool operator<(const Points& other) const; //сравнение - "меньше"

    std::ostream& print(std::ostream& os) const; //вывод координат в поток

    friend std::ostream& operator<<(std::ostream& os, const Points& points);
    friend std::istream& operator>>(std::istream& is, Points& points);
};
