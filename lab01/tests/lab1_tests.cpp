#include <gtest/gtest.h>
#include "../include/perevod.h"





// Тест для проверки корректного преобразования времени
TEST(Time_Test, ValidTime_Morning) {
    EXPECT_EQ(perevod(3, 45, "am"), "03:45");
}

TEST(Time_Test, ValidTime_Afternoon) {
    EXPECT_EQ(perevod(3, 45, "pm"), "15:45");
}

TEST(Time_Test, ValidTime_Midnight) {
    EXPECT_EQ(perevod(12, 0, "am"), "00:00");
}

TEST(Time_Test, ValidTime_Noon) {
    EXPECT_EQ(perevod(12, 0, "pm"), "12:00");
}

// Тест для проверки некорректных входных данных
TEST(Time_Test, InvalidHour) {
    EXPECT_EQ(perevod(13, 45, "am"), "Ошибка: Час должен быть в диапазоне от 1 до 12");
}

TEST(Time_Test, InvalidMinutes) {
    EXPECT_EQ(perevod(3, 60, "am"), "Ошибка: Минуты должны быть в диапазоне от 0 до 59");
}

TEST(Time_Test, InvalidPeriod) {
    EXPECT_EQ(perevod(3, 45, "xx"), "Ошибка: Период должен быть 'am' или 'pm'");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}