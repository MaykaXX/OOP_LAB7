
#include <iostream>
#include "SingleList.h"

template<typename T>
SingleList<T>::SingleList(int data) {
    head = new SingleNode<T>();
    head->data = data;
    head->next = nullptr;
    size++;
}

template<typename T>
SingleList<T>::~SingleList() {
    while (head->next != nullptr) {
        SingleNode<T> * current = head->next;
        delete head;
        head = current;
        size--;
    }
}

template<typename T>
void SingleList<T>::push_back(T data) {
    // auto *current = new SingleNode<T>();
    // current->data=data;

    if (head == nullptr) {
        head = new SingleNode<T>(data);
    }
    else {
        SingleNode<T> * current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new SingleNode<T>(data);
    }
    size++;
}

template<typename T>
void SingleList<T>::push_front(T data) {
    if (head == nullptr) {
        head = new SingleNode<T>(data);
    }else {
        SingleNode<T> * current = head;
        head = new SingleNode<T>(data);
        head->next = current;
    }
    size++;
}

