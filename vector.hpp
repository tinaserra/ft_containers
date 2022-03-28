/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:13 by vserra            #+#    #+#             */
/*   Updated: 2022/03/28 17:42:01 by vserra           ###   ########.fr       */
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

		// Operator=
		vector &operator=(const vector& rhs)
		{
			if (*this == rhs)
				return (*this);
			this->clear();
			this->insert(this->end(), rhs.begin(), rhs.end());
			return (*this);
		}
		
		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		/* ------------------------------------------------------------------ */
		/* ELEMENT ACCESS                                                     */
		/* ------------------------------------------------------------------ */

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