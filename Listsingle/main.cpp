#include "listsingle.h"

int main()

{

    my_std::List<int> list;

    list.push_front(5);

    list.insert(list.find(5),4);

    std::cout<<list.find(4)->getdata();

    return 0;

}