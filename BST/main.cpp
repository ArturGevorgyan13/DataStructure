#include "bst.h"

int main()

{

    BST<int> tree;

    tree.insertR(20);   
    tree.insertR(13);
    tree.insertR(7);
    tree.insertR(9);
    tree.insertR(8);
    tree.insertR(10);
    tree.insertR(30);
    tree.insertR(25);
    tree.insertR(35);

    tree.postorderR();
    std::cout<<std::endl;
    tree.postorder();
    std::cout<<std::endl;
    tree.inorderR();
    std::cout<<std::endl;
    tree.inorder();
    std::cout<<std::endl;
    tree.preorderR();
    std::cout<<std::endl;
    tree.preorder();
    std::cout<<std::endl;
    tree.levelorder();
    std::cout<<std::endl;

    std::cout<<tree.search(8)<<std::endl;
    std::cout<<tree.search(12)<<std::endl;
    std::cout<<tree.searchR(9)<<std::endl;
    std::cout<<tree.searchR(90)<<std::endl;

    tree.removeR(9);
    tree.inorder();
    std::cout<<std::endl;
    std::cout<<tree.search(9)<<std::endl;

    std::cout<<tree.findmax()<<std::endl;
    std::cout<<tree.findmin()<<std::endl;

    std::cout<<tree.getheight()<<std::endl;
    std::cout<<tree.getheightR()<<std::endl;

    return 0;

}