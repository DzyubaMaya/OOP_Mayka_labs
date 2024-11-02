#pragma once
#include "../include/points.h"

#include <algorithm>
#include <cmath>

// Шаблонный базовый класс Figure
template <typename T>
struct Figure {
    virtual Point<T> geometricalCenter() const = 0;
    virtual T square() const = 0;
    virtual ~Figure() {
        std::cout << "destory" << std::endl;
    }
};