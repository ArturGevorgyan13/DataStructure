#include "listdouble.tpp"

int main()

{

    my_std::List<int> list;

    list.inserthead(5);

    list.inserthead(6);

    list.inserttail(7);

    list.insertposition(2,1);

    list.insertposition(1,9);

    list.displayforward();

    my_std::List<int> list2(list);

    list2.displayforward();

    return 0;

}