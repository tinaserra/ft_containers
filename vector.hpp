/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:13 by vserra            #+#    #+#             */
/*   Updated: 2022/04/05 19:45:32 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	private:

		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		pointer			_start;
		pointer			_end;

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
		template <class inputIterator>
		vector (inputIterator first, inputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<inputIterator>::value, inputIterator>::type* = NULL)
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

		const_reverse_iterator	rbegin() { return const_reverse_iterator(_end); }

		reverse_iterator		rend() { return reverse_iterator(_start); }
		
		const_reverse_iterator	rend() { return const_reverse_iterator(_start); }


		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		size_type	size() const { return _size; }

		size_type	max_size() const { return _alloc.max_size(); }

		size_type	capacity(void) const { return (_capacity); }

		void		resize (size_type size, value_type val = value_type())
		{
			if (size < _size)
			{
				while (size < _size)
				{
					_size--;
					_alloc.destroy((_start + _size));
				}
			}
			else
			{
				if (size <= _capacity)
					;
				else if (size <= _size * 2)
					this->reserve(_size * 2);
				else
					this->reserve(size);
				while (_size < size) {

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

		void		reserve (size_type capacity)
		{
			vector		res;
			iterator	itBegin = this->begin();
			iterator	itEnd = this->end();

			if (capacity > this->max_size())
				throw std::length_error("Error : Alloc size is greater than max_size");
			if (capacity <= this->capacity())
				return ;
			difference_type len = ft::itDiff(itBegin, itEnd);
			if (capacity < (size_t)len)
				throw std::bad_alloc();
			res._alloc = _alloc;
			res._size = len;
			res._capacity = capacity;
			res._start = res._alloc.allocate(capacity);
			res._end = res._start + res._size;
			for (size_type i = 0; itBegin != itEnd; ++itBegin)
			{
				res._alloc.construct(res._start + i, *itBegin);
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

		reference		at (size_type n) {

			if (n >= this->size()) {

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
		void assign (InputIterator first, InputIterator last)
		{
			this->clear();
			difference_type n = ft::itDiff(first, last);
			this->reserve(n); // Demande que la capacité vectorielle soit au moins suffisante pour contenir n éléments
			while (first != last)
			{
				_alloc.construct(_start + _size, *first);
				++first;
				_size++;
			}
			_end = _start + _size;
		}

		// Assign fill (2)
		void assign (size_type n, const value_type& val)
		{
			this->clear();
			this->reserve(n);
			while (n != 0)
			{
				_alloc.construct(_start + _size, val);
				_size++;
				n--;
			}
			_end = _start + _size;
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

};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

};

#endif