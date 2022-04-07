/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:13 by vserra            #+#    #+#             */
/*   Updated: 2022/04/07 20:29:33 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:

		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef size_t											size_type;

		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::difference_type		difference_type;
		typedef typename ft::randomIterator<value_type>			iterator;
		typedef typename ft::randomIterator<const value_type>	const_iterator;
		typedef typename ft::reverseIterator<iterator>			reverse_iterator;
		typedef typename ft::reverseIterator<const_iterator>	const_reverse_iterator;


		/* ------------------------------------------------------------------ */
		/* MEMBER FUNCTIONS                                                   */
		/* ------------------------------------------------------------------ */

		// Default constructor
		explicit vector (const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_size = 0;
			_capacity = 0;
			_start = NULL;
			_end = NULL;
		}

		// Fill constructor
		explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_size = n;
			_capacity = n;
			_start = _alloc.allocate(n);
			_end = _start;

			for (size_t i = 0; i < n; i++)
			{
				_alloc.construct(_end, val);
				_end++;
			}
		}

		// Range constructor
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			_alloc = alloc;
			_size = ft::itDiff(first, last);
			_capacity = _size;
			_start = _alloc.allocate(_capacity);
			_end = _start;

			while (first != last)
			{
				_alloc.construct(_end, *first);
				++first;
				_end++;
			}
		}

		// Copy constructor
		vector (const vector& x)
		{
			size_type n = x.size();
			pointer tmp;

			_start = _alloc.allocate(n);
			_end = _start;
			_size = n;
			_capacity = n;
			tmp = x._start;

			while (0 < n)
			{
				_alloc.construct(_end++, *tmp++);
				n--;
			}
		}

		// Destructor
		virtual ~vector()
		{
			this->clear();
			_alloc.deallocate(_start, _capacity);
		}

		// Assignation operator
		vector &operator=(const vector& rhs)
		{
			if (*this == rhs)
				return *this;
			this->clear();
			this->insert(this->end(), rhs.begin(), rhs.end());
			return *this;
		}


		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		iterator				begin() { return iterator(_start); }

		const_iterator			begin() const { return const_iterator(_start); }

		iterator				end() { return iterator(_end); }

		const_iterator			end() const { return const_iterator(_end); }

		reverse_iterator		rbegin() { return reverse_iterator(_end); }

		const_reverse_iterator	rbegin() const { return const_reverse_iterator(_end); }

		reverse_iterator		rend() { return reverse_iterator(_start); }
		
		const_reverse_iterator	rend() const { return const_reverse_iterator(_start); }


		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		size_type	size() const { return _size; }

		size_type	max_size() const { return _alloc.max_size(); }

		size_type	capacity(void) const { return (_capacity); }

		void		resize(size_type size, value_type val = value_type())
		{
			if (size < _size) // on reduit en supprimant les elements en trop
			{
				while (size < _size)
				{
					_size--;
					_alloc.destroy((_start + _size));
				}
			}
			else // on ajoute des elements
			{
				if (size <= _capacity)
					;
				else if (size <= _size * 2)
					this->reserve(_size * 2);
				else
					this->reserve(size);
				while (_size < size)
				{
					_alloc.construct(_start + _size, val);
					_size++;
				}
			}
			_end = _start + _size;
		}

		bool		empty() const
		{
			if (_size == 0)
				return (true);
			return (false);
		}

		void		reserve(size_type capacity)
		{
			vector		res;
			iterator	it_begin = this->begin();
			iterator	it_end = this->end();

			if (capacity > this->max_size())
				throw std::length_error("Error : [reserve] Alloc size is greater than max_size");
			if (capacity <= this->capacity())
				return ;
			difference_type len = ft::itDiff(it_begin, it_end);
			if (capacity < (size_t)len)
				throw std::bad_alloc();
			res._alloc = _alloc;
			res._size = len;
			res._capacity = capacity;
			res._start = res._alloc.allocate(capacity);
			res._end = res._start + res._size;
			for (size_type i = 0; it_begin != it_end; ++it_begin)
			{
				res._alloc.construct(res._start + i, *it_begin);
				i++;
			}
			if (_start != NULL)
			{
				this->clear();
				_alloc.deallocate(_start, _capacity);
				_start = NULL;
				_size = 0;
				_capacity = 0;
			}
			_alloc = res._alloc;
			_start = res._start;
			_end = res._end;
			_size = res._size;
			_capacity = res._capacity;
			res._start = NULL;
			res._size = 0;
			res._capacity = 0;
		}

		/* ------------------------------------------------------------------ */
		/* ELEMENT ACCESS                                                     */
		/* ------------------------------------------------------------------ */

		reference		operator[] (size_type n) { return (_start[n]); }

		const_reference	operator[] (size_type n) const { return (_start[n]); }

		reference		at (size_type n)
		{
			if (n >= this->size())
			{
				throw std::out_of_range("Error : [at] out of range error");
			}
			return (_start[n]);
		}

		const_reference	at (size_type n) const
		{
			if (n >= this->size())
			{
				throw std::out_of_range("Error : [at] out of range error");
			}
			return (_start[n]);
		}

		reference		front() { return (*(_start)); }

		const_reference	front() const { return (*(_start)); }

		reference		back() { return (*(_end - 1)); }

		const_reference	back() const { return (*(_end - 1)); }


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
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, _capacity);
			}
			_capacity = 0;
			_size = 0;
			if (dist)
			{
				_check_range(dist);
				_start = _alloc.allocate(dist);
				_capacity = dist;
			}
			for (iterator i = begin(); i < begin() + dist; i++)
				this->_alloc.construct(i, *first++);
			this->_size = dist;
		}

		// Assign fill (2)
		void	assign(size_type n, const value_type& val)
		{
			this->_dealloc();
			if (n)
				this->reserve(n);
			for (iterator i = begin(); i < begin() + n; i++)
				this->_alloc.construct(i, val);
			this->_size = n;
		}

		void push_back (const value_type& val)
		{
			if (_size == _capacity)
				this->resize(_size + 1, val);
			else
			{
				_alloc.construct(_start + _size, val);
				_size++;
			}
			_end = _start + _size;
		}

		void pop_back()
		{
			if (this->empty() == false)
			{
				_alloc.destroy(--_end);
				_size--;
			}
		}

		// Insert single element (1)
		iterator insert (iterator position, const value_type& val)
		{
			difference_type			newSize = ft::itDiff(this->begin(), position);

			insert(position, 1, val);
			return iterator(this->begin() + newSize);
		}

		// Insert fill (2)
		void insert (iterator position, size_type n, const value_type& val)
		{
			difference_type			beginToPosition = ft::itDiff(this->begin(), position);
			difference_type			beginToEnd = ft::itDiff(this->begin(), this->end());
			difference_type			newSize = n;
			iterator				previousEnd;
			iterator				end;

			this->resize(this->_size + newSize);

			previousEnd = this->begin() + beginToEnd;
			position = this->begin() + beginToPosition;
			end = this->_start + this->_size;
			this->_end = this->_start + this->_size;
			while (previousEnd != position)
				*(--end) = *(--previousEnd);
			while (0 < n)
			{
				*position++ = val;
				n--;
			}
		}

		// Insert range (3)
		template < class InputIterator >
		void insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type			beginToPosition = ft::itDiff(this->begin(), position);
			difference_type			beginToEnd = ft::itDiff(this->begin(), this->end());
			difference_type			newSize = ft::itDiff(first, last);
			iterator				previousEnd;
			iterator				end;

			this->resize(this->_size + newSize);

			previousEnd = this->begin() + beginToEnd;
			position = this->begin() + beginToPosition;
			end = this->end();
			while (previousEnd != position)
				*(--end) = *(--previousEnd);
			while (first != last)
			{
				*position = *first;
				position++;
				first++;
			}
			this->_end = this->_start + this->_size;
		}

		// Iterator erase (1)
		iterator erase(iterator position)
		{
			return (this->erase(position, position + 1));
		}

		// Range erase (2)
		iterator erase(iterator first, iterator last)
		{
			size_type	rangeToDelete = ft::itDiff(first, last);
			iterator	tmp = first;

			while (last != this->end())
			{
				*first = *last;
				++first;
				++last;
			}
			for (size_type i = 0; i < rangeToDelete; i++)
			{
				this->_alloc.destroy((this->_start + this->_size));
				this->_size--;
				this->_end--;
			}
			return (tmp);
		}

		void swap(vector& x)
		{
			allocator_type	tmpAlloc;
			size_type		tmpSize;
			size_type		tmpCapacity;
			pointer			tmpStart;
			pointer			tmpEnd;

			tmpAlloc = this->_alloc;
			tmpSize = this->_size;
			tmpCapacity = this->_capacity;
			tmpStart = this->_start;
			tmpEnd = this->_end;

			this->_alloc = x._alloc;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_start = x._start;
			this->_end = x._end;

			x._alloc = tmpAlloc;
			x._size = tmpSize;
			x._capacity = tmpCapacity;
			x._start = tmpStart;
			x._end = tmpEnd;
		}

		void clear()
		{
			size_type len = size();

			for (size_type i = 0; i < len; i++)
			{
				_end--;
				_alloc.destroy(_end);
			}
			_size = 0;
		}

		/* ------------------------------------------------------------------ */
		/* ALLOCATOR                                                          */
		/* ------------------------------------------------------------------ */

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

	private:
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		pointer			_start;
		pointer			_end;
};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

// Operator ==
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() == rhs.size())
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	return (false);
}

// Operator !=
// a!=b -> !(a==b)
template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

// Operator <
template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs != rhs)
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	return (false);
}

// Operator <=
// a<=b -> !(b<a)
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(rhs < lhs));
}

// Operator >
// a>b -> b<a
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (rhs < lhs);
}

// Operator >=
// a>=b -> !(a<b)
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
}

// No member Swap overload
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

};

#endif