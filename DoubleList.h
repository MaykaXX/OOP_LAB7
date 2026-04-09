//
// Created by hwang on 09.04.2026.
//

#ifndef UNTITLED2_DOUBLELIST_H
#define UNTITLED2_DOUBLELIST_H
#include "DoubleNode.h"

template <typename T>
class DoubleList {
    DoubleNode<T> * head = nullptr;
    int size = 0;
public:
    DoubleList(T data);
    ~DoubleList();
    int get_size(){return size;}
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    bool is_empty();
    T& operator[](const int index);
    void insert(T data, int index);
    void remove(int index);
    int find(T data);
    void printList();


};


#endif //UNTITLED2_DOUBLELIST_H