#pragma once

#include "figure.h"
#include <vector>

// Класс Rhombus
class Rhombus : public Figure
{
protected:
    std::vector<Points> points; // четыре точки ромба
    

public:
    Rhombus() = default;
    Rhombus(const std::vector<Points>& points); // конструктор, принимающий четыре точки
    Rhombus(const Rhombus &rhombus);            // копирование
    Rhombus(Rhombus &&rhombus) noexcept;        // перемещение
    Rhombus &operator=(const Rhombus &rhombus); 
    Rhombus &operator=(Rhombus &&rhombus) noexcept; 
    bool operator==(const Rhombus &other) const;    // сравнение

    operator double() const;                   // Переопределение метода для получения площади
    Points geometricalCenter() const override; // Виртуальный метод для получения геометрического центра
    double square() const override;


    bool isRhombus(const std::vector<Points>& points) const; // Проверка, что точки образуют ромб
    double distance(const Points& p1, const Points& p2) const; // Вычисление расстояния между точками

    friend std::ostream &operator<<(std::ostream &stream, const Rhombus &rhombus);
    friend std::istream &operator>>(std::istream &stream, Rhombus &rhombus);

};