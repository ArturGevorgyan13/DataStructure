#include "listsinglecircular.h"

int main()

{

    ListCircular<int> list;

    list.insertbegin(1);
    list.insertbegin(5);
    list.insertbegin(7);
    list.insertbegin(0);

    list.insertbegin(1);
    list.insert(6,2);

    list.erasebegin();

    std::cout<<list.empty()<<std::endl;
    std::cout<<list.size()<<std::endl;


    list.display();

    list.reverse();

    list.display();

    return 0;

}