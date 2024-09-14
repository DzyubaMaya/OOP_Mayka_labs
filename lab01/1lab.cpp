
#include <iostream>
#include <string>
#include "perevod.h"

int main() {
    int hour, minute;
    std::string period;
    std::string result;

    // Ввод данных пользователем для часов
    while (true) {
        std::cout << "Введите час (1-12): ";
        std::cin >> hour;
        //проверяем часы
        result = perevod(hour, 0, "am"); 
        if (result.find("Ошибка") == std::string::npos) {
            break;
        }
        std::cout << result << std::endl;
    }

    // Ввод данных пользователем для минут
    while (true) {
        std::cout << "Введите минуты (0-59): ";
        std::cin >> minute;
        //проверяем минуты
        result = perevod(1, minute, "am"); 
        if (result.find("Ошибка") == std::string::npos) {
            break;
        }
        std::cout << result << std::endl;
    }

    // Ввод данных пользователем для периода
    while (true) {
        std::cout << "Введите период (am/pm): ";
        std::cin >> period;
        //проверяем период
        result = perevod(1, 0, period); 
        if (result.find("Ошибка") == std::string::npos) {
            break;
        }
        std::cout << result << std::endl;
    }

    // Преобразование и вывод результата
    result = perevod(hour, minute, period);
    std::cout << "Время в 24-часовом формате: " << result << std::endl;

    return 0;
}