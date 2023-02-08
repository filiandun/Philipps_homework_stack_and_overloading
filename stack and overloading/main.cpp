#include <iostream>
#include "stack.h"


/*
* Что-то не так с моим деструктором, с ним выдаёт ошибку,
* он может работать, но без этих строк из main.cpp:
* (51) Stack stack_sum = stack_1 + stack_2;
* (67) Stack stack_product = stack_3 * stack_4;
*/



int main()
{
    setlocale(LC_ALL, "rus");

    Stack stack_1(6, 2, 0, 30, 654, 101, 44); // первое число - длина будущего стека
    Stack stack_2(5, 101, 44, 12, 0, 988); // первое число - длина будущего стека


// КОНСТРУКТОР КОПИРОВАНИЯ
    std::cout << "КОНСТРУКТОР КОПИРОВАНИЯ: " << std::endl << std::endl;
    Stack stack_1_construct_copy = stack_1;

    std::cout << "STACK_1: "; stack_1.print();
    std::cout << "STACK_1_CONSTRUCT_COPY: "; stack_1_construct_copy.print(); std::cout << std::endl << std::endl;



// COPY_IN
    std::cout << "ФУНКЦИЯ COPY_IN:" << std::endl << std::endl;
    Stack stack_1_func_copy;

    std::cout << "STACK_1 ДО: "; stack_1.print();
    std::cout << "STACK_1_FUNC_COPY ДО: "; stack_1_func_copy.print(); std::cout << std::endl;

    std::cout << "АДРЕС СКОПИРОВАННОГО СТЕКА: " << stack_1.copy_in(stack_1_func_copy) << std::endl;

    std::cout << "STACK_1 ПОСЛЕ: "; stack_1.print();
    std::cout << "STACK_1_FUNC_COPY ПОСЛЕ: "; stack_1_func_copy.print(); std::cout << std::endl << std::endl;



// OPERATOR+
    std::cout << "OPERATOR+: " << std::endl << std::endl;

    std::cout << "STACK_1: "; stack_1.print();
    std::cout << "STACK_2: "; stack_2.print(); std::cout << std::endl;

    std::cout << "АДРЕС ГОЛОВЫ НОВОГО СТЕКА (STACK_1 + STACK_2): " << stack_1 + stack_2 << std::endl;

    Stack stack_sum = stack_1 + stack_2;
    std::cout << "STACK_SUM = STACK_1 + STACK_2: "; stack_sum.print(); std::cout << std::endl << std::endl;



// OPERATOR*
    std::cout << "OPERATOR*: " << std::endl << std::endl;

    Stack stack_3(7, 344, 1, 112, 21, 48, 90, 1001);
    Stack stack_4(6, 1001, 1, 76, 564, 19, 21);

    std::cout << "STACK_3: "; stack_3.print();
    std::cout << "STACK_4: "; stack_4.print(); std::cout << std::endl;

    std::cout << "АДРЕС ГОЛОВЫ НОВОГО СТЕКА (STACK_1 * STACK_2): " << stack_1 + stack_2 << std::endl;

    Stack stack_product = stack_3 * stack_4;
    std::cout << "STACK_PRODUCT = STACK_1 * STACK_2: "; stack_product.print();




    return 0;
}