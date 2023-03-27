#ifndef RB_ITERATOR
#define RB_ITERATOR

#include "../tree/RBTreeNode.hpp"

namespace ft
{
	template <typename NodePtr, typename Value>
	class rb_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef RBTreeNode<value_type> node_type;
		typedef node_type *node_ptr;

	private:
		NodePtr _node;

	public:
		rb_iterator() : _node() {}

		rb_iterator(const rb_iterator &it) : _node(it._node) {}

		rb_iterator(const NodePtr &val) : _node(val) {}

		rb_iterator &operator=(const rb_iterator &it)
		{
			if (this != &it)
				_node = it._node;
			return *this;
		}

		rb_iterator &operator=(const NodePtr &p)
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

		NodePtr base() const
		{
			return _node;
		}
	};

	template <typename NodePtr, typename Value>
	inline bool
	operator==(const rb_iterator<NodePtr, Value> &rhs, const rb_iterator<NodePtr, Value> &lhs)
	{
		return rhs.base() == lhs.base();
	}

	template <typename NodePtr, typename Value>
	inline bool
	operator!=(const rb_iterator<NodePtr, Value> &rhs, const rb_iterator<NodePtr, Value> &lhs)
	{
		return rhs.base() != lhs.base();
	}
}
#endif