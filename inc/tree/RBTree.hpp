#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include <iostream>
#include <stddef.h>
#include <memory>

namespace ft
{
    // template <class T, class Alloc = std::allocator<T> >
    class RBTree
    {
    private:
        // typedef T value_type;
 bv
    private:
        Node *_root;
        Node *_end;
        Node *_last;
        RBTreeNode::Color currentColor;
        RBTreeNode::Color rootColor;
        RBTreeNode::Color nilColor;
        // allocator_type _allocator;
    public:
        // form;
        RBTree() : _root(NULL), _end(NULL), _last(NULL)
        {
            currentColor = RBTreeNode::RED;
            nilColor = RBTreeNode::BLACK;
            rootColor = RBTreeNode::BLACK;

            // createNode(&this->_end, getRoot(), _allocator);
            // _end->color = BLACK;
        }
        // RBTree(const allocator_type& _alloc = allocator_type()) : _allocator(_alloc)
        // {
        //     create_node(&this->_end, _Val(), _allocator);
        //     _end->color = BLACK;
        // }
        RBTree(RBTree const &rBTree)
        {
            *this = rBTree;
        }
        RBTree &operator=(RBTree const &rBTree)
        {
            if (this == &rBTree)
                return (*this);
            _root = rBTree._root;
            return (*this);
        }
        ~RBTree() {}

    public:
        // get-set
        Node *getRoot()
        {
            return (_root);
        }

        Node *getLast()
        {
            return (_last);
        }

    public:
        // rules;
        bool isRootColorBlack(Node &node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node.color != RBTreeNode::BLACK)
                return (false);
            return (true);
        }
        bool isCurrentColorRed(Node &node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node.color != RBTreeNode::RED)
                return (false);
            return (true);
        }
        bool isRootChildColorRed(Node &node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node.parent && node.parent->color == RBTreeNode::RED && node.color == RBTreeNode::RED)
                return (false);
            return (true);
        }
        bool isRootToLeafBlackEqualCount(Node &node)//?
        {
            int blackCount = 0;

            Node* currNode = &node;
            while (currNode != NULL)
            {
                if (currNode->color == BLACK)
                    blackCount++;
                // Leaf node is reached
                if (currNode->left == NULL && currNode->right == NULL)
                    break;
                // Only one child is present and it is red
                if ((currNode->left != NULL && currNode->left->color == RED && currNode->right == NULL) ||
                    (currNode->right != NULL && currNode->right->color == RED && currNode->left == NULL))
                    break;
                // If both children are present and are black, move to the left child
                if (currNode->left != NULL && currNode->right != NULL && 
                    currNode->left->color == BLACK && currNode->right->color == BLACK)
                    currNode = currNode->left;
                else if (currNode->left != NULL && currNode->left->color == RED) // Move to the left child if it is red
                    currNode = currNode->left;
                else if (currNode->right != NULL && currNode->right->color == RED) // Move to the right child if it is red
                    currNode = currNode->right;
                else
                    break; // If any of the above conditions are not satisfied, break the loop
            }
            // Check if the number of black nodes on this path is equal to the count of black nodes on other paths
            Node* leafNode = currNode;
            int leafToRootBlackCount = 0;
            while (leafNode != NULL && leafNode != &node)
            {
                if (leafNode->color == BLACK)
                    leafToRootBlackCount++;

                leafNode = leafNode->parent;
            }
            return (leafToRootBlackCount == blackCount);
        }
        bool isLeftLeftCase(Node *nodeLeft)//right rot
        {
            if (!(nodeLeft->left && nodeLeft->key && nodeLeft->left->key))
                return (false);
            return (true);
        }
        bool isRightLeftCase(Node *node)//
        {
            if (!(node->parent != NULL && node->parent->parent != NULL &&
                 node->parent == node->parent->parent->left && node == node->parent->right))
                return (false);
            return (true);
        }
        bool isRightRightCase(Node *nodeRight)//left
        {
            if (!(nodeRight->right && nodeRight->key && nodeRight->right->key))
                return (false);
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
        Node *getMax(Node *root)
        {
            if (!root || !root->right)
                return (root);
            return getMax(root->right);
        }
        Node *getMin(Node *root)
        {
            if (!root || !root->left)
                return (root);
            return getMin(root->left);
        }
        void changeColor(Node *node)
        {
            (void)node;
        }
        void rootChangeColor(Node *root)
        {
            if (root != NULL)
                root->color = BLACK;
        }
        void lastedNode(Node *lastNode)
        {
            _last = search(lastNode->key);
            // std::string color = _last->parent->color == RBTreeNode::RED ? "RED" : "BLACK";
            // std::cout << "last color : " << color << "num" << _last->parent->key << std::endl;
        }

    public:
        // tree user utils
        void printRBTree(Node *root, int space = 0, int height = 10, int distance = 5)
        {
            height = getHeight(_root);
            distance = height / 2;
            if (_root == NULL)
                return;
            space += distance;
            printRBTree(root->right, space, height, distance);

            std::cout << std::endl;
            for (int i = distance; i < space; i++)
                std::cout << " ";
            std::cout << root->key << (root->color == BLACK ? "B" : "R") << std::endl;

            printRBTree(root->left, space, height, distance);
        }
        void printHelper(Node *root, std::string indent, bool last)
        {
            if (root != NULL)
            {
                std::cout << indent;
                if (last)
                {
                    std::cout << "R----";
                    indent += "   ";
                }
                else
                {
                    std::cout << "L----";
                    indent += "|  ";
                }

                std::string sColor = root->color == RBTreeNode::RED ? "RED" : "BLACK";
                std::cout << root->key << "(" << sColor << ")" << std::endl;
                printHelper(root->left, indent, false);
                printHelper(root->right, indent, true);
            }
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
            if (ptr->parent == _end)
                _end->left = right_child;
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
                _root = left_child;
            if (ptr->parent == _end)
                _end->left = left_child;
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
            while (node->parent != NULL && node->parent->color == RED)
            {
                isLeft
            }
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
            Node *current = _root;
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
            Node *current = _root;

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
            {
                _root = ptr;
                _root->parent = NULL;
            }
            else if (ptr->key < parent->key)
                parent->left = ptr;
            else
                parent->right = ptr;
            if (ptr != NULL && ptr->parent != NULL)
                lastedNode(ptr);
            // selectState
            // isAllFunction
            // fixValidation for is
            // checkValidation
            rootChangeColor(_root);
            return;
        }
        void delone(const int &key)
        {
            (void)key;
            return;
        }
    };
}

#endif