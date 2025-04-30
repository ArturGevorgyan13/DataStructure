#ifndef D_H
#define D_H
#include <iostream>

template <typename T>
class Deque{

private:    
    static const int N=10;
    int rear;
    int front;
    int count;
    T deque[N];
    
public: 
    Deque();
    ~Deque()=default;
    Deque(const Deque& other)=default;
    Deque(Deque&& other)=default;
    Deque& operator=(const Deque& other)=default;
    Deque& operator=(Deque&& other)=default;

public:
    void insertfront(T data);
    void insertrear(T data);
    void deletefront();
    void deleterear();
    void display() const;
    T* getfront();
    T* getrear();
    const T* getfront() const;
    const T* getrear() const;
    int size() const;
    bool empty() const;
    void clear();

};

template <typename T>
Deque<T>::Deque(): rear(-1),front(-1),count(0){}

template <typename T>
int Deque<T>::size() const{

    return count;

}

template <typename T>
bool Deque<T>::empty() const{

    return count==0;

}

template <typename T>
T* Deque<T>::getfront(){

    if(rear==-1){
        
        std::cout<<"Deque is empty!\n";

        return nullptr;

    }

    else return &deque[front];

}

template <typename T>
T* Deque<T>::getrear(){

    if(rear==-1){
           
        std::cout<<"Deque is empty!\n";

        return nullptr;

    }

    else return &deque[rear];

}

template <typename T>
const T* Deque<T>::getfront() const{

    if(rear==-1){
        
        std::cout<<"Deque is empty!\n";

        return nullptr;

    }

    else return &deque[front];

}

template <typename T>
const T* Deque<T>::getrear() const{

    if(rear==-1){
        
        std::cout<<"Deque is empty!\n";

        return nullptr;

    }

    else return &deque[rear];

}

template <typename T>
void Deque<T>::clear(){

    rear=front=-1;

    count=0;

}

template <typename T>
void Deque<T>::display() const{

    if(rear==-1){
        
        std::cout<<"Deque is empty!\n";

        return;

    }    

    int i=front;

    while(i!=rear){

        std::cout<<deque[i]<<" ";

        i=(i+1)%N;

    }

    std::cout<<deque[i]<<std::endl;

}

template <typename T>
void Deque<T>::insertfront(T data){

    if(front==(rear+1)%N){
        
        std::cout<<"Deque is full!\n";

        return;

    }    

    if(rear==-1){
        
        rear=front=0;

        deque[rear]=data;

    }    

    else if(front==0){
        
        front=N-1;

        deque[front]=data;

    }    

    else{

        deque[--front]=data;

    }

    ++count;

}

template <typename T>
void Deque<T>::insertrear(T data){

    if(front==(rear+1)%N){

        std::cout<<"Deque is full!\n";

        return;

    }

    if(rear==-1){

        rear=front=0;

        deque[rear]=data;

    }

    else if(rear==N-1){

        rear=0;

        deque[rear]=data;

    }

    else{

        deque[++rear]=data;

    }

    ++count;

}

template <typename T>
void Deque<T>::deletefront(){

    if(rear==-1){

        std::cout<<"Deque is empty!\n";

        return;

    }

    if(rear==front){

        rear=front=-1;

    } 

    else if(front==N-1){

        front=0;

    }

    else{

        ++front;

    }

    --count;

}

template <typename T>
void Deque<T>::deleterear(){

    if(rear==-1){

        std::cout<<"Deque is empty!\n";

        return;

    }

    else if(rear==front){

        rear=front=-1;

    }

    else if(rear==0){

        rear=N-1;

    }

    else{

        --rear;

    }


    --count;

}

#endif