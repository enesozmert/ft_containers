#ifndef RBTREEFUNCTIONS
#define RBTREEFUNCTIONS

#include "../tree/RBTreeNode.hpp"

template <typename T>
	bool
	tree_is_left_child(typename RBTreeNode<T>::node_ptr node)
	{
		if (node && node->_parent && node->_parent->_left)
			return node == node->_parent->_left;
		else
			return false;
	}

	template <typename T>
	bool
	tree_is_left_child(typename RBTreeNode<T>::const_node_ptr node)
	{
		if (node && node->_parent && node->_parent->_left)
			return node == node->_parent->_left;
		else
			return false;
	}

	template <typename T>
	typename RBTreeNode<T>::node_ptr
	tree_min(typename RBTreeNode<T>::node_ptr root)
	{
		while (root->_left != NULL)
			root = root->_left;
		return root;
	}

	template <typename T>
	typename RBTreeNode<T>::const_node_ptr
	tree_min(typename RBTreeNode<T>::const_node_ptr root)
	{
		while (root->_left != NULL)
			root = root->_left;
		return root;
	}

	template <typename T>
	typename RBTreeNode<T>::node_ptr
	tree_max(typename RBTreeNode<T>::node_ptr root)
	{
		while (root->_right != NULL)
			root = root->_right;
		return root;
	}

	template <typename T>
	typename RBTreeNode<T>::const_node_ptr
	tree_max(typename RBTreeNode<T>::const_node_ptr root)
	{
		while (root->_right != NULL)
			root = root->_right;
		return root;
	}


#endif