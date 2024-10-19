#include <gtest/gtest.h>
#include "../include/points.h"
#include "../include/rhombus.h"
#include "../include/hexagon.h"
#include "../include/pentagon.h"

// Тесты для класса Rhombus
TEST(RhombusTest, InitializationTest) {
    std::vector<Points> rhombusPoints = {
        Points(0, 0),
        Points(1, 1),
        Points(2, 0),
        Points(1, -1)
    };

    Rhombus r(rhombusPoints);

    // Проверяем, что ромб инициализирован без исключений
    EXPECT_NO_THROW(Rhombus(rhombusPoints));
}

TEST(RhombusTest, SquareTest) {
    std::vector<Points> rhombusPoints = {
        Points(0, 0),
        Points(1, 1),
        Points(2, 0),
        Points(1, -1)
    };

    Rhombus r(rhombusPoints);

    // Проверяем, что площадь вычисляется правильно
    EXPECT_NEAR(r.square(), 2.0, 1e-6);
}

TEST(RhombusTest, GeometricalCenterTest) {
    std::vector<Points> rhombusPoints = {
        Points(0, 0),
        Points(1, 1),
        Points(2, 0),
        Points(1, -1)
    };

    Rhombus r(rhombusPoints);

    // Проверяем, что геометрический центр вычисляется правильно
    Points center = r.geometricalCenter();
    EXPECT_NEAR(center.getX(), 1.0, 1e-6);
    EXPECT_NEAR(center.getY(), 0.0, 1e-6);
}

TEST(RhombusTest, InvalidPointsTest) {
    std::vector<Points> invalidPoints = {
        Points(0, 0),
        Points(1, 1),
        Points(2, 2),
        Points(3, 3)
    };

    // Проверяем, что исключение выбрасывается при попытке создать ромб с неправильными точками
    EXPECT_THROW(Rhombus r(invalidPoints), std::invalid_argument);
}

// Тесты для класса Hexagon
TEST(HexagonTest, InitializationTest) {
    Points center(0, 0);
    double radius = 1.0;

    Hexagon h(center, radius);

    // Проверяем, что центр и радиус шестиугольника совпадают с ожидаемыми
    EXPECT_EQ(h.geometricalCenter(), center);
    EXPECT_EQ(h.square(), (3 * std::sqrt(3) / 2) * radius * radius);
}

TEST(HexagonTest, SquareTest) {
    Points center(0, 0);
    double radius = 1.0;

    Hexagon h(center, radius);

    // Проверяем, что площадь вычисляется правильно
    EXPECT_NEAR(h.square(), (3 * std::sqrt(3) / 2) * radius * radius, 1e-6);
}

TEST(HexagonTest, GeometricalCenterTest) {
    Points center(0, 0);
    double radius = 1.0;

    Hexagon h(center, radius);

    // Проверяем, что геометрический центр вычисляется правильно
    EXPECT_EQ(h.geometricalCenter(), center);
}

// Тесты для класса Pentagon
TEST(PentagonTest, InitializationTest) {
    Points center(0, 0);
    double radius = 1.0;

    Pentagon p(center, radius);

    // Проверяем, что центр и радиус пятиугольника совпадают с ожидаемыми
    EXPECT_EQ(p.geometricalCenter(), center);
    EXPECT_EQ(p.square(), (5.0 / 2.0) * radius * radius * std::sin(2 * M_PI / 5));
}

TEST(PentagonTest, SquareTest) {
    Points center(0, 0);
    double radius = 1.0;

    Pentagon p(center, radius);

    // Проверяем, что площадь вычисляется правильно
    EXPECT_NEAR(p.square(), (5.0 / 2.0) * radius * radius * std::sin(2 * M_PI / 5), 1e-6);
}

TEST(PentagonTest, GeometricalCenterTest) {
    Points center(0, 0);
    double radius = 1.0;

    Pentagon p(center, radius);

    // Проверяем, что геометрический центр вычисляется правильно
    EXPECT_EQ(p.geometricalCenter(), center);
}

int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}