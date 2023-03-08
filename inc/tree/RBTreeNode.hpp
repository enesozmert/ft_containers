#ifndef RBTreeNode
#define RBTreeNode

#include <iostream>
#include <stddef.h>
#include <memory>

enum Color {RED, BLACK};

struct Node
{
    int key;
    Color color;
    Node *left, *right, *parent;
    Node(int key) : key(key), color(RED), left(NULL), right(NULL), parent(NULL) {}
};

template<typename T, typename Value, typename Alloc>
void createNode(T * node, Value value, Alloc allocator)
{
    *node = allocator.allocate(1);
    allocator.construct(*node, value);
}

#endif