#include "queue.h"

int main()

{

    my_std::Queue<int> queue;

    queue.push(5);
    queue.push(9);
    queue.push(8);
    queue.push(7);

    queue.pop();

    std::cout<<queue.size();

    return 0;

}