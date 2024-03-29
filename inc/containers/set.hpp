#ifndef SET_HPP
#define SET_HPP

#include "../tree/RBTree.hpp"

namespace ft
{

	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class set
	{
	private: // types
		typedef ft::RBTree<T, Compare, Alloc> tree_type;

	public: // types
		typedef T key_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename tree_type::value_type value_type;
		typedef typename tree_type::value_compare value_compare;
		typedef typename tree_type::reference reference;
		typedef typename tree_type::const_reference const_reference;
		typedef typename tree_type::pointer pointer;
		typedef typename tree_type::const_pointer const_pointer;
		typedef typename tree_type::size_type size_type;
		typedef typename tree_type::difference_type difference_type;
		typedef typename tree_type::const_iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef typename tree_type::const_reverse_iterator reverse_iterator;
		typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

	private: // attributes
		tree_type _tree;
	
	public: // methods
		// constructors / destructor

		explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _tree(comp, alloc) {}
		template <typename InputIterator>
		set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) : _tree(comp, alloc)
		{
			this->insert(first, last);
		}
		set(const set &other) : _tree(other._tree) {}
		~set() {}

		// operator overload

		set &operator=(const set &other)
		{
			if (this != &other)
				this->_tree = other._tree;
			return *this;
		}

		// iterators

		iterator begin() { return this->_tree.begin(); }
		const_iterator begin() const { return this->_tree.begin(); }
		iterator end() { return this->_tree.end(); }
		const_iterator end() const { return this->_tree.end(); }
		reverse_iterator rbegin() { return this->_tree.rbegin(); }
		const_reverse_iterator rbegin() const { return this->_tree.rbegin(); }
		reverse_iterator rend() { return this->_tree.rend(); }
		const_reverse_iterator rend() const { return this->_tree.rend(); }

		// capacity

		bool empty() const { return this->_tree.empty(); }
		size_type size() const { return this->_tree.size(); }
		size_type max_size() const { return this->_tree.max_size(); }

		// modifiers

		ft::pair<iterator, bool> insert(const value_type &val)
		{ return this->_tree.insert(val); }
		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return this->_tree.insert(val).first;
		}
		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{ this->_tree.insert(first, last); }
		void erase(iterator position)
		{ this->_tree.erase(*position); }
		size_type erase(const value_type &val)
		{ return this->_tree.erase(val); }
		void erase(iterator first, iterator last)
		{
			while (first != last)
				this->_tree.erase(*(first++));
		}
		void swap(set &other) { this->_tree.swap(other._tree); }
		void clear() { this->_tree.clear(); }

		// observers

		key_compare key_comp() const { return key_compare(); }
		value_compare value_comp() const { return this->_tree.value_comp(); }

		// operations

		iterator find(const value_type &val) const { return this->_tree.find(val); }
		size_type count(const value_type &val) const { return this->_tree.count(val); }
		iterator lower_bound(const value_type &val) const { return this->_tree.lower_bound(val); }
		iterator upper_bound(const value_type &val) const { return this->_tree.upper_bound(val); }
		ft::pair<iterator, iterator> equal_range(const value_type &val) const { return this->_tree.equal_range(val); }

		// allocator

		allocator_type get_allocator() const { return this->_tree.get_allocator(); }

	};

	// external operator overloads

	template <typename T, typename Compare, typename Alloc>
	inline bool
	operator==(const set<T, Compare, Alloc> &lhs,
			   const set<T, Compare, Alloc> &rhs)
	{
		return lhs.size() == rhs.size() &&
			   ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool
	operator!=(const set<T, Compare, Alloc> &lhs,
			   const set<T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool
	operator<(const set<T, Compare, Alloc> &lhs,
			  const set<T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool
	operator>(const set<T, Compare, Alloc> &lhs,
			  const set<T, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool
	operator<=(const set<T, Compare, Alloc> &lhs,
			   const set<T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool
	operator>=(const set<T, Compare, Alloc> &lhs,
			   const set<T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T, typename Compare, typename Alloc>
	void
	swap(set<T, Compare, Alloc> &x, set<T, Compare, Alloc> &y)
	{
		x.swap(y);
	}

}

#endif
