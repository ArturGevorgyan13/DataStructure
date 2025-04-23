#include "stack.h"

template <typename T,int size>
my_std::Stack<T,size>::Stack(){

    vec.reserve(size);

}

template <typename T,int size>
my_std::Stack<T,size>::~Stack(){

    vec.clear();

}

template <typename T,int size>
void my_std::Stack<T,size>::push(const T& element){

    vec.push_back(element);

}

template <typename T,int size>
T my_std::Stack<T,size>::pop(){

    if(size==0) throw std::out_of_range("Error!");

    T tmp=vec[vec.fsize()-1];

    vec.pop_back();

    return tmp;

}

template <typename T,int size>
bool my_std::Stack<T,size>::isempty() const{

    return vec.fsize()==0;

}

template <typename T,int size>
T my_std::Stack<T,size>::top() const{

    return vec[vec.fsize()-1];

}

template <typename T,int size>
int my_std::Stack<T,size>::ssize() const{

    return vec.fsize();

}

template <typename T,int size>
void my_std::Stack<T,size>::clear(){

    vec.clear();

}