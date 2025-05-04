#include "graph.h"

int main()

{

    Graph<char> g(5);

    g.setlabel(0,'A');
    g.setlabel(1,'B');
    g.setlabel(2,'C');
    g.setlabel(3,'D');
    g.setlabel(4,'E');

    g.addedge(0,1);    
    g.addedge(0,2);   
    g.addedge(2,3);   
    g.addedge(1,3);  
    g.addedge(3,4);  
    
    g.display();

    g.BFS(0);
    g.DFS(0);

    return 0;

}