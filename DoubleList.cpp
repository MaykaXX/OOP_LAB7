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
    if (head == nullptr) {
        throw "Error: List is empty!";
    }

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

template<typename T>
T &DoubleList<T>::operator[](const int index) {
    if (index < 0 || index >= size) {
        throw "Error: Index out of bounds!";
    }

    int counter = 0;
    DoubleNode<T> * current = head;
    while (current->next != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->next;
        counter++;
    }

    return head->data;
}

template<typename T>
void DoubleList<T>::insert(T data, int index) {
    if (index == 0) {
        push_front(data);
    }else {
        DoubleNode<T> * previous_node = head;
        for (int i = 0; i < index - 1; i++) {
            previous_node = previous_node->next;
        }
        DoubleNode<T> * newNode = new DoubleNode<T>(data);

        newNode->next = previous_node->next;
        newNode->previous = previous_node;

        if (previous_node->next != nullptr) {
            previous_node->next->previous = newNode;
        }

        previous_node->next = newNode;
    }
}

template<typename T>
void DoubleList<T>::remove(int index) {
    if (index == 0) {
        pop_front();
        return;
    }
    else {
        DoubleNode<T> * current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        DoubleNode<T> * previous_element = current->previous;
        current->previous->next = current->next;
        if (current->next != nullptr) {
            current->next->previous = current->previous;
        }
        delete current;
        size--;
    }
}

template<typename T>
int DoubleList<T>::find(T data) {
        int counter = 0;
        DoubleNode<T> * current = head;
        while (current->next != nullptr) {
            if (current->data == data) {
                return counter;
            }

            current = current->next;
            counter++;
        }

        return -1;
}
