#ifndef RB_CONST_ITERATOR_HPP
#define RB_CONST_ITERATOR_HPP

#include "rb_iterator.hpp"
#include "../functions/RBTreeFunctions.hpp"
#include "iterator_traits.hpp"
#include "../tree/RBTreeNode.hpp"

namespace ft
{

    template <typename Const_node_ptr, typename Value>
    class rb_const_iterator
    {
        /*
         * Member types :
         */
    public:
        typedef ft::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef Value value_type;
        typedef const Value *pointer;
        typedef const Value &reference;
        typedef rb_iterator<typename RBTreeNode<Value>::node_ptr, Value>	RBtree_normal_iterator;

        /*
         * Member variables :
         */
    private:
        Const_node_ptr _node;

        /*
         * Member functions :
         */
    public:
        rb_const_iterator() : _node() {}

        rb_const_iterator(const rb_const_iterator &it) : _node(it._node) {}

        rb_const_iterator(const RBtree_normal_iterator &it) : _node(it.base()) {}

        rb_const_iterator(const Const_node_ptr &val) : _node(val) {}

        rb_const_iterator &operator=(const rb_const_iterator &it)
        {
            if (this != &it)
                _node = it._node;
            return *this;
        }

        rb_const_iterator &operator=(const Const_node_ptr &p)
        {
            _node = p;
            return *this;
        }

        reference operator*() const { return _node->_data; }
        pointer operator->() const { return &(_node->_data); }

        rb_const_iterator &operator++()
        {
            if (_node->_right != NULL)
                _node = tree_min<value_type>(_node->_right);
            else
            {
                while (!tree_is_left_child<value_type>(_node))
                    _node = _node->_parent;
                _node = _node->_parent;
            }
            return *this;
        }

        rb_const_iterator operator++(int)
        {
            rb_const_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        rb_const_iterator &operator--()
        {
            if (_node->_left != NULL)
                _node = tree_max<value_type>(_node->_left);
            else
            {
                while (tree_is_left_child<value_type>(_node))
                    _node = _node->_parent;
                _node = _node->_parent;
            }
            return *this;
        }

        rb_const_iterator operator--(int)
        {
            rb_const_iterator tmp(*this);
            --(*this);
            return tmp;
        }

        Const_node_ptr base() const
        {
            return _node;
        }
    };

    template <typename Const_node_ptr, typename Value>
    inline bool
    operator==(const rb_const_iterator<Const_node_ptr, Value> &rhs,
               const rb_const_iterator<Const_node_ptr, Value> &lhs)
    {
        return rhs.base() == lhs.base();
    }

    template <typename Const_node_ptr, typename Value>
    inline bool
    operator!=(const rb_const_iterator<Const_node_ptr, Value> &rhs,
               const rb_const_iterator<Const_node_ptr, Value> &lhs)
    {
        return rhs.base() != lhs.base();
    }

    template <typename Const_node_ptr, typename Node_ptr, typename Value>
    inline bool
    operator==(const rb_const_iterator<Const_node_ptr, Value> &rhs,
               const rb_iterator<Node_ptr, Value> &lhs)
    {
        return rhs.base() == lhs.base();
    }

    template <typename Const_node_ptr, typename Node_ptr, typename Value>
    inline bool
    operator!=(const rb_const_iterator<Const_node_ptr, Value> &rhs,
               const rb_iterator<Node_ptr, Value> &lhs)
    {
        return rhs.base() != lhs.base();
    }

    template <typename Const_node_ptr, typename Node_ptr, typename Value>
    inline bool
    operator==(const rb_iterator<Node_ptr, Value> &rhs,
               const rb_const_iterator<Const_node_ptr, Value> &lhs)
    {
        return rhs.base() == lhs.base();
    }

    template <typename Const_node_ptr, typename Node_ptr, typename Value>
    inline bool
    operator!=(const rb_iterator<Node_ptr, Value> &rhs,
               const rb_const_iterator<Const_node_ptr, Value> &lhs)
    {
        return rhs.base() != lhs.base();
    }
} // namespace ft

#endif