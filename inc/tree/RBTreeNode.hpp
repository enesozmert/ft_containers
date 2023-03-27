#ifndef RBTREENODE
#define RBTREENODE

#include <iostream>
#include <stddef.h>
#include <memory>

namespace ft
{
	enum Color
	{
		RED,
		BLACK
	};

	/* Red-Black Tree Node */

	template <typename T>
	class RBTreeNode
	{
		/*
		 * Member types :
		 */
	public:
		typedef T data_type;
		typedef Color color_type;
		typedef RBTreeNode<data_type> *node_ptr;
		typedef const RBTreeNode<data_type> *const_node_ptr;

		/*
		 * Member variables :
		 */
		data_type _data;
		color_type _color;
		node_ptr _parent;
		node_ptr _left;
		node_ptr _right;

		/*
		 * Member functions :
		 */
		RBTreeNode() : _data(), _color(BLACK), _parent(), _left(), _right() {}

		RBTreeNode(const RBTreeNode &n)
			: _data(n._data), _color(n._color), _parent(n._parent), _left(n._left), _right(n._right) {}

		virtual ~RBTreeNode() {}

		RBTreeNode &operator=(const RBTreeNode &n)
		{
			if (this != &n)
			{
				_data = n._data;
				_color = n._color;
				_parent = n._parent;
				_left = n._left;
				_right = n._right;
			}
			return *this;
		}

		void flip_color()
		{
			this->_color = _color == RED ? BLACK : RED;
		}
	};
}

#endif