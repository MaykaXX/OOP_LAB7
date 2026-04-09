//
// Created by hwang on 09.04.2026.
//

#include "DoubleList.h"
#include <iostream>

template<typename T>
DoubleList<T>::DoubleList(T data) {
    head = new DoubleNode<T>();
    head->data = data;
    head->next = nullptr;
    head->prev = nullptr;
    size++;
}

template<typename T>
DoubleList<T>::~DoubleList() {
    while (head->next != nullptr) {
        DoubleNode<T> * current = head->next;
        delete head;
        head = current;
        size--;
    }
}

template<typename T>
void DoubleList<T>::push_back(T data) {
    if (head == nullptr) {
        head = new DoubleNode<T>(data);
    }
    else {
        DoubleNode<T> * current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        DoubleNode<T> *new_node = new DoubleNode<T>(data);
        current->next = new_node;
        new_node->prev = current;

    }
    size++;
}

template<typename T>
void DoubleList<T>::push_front(T data) {
    if (head == nullptr) {
        head = new DoubleNode<T>(data);
    }else {
        DoubleNode<T> * current = head;
        head = new DoubleNode<T>(data);
        head->next = current;
        current->prev = head;
    }
    size++;
}

template<typename T>
void DoubleList<T>::pop_back() {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    DoubleNode<T> *current = head;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        size--;
    }

    while (current->next != nullptr) {
        current = current->next;
    }

    DoubleNode<T> * previous = current->prev;
    previous->next = nullptr;
    delete current;

    size--;
}


