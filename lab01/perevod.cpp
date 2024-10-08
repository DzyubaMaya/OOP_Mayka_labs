
#include "perevod.h"
#include <string>

std::string perevod(int hour, int minute, const std::string& period) {
    // Проверка корректности входных данных
    if (hour < 1 || hour > 12) {
        return "Ошибка: Час должен быть в диапазоне от 1 до 12";
    }
    if (minute < 0 || minute > 59) {
        return "Ошибка: Минуты должны быть в диапазоне от 0 до 59";
    }
    if (period != "am" && period != "pm") {
        return "Ошибка: Период должен быть 'am' или 'pm'";
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
    std::string result;

    // Добавляем часы
    if (hour < 10) {
        result += "0";
    }
    result += std::to_string(hour);

    // Добавляем двоеточие для красоты
    result += ":";

    // Добавляем минуты
    if (minute < 10) {
        result += "0";
    }
    result += std::to_string(minute);

    return result;
}