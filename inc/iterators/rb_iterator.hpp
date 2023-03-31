#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "../tree/RBTreeNode.hpp"
#include "../functions/RBTreeFunctions.hpp"

namespace ft
{
	template <typename T, typename Value>
	class rb_iterator
	{
	public:
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::value_type value_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::reference reference;
		typedef typename iterator_traits<T>::iterator_category iterator_category;
		typedef RBTreeNode<value_type> nodeType;
		typedef nodeType *node_ptr;

	private:
		value_type _node;

	public:
		rb_iterator() : _node() {}

		rb_iterator(const rb_iterator &it) : _node(it._node) {}

		rb_iterator(const value_type &val) : _node(val) {}

		rb_iterator &operator=(const rb_iterator &it)
		{
			if (this != &it)
				_node = it._node;
			return *this;
		}

		rb_iterator &operator=(const value_type &p)
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

		value_type base() const
		{
			return _node;
		}
	};

	template <typename value_type, typename Value>
	inline bool
	operator==(const rb_iterator<value_type, Value> &rhs, const rb_iterator<value_type, Value> &lhs)
	{
		return rhs.base() == lhs.base();
	}

	template <typename value_type, typename Value>
	inline bool
	operator!=(const rb_iterator<value_type, Value> &rhs, const rb_iterator<value_type, Value> &lhs)
	{
		return rhs.base() != lhs.base();
	}
}
#endif