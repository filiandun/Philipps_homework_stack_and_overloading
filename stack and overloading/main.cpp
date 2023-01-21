#include <iostream>
#include "stack.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Stack stack_1(6, 2, 0, 30, 654, 101, 44);
    Stack stack_2(5, 101, 44, 12, 0, 988);


// COPY_IN
    std::cout << "####ФУНКЦИЯ COPY_IN####" << std::endl << std::endl;
    Stack stack_1_copy;

    std::cout << "STACK 1 ДО: "; stack_1.print();
    std::cout << "STACK 1 ДО: "; stack_1_copy.print(); std::cout << std::endl;

    std::cout << "АДРЕС СКОПИРОВАННОГО СТЕКА: " << stack_1.copy_in(stack_1_copy) << std::endl;

    std::cout << "STACK 1 ПОСЛЕ: "; stack_1.print();
    std::cout << "STACK 1 COPY ПОСЛЕ: "; stack_1_copy.print(); std::cout << std::endl << std::endl;


// OPERATOR+
    std::cout << "####ФУНКЦИЯ OPERATOR+####" << std::endl << std::endl;

    std::cout << "STACK 1: "; stack_1.print();
    std::cout << "STACK 2: "; stack_2.print();

    std::cout << stack_1 + stack_2 << std::endl << std::endl << std::endl;


// OPERATOR*
    std::cout << "####ФУНКЦИЯ OPERATOR*####" << std::endl << std::endl;

    Stack stack_3(7, 344, 1, 112, 21, 48, 90, 1001);
    Stack stack_4(6, 1001, 1, 76, 564, 19, 21);

    std::cout << "STACK 3: "; stack_3.print();
    std::cout << "STACK 4: "; stack_4.print();

    std::cout << stack_3 * stack_4 << std::endl;



    return 0;
}