#include <iostream>
#include <initializer_list>
#include "laba2.h"

bool isThreeBase(char M)
{
    return (M >= '0' && M <= '2');
}

// Конструктор по умолчанию
Three::Three() : _size(0), _array{nullptr} {}

// Конструктор принимает на вход беззнаковое десятичное число и преобразует его в троичное
Three::Three(unsigned int num)
{
    _size = 0;
    unsigned int temp_number = num;
    //количество цифр в троичном представлении
    do
    {
        temp_number /= 3;
        _size++;
    } while (temp_number > 0);

    //память для массива
    _array = new unsigned char[_size];

    //число в троичную сс
    for (size_t i = 0; i < _size; ++i)
    {
        _array[_size - 1 - i] = (num % 3) + '0'; // правильный порядок цифр
        num /= 3;
    }
}

// Конструктор с initializer_list
Three::Three(const std::initializer_list<unsigned char> &t)
{
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i{0};

    // M - переменная, для хранения текущего элемента при итерации
    for (unsigned char M : t)
    {
        if (!isThreeBase(M))
            throw std::logic_error("not three-base system");
        _array[i++] = M; // Если символ допустим, сохраняем его в массиве _array по текущему индексу
    }
}

// Конструктор с std::string
Three::Three(const std::string &t)
{
    _array = new unsigned char[t.size()];
    _size = t.size();
    for (size_t i{0}; i < _size; i++)
    {
        if (!isThreeBase(t[i]))
            throw std::logic_error("not three-base system"); // Проверяем, что символ t[i] принадлежит троичной системе счисления
        _array[i] = t[i];                                    // Присваиваем каждому элементу массива значение t[i]
    }
}

// Конструктор копирования
Three::Three(const Three &other)
{
    _size = other._size;               // инициализация размера
    _array = new unsigned char[_size]; 

    // копирование элементов из other._array в _array
    for (size_t i = 0; i < _size; i++)
    {
        _array[i] = other._array[i];
    }
}

// Конструктор перемещения
Three::Three(Three &&other) noexcept
{
    _size = other._size;   // перемещение размера
    _array = other._array; // перемещение указателя на массив

    // обнуление размера и указателя
    other._size = 0;
    other._array = nullptr;
}


// Метод для сложения двух троичных чисел
Three Three::add(const Three &other) const {
    //максимальный размер массивов
    size_t max_size = std::max(_size, other._size);
    //массив для хранения результата сложения с учетом возможного переноса
    unsigned char *result_array = new unsigned char[max_size + 1];
    size_t i = 0;
    int temp = 0;

    //инициализация индексов для итерации по разрядам чисел
    int index1 = _size - 1;
    int index2 = other._size - 1;

    //цикл по всем разрядам чисел, начиная с младшего разряда
    while (index1 >= 0 || index2 >= 0 || temp) {
        //текущие цифры чисел или 0, если разряд отсутствует
        int digit1 = 0;
        int digit2 = 0;

        if (index1 >= 0) {
            digit1 = _array[index1] - '0';
            --index1;
        }

        if (index2 >= 0) {
            digit2 = other._array[index2] - '0';
            --index2;
        }

        // сумма цифр и переноса
        int sum = digit1 + digit2 + temp;

        //результат в массив
        result_array[i] = (sum % 3) + '0';

        //обновление переноса
        temp = sum / 3;

        //к следующему разряду
        ++i;
    }

    //реверс массива result_array
    std::reverse(result_array, result_array + i);

    //новый объект Three для результата
    Three result;
    result._array = result_array;
    result._size = i;
    return result;
}

// Метод для вычитания двух троичных чисел
Three Three::subtract(const Three &other) const {
    if (lt(other))
        throw std::range_error("a - b < 0");

    // максимальный размер массивов
    size_t max_size = std::max(_size, other._size);
    //массив для результата вычитания
    unsigned char *result_array = new unsigned char[max_size];
    size_t i = 0;
    int borrow = 0;

    //инициализация индексов для итерации по разрядам чисел
    int index1 = _size - 1;
    int index2 = other._size - 1;

    // цикл по всем разрядам чисел, начиная с младшего разряда
    while (index1 >= 0 || index2 >= 0) {
        // текущие цифры чисел
        int digit1 = 0;
        int digit2 = 0;

        if (index1 >= 0) {
            digit1 = _array[index1] - '0';
            --index1;
        }

        if (index2 >= 0) {
            digit2 = other._array[index2] - '0';
            --index2;
        }

        int diff = digit1 - digit2 - borrow;

        // если разность отрицательная, занимаем из старшего разряда
        if (diff < 0) {
            diff += 3;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result_array[i] = diff + '0';
        ++i;
    }

    std::reverse(result_array, result_array + i); 

    // удаление ведущих нулей
    size_t zero = 0;
    while (zero < i && result_array[zero] == '0') {
        ++zero;
    }
    if (zero == i) { // если все цифры были нулями, оставляем один ноль
        --zero;
    }

    // сдвиг содержимого массива на количество удаленных нулей
    if (zero > 0) {
        for (size_t j = zero; j < i; ++j) {
            result_array[j - zero] = result_array[j];
        }
    }
    size_t shifted_size = i - zero;

    Three result;
    result._size = shifted_size;
    result._array = result_array;


    return result;
}


// Метод для проверки, является ли текущее число меньше другого числа
bool Three::lt(const Three &other) const {
    if (_size < other._size)
        return true;
    else if (_size > other._size)
        return false;
    if (_size == 0)
        return false;

    size_t i = 0;
    while (i < _size && _array[i] == other._array[i])
        ++i;

    // Если все элементы равны, то числа равны(проверка на выход за пределы массива)
    if (i == _size)
        return false;

    return _array[i] < other._array[i];
}



// Метод для проверки, является ли текущее число больше другого числа
bool Three::gt(const Three &other) const {
    if (_size > other._size)
        return true;
    else if (_size < other._size)
        return false;
    if (_size == 0)
        return false;

    size_t i = 0;
    while (i < _size && _array[i] == other._array[i])
        ++i;

    // Если все элементы равны, то числа равны(проверка на выход за границы массива)
    if (i == _size)
        return false;

    return _array[i] > other._array[i];
}



// Метод для проверки равны ли 2 троичных числа
bool Three::equals(const Three &other) const
{
    if (_size != other._size)
    {
        return false;
    }
    for (size_t i = 0; i < _size; ++i)
    {
        if (_array[i] != other._array[i])
        {
            return false;
        }
    }
    return true;
}

// Оператор для проверки на равенство
bool Three::operator==(const Three &other) const
{
    return equals(other); // метод equals 
}

// Оператор для проверки на неравенство
bool Three::operator!=(const Three &other) const
{
    return !equals(other); 
}

// Оператор для проверки на "меньше"
bool Three::operator<(const Three &other) const
{
    return lt(other); // метод lt 
}

// Оператор для проверки на "больше"
bool Three::operator>(const Three &other) const
{
    return gt(other); // метод gt 
}

// Оператор для проверки на "меньше или равно"
bool Three::operator<=(const Three &other) const
{
    return lt(other) || equals(other); // true, если число меньше или равно другому числу
}

// Оператор для проверки на "больше или равно"
bool Three::operator>=(const Three &other) const
{
    return gt(other) || equals(other); // true, если число больше или равно другому числу
}

// Метод для вывода троичного числа
std::ostream &Three::print(std::ostream &os) const
{
    for (size_t i = 0; i < _size; ++i)
    {
        os << _array[i];
    }
    return os;
}

// деструктор
Three::~Three() noexcept
{
    delete[] _array;
}
