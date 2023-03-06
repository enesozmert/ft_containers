#ifndef STACK_HPP
#define STACK_HPP

#include <stddef.h>
#include <memory>
#include <iostream>
#include <string>
#include "./vector.hpp"
#include "../exception/stack_exception.hpp"
#include "../common/type_traits/type_traits.hpp"

class stackException;
namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef typename container_type::reference reference;
		typedef typename container_type::value_type value_type;
		typedef typename container_type::const_reference const_reference;
		typedef typename container_type::size_type size_type;
		//  container_type	Container
		//  value_type	Container::value_type
		//  size_type	Container::size_type
		//  reference	Container::reference
		//  const_reference	Container::const_reference
	protected:
		container_type _c;

	public:
		explicit stack(const container_type &c_type = container_type()) : c(c_type) {}
		stack(const stack &other) : _c(other._c) {}
	public:
		stack &operator=(const stack &other)
		{
			_c = other._c;
			return (*this);
		}

		bool empty() const
		{
			return (_c.empty());
		}

		size_type size() const
		{
			return (_c.size());
		}

		value_type &top()
		{
			return (_c.back());
		}

		const value_type &top() const
		{
			return (_c.back());
		}

		void push(const value_type &val)
		{
			_c.push_back(val);
		}

		void pop()
		{
			_c.pop_back();
		}

	public:
		template <class A, class Cont>
		friend bool operator==(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs)
		{
			return (lhs._c == rhs._c);
		}
		template <class A, class Cont>
		friend bool operator!=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs)
		{
			return (lhs._c != rhs._c);
		}
		template <class A, class Cont>
		friend bool operator<(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs)
		{
			return (lhs._c < rhs._c);
		}
		template <class A, class Cont>
		friend bool operator<=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs)
		{
			return (lhs._c <= rhs._c);
		}
		template <class A, class Cont>
		friend bool operator>(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs)
		{
			return (lhs._c > rhs._c);
		}
		template <class A, class Cont>
		friend bool operator>=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs)
		{
			return (lhs._c >= rhs._c);
		}
	};
}
#endif
