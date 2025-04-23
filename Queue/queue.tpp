#include "queue.h"

template <typename T>
bool my_std::Queue<T>::empty() const{

    return list.empty();

}

template <typename T>
int my_std::Queue<T>::size() const{

    return list.size();

}

template <typename T>
void my_std::Queue<T>::push(const T& value){

    list.push_back(value);

}

template <typename T>
void my_std::Queue<T>::pop(){

    if(list.empty()) throw std::out_of_range("Error!");

    list.pop_front();

}

template <typename T>
T my_std::Queue<T>::front(){

    if(list.empty()) throw std::out_of_range("Error!");

    return list.front();

}

template <typename T>
T my_std::Queue<T>::back(){

    if(list.empty()) throw std::out_of_range("Error!");

    return list.back();

}