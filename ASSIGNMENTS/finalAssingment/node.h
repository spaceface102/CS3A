#ifndef NODE_STRUCT_TEMPLATE_H
#define NODE_STRUCT_TEMPLATE_H

template<typename E>
struct Node
{
    E data;
    Node<E> *next;
    Node<E>(E data) : data(data), next(nullptr) {}
};

#endif