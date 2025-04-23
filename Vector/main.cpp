#include "vector.h"

int main()

{

    my_std::Vector<int> vec;

    vec.push_back(7);
    vec.push_back(0);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(4);

    vec.insert(2,9);

    vec.erase(2);

    for(int i=0;i<vec.fsize();i++){

        std::cout<<vec[i]<<std::endl;

    }

    vec.reserve(100);

    std::cout<<vec.fsize();

    return 0;

}