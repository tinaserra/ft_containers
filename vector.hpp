/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:13 by vserra            #+#    #+#             */
/*   Updated: 2022/04/11 12:57:50 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream> // asuppr
# include <cstddef>
# include "ReverseIterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:

		typedef T												value_type;
		typedef Alloc											allocator_type;

		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef T*												iterator;
		typedef const T*										const_iterator;
		typedef typename ft::reverseIterator<iterator>			reverse_iterator;
		typedef typename ft::reverseIterator<const_iterator>	const_reverse_iterator;
		typedef size_t											size_type;
		typedef ptrdiff_t										difference_type;

		/* ------------------------------------------------------------------ */
		/* MEMBER FUNCTIONS                                                   */
		/* ------------------------------------------------------------------ */

		// Default constructor
		explicit vector (const allocator_type& alloc = allocator_type())
		{
			this->_alloc = alloc;
			this->_size = 0;
			this->_capacity = 0;
			this->_start = NULL;
		}

		// Fill constructor	
		explicit vector(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = NULL;
			_check_range(n);
			if (n)
			{
				_start = _alloc.allocate(n);
				_capacity = n;
			}
			else
				_capacity = 0;
			_size = n;

			iterator	pos = _start;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(pos++, val);
		}


		// Range constructor
		template < class InputIterator >
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			_alloc = alloc;
			difference_type dist = std::distance(first, last);
			this->_size = static_cast<size_type>(dist);
			this->_capacity = static_cast<size_type>(dist);
			if (dist)
			{
				_check_range(_capacity);
				_start = _alloc.allocate(_capacity);
				std::uninitialized_copy(first, last, this->_start);
			}
		}

		// Copy constructor
		vector(const vector& x)
		{
			_start = NULL;
			_size = x._size;
			_capacity = x._capacity;
			if (x._capacity)
				_start = _alloc.allocate(_capacity);
			if (x._capacity)
				std::uninitialized_copy(x._start, x._start + x._size, _start);
		}

		// Destructor
		virtual ~vector()
		{
			this->clear();
			if (this->_capacity)
				this->_alloc.deallocate(this->_start, this->_capacity);
		}

		// Assignation operator
		vector	&operator=(const vector& rhs)
		{
			if (*this != rhs)
			{
				this->_dealloc();
				if (rhs.empty())
					return (*this);
				this->_size = rhs.size();
				this->_capacity = rhs.capacity();
				_check_range(rhs.capacity());
				_start = _alloc.allocate(rhs.capacity());
				std::uninitialized_copy(rhs.begin(), rhs.end(), this->_start);
			}
			return (*this);
		}

		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		iterator				begin() { return iterator(this->_start); }

		const_iterator			begin() const { return const_iterator(this->_start); }

		iterator				end() { return iterator(this->_start + this->_size); }

		const_iterator			end() const { return const_iterator(this->_start + this->_size); }

		reverse_iterator		rbegin() { return reverse_iterator(this->end()); }

		const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->end()); }

		reverse_iterator		rend() { return reverse_iterator(this->begin()); }
		
		const_reverse_iterator	rend() const { return const_reverse_iterator(this->begin()); }


		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		size_type	size() const { return this->_size; }

		size_type	max_size() const { return this->_alloc.max_size(); }

		size_type	capacity(void) const { return (this->_capacity); }

		// void	resize(size_type size, value_type val = value_type())
		// {
		// 	this->_check_range(size);
		// 	if (size == this->_size)
		// 		return ;
		// 	if (size == 0)
		// 		return (clear());
		// 	if (size < this->_size)
		// 	{
		// 		// erase(begin() + size, end());
		// 		iterator it = end();
		// 		size_type diff = this->_size - size;
		// 		while (diff--)
		// 		{
		// 			this->_alloc.destroy(&it);
		// 			this->_size--;
		// 		}
		// 		return ;
		// 	}
		// 	if (size > this->_size)
		// 	{
		// 		// insert(end(), size - this->_size, val);
		// 		// this->_realloc_fill(size, val);
		// 		if (size <= this->_capacity)
		// 				;
		// 		if (this->_capacity < size)
		// 		{
		// 			// if (size <= this->_size * 2)
		// 			// 	this->reserve(this->_size * 2);
		// 			// else
		// 				this->reserve(size);
		// 		}
		// 		while (this->_size < size)
		// 		{
		// 			this->_alloc.construct(this->_start + this->_size, val);
		// 			this->_size++;
		// 		}
		// 	}
		// }

		void	resize(size_type n, value_type val = value_type())
		{
			this->_check_range(n);
			if (n == this->_size)
				return ;
			if (n == 0)
				return (clear());
			if (n < this->_size)
			{
				iterator it = end();
				size_type diff = this->_size - n;
				while (diff--)
				{
					this->_alloc.destroy(--it);
					this->_size--;
				}
				return ;
			}
			if (n > this->_size)
			{
				// this->_realloc_fill(n, val);
				iterator	tmp = this->_alloc.allocate(n);
				size_type	prevSize = _size;
				std::uninitialized_copy(_start, _start + _size, tmp);
				_dealloc();
				_start = tmp;
				std::uninitialized_fill(_start + prevSize, _start + n, val);
				_size = n;
				_capacity = n;
			}
		}

		bool		empty() const
		{
			if (this->_size == 0)
				return (true);
			return (false);
		}

		// void		reserve(size_type n)
		// {
		// 	vector		res;
		// 	iterator	it_begin = this->begin();
		// 	iterator	it_end = this->end();

		// 	if (n > this->max_size())
		// 		throw std::out_of_range("Error: vector: [reserve] out of range");
		// 	if (n <= this->capacity())
		// 		return ;
		// 	difference_type len = ft::itDiff(it_begin, it_end);
		// 	if (n < (size_t)len)
		// 		throw std::bad_alloc();
		// 	res._alloc = this->_alloc;
		// 	res._size = len;
		// 	res._capacity = this->_capacity;
		// 	if (this->_capacity== 0)
		// 		res._capacity = 1;
		// 	while (res._capacity < n)
		// 		res._capacity *= 2;
		// 	res._start = res._alloc.allocate(res._capacity);
		// 	res._end = res._start + res._size;
		// 	for (size_type i = 0; it_begin != it_end; ++it_begin)
		// 	{
		// 		res._alloc.construct(res._start + i, *it_begin);
		// 		i++;
		// 	}
		// 	if (this->_start != NULL)
		// 	{
		// 		this->clear();
		// 		this->_alloc.deallocate(this->_start, _capacity);
		// 		this->_start = NULL;
		// 		this->_size = 0;
		// 		this->_capacity = 0;
		// 	}
		// 	this->_alloc = res._alloc;
		// 	this->_start = res._start;
		// 	this->_size = res._size;
		// 	this->_capacity = res._capacity;
		// 	res._start = NULL;
		// 	res._size = 0;
		// 	res._capacity = 0;
		// }

		void	reserve(size_type n)
		{
			if (this->_capacity > n)
				return ;
			if (n > max_size())
				throw std::out_of_range("vector::reserve");

			// if (this->_capacity== 0)
			// 	this->_capacity = 1;
			// while (this->_capacity < n)
			// 	this->_capacity *= 2;
			else
				this->_realloc(n);
		}

		void	_dealloc()
		{
			if (this->_capacity)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, _capacity);
			}
			_capacity = 0;
			_size = 0;
		}

		void	_realloc(size_type n)
		{
			size_type	prevSize = this->_size;
			iterator	tmp = _alloc.allocate(n);
			std::uninitialized_copy(_start, _start + _size, tmp);
			_dealloc();
			_size = prevSize;
			_start = tmp;
			_capacity = n;
		}

		/* ------------------------------------------------------------------ */
		/* ELEMENT ACCESS                                                     */
		/* ------------------------------------------------------------------ */

		reference		operator[] (size_type n) { return (this->_start[n]); }

		const_reference	operator[] (size_type n) const { return (this->_start[n]); }

		reference		at (size_type n)
		{
			if (n >= this->size())
			{
				throw std::out_of_range("Error : [at] out of range error");
			}
			return (this->_start[n]);
		}

		const_reference	at (size_type n) const
		{
			if (n >= this->size())
			{
				throw std::out_of_range("Error : [at] out of range error");
			}
			return (this->_start[n]);
		}

		reference		front() { return (*begin()); }

		const_reference	front() const { return (*begin()); }

		reference		back() { return (*(end() - 1)); }

		const_reference	back() const { return (*(end() - 1)); }


		/* ------------------------------------------------------------------ */
		/* MODIFIERS                                                          */
		/* ------------------------------------------------------------------ */

		// Assign range (1)
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type dist = std::distance(first, last);
			if (this->_capacity)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_start + i);
				this->_alloc.deallocate(this->_start, _capacity);
			}
			this->_capacity = 0;
			this->_size = 0;
			if (dist)
			{
				_check_range(dist);
				this->_start = this->_alloc.allocate(dist);
				this->_capacity = dist;
			}
			for (iterator i = begin(); i < begin() + dist; i++)
				this->_alloc.construct(i, *first++);
			this->_size = dist;
		}

		// Assign fill (2)
		void	assign(size_type n, const value_type& val)
		{
			if (this->_capacity)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_start + i);
				this->_alloc.deallocate(this->_start, _capacity);
			}
			this->_capacity = 0;
			this->_size = 0;
			if (n)
				this->reserve(n);
			for (iterator i = begin(); i < begin() + n; i++)
				this->_alloc.construct(i, val);
			this->_size = n;
		}

		// void push_back (const value_type& val)
		// {
		// 	if (this->_size == this->_capacity)
		// 		this->resize(this->_size + 1, val);
		// 	else
		// 	{
		// 		this->_alloc.construct(this->_start + this->_size, val);
		// 	// std::cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOO " << std::endl;
		// 		this->_size++;
		// 	}
		// 	this->_end = this->_start + this->_size;
		// }

		void	push_back(const value_type& val)
		{
			this->_insert_back(val);
			this->_size++;
		}

		void	_insert_back(value_type const & val)
		{
			if (_capacity == 0)
			{
				_start = _alloc.allocate(1);
				_alloc.construct(_start, val);
				_capacity = 1;
				return ;
			}
			if (_size + 1 <= this->_capacity)
			{
				_alloc.construct(_start + _size, val);
				return ;
			}
			size_type	newSize;
			size_type	prevSize = _size;
			_check_range(_size + 1);
			if (_size * 2 < _alloc.max_size())
				newSize = _size * 2;
			else
				newSize = _size + 1;
			iterator	tmp;
			tmp = _alloc.allocate(newSize);
			std::uninitialized_copy(_start, _start + _size, tmp);
			_alloc.construct(tmp + prevSize, val);    
			_dealloc();
			_capacity = newSize;
			_start = tmp;
			_size = prevSize;
		}

		void	pop_back()
		{
			if (this->empty() == false)
			{
				this->_alloc.destroy(end() - 1);
				this->_size--;
			}
		}

		// Insert single element (1)
		iterator	insert(iterator position, const value_type& val)
		{
			difference_type			newSize = std::distance(this->begin(), position);

			insert(position, 1, val);
			return (this->begin() + newSize);
		}

		// Insert fill (2)
		void	insert(iterator position, size_type n, const value_type& val)
		{
			difference_type			beginToPos = std::distance(this->begin(), position);
			difference_type			prevSize = this->_size;
			iterator				prevEnd;
			iterator				end;

			this->resize(this->_size + n);
			// if (_capacity < _size + newSize)
			// 	this->reserve(this->_size + newSize);

			prevEnd = this->begin() + prevSize;
			position = this->begin() + beginToPos;
			end = this->_start + this->_size;
			while (prevEnd != position)
			{
					*(--end) = *(--prevEnd);
			}
			while (n > 0)
			{
				*position++ = val;
				n--;
			}
		}

		// Insert range (3)
		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type			beginToPos = std::distance(this->begin(), position);
			difference_type			prevSize = this->_size;
			difference_type			newSize = std::distance(first, last);
			iterator				prevEnd;
			iterator				end;

			this->resize(this->_size + newSize);

			prevEnd = this->begin() + prevSize;
			position = this->begin() + beginToPos;
			end = this->end();
			while (prevEnd != position)
			{
				*(--end) = *(--prevEnd);
			}
			while (first != last)
			{
				*position = *first;
				position++;
				first++;
			}
		}

		// Iterator erase (1)
		iterator	erase(iterator position)
		{
			if (position == end())
				return position;
			return (this->erase(position, position + 1));
		}

		// Range erase (2)
		iterator	erase(iterator first, iterator last)
		{
			if (first == last)
				return (first);
			if (last == end())
			{
				for (iterator i = first; i != last; i++)
				{
					this->_alloc.destroy(i);
					this->_size--;
				}
				return (first);
			}
			iterator it = first;
			difference_type size = std::distance(first, last);
			while (it != last)
			{
				this->_alloc.destroy(it);
				it++;
			}
			it = first;
			while (it + size != end())
			{
				this->_alloc.construct(it, *(it + size));
				this->_alloc.destroy(it + size);
				it++;
			}
			this->_size -= static_cast<size_type>(size);
			return (first);
		}

		void	swap(vector& x)
		{
			std::swap(this->_alloc, x._alloc);
			std::swap(this->_start, x._start);
			std::swap(this->_size, x._size);
			std::swap(this->_capacity, x._capacity);
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				this->_alloc.destroy(_start + i);
			this->_size = 0;
		}

		/* ------------------------------------------------------------------ */
		/* ALLOCATOR                                                          */
		/* ------------------------------------------------------------------ */

		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

	private:
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		pointer			_start;

		void	_check_range(size_type n)
		{
			if (n > this->_alloc.max_size())
				throw std::out_of_range("Error: vector: out of range");
		}
};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

// Operator ==
template <class T, class Alloc>
bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() == rhs.size())
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	return (false);
}

// Operator !=
// a!=b -> !(a==b)
template <class T, class Alloc>
bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

// Operator <
template <class T, class Alloc>
bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs != rhs)
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	return (false);
}

// Operator <=
// a<=b -> !(b<a)
template <class T, class Alloc>
bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(rhs < lhs));
}

// Operator >
// a>b -> b<a
template <class T, class Alloc>
bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (rhs < lhs);
}

// Operator >=
// a>=b -> !(a<b)
template <class T, class Alloc>
bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
}

// No member Swap overload
template <class T, class Alloc>
void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

};

#endif