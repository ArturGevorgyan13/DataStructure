#include "deque.h"

int main()

{

    Deque<int> d;

    std::cout<<d.size()<<std::endl;
    std::cout<<d.empty()<<std::endl;

    d.insertfront(5);
    d.insertfront(7);
    d.insertfront(9);

    d.insertrear(0);
    d.insertrear(-1);
    d.insertrear(-4);
    d.insertrear(-6);
    d.insertrear(-8);
    d.insertrear(-3);
    d.insertrear(-5);

    d.display();

    std::cout<<d.size()<<std::endl;
    std::cout<<d.empty()<<std::endl;

    //d.clear();
    //std::cout<<d.size()<<std::endl;

    d.deleterear();

    d.display();
    d.insertrear(0);

    d.display();

    d.insertrear(0);

    std::cout<<*(d.getfront())<<std::endl;
    std::cout<<*(d.getrear())<<std::endl;

    return 0;

}