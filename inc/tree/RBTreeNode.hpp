#ifndef RBTreeNode
#define RBTreeNode

#include <iostream>

enum Color {RED, BLACK};

struct Node
{
    int key;
    Color color;
    Node *left, *right, *parent;
    Node(int key) : key(key), color(RED), left(NULL), right(NULL), parent(NULL) {}
};


#endif