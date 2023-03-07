#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include <iostream>

class RBTree
{
    private:
        Node *root;
        RBTreeNode::Color currentColor;
        RBTreeNode::Color nilColor;
    public:
        // form;
        RBTree() : root(NULL), currentColor(RBTreeNode::RED), nilColor(RBTreeNode::BLACK)
        {
            currentColor = RBTreeNode::RED;
            nilColor = RBTreeNode::BLACK;
        }
        RBTree(RBTree const &rBTree)
        {
            *this = rBTree;
        }
        RBTree &operator=(RBTree const &rBTree)
        {
            if (this == &rBTree)
                return (*this);
            root = rBTree.root;
            return (*this);
        }
        ~RBTree(){}
    public:
        //get-set
        Node *getRoot()
        {
            return (root);
        }
    private:
        // rules;
        bool isCurrentColorRed(Node &node)
        {
            (void)node;
            // 1. olarak yazılır/kullanılır;
            return (true);
        }
        bool isRootChildColorRed(Node &node)
        {
            (void)node;
            // 1. olarak yazılır/kullanılır;
            return (true);
        }
        bool isRootToNilBlackCount(Node &node)
        {
            (void)node;
            // 1. olarak yazılır/kullanılır;
            return (true);
        }

    private:
        // tree utils;
        int getHeight(Node *root)
        {
            if (root == NULL)
                return (0);
            return (1 + std::max(getHeight(root->left), getHeight(root->right)));
        }
    public:
        //tree user utils
        void printRBTree(Node *root, int space = 0, int height = 10, int distance = 5)
        {
            height = getHeight(root);
            distance = height / 2;
            if (root == NULL)
                return;
            space += distance;
            printRBTree(root->right, space, height, distance);

            std::cout << std::endl;
            for (int i = distance; i < space; i++)
                std::cout << " ";
            std::cout << root->key << (root->color == BLACK ? "B" : "R") << std::endl;

            printRBTree(root->left, space, height, distance);
        }
    public:
        // tree rotate;
        void rotateLeft(Node *ptr)
        {
            Node *right_child = ptr->right;
            ptr->right = right_child->left;

            if (ptr->right != NULL)
                ptr->right->parent = ptr;
            right_child->parent = ptr->parent;
            if (ptr->parent == NULL)
                root = right_child;
            else if (ptr == ptr->parent->left)
                ptr->parent->left = right_child;
            else
                ptr->parent->right = right_child;
            right_child->left = ptr;
            ptr->parent = right_child;
        }
        void rotateRight(Node *ptr)
        {
            Node *left_child = ptr->left;
            ptr->left = left_child->right;
            if (ptr->left != NULL)
                ptr->left->parent = ptr;
            left_child->parent = ptr->parent;
            if (ptr->parent == NULL)
                root = left_child;
            else if (ptr == ptr->parent->left)
                ptr->parent->left = left_child;
            else
                ptr->parent->right = left_child;
            left_child->right = ptr;
            ptr->parent = left_child;
        }

    private:
        void fixValidation(Node &node)
        {
            (void)node;
            // 3. olarak yazılır/kullanılır; true => devam , false
        }
        bool checkValidation(Node &node)
        {
            // 3. olarak yazılır/kullanılır; true => devam , false => fixValidation yapılır?
            (void)node;
            // Node *current = root;
            // while (current != NULL)
            // {
            // }
            return (true);
        }
        int selectState(Node &node)
        {
            // 2. olarak yazılır/kullanılır;
            (void)node;
            return (0);
        }

    public:
        Node *search(const int &n)
        {
            Node *current = root;
            while (current != NULL)
            {
                if (current->key == n)
                {
                    std::cout << "Found " << n << " in Red Black Tree.\n";
                    return (current);
                }
                else if (current->key < n)
                    current = current->right;
                else
                    current = current->left;
            }
            std::cout << n << " is not found in Red Black Tree.\n";
            return (NULL);
        }
        void insert(const int &key)
        {
            Node *ptr = new Node(key);
            Node *parent = NULL;
            Node *current = root;

            while (current != NULL)
            {
                parent = current;
                if (ptr->key < current->key)
                    current = current->left;
                else
                    current = current->right;
            }
            ptr->parent = parent;
            if (parent == NULL)
                root = ptr;
            else if (ptr->key < parent->key)
                parent->left = ptr;
            else
                parent->right = ptr;

            // selectState
            // isAllFunction
            // fixValidation for is
            // checkValidation
            return;
        }
        void delone(const int &key)
        {
            (void)key;
            return;
        }
};

#endif