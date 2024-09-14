
#include <iostream>
#include <string>
#include "perevodik.h"

int main() {
    int hour, minute;
    std::string period;
    std::string resultatik;

    // Ввод данных пользователем для часов
    while (true) {
        std::cout << "Введите час (1-12): ";
        std::cin >> hour;
        //проверяем часы
        resultatik = perevodik(hour, 0, "am"); 
        if (resultatik.find("Ошибка") == std::string::npos) {
            break;
        }
        std::cout << resultatik << std::endl;
    }

    // Ввод данных пользователем для минут
    while (true) {
        std::cout << "Введите минуты (0-59): ";
        std::cin >> minute;
        //проверяем минуты
        resultatik = perevodik(1, minute, "am"); 
        if (resultatik.find("Ошибка") == std::string::npos) {
            break;
        }
        std::cout << resultatik << std::endl;
    }

    // Ввод данных пользователем для периода
    while (true) {
        std::cout << "Введите период (am/pm): ";
        std::cin >> period;
        //проверяем период
        resultatik = perevodik(1, 0, period); 
        if (resultatik.find("Ошибка") == std::string::npos) {
            break;
        }
        std::cout << resultatik << std::endl;
    }

    // Преобразование и вывод результата
    resultatik = perevodik(hour, minute, period);
    std::cout << "Время в 24-часовом формате: " << resultatik << std::endl;

    return 0;
}