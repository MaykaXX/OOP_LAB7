
#include <iostream>
#include "SingleList.h"

template<typename T>
SingleList<T>::SingleList(T data) {
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

template<typename T>
void SingleList<T>::printList() {
    if (head == nullptr) {
        std::cout << "[]" << std::endl;
    }
    SingleNode<T> * current = head;
    std::cout <<"[";
    while (current->next != nullptr) {
        std::cout << current->data << ", ";
        current = current->next;
    }
    std::cout << current->data;
    std::cout << "]" << std::endl;

}

template<typename T>
void SingleList<T>::pop_back() {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    SingleNode<T> *current = head;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        size--;
    }

    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;

    size--;


}

template<typename T>
void SingleList<T>::pop_front() {
    SingleNode<T> * temp = head;
    head = head->next;
    delete temp;
    size--;
}

template<typename T>
bool SingleList<T>::is_empty() {
    if (head == nullptr) {
        return true;
    }else {
        return false;
    }
}

template<typename T>
T &SingleList<T>::operator[](const int index) {
    int counter = 0;
    SingleNode<T> * current = head;
    while (current->next != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->next;
        counter++;
    }
}

template<typename T>
void SingleList<T>::insert(T data, int index) {

    if (index == 0) {
        push_front(data);
    }else {
        SingleNode<T> * previous = head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->next;
        }
        SingleNode<T> * newNode = new SingleNode<T>(data, previous->next);
        previous->next = newNode;
    }
}

template<typename T>
void SingleList<T>::remove(int index) {
    if (index == 0) {
        pop_front();
    }
    else {
        SingleNode<T> * previous = head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->next;
        }

        SingleNode<T> * next_element = previous->next->next;
        delete previous->next;
        previous->next = next_element;

    }
}

template<typename T>
int SingleList<T>::find(T data) {
    int counter = 0;
    SingleNode<T> * current = head;
    while (current->next != nullptr) {
        if (current->data == data) {
            return counter;
        }

        current = current->next;
        counter++;
    }

    return -1;
}

