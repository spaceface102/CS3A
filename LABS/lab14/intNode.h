#ifndef INTNODE_STRUCT_H
#define INTNODE_STRUCT_H

struct IntNode
{
    int data;
    IntNode* next;
    IntNode* prev;
    IntNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};

#endif //INTNODE_STRUCT_H