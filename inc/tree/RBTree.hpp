#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include "../iterators/rb_iterator.hpp"
#include <iostream>
#include <stddef.h>
#include <memory>

namespace ft
{
    template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
    class RBTree
    {
    private:
        // tpyedef include
        typedef ft::RBTreeNode<T> node_type;
        typedef T value_type;
        typedef Compare value_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::template rebind<node_type>::other node_allocator_type;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename node_type::node_ptr node_ptr;
        typedef typename node_type::const_node_ptr const_node_ptr;

        typedef ft::rb_iterator<node_ptr, value_type> iterator;
        typedef ft::rb_iterator<const_node_ptr, value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        size_type _size;
        node_type _parent;
        node_ptr _begin_node;
        value_compare _compare;
        allocator_type _allocator;
        node_allocator_type _node_allocator;

        /*
         * Member functions :
         */
    public:
        // Constructors
        RBtree(const value_compare &comp, const allocator_type &alloc)
            : _size(), _parent(), _begin_node(&_parent), _compare(comp), _allocator(alloc), _node_allocator(alloc) {}

        RBtree(const RBtree &t)
            : _size(), _parent(), _begin_node(&_parent), _compare(t._compare), _allocator(t._allocator), _node_allocator(t._node_allocator)
        {
            if (t.root() != NULL)
            {
                this->root() = this->copy(t.root());
                this->root()->_parent = &this->_parent;
            }
        }

        // Destructor
        ~RBtree()
        {
            if (this->root() != NULL)
            {
                this->destroy(this->root());
                this->root() = NULL;
                this->_begin_node = this->end_node();
            }
        }

        // Operator Overload
        RBtree &operator=(const RBtree &t)
        {
            if (this != &t)
            {
                this->clear();
                this->_compare = t._compare;
                if (t.root() != NULL)
                {
                    this->root() = this->copy(t.root());
                    this->root()->_parent = &this->_parent;
                }
            }
            return *this;
        }
    public:
        // Iterators
		iterator begin() { return iterator(this->_begin_node); }
		const_iterator begin() const { return const_iterator(this->_begin_node); }
		iterator end() { return iterator(&this->_parent); }
		const_iterator end() const { return const_iterator(&this->_parent); }
		reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

		// Capacity
		bool empty() const { return this->_size == 0; }
		size_type size() const { return this->_size; }
		size_type max_size() const { return this->_allocator.max_size() / 5; }
    public:
        // get-set

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

        bool is_nil(nodeType node) const
        {
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
        void rotate_left(node_ptr node)
		{
			node_ptr right_node = node->_right;
			node->_right = right_node->_left;
			if (node->_right != NULL)
				node->_right->_parent = node;
			right_node->_parent = node->_parent;
			if (tree_is_left_child<value_type>(node))
				node->_parent->_left = right_node;
			else
				node->_parent->_right = right_node;
			right_node->_left = node;
			node->_parent = right_node;
		}

		void rotate_right(node_ptr node)
		{
			node_ptr left_node = node->_left;
			node->_left = left_node->_right;
			if (node->_left != NULL)
				node->_left->_parent = node;
			left_node->_parent = node->_parent;
			if (tree_is_left_child<value_type>(node))
				node->_parent->_left = left_node;
			else
				node->_parent->_right = left_node;
			left_node->_right = node;
			node->_parent = left_node;
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