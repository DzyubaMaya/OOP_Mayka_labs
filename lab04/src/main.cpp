#include <iostream>
#include <sstream>
#include "figure.h"
#include "hexagon.h"
#include "pentagon.h"
#include "rhombus.h"
#include "array.h"
#include <memory>

int main() {
    
    // Создание массива для хранения шестиугольников с типом int
    FigureArray<Pentagon<int>> hexArray;
    hexArray.pushBack(Pentagon<int>(Point<int>(0, 0), 5));
    hexArray.pushBack(Pentagon<int>(Point<int>(1, 1), 6));
    hexArray.pushBack(Pentagon<int>(Point<int>(1, 1), 7));
    hexArray.pushBack(Pentagon<int>(Point<int>(1, 1), 8));
    hexArray.pushBack(Pentagon<int>(Point<int>(1, 1), 9));
    hexArray.pushBack(Pentagon<int>(Point<int>(1, 1), 10));
    hexArray.pushBack(Pentagon<int>(Point<int>(1, 1), 11));
    hexArray.pushBack(Pentagon<int>(Point<int>(1, 1), 12));

    //Вывод шестиугольников
    std::cout << "Pentagon:" << std::endl;
    for (size_t i = 0; i < hexArray.size(); ++i) {
        std::cout << "Pentagon " << i << ": " << hexArray[i] << std::endl;
    }

    FigureArray<Pentagon<int>*> hexArrayPtr;
    hexArrayPtr.pushBack(new Pentagon<int>(Point<int>(0, 0), 5));
    hexArrayPtr.pushBack(new Pentagon<int>(Point<int>(1, 1), 6));


    //Вывод шестиугольников
    std::cout << "Pentagon:" << std::endl;
    for (size_t i = 0; i < hexArrayPtr.size(); ++i) {
        std::cout << "Pentagon " << i << ": " << *hexArrayPtr[i] << std::endl;
    }

    // Создание массива для хранения пятиугольников с типом double
    FigureArray<Pentagon<double>> pentArray;
    pentArray.pushBack(Pentagon<double>(Point<double>(0.0, 0.0), 5.5));
    pentArray.pushBack(Pentagon<double>(Point<double>(1.0, 1.0), 6.5));

    // Вывод пятиугольников
    std::cout << "Pentagons:" << std::endl;
    for (size_t i = 0; i < pentArray.size(); ++i) {
        std::cout << "Pentagon " << i << ": " << pentArray[i] << std::endl;
    }



    // Создание массива для хранения ромбов с типом float
    FigureArray<Rhombus<float>> rhombusArray;

    // Создание вектора точек для первого ромба
    std::vector<Point<float>> points1 = {
        Point<float>(0, 0),
        Point<float>(1, 1),
        Point<float>(2, 0),
        Point<float>(1, -1)
    };

    // Создание вектора точек для второго ромба
    std::vector<Point<float>> points2 = {
        Point<float>(0, 0),
        Point<float>(2, 2),
        Point<float>(4, 0),
        Point<float>(2, -2)
    };

    // Добавление ромбов в массив
    rhombusArray.pushBack(Rhombus<float>(points1));
    rhombusArray.pushBack(Rhombus<float>(points2));

    // Вывод ромбов
    std::cout << "Rhombuses:" << std::endl;
    for (size_t i = 0; i < rhombusArray.size(); ++i) {
        std::cout << "Rhombus " << i << ": " << rhombusArray[i] << std::endl;
    }

    return 0;
}