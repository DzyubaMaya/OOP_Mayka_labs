#include <gtest/gtest.h>
#include "../include/perevodik.h"


TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(true);
}


// Тест для проверки корректного преобразования времени
TEST(Time_Test, ValidTime_Morning) {
    EXPECT_EQ(perevodik(3, 45, "am"), "03:45");
}

TEST(Time_Test, ValidTime_Afternoon) {
    EXPECT_EQ(perevodik(3, 45, "pm"), "15:45");
}

TEST(Time_Test, ValidTime_Midnight) {
    EXPECT_EQ(perevodik(12, 0, "am"), "00:00");
}

TEST(Time_Test, ValidTime_Noon) {
    EXPECT_EQ(perevodik(12, 0, "pm"), "12:00");
}

// Тест для проверки некорректных входных данных
TEST(Time_Test, InvalidHour) {
    EXPECT_EQ(perevodik(13, 45, "am"), "Ошибочка: Час должен быть в диапазоне от 1 до 12");
}

TEST(Time_Test, InvalidMinutes) {
    EXPECT_EQ(perevodik(3, 60, "am"), "Ошибочка: Минуты должны быть в диапазоне от 0 до 59");
}

TEST(Time_Test, InvalidPeriod) {
    EXPECT_EQ(perevodik(3, 45, "xx"), "Ошибочка: Период должен быть 'am' или 'pm'");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}