#include <gtest/gtest.h>
#include "../include/laba2.h"

// Тест конструктора по умолчанию
TEST(ThreeTest, DefaultConstructor) {
    Three t;
    std::ostringstream oss;
    t.print(oss);
    EXPECT_EQ(oss.str(), "");  
}

// Тест конструктора с беззнаковым десятичным числом
TEST(ThreeTest, ConstructorWithUnsignedInt) {
    Three t(27);
    std::ostringstream oss;
    t.print(oss);
    EXPECT_EQ(oss.str(), "1000");
}

// Тест конструктора с initializer_list
TEST(ThreeTest, ConstructorWithInitializerList) {
    Three t({'1', '2', '0'});
    std::ostringstream oss;
    t.print(oss);
    EXPECT_EQ(oss.str(), "120");
}

// Тест конструктора с std::string
TEST(ThreeTest, ConstructorWithString) {
    Three t("120");
    std::ostringstream oss;
    t.print(oss);
    EXPECT_EQ(oss.str(), "120");
}

// Тест конструктора копирования
TEST(ThreeTest, CopyConstructor) {
    Three t1({'1', '2', '0'});
    Three t2(t1);
    std::ostringstream oss;
    t2.print(oss);
    EXPECT_EQ(oss.str(), "120");
}

// Тест конструктора перемещения
TEST(ThreeTest, MoveConstructor) {
    Three t1({'1', '2', '0'});
    Three t2(std::move(t1));
    std::ostringstream oss;
    t2.print(oss);
    EXPECT_EQ(oss.str(), "120");
}

// Тест метода add
TEST(ThreeTest, AddMethod) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '1', '1'});
    Three t3 = t1.add(t2);
    std::ostringstream oss;
    t3.print(oss);
    EXPECT_EQ(oss.str(), "1001");
}

// Тест метода subtract
TEST(ThreeTest, SubtractMethod) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '1', '1'});
    Three t3 = t1.subtract(t2);
    std::ostringstream oss;
    t3.print(oss);
    EXPECT_EQ(oss.str(), "2");
}


// Тест метода equals
TEST(ThreeTest, EqualsMethod) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '2', '0'});
    EXPECT_TRUE(t1.equals(t2));
}

// Тест метода lt
TEST(ThreeTest, LtMethod) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '2', '1'});
    EXPECT_TRUE(t1.lt(t2));
}

// Тест метода gt
TEST(ThreeTest, GtMethod) {
    Three t1({'1', '2', '1'});
    Three t2({'1', '2', '0'});
    EXPECT_TRUE(t1.gt(t2));
}

// Тест оператора ==
TEST(ThreeTest, EqualityOperator) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '2', '0'});
    EXPECT_TRUE(t1 == t2);
}

// Тест оператора !=
TEST(ThreeTest, InequalityOperator) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '2', '1'});
    EXPECT_TRUE(t1 != t2);
}

// Тест оператора <
TEST(ThreeTest, LessThanOperator) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '2', '1'});
    EXPECT_TRUE(t1 < t2);
}

// Тест оператора >
TEST(ThreeTest, GreaterThanOperator) {
    Three t1({'1', '2', '1'});
    Three t2({'1', '2', '0'});
    EXPECT_TRUE(t1 > t2);
}

// Тест оператора <=
TEST(ThreeTest, LessThanOrEqualOperator) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '2', '0'});
    EXPECT_TRUE(t1 <= t2);
}

// Тест оператора >=
TEST(ThreeTest, GreaterThanOrEqualOperator) {
    Three t1({'1', '2', '0'});
    Three t2({'1', '2', '0'});
    EXPECT_TRUE(t1 >= t2);
}

// Тест метода print
TEST(ThreeTest, PrintMethod) {
    Three t({'1', '2', '0'});
    std::ostringstream oss;
    t.print(oss);
    EXPECT_EQ(oss.str(), "120");
}

int test(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}