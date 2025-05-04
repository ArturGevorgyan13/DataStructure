#ifndef G_H
#define G_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

template <typename T>
class Graph{

private:
    int n;
    std::vector<T> labels;
    std::vector<std::vector<int>> matrix;

public:
    Graph(int n);

public:
    void setlabel(int index,T val);
    void addedge(int u,int v);
    void display();
    void BFS(int vertex);
    void DFS(int vertex);
    void DFSrecursive(int vertex);
    void BFSrecursive(int vertex);

private:
    void DFSHelper(int vertex,std::vector<bool>& visited);
    void BFSHelper(std::queue<int>& q,std::vector<bool>& visited);

};

template <typename T>
Graph<T>::Graph(int n):n(n),labels(n),matrix(n,std::vector<int>(n,0)){}

template <typename T>
void Graph<T>::setlabel(int index,T val){

    labels[index]=val;

}

template <typename T>
void Graph<T>::addedge(int u,int v){

    matrix[u][v]=1;

    matrix[v][u]=1;

}

template <typename T>
void Graph<T>::display(){

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            std::cout<<matrix[i][j]<<" ";

        }

        std::cout<<"\n";

    }

}

template <typename T>
void Graph<T>::BFS(int start){

    std::vector<bool> visited(n,false);

    std::queue<int> q;

    visited[start]=true;

    q.push(start);

    while(!q.empty()){

        int vertex=q.front();

        q.pop();

        std::cout<<labels[vertex]<<" ";

        for(int neighbor=0;neighbor<n;neighbor++){

            if(matrix[vertex][neighbor]==1 && !visited[neighbor]){

                visited[neighbor]=true;

                q.push(neighbor);

            }

        }

    }

    std::cout<<std::endl;

}

template <typename T>
void Graph<T>::DFS(int start){

    std::vector<bool> visited(n,false);

    std::stack<int> s;

    visited[start]=true;

    s.push(start);

    while(!s.empty()){

        int vertex=s.top();

        s.pop();

        std::cout<<labels[vertex]<<" ";

        for(int i=0;i<n;i++){

            if(matrix[vertex][i]==1 && !visited[i]){

                visited[i]=true;

                s.push(i);

            }

        }

    }

    std::cout<<std::endl;

}

template <typename T>
void Graph<T>::DFSrecursive(int vertex){

    std::vector<bool> visited(n,false);

    DFSHelper(vertex,visited);

    std::cout<<std::endl;

}

template <typename T>
void Graph<T>::DFSHelper(int vertex,std::vector<bool>& visited){

    visited[vertex]=true;

    std::cout<<labels[vertex]<<" ";

    for(int i=0;i<n;i++){

        if(matrix[vertex][i]==1 && !visited[i]){

            DFSHelper(i,visited);

        }

    }

}

template <typename T>
void Graph<T>::BFSrecursive(int vertex){

    std::queue<int> q;

    q.push(vertex);

    std::vector<bool> visited(n,false);
   
    visited[vertex]=true;

    BFSHelper(q,visited);

    std::cout<<std::endl;

}

template <typename T>
void Graph<T>::BFSHelper(std::queue<int>& q,std::vector<bool>& visited){

    if(q.empty()) return;

    int v=q.front();

    q.pop();

    std::cout<<labels[v]<<" ";

    for(int i=0;i<n;i++){

        if(matrix[v][i]==1 && !visited[i]){

            visited[i]=true;
    
            q.push(i);

        }

    }

    BFSHelper(q,visited);

}

#endif