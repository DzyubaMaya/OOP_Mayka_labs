#pragma once
#include "../include/points.h"

#include <algorithm>
#include <cmath>

// Базовый класс Figure
struct Figure {
        virtual Points geometricalCenter() const = 0;
        virtual double square() const = 0;
        virtual ~Figure() = default;
};



