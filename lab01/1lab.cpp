
#include <iostream>
#include <string>
#include "perevodik.h"

int main() {
    int hour, minute;
    std::string period;

    // Ввод данных пользователем
    std::cout << "Введите час (1-12): ";
    std::cin >> hour;
    std::cout << "Введите минуты (0-59): ";
    std::cin >> minute;
    std::cout << "Введите период (am/pm): ";
    std::cin >> period;

    // Преобразование и вывод результата
    std::string resultatik = perevodik(hour, minute, period);
    std::cout << "Время в 24-часовом формате: " << resultatik << std::endl;

    return 0;
}