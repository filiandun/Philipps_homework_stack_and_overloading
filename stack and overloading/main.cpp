#include <iostream>
#include "stack.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Stack stack_1(6, 2, 0, 30, 654, 101, 44);
    Stack stack_2(5, 101, 44, 12, 0, 988);


// КОНСТРУКТОР КОПИРОВАНИЯ
    Stack stack_2_copy = stack_2;
    std::cout << "STACK 2: "; stack_2.print();
    std::cout << "STACK 2 COPY: "; stack_2_copy.print(); std::cout << std::endl << std::endl;


// COPY_IN
    Stack stack_1_copy;

    std::cout << "STACK 1 BEFORE: "; stack_1.print();
    std::cout << "STACK 1 COPY BEFORE: "; stack_1_copy.print();

    std::cout << "АДРЕС: " << stack_1.copy_in(stack_1_copy) << std::endl;
    std::cout << "STACK 1 AFTER: "; stack_1.print();
    std::cout << "STACK 1 COPY AFTЕR: "; stack_1_copy.print(); std::cout << std::endl << std::endl;


// OPERATOR+ (РАБОТАЕТ)
    std::cout << "STACK 1: "; stack_1.print();
    std::cout << "STACK 2: "; stack_2.print();
    std::cout << "АДРЕС: " << stack_1 + stack_2 << std::endl << std::endl << std::endl;


// OPERATOR+ (РАБОТАЕТ)
    Stack stack_3(7, 90, 1, 112, 21, 48, 90, 1001);
    Stack stack_4(6, 1001, 1, 76, 564, 19, 21);

    //std::cout << "STACK 3: "; stack_3.print();
    //std::cout << "STACK 4: "; stack_4.print();

    //std::cout << "АДРЕС: " << stack_3 * stack_4 << std::endl;


    Stack stack_5 = (stack_3 * stack_4);
    //stack_5.print();


    return 0;
}