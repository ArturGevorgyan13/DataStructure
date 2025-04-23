#include "avl.h"

int main()

{

    AVL<int> tree;

    tree.insert(tree.root,5);
    tree.insert(tree.root,7);
    tree.insert(tree.root,3);
    tree.insert(tree.root,2);
    tree.remove(tree.root,2);

    std::cout<<tree.getheight(tree.root)<<std::endl;

    return 0;

}