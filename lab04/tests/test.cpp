#include <gtest/gtest.h>
#include <sstream>
#include "figure.h"
#include "hexagon.h"
#include "pentagon.h"
#include "rhombus.h"
#include "array.h"
#include "points.h"

// Тесты для класса Point
TEST(PointTest, DefaultConstructor) {
    Point<int> p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PointTest, ParameterConstructor) {
    Point<int> p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

TEST(PointTest, CopyConstructor) {
    Point<int> p1(3, 4);
    Point<int> p2(p1);
    EXPECT_EQ(p2.getX(), 3);
    EXPECT_EQ(p2.getY(), 4);
}

TEST(PointTest, MoveConstructor) {
    Point<int> p1(3, 4);
    Point<int> p2(std::move(p1));
    EXPECT_EQ(p2.getX(), 3);
    EXPECT_EQ(p2.getY(), 4);
}

TEST(PointTest, AssignmentOperator) {
    Point<int> p1(3, 4);
    Point<int> p2;
    p2 = p1;
    EXPECT_EQ(p2.getX(), 3);
    EXPECT_EQ(p2.getY(), 4);
}

TEST(PointTest, MoveAssignmentOperator) {
    Point<int> p1(3, 4);
    Point<int> p2;
    p2 = std::move(p1);
    EXPECT_EQ(p2.getX(), 3);
    EXPECT_EQ(p2.getY(), 4);
}

TEST(PointTest, EqualityOperator) {
    Point<int> p1(3, 4);
    Point<int> p2(3, 4);
    Point<int> p3(4, 3);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, LessThanOperator) {
    Point<int> p1(3, 4);
    Point<int> p2(4, 3);
    EXPECT_TRUE(p1 < p2);
    EXPECT_FALSE(p2 < p1);
}

// Тесты для класса Hexagon
TEST(HexagonTest, DefaultConstructor) {
    Hexagon<int> h;
    EXPECT_EQ(h.geometricalCenter(), Point<int>(0, 0));
}

// Тесты для класса Pentagon
TEST(PentagonTest, DefaultConstructor) {
    Pentagon<int> p;
    EXPECT_EQ(p.geometricalCenter(), Point<int>(0, 0));
}





// Тесты для класса Rhombus
TEST(RhombusTest, DefaultConstructor) {
    Rhombus<int> r;
    EXPECT_EQ(r.geometricalCenter(), Point<int>(0, 0));
}

TEST(RhombusTest, AssignmentOperator) {
    std::vector<Point<int>> points = {
        Point<int>(0, 0),
        Point<int>(1, 1),
        Point<int>(2, 0),
        Point<int>(1, -1)
    };
    Rhombus<int> r1(points);
    Rhombus<int> r2;
    r2 = r1;
    EXPECT_EQ(r2.geometricalCenter(), Point<int>(1, 0));
    EXPECT_NEAR(r2.square(), 2, 0.01); // Примерное значение площади
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}