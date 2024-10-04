#include <iostream>
#include "laba2.h"

int main() {
    try {
        //Создание объектов с использованием различных конструкторов
        Three t1 = Three();
        Three t2 = Three{'1', '2', '0'};
        Three t3 = Three("122");

        // Вывод созданных объектов
        t1.print(std::cout) << std::endl;
        t2.print(std::cout) << std::endl;
        t3.print(std::cout) << std::endl;

        Three t4 = t2.add(t3);
        t4.print(std::cout) << std::endl;

         Three t5 = t3.subtract(t2);
         t5.print(std::cout) << std::endl;

         Three t11({'2', '0', '2'});
         Three t21({'1', '1', '1'});
         Three t31 = t11.subtract(t21);
         t31.print(std::cout) << std::endl;

        


    } catch (const std::invalid_argument &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}