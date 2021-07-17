#ifndef INTNODE_STRUCT_H
#define INTNODE_STRUCT_H

struct IntNode
{
    int data;
    IntNode* next;
    IntNode(int data) : data(data), next(nullptr) {}
};

#endif //INTNODE_STRUCT_H