//
// Created by hwang on 09.04.2026.
//

#ifndef UNTITLED2_DOUBLENODE_H
#define UNTITLED2_DOUBLENODE_H

template<typename T>
struct DoubleNode {
    T data;
    DoubleNode* next;
    DoubleNode* previous;
};


#endif //UNTITLED2_DOUBLENODE_H