//
// Created by hwang on 07.04.2026.
//

#ifndef UNTITLED2_SINGLENODE_H
#define UNTITLED2_SINGLENODE_H
#include <memory>

template<typename T>
struct SingleNode {
    int data;
    std::shared_ptr<SingleNode> next;
};

#endif //UNTITLED2_SINGLENODE_H