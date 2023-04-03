#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include "../iterators/rb_iterator.hpp"
#include "../iterators/rb_const_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../common/pair/pair.hpp"
#include "../common/algorithm/algorithm.hpp"
#include <iostream>
#include <stddef.h>
#include <memory>
#include <functional>
#include <cmath>

class RBTreeNode;
namespace ft
{
    template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
    class RBTree
    {
    private:
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

    public:
        typedef ft::rb_iterator<node_ptr, value_type> iterator;
        typedef ft::rb_const_iterator<const_node_ptr, value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        typedef Color node_color;

    private:
        size_type _size;
        node_type _parent;
        node_ptr _begin_node;
        value_compare _compare;
        allocator_type _allocator;
        node_allocator_type _node_allocator;

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
        node_ptr &root() { return this->_parent._left; }
        const_node_ptr &root() const { return const_cast<const_node_ptr &>(this->_parent._left); }
        node_ptr end_node() { return &this->_parent; }
        const_node_ptr end_node() const { return const_cast<const_node_ptr>(&this->_parent); }
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
        node_ptr construct_node(const value_type &data)
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

        node_ptr replacement_node(node_ptr node) const
        {
            if (node->_left == NULL || node->_right == NULL)
                return node;
            else
                return tree_min<value_type>(node->_right);
        }
        void destroy_node(node_ptr node)
        {
            this->_allocator.destroy(&node->_data);
            this->_node_allocator.deallocate(node, 1);
            --this->_size;
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

    private:
        // fixed point
        void rebalance_after_insertion(node_ptr node)
        {
            while (node != this->root() && this->get_node_color(node->_parent) == RED) // Case 1 & 2
            {
                node_ptr uncle = this->get_sibling(node->_parent);
                if (this->get_node_color(uncle) == RED) // Case 3
                {
                    uncle->flip_color();
                    node = node->_parent;
                    node->flip_color();
                    node = node->_parent;
                    node->flip_color();
                }
                else if (tree_is_left_child<value_type>(node->_parent)) // Case 4
                {
                    if (!tree_is_left_child<value_type>(node)) // Case 4.1
                    {
                        node = node->_parent;
                        this->rotate_left(node);
                    }
                    node = node->_parent; // Case 4.2
                    node->flip_color();
                    node = node->_parent;
                    node->flip_color();
                    this->rotate_right(node);
                    break;
                }
                else // Case 4
                {
                    if (tree_is_left_child<value_type>(node)) // Case 4.3
                    {
                        node = node->_parent;
                        this->rotate_right(node);
                    }
                    node = node->_parent; // Case 4.4
                    node->flip_color();
                    node = node->_parent;
                    node->flip_color();
                    this->rotate_left(node);
                    break;
                }
            }
        }
        void rebalance_before_erasion(node_ptr root, node_ptr node, node_ptr sibling)
        {
            while (true) // (node != root && this->get_node_color(node) == BLACK)
            {
                if (!tree_is_left_child<value_type>(sibling)) // tree_is_left_child(node)
                {
                    if (this->get_node_color(sibling) == RED) // Case 3
                    {
                        sibling->flip_color();
                        sibling->_parent->flip_color();
                        this->rotate_left(sibling->_parent);
                        if (root == sibling->_left)
                            root = sibling;
                        sibling = sibling->_left->_right;
                    }
                    if (this->get_node_color(sibling->_left) == BLACK && this->get_node_color(sibling->_right) == BLACK) // Case 4
                    {
                        sibling->flip_color();
                        node = sibling->_parent;
                        if (node == root || this->get_node_color(node) == RED)
                        {
                            node->_color = BLACK;
                            break;
                        }
                        sibling = this->get_sibling(node);
                    }
                    else // sibling has one red child
                    {
                        if (this->get_node_color(sibling->_right) == BLACK) // Case 5
                        {
                            sibling->_left->flip_color(); // the left child is red
                            sibling->flip_color();
                            this->rotate_right(sibling);
                            sibling = sibling->_parent;
                        }
                        sibling->_color = sibling->_parent->_color; // Case 6
                        sibling->_parent->_color = BLACK;
                        sibling->_right->_color = BLACK;
                        this->rotate_left(sibling->_parent);
                        break;
                    }
                }
                else // the same as before, but in reverse color
                {
                    if (this->get_node_color(sibling) == RED) // Case 3
                    {
                        sibling->flip_color();
                        sibling->_parent->flip_color();
                        this->rotate_right(sibling->_parent);
                        if (root == sibling->_right)
                            root = sibling;
                        sibling = sibling->_right->_left;
                    }
                    if (this->get_node_color(sibling->_left) == BLACK && this->get_node_color(sibling->_right) == BLACK) // Case 4
                    {
                        sibling->flip_color();
                        node = sibling->_parent;
                        if (node == root || this->get_node_color(node) == RED)
                        {
                            node->_color = BLACK;
                            break;
                        }
                        sibling = this->get_sibling(node);
                    }
                    else // sibling has one red child
                    {
                        if (this->get_node_color(sibling->_left) == BLACK) // Case 5
                        {
                            sibling->_right->flip_color(); // the right child is red
                            sibling->flip_color();
                            this->rotate_left(sibling);
                            sibling = sibling->_parent;
                        }
                        sibling->_color = sibling->_parent->_color; // Case 6
                        sibling->_parent->_color = BLACK;
                        sibling->_left->_color = BLACK;
                        this->rotate_right(sibling->_parent);
                        break;
                    }
                }
            }
        }

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
        node_ptr insert(node_ptr node, node_ptr new_node, bool &inserted, iterator &pos)
        {
            if (node == NULL)
            {
                pos = new_node;
                inserted = true;
                return new_node;
            }
            if (this->_compare(node->_data, new_node->_data) == this->_compare(new_node->_data, node->_data))
            {
                node->_left = insert(node->_left, new_node, inserted, pos);
                node->_left->_parent = node;
            }
            else if (this->_compare(node->_data, new_node->_data)) // greater than
            {
                node->_right = insert(node->_right, new_node, inserted, pos);
                node->_right->_parent = node;
            }
            else if (this->_compare(new_node->_data, node->_data)) // less than
            {
                node->_left = insert(node->_left, new_node, inserted, pos);
                node->_left->_parent = node;
            }
            else // equal
            {
                pos = node;
                inserted = false;
            }
            return node;
        }
        void erase(node_ptr root, node_ptr node)
        {
            node_ptr replmt = this->replacement_node(node);
            node_ptr replmt_child = replmt->_left == NULL ? replmt->_right : replmt->_left;
            node_ptr sibling = NULL;

            if (replmt_child != NULL)
                replmt_child->_parent = replmt->_parent;
            if (tree_is_left_child<value_type>(replmt))
            {
                replmt->_parent->_left = replmt_child;
                if (replmt == root)
                    root = replmt_child; // sibling will be null in this case
                else
                    sibling = replmt->_parent->_right;
            }
            else
            {
                // root can't be this->_parent's right child
                replmt->_parent->_right = replmt_child;
                sibling = replmt->_parent->_left;
            }

            node_color replmt_color = replmt->_color;

            if (replmt != node) // copy the content of node into replmt
            {
                replmt->_parent = node->_parent;
                if (tree_is_left_child<value_type>(node))
                    replmt->_parent->_left = replmt;
                else
                    replmt->_parent->_right = replmt;
                replmt->_left = node->_left;
                replmt->_left->_parent = replmt;
                replmt->_right = node->_right;
                if (replmt->_right != NULL)
                    replmt->_right->_parent = replmt;
                replmt->_color = node->_color;
                if (node == root)
                    root = replmt;
            }

            // we don't need to rebalance if we removed a red node or if there are no more nodes in the tree
            if (replmt_color == BLACK && root != NULL) // Case 1
            {
                // replmt had either no children or one red child (replmt_child).
                // so, if replmt_child != NULL it is either red or root.
                // root can't be double black and a red node will be flipped to black.
                if (replmt_child != NULL) // Case 2
                    replmt_child->_color = BLACK;
                else
                    this->rebalance_before_erasion(root, replmt_child, sibling); // replmt_child is always NULL at the start
            }
        }
        void destroy(node_ptr node)
        {
            if (node == NULL)
                return;
            destroy(node->_left);
            destroy(node->_right);
            this->destroy_node(node);
        }

    public:
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            iterator it = find(val);
            if (it != end())
                return ft::make_pair<iterator, bool>(it, false);

            node_ptr new_node = this->construct_node(val);
            bool inserted = false;
            iterator pos;

            this->root() = this->insert(this->root(), new_node, inserted, pos);
            this->root()->_parent = &this->_parent;
            if (!inserted)
                this->destroy_node(new_node);
            else
                this->rebalance_after_insertion(new_node);
            this->root()->_color = BLACK;
            return ft::make_pair(pos, inserted);
        }

        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            return this->insert(val).first;
        }

        template <typename InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            for (; first != last; first++)
                this->insert(*first);
        }
        void erase(iterator position)
        {
            node_ptr pos = position.base();
            if (pos == this->_begin_node)
            {
                position++;
                this->_begin_node = position.base();
            }
            this->erase(this->root(), pos);
            if (this->root() != NULL)
            {
                this->root()->_parent = this->end_node();
                this->root()->_color = BLACK;
            }
            this->destroy_node(pos);
        }

        size_type erase(const value_type &val)
        {
            iterator pos = this->find(val);
            if (pos == this->end())
                return 0;
            this->erase(pos);
            return 1;
        }

        void erase(iterator first, iterator last)
        {
            while (first != last)
                this->erase(first++);
        }

        void swap(RBTree &t)
        {
            ft::swap(this->_begin_node, t._begin_node);
            ft::swap(this->_parent._left, t._parent._left);
            ft::swap(this->_size, t._size);
            if (this->_size != 0 && t._size != 0)
                ft::swap(this->root()->_parent, t.root()->_parent);
            else if (this->_size != 0)
                this->root()->_parent = this->end_node();
            else if (t._size != 0)
                t.root()->_parent = t.end_node();
            ft::swap(this->_compare, t._compare);
        }

        void clear()
        {
            if (this->root() != NULL)
            {
                this->destroy(this->root());
                this->root() = NULL;
                this->_begin_node = this->end_node();
            }
        }
        size_type count(const value_type& val) const
		{ return this->find(val) == this->end() ? 0 : 1; }

		iterator lower_bound(const value_type& val)
		{
			node_ptr node = this->root();
			node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (!this->_compare(node->_data, val))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return iterator(pos);
		}

		const_iterator lower_bound(const value_type& val) const
		{
			const_node_ptr node = this->root();
			const_node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (!this->_compare(node->_data, val))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return const_iterator(pos);
		}

		iterator upper_bound(const value_type& val)
		{
			node_ptr node = this->root();
			node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return iterator(pos);
		}

		const_iterator upper_bound(const value_type& val) const
		{
			const_node_ptr node = this->root();
			const_node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return const_iterator(pos);
		}

		ft::pair<iterator, iterator> equal_range(const value_type& val)
		{
			node_ptr node = this->root();
			node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else if (this->_compare(node->_data, val))
					node = node->_right;
				else
					return ft::make_pair(iterator(node), iterator(node->_right == NULL ? pos : tree_min<value_type>(node->_right)));
			}
			return ft::make_pair(iterator(pos), iterator(pos));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const value_type& val) const
		{
			const_node_ptr node = this->root();
			const_node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else if (this->_compare(node->_data, val))
					node = node->_right;
				else
					return ft::make_pair(const_iterator(node), const_iterator(node->_right == NULL ? pos : tree_min<value_type>(node->_right)));
			}
			return ft::make_pair(const_iterator(pos), const_iterator(pos));
		}
    };
    template <typename T, typename Compare, typename Alloc>
    void swap(RBTree<T, Compare, Alloc> &first, RBTree<T, Compare, Alloc> &second)
    {
        std::cout << "swapping " << std::endl;
        first.swap(second);
    }
}

#endif