#include "stack.h"

int main()

{

    my_std::Stack<int> stack;

    stack.push(9);
    stack.push(9);
    stack.push(3);
    stack.push(4);
    stack.push(7);
    stack.push(1);

    std::cout<<stack.pop();
    std::cout<<stack.top();

    return 0;

}