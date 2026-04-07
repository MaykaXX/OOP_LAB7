//
// Created by hwang on 07.04.2026.
//

#ifndef UNTITLED2_SINGLELIST_H
#define UNTITLED2_SINGLELIST_H
#include "SingleNode.h"

template<typename T>
class SingleList {
    SingleNode<T> * head = nullptr;
    int size = 0;

    public:
    SingleList(int data);
    ~SingleList();
    int get_size() {return size;};
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    bool is_empty();
    T& operator[](const int index);
    void insert(T data, int index);
    void printList();

};


#endif //UNTITLED2_SINGLELIST_H