#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "../tree/RBTreeNode.hpp"
#include "../functions/RBTreeFunctions.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	template <typename Node_ptr, typename Value>
	class rb_iterator
	{
		/*
		 * Member types :
		 */
	public:
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef Value value_type;
		typedef Value *pointer;
		typedef Value &reference;
		typedef const Value *const_pointer;
        typedef const Value &const_reference;
		/*
		 * Member variables :
		 */
	private:
		Node_ptr _node;

		/*
		 * Member functions :
		 */
	public:
		rb_iterator() : _node() {}

		rb_iterator(const rb_iterator &it) : _node(it._node) {}

		rb_iterator(const Node_ptr &val) : _node(val) {}

		rb_iterator &operator=(const rb_iterator &it)
		{
			if (this != &it)
				_node = it._node;
			return *this;
		}

		rb_iterator &operator=(const Node_ptr &p)
		{
			_node = p;
			return *this;
		}

		reference operator*() const { return _node->_data; }
		pointer operator->() const { return &_node->_data; }

		rb_iterator &operator++()
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

		rb_iterator operator++(int)
		{
			rb_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		rb_iterator &operator--()
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

		rb_iterator operator--(int)
		{
			rb_iterator tmp(*this);
			--(*this);
			return tmp;
		}

		Node_ptr base() const
		{
			return _node;
		}
	};

	template <typename Node_ptr, typename Value>
	inline bool
	operator==(const rb_iterator<Node_ptr, Value> &rhs, const rb_iterator<Node_ptr, Value> &lhs)
	{
		return rhs.base() == lhs.base();
	}

	template <typename Node_ptr, typename Value>
	inline bool
	operator!=(const rb_iterator<Node_ptr, Value> &rhs, const rb_iterator<Node_ptr, Value> &lhs)
	{
		return rhs.base() != lhs.base();
	}
}
#endif