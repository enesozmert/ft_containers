#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include <iostream>
#include <stddef.h>
#include <memory>

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class RBTree
    {
    private:
        // tpyedef include
        typedef T value_type;
        typedef typename Alloc::template rebind<Node<T> >::other allocator_type; //
        typedef typename Alloc::reference reference;                             // Reference to element
        typedef typename Alloc::const_reference const_reference;                 // Reference to constant element
        typedef typename Alloc::pointer pointer;                                 // Pointer to element
        typedef typename Alloc::const_pointer const_pointer;                     // Pointer to const element
        typedef	ft::reverse_iterator<iterator> reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ft::Node<T> *nodeType;

    private:
        nodeType _root;
        nodeType _header;
        nodeType _nil;
        nodeType _last;
        ft::Color currentColor;
        ft::Color rootColor;
        ft::Color nilColor;
        allocator_type _allocator;
        size_t _count;

    public:
        // form;
        RBTree() : _root(NULL), _end(NULL), _last(NULL), _allocator()
        {
            currentColor = ft::RED;
            nilColor = ft::BLACK;
            rootColor = ft::BLACK;

            createNode(&this->_end, T());
            _end->color = ft::BLACK;
        }
        // RBTree(const allocator_type& _alloc = allocator_type()) : _root(NULL), _end(NULL), _last(NULL), _allocator(_alloc)
        // {
        //     create_node(&this->_end, getRoot(), _allocator);
        //     _end->color = BLACK;
        // }ı
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
        nodeType getRoot()
        {
            return (_root);
        }

        nodeType getLast()
        {
            return (_last);
        }

    public:
        // rules;
        bool isRootColorBlack(nodeType &node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node->color != ft::BLACK)
                return (false);
            return (true);
        }
        bool isCurrentColorRed(nodeType node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node->color != ft::RED)
                return (false);
            return (true);
        }
        bool isRootChildColorRed(nodeType node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node->parent && node->parent->color == ft::RED && node->color == ft::RED)
                return (false);
            return (true);
        }

        bool is_nil(nodeType node) const {
			return node == _nil || node == _header;
		}

    private:
        // tree utils;
        int getHeight(nodeType *root)
        {
            if (root == NULL)
                return (0);
            return (1 + std::max(getHeight(root->left), getHeight(root->right)));
        }
        nodeType getMax(nodeType root)
        {
            if (!root || !root->right)
                return (root);
            return getMax(root->right);
        }
        nodeType getMin(nodeType root)
        {
            if (!root || !root->left)
                return (root);
            return getMin(root->left);
        }
        void changeColor(nodeType *node)
        {
            (void)node;
        }
        void rootChangeColor(nodeType root)
        {
            if (root != NULL)
                root->color = ft::BLACK;
        }
        void lastedNode(nodeType lastNode)
        {
            _last = search(lastNode->key);
            // std::string color = _last->parent->color == RBTreeNode::RED ? "RED" : "BLACK";
            // std::cout << "last color : " << color << "num" << _last->parent->key << std::endl;
        }
        void createNode(nodeType *node, value_type value)
        {
            *node = _allocator.allocate(1);
            _allocator.construct(*node, value);
        }

    public:
        // tree user utils
        void printHelper(nodeType root, std::string indent, bool last)
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

                std::string sColor = root->color == ft::RED ? "RED" : "BLACK";
                std::cout << root->key << "(" << sColor << ")" << std::endl;
                printHelper(root->left, indent, false);
                printHelper(root->right, indent, true);
            }
        }

    public:
        // tree rotate;
        void rotateLeft(nodeType ptr)
        {
            nodeType y;

			y = node->right;
			node->right = y->left;
			if (!is_nil(y->left))
				y->left->parent = node;
			y->parent = node->parent;
			if (node->parent == NULL)
				_root = y;
			else if (node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
			y->left = node;
			node->parent = y;
        }
        void rotateRight(nodeType ptr)
        {
            nodeType left_child = ptr->left;
            ptr->left = left_child->right;
            if (ptr->left != NULL)
                ptr->left->parent = ptr;
            left_child->parent = ptr->parent;
            if (ptr->parent == _end)
                _end->left = left_child;
            if (ptr->parent == NULL)
                _root = left_child;
            else if (isLeftLeftCase(ptr))
                ptr->parent->left = left_child;
            else
                ptr->parent->right = left_child;
            left_child->right = ptr;
            ptr->parent = left_child;
        }

    private:
        void fixValidation(nodeType node)
        {
            // while (node.parent != NULL && node.parent->color == RED)
            // {
            // }
            selectState(node);
            // 3. olarak yazılır/kullanılır; true => devam , false
        }
        bool checkValidation(nodeType node)
        {
            // 3. olarak yazılır/kullanılır; true => devam , false => fixValidation yapılır?
            (void)node;
            // nodeType*current = root;
            // while (current != NULL)
            // {
            // }
            return (true);
        }
        int selectState(nodeType node)
        {
            // (void)node;
            // 2. olarak yazılır/kullanılır;
            (void)node;
            // if (isLeftLeftCase(node->left))
            // {
            //     std::cout << "left left Case OKOKOKOKOKOKOKOKOKOKOKOKOKOOKKOKOO" << std::endl;
            //     // rotateRight(node);
            // }
            // else
            //     std::cout << "left left Case NONONONONONONONONONO" << std::endl;
            // if (isRightRightCase(node->right))
            // {
            //     std::cout << "ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok" << std::endl;
            //     // rotateLeft(node);
            // }
            // else
            //     std::cout << "no no no no no no no no no no non ono no non on on onononon ononon ononon ononon onon o" << std::endl;
            return (0);
        }

    public:
        nodeType search(const value_type &key)
        {
            nodeType current = _root;
            while (current != NULL)
            {
                if (current->key == key)
                {
                    std::cout << "Found " << key << " in Red Black Tree.\n";
                    return (current);
                }
                else if (current->key < key)
                    current = current->right;
                else
                    current = current->left;
            }
            std::cout << key << " is not found in Red Black Tree.\n";
            return (NULL);
        }
        void insertForRoot(const value_type &key)
        {
            createNode(&_root, key);
            _root->color = ft::BLACK;
            _end->left = getRoot();
            _root->parent = _end;
            _end->parent = getMax(_root);
            if (_root != NULL && _root->parent != NULL)
                lastedNode(_root);
        }
        void insertForChild(const value_type &key)
        {
            nodeType ptr;
            nodeType parent = NULL;
            nodeType current = _root;

            createNode(&ptr, key);
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
            fixValidation(_last);
        }
        void insert(const value_type &key)
        {
            if (!_end)
                createNode(&_end, T());
            if (_root == NULL)
                insertForRoot(key);
            else
                insertForChild(key);
            _count += 1;
            // selectState
            // isAllFunction
            // fixValidation for is
            // checkValidation
            rootChangeColor(_root);
            return;
        }
        void delone(const value_type &key)
        {
            (void)key;
            return;
        }
    };
}

#endif