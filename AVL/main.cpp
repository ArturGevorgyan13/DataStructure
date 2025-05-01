#include "avl.h"

int main()

{

    AVL<int> tree;

    tree.root=tree.insert(tree.root,5);
    tree.root=tree.insert(tree.root,7);
    tree.root=tree.insert(tree.root,3);
    tree.root=tree.insert(tree.root,2);
    tree.root=tree.insert(tree.root,1);
    tree.root=tree.insert(tree.root,0);
    tree.root=tree.insert(tree.root,10);

    std::cout<<tree.getheight(tree.root)<<std::endl;

    return 0;

}
