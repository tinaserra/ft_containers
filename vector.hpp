/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:13 by vserra            #+#    #+#             */
/*   Updated: 2022/03/29 20:03:55 by vserra           ###   ########.fr       */
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