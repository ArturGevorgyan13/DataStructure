#include "listdoublecircular.h"

int main()

{

    DLC<int> list;

    std::cout<<list.empty()<<std::endl;

    list.display();

    list.insertbegin(5);
    list.insertbegin(9);
    list.insertbegin(2);
    list.insertbegin(7);

    list.display();

    list.insertend(3);
    list.insertend(0);

    list.display();

    list.insert(11,2);

    list.display();

    std::cout<<list.size()<<std::endl;

    list.erase(2);

    list.display();

    DLC<int> list2=list;

    list2.display();

    list2.reverse();

    list2.display();

    list.display();

    return 0;

}