/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:24:13 by vserra            #+#    #+#             */
/*   Updated: 2022/03/29 21:22:22 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft {

template < typename Iterator >
class reverseIterator: public iterator< typename iterator_traits<Iterator>::value_type,
										typename iterator_traits<Iterator>::difference_type,
										typename iterator_traits<Iterator>::pointer,
										typename iterator_traits<Iterator>::reference >
{
	private:
		Iterator	current;
		typedef iterator_traits<Iterator>	traits_type;

	public:
		typedef Iterator									iterator_type;
		typedef typename traits_type::difference_type		difference_type;
		typedef typename traits_type::pointer				pointer;
		typedef typename traits_type::reference				reference;

		/* ------------------------------------------------------------------ */
		/* CONSTRUCTORS & DESTRUCTORS                                         */
		/* ------------------------------------------------------------------ */

		//default
		reverseIterator() : current() {}

		//initialization
		explicit reverseIterator(iterator_type it) : current(it) {}

		//copy
		reverseIterator(reverseIterator const & it) : current(it.current) {}

		//copy form InputIterator
		template<typename InputIterator> //template <class Iter>
		reverseIterator(reverseIterator<InputIterator> const & it) : current(it.base()) {}

		/* ------------------------------------------------------------------ */
		/* MEMBER FUNCTIONS                                                   */
		/* ------------------------------------------------------------------ */

		iterator_type		base() const { return (current); }

		pointer				operator->() const { return (&(operator*())); }

		reverseIterator		operator+(difference_type n) const
		{
			return (reverseIterator(current - n));
		}

		reverseIterator		operator-(difference_type n) const
		{
			return reverseIterator(current + n);
		}

		reverseIterator&	operator++()
		{
			--current;
			return (*this);
		}

		reverseIterator		operator++(int)
		{
			reverseIterator tmp = (*this);

			--current;
			return (tmp);
		}

		reverseIterator&	operator--()
		{
			++current;
			return (*this);
		}

		reverseIterator		operator--(int)
		{
			reverseIterator tmp = (*this);

			++current;
			return (tmp);
		}

		reference			operator*() const
		{
			Iterator tmp = current;
			return (*(--tmp));
		}

		reverseIterator&	operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reverseIterator&	operator-=(difference_type n)
		{
			current += n;
			return (*this);
		}

		reference			operator[](difference_type n) const
		{
			return (*(*this + n));
		}
};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

};

#endif