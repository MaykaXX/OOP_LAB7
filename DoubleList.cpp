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
    head->previous = nullptr;
    size++;
}

template<typename T>
DoubleList<T>::~DoubleList() {
    while (head != nullptr) {
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
        new_node->previous = current;

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
        current->previous = head;
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
        return;
    }

    while (current->next != nullptr) {
        current = current->next;
    }

    DoubleNode<T> * previous = current->previous;
    previous->next = nullptr;
    delete current;

    size--;
}

template<typename T>
void DoubleList<T>::printList() {
    if (head == nullptr) {
        std::cout << "[]" << std::endl;
        return;
    }
    DoubleNode<T> * current = head;
    std::cout <<"[";
    while (current->next != nullptr) {
        std::cout << current->data << ", ";
        current = current->next;
    }
    std::cout << current->data;
    std::cout << "]" << std::endl;
}

template<typename T>
void DoubleList<T>::pop_front() {
    if (head == nullptr) return;

    DoubleNode<T> * tmp = head;
    head = head->next;

    if (head!=nullptr) {
        head->previous = nullptr;
    }

    delete tmp;
    size--;
}

template<typename T>
bool DoubleList<T>::is_empty() {
    if (head == nullptr) {
        return true;
    }else {
        return false;
    }
}
