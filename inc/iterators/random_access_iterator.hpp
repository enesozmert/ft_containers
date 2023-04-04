#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator
	{
	public:
		typedef typename iterator_traits<T>::value_type value_type;
		typedef typename iterator_traits<T>::difference_type difference_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::reference reference;
		typedef typename iterator_traits<T>::const_reference const_reference;
		typedef typename iterator_traits<T>::const_pointer const_pointer;

		random_access_iterator() : _ptr(NULL) {}
		random_access_iterator(T ptr) : _ptr(ptr) {}
		template <class Itererator>
		explicit random_access_iterator(const random_access_iterator<Itererator> &other) : _ptr(other.base()) {}
		random_access_iterator &operator=(const random_access_iterator &other)
		{
			_ptr = other._ptr;
			return *this;
		}

		// operator const_iterator() const {return const_iterator(_ptr);}
		reference operator*() { return *this->_ptr; }
		const_reference operator*() const { return *this->_ptr; }
		pointer operator->() { return _ptr; }
		const_pointer operator->() const { return _ptr; }

		random_access_iterator &operator++()
		{
			++_ptr;
			return *this;
		}
		random_access_iterator operator++(int)
		{
			random_access_iterator temp(*this);
			++_ptr;
			return temp;
		}
		random_access_iterator &operator--()
		{
			--_ptr;
			return *this;
		}
		random_access_iterator operator--(int)
		{
			random_access_iterator temp(*this);
			--_ptr;
			return temp;
		}

		random_access_iterator operator+(difference_type n) const { return random_access_iterator(_ptr + n); }
		random_access_iterator operator-(difference_type n) const { return random_access_iterator(_ptr - n); }
		random_access_iterator &operator+=(difference_type n)
		{
			_ptr += n;
			return *this;
		}
		random_access_iterator &operator-=(difference_type n)
		{
			_ptr -= n;
			return *this;
		}

		reference operator[](difference_type n) { return *(_ptr + n); }
		const_reference operator[](difference_type n) const { return *(_ptr + n); }

		bool operator==(const random_access_iterator &rhs) const { return _ptr == rhs._ptr; }
		bool operator!=(const random_access_iterator &rhs) const { return _ptr != rhs._ptr; }
		bool operator<(const random_access_iterator &rhs) const { return _ptr < rhs._ptr; }
		bool operator<=(const random_access_iterator &rhs) const { return _ptr <= rhs._ptr; }
		bool operator>(const random_access_iterator &rhs) const { return _ptr > rhs._ptr; }
		bool operator>=(const random_access_iterator &rhs) const { return _ptr >= rhs._ptr; }

		int operator+(const random_access_iterator &right_hand_side)
		{
			return (this->_ptr + right_hand_side._ptr);
		}
		int operator-(const random_access_iterator &right_hand_side)
		{
			return (this->_ptr - right_hand_side._ptr);
		}

		pointer base() const { return _ptr; }

	private:
		T _ptr;
	};

	template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &x) { return x + n; }

	template <typename T>
	random_access_iterator<T> operator-(typename random_acceszs_iterator<T>::difference_type n, const random_access_iterator<T> &x) { return x - n; }

} // namespace ft

#endif

/*
base() işlemi, bir iterator'un temel halini (base) döndürür.
Bu temel hal, bir arka uç (past-the-end) işaretçisiyle birleştirilebilir ve
çoğu durumda bir aralığın başlangıcını belirlemek için kullanılabilir.

Örneğin, bir reverse_iterator tipindeki bir iterator,
standart bir iteratorun tam tersine işaret eder.
base() işlemi, reverse_iterator'ın işaret ettiği standart iteratorunun
temel halini döndürür.
Böylece, base() işlemi, reverse_iterator'ı bir aralığın sonundan başlayarak
öğeleri gezinmek için kullanırken başlangıç noktasını belirlemek için
kullanılabilir.
*/