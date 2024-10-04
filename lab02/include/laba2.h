#ifndef LABA2_H
#define LABA2_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

class Three {
public:
    // Конструктор по умолчанию
    Three();

  

    // Конструктор принимает на вход беззнаковое десятичное число и преобразует его в троичное
    Three(unsigned int num);

    // Конструктор с initializer_list
    Three(const std::initializer_list<unsigned char> &t);

    // Конструктор с std::string
    Three(const std::string &t);

    // Конструктор копирования
    Three(const Three &other);

    // Конструктор перемещения
    Three(Three &&other) noexcept;

    // Метод для сложения двух троичных чисел
    Three add(const Three &other) const;

    // Метод для вычитания двух троичных чисел
    Three subtract(const Three &other) const;

    // Метод для проверки равны ли 2 троичных числа
    bool equals(const Three &other) const;

    // Метод для проверки, является ли текущее число меньше другого числа
    bool lt(const Three &other) const;

    // Метод для проверки, является ли текущее число больше другого числа
    bool gt(const Three &other) const;

    // Оператор для проверки на равенство
    bool operator==(const Three &other) const;

    // Оператор для проверки на неравенство
    bool operator!=(const Three &other) const;

    // Оператор для проверки на "меньше"
    bool operator<(const Three &other) const;

    // Оператор для проверки на "больше"
    bool operator>(const Three &other) const;

    // Оператор для проверки на "меньше или равно"
    bool operator<=(const Three &other) const;

    // Оператор для проверки на "больше или равно"
    bool operator>=(const Three &other) const;

    // Метод для вывода троичного числа
    std::ostream &print(std::ostream &os) const;

    // Деструктор
    ~Three() noexcept;

private:
    size_t _size;
    unsigned char *_array;

    static bool isThreeBase(char M) {
        return (M >= '0' && M <= '2');
    }
};

#endif // LABA2_H