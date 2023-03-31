#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include "../iterators/rb_iterator.hpp"
#include <iostream>
#include <stddef.h>
#include <memory>

class RBTreeNode;
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

        typedef typename RBTreeNode<T>::Color node_color;

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
        RBTree(const value_compare &comp, const allocator_type &alloc)
            : _size(), _parent(), _begin_node(&_parent), _compare(comp), _allocator(alloc), _node_allocator(alloc) {}

        RBTree(const RBTree &t)
            : _size(), _parent(), _begin_node(&_parent), _compare(t._compare), _allocator(t._allocator), _node_allocator(t._node_allocator)
        {
            if (t.root() != NULL)
            {
                this->root() = this->copy(t.root());
                this->root()->_parent = &this->_parent;
            }
        }

        // Destructor
        ~RBTree()
        {
            if (this->root() != NULL)
            {
                this->destroy(this->root());
                this->root() = NULL;
                this->_begin_node = this->end_node();
            }
        }

        // Operator Overload
        RBTree &operator=(const RBTree &t)
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
        bool isRootColorBlack(node_ptr &node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node->color != ft::BLACK)
                return (false);
            return (true);
        }
        bool isCurrentColorRed(node_ptr node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node->color != ft::RED)
                return (false);
            return (true);
        }
        bool isRootChildColorRed(node_ptr node)
        {
            // (void)node;
            // 1. olarak yazılır/kullanılır;
            if (node->parent && node->parent->color == ft::RED && node->color == ft::RED)
                return (false);
            return (true);
        }

    private:
        // tree utils;
        int getHeight(node_ptr *root)
        {
            if (root == NULL)
                return (0);
            return (1 + std::max(getHeight(root->left), getHeight(root->right)));
        }
        node_ptr getMax(node_ptr root)
        {
            if (!root || !root->right)
                return (root);
            return getMax(root->right);
        }
        node_ptr getMin(node_ptr root)
        {
            if (!root || !root->left)
                return (root);
            return getMin(root->left);
        }
        node_color get_node_color(node_ptr node)
		{
			if (node == NULL)
				return BLACK;
			else
				return node->_color;
		}
        node_ptr construct_node(const value_type& data)
		{
			node_ptr new_node = this->_node_allocator.allocate(1);
			this->_allocator.construct(&new_node->_data, data);
			new_node->_color = RED;
			new_node->_parent = NULL;
			new_node->_left = NULL;
			new_node->_right = NULL;
			if (this->empty() || this->_compare(data, this->_begin_node->_data))
				this->_begin_node = new_node;
			++this->_size;
			return new_node;
		}   
		node_ptr copy(const_node_ptr node)
		{
			if (node == NULL)
				return NULL;
			node_ptr new_node = this->construct_node(node->_data);
			new_node->_left = copy(node->_left);
			if (new_node->_left != NULL)
				new_node->_left->_parent = new_node;
			new_node->_right = copy(node->_right);
			if (new_node->_right != NULL)
				new_node->_right->_parent = new_node;
			return new_node;
		}
        node_ptr get_sibling(node_ptr node) const
		{
			if (tree_is_left_child<value_type>(node))
				return node->_parent->_right;
			else
				return node->_parent->_left;
		}

    public:
        // tree user utils
        void printHelper(node_ptr root, std::string indent, bool last)
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

    public:
        // Observer
        value_compare value_comp() const { return this->_compare; }

    public:
        // Operations
        iterator find(const value_type &val)
        {
            node_ptr node = this->root();

            while (node != NULL)
            {
                if (this->_compare(node->_data, val))
                    node = node->_right;
                else if (this->_compare(val, node->_data))
                    node = node->_left;
                else
                    return iterator(node);
            }
            return this->end();
        }

        const_iterator find(const value_type &val) const
        {
            const_node_ptr node = this->root();

            while (node != NULL)
            {
                if (this->_compare(node->_data, val))
                    node = node->_right;
                else if (this->_compare(val, node->_data))
                    node = node->_left;
                else
                    return const_iterator(node);
            }
            return this->end();
        }
        void delone(const value_type &key)
        {
            (void)key;
            return;
        }
    };
}

#endif