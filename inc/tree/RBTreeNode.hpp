#ifndef RBTreeNode
#define RBTreeNode

#include <iostream>
#include <stddef.h>
#include <memory>


namespace ft
{
    enum Color {RED, BLACK};

    template <class T>
    struct Node
    {
        T key;
        Color color;
        Node *left, *right, *parent;
        Node(T key) : key(key), color(RED), left(NULL), right(NULL), parent(NULL) {}
    };
}

#endif