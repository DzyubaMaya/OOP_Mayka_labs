
#include "perevodik.h"
#include <string>

std::string perevodik(int hour, int minute, const std::string& period) {
    // Проверка корректности входных данных
    if (hour < 1 || hour > 12) {
        return "Ошибочка: Час должен быть в диапазоне от 1 до 12";
    }
    if (minute < 0 || minute > 59) {
        return "Ошибочка: Минуты должны быть в диапазоне от 0 до 59";
    }
    if (period != "am" && period != "pm") {
        return "Ошибочка: Период должен быть 'am' или 'pm'";
    }
    
    // Преобразование часов в 24-часовой формат
    if (period == "am") {   
        if (hour == 12) {
            hour = 0; // полночь
        }
    } else if (period == "pm") {
        if (hour != 12) {
            hour += 12;
        }
    }

    // Форматирование в формат строки
    std::string resultatik;

    // Добавляем часы
    if (hour < 10) {
        resultatik += "0";
    }
    resultatik += std::to_string(hour);

    // Добавляем двоеточие для красоты
    resultatik += ":";

    // Добавляем минуты
    if (minute < 10) {
        resultatik += "0";
    }
    resultatik += std::to_string(minute);

    return resultatik;
}