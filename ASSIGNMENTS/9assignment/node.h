#ifndef NODE_STRUCT_TEMPLATE_H
#define NODE_STRUCT_TEMPLATE_H

template<typename E>
struct Node
{
    E data;
    Node *next;
    Node(E data) : data(data), next(nullptr) {}
};

#endif