#include "../include/points.h"
#include "../include/rhombus.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/array.h"

#include <iostream>
#include <cmath>
#include <vector>

int main() {
    // Создаем объекты точек
    Points a(1, 2);
    Points b(3, 5);
    std::cout << a << "," << (a < b) << std::endl;

    // Создаем объект ромба с четырьмя точками
    std::vector<Points> rhombusPoints = {
        Points(0, 0),
        Points(1, 1),
        Points(2, 0),
        Points(1, -1)
    };

    Rhombus r; // Объявляем переменную r здесь
    try {
        r = Rhombus(rhombusPoints); // Инициализируем её внутри блока try
        std::cout << r << ", square=" << static_cast<double>(r) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    // Создаем объект пятиугольника
    Pentagon p1({0, 0}, 5); 
    std::cout << "Pentagon p1: " << p1 << std::endl;

    // Создаем объект шестиугольника
    Hexagon h1({0, 0}, 6); 
    std::cout << "Hexagon h1: " << h1 << std::endl;

    // Создаем объект FigureArray и добавляем в него фигуры
    FigureArray array;
    array.pushBack(&r);
    array.pushBack(&p1);
    array.pushBack(&h1);

    // Выводим текущий размер массива
    std::cout << "Current size of array: " << array.size() << std::endl;

    // Удаляем фигуру по индексу 1
    array.erase(1);

    // Выводим текущий размер массива после удаления
    std::cout << "Current size of array after erase: " << array.size() << std::endl;

    // Создаем объекты ромба, пятиугольника и шестиугольника
    std::vector<Points> rhombusPoints1 = {
        Points(0, 0),
        Points(1, 1),
        Points(2, 0),
        Points(1, -1)
    };

    Rhombus r1; // Объявляем переменную r1 здесь
    try {
        r1 = Rhombus(rhombusPoints1); // Инициализируем её внутри блока try
        std::cout << "Rhombus r1: " << r1 << std::endl;

        // Выводим геометрический центр и площадь каждой фигуры
        std::cout << "Geometric center of r1: " << r1.geometricalCenter() << std::endl;
        std::cout << "Area of r1: " << static_cast<double>(r1) << std::endl;

        // Создаем копии фигур
        Rhombus r2 = r1;
        Pentagon p2({0, 0}, 5);
        Hexagon h2({0, 0}, 6);

        // Выводим информацию о фигурах
        std::cout << "Rhombus r2: " << r2 << std::endl;
        std::cout << "Pentagon p2: " << p2 << std::endl;
        std::cout << "Hexagon h2: " << h2 << std::endl;

        // Выводим геометрический центр и площадь каждой фигуры
        std::cout << "Geometric center of r2: " << r2.geometricalCenter() << std::endl;
        std::cout << "Area of r2: " << static_cast<double>(r2) << std::endl;

        std::cout << "Geometric center of p2: " << p2.geometricalCenter() << std::endl;
        std::cout << "Area of p2: " << static_cast<double>(p2) << std::endl;

        std::cout << "Geometric center of h2: " << h2.geometricalCenter() << std::endl;
        std::cout << "Area of h2: " << static_cast<double>(h2) << std::endl;

        // Создаем объект FigureArray
        FigureArray figureArray;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}















    