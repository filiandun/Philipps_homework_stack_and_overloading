#include <iostream>
#include "stack.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Stack stack;
    stack.pop(); // ничего удалятся не будет, так как стек пустой

    stack.push(6);
    stack.push(1);
    stack.push(80);
    stack.push(23);

    stack.print();


    std::cout << std::endl;
    stack.pop(); stack.pop(); // удалятся два последние добавленные узлы (23 и 80)

    stack.print();

}