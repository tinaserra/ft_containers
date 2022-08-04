/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:24:13 by vserra            #+#    #+#             */
/*   Updated: 2022/08/04 13:02:28 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft {

template < typename Iterator >
class reverseIterator: public iterator< typename iterator_traits<Iterator>::value_type,
										typename iterator_traits<Iterator>::difference_type,
										typename iterator_traits<Iterator>::pointer,
										typename iterator_traits<Iterator>::reference >
{
	protected:
		Iterator											current;
		typedef iterator_traits<Iterator>					traits_type;

	public:
		typedef Iterator									iterator_type;
		typedef typename traits_type::difference_type		difference_type;
		typedef typename traits_type::pointer				pointer;
		typedef typename traits_type::reference				reference;
		typedef typename traits_type::value_type			value_type;

		/* ------------------------------------------------------------------ */
		/* CONSTRUCTORS & DESTRUCTORS                                         */
		/* ------------------------------------------------------------------ */

		//default
		reverseIterator() : current() {}

		//initialization : on construit un itérateur inverse à partir d'un itérateur normal
		explicit reverseIterator(iterator_type it) : current(it) {}

		//copy : Construit un itérateur inverse à partir d'un autre itérateur inverse
		reverseIterator(reverseIterator const & rev_it) : current(rev_it.current) {}

		//copy form InputIterator : on construit un itérateur inverse à partir d'un autre itérateur inverse
		template<typename InputIterator> //template <class Iter>
		reverseIterator(reverseIterator<InputIterator> const & rev_it) : current(rev_it.base()) {}


		/* ------------------------------------------------------------------ */
		/* MEMBER FUNCTIONS                                                   */
		/* ------------------------------------------------------------------ */

		iterator_type		base() const { return (current); }

		pointer				operator->() const { return (&(operator*())); }

		reference			operator*() const
		{
			Iterator tmp = current;
			return (*(--tmp));
		}

		reverseIterator		operator+(difference_type n) const
		{
			return reverseIterator(current - n);
		}

		reverseIterator		operator-(difference_type n) const
		{
			return reverseIterator(current + n);
		}

		// pre-incrementation
		reverseIterator&	operator++()
		{
			--current;
			return *this;
		}

		 // post-incrementation
		reverseIterator		operator++(int)
		{
			reverseIterator tmp = (*this);
			--current;
			// ++(*this);
			return tmp;
		}

		reverseIterator&	operator--()
		{
			++current;
			return *this;
		}

		reverseIterator		operator--(int)
		{
			reverseIterator tmp = (*this);
			++current;
			// --(*this);
			return tmp;
		}

		reverseIterator&	operator+=(difference_type n)
		{
			current -= n;
			return *this;
		}

		reverseIterator&	operator-=(difference_type n)
		{
			current += n;
			return *this;
		}

		reference			operator[](difference_type n) const
		{
			return *(*this + n);
		}
};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

template <class InputIterator1, class InputIterator2>
bool	operator==(const reverseIterator<InputIterator1>& lhs,
					const reverseIterator<InputIterator2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class InputIterator1, class InputIterator2>
bool	operator!=(const reverseIterator<InputIterator1>& lhs,
					const reverseIterator<InputIterator2>& rhs)
{
	return (!(lhs == rhs));
}

template <class InputIterator1, class InputIterator2>
bool	operator<(const reverseIterator<InputIterator1>& lhs,
					const reverseIterator<InputIterator2>& rhs)
{
	return (rhs.base() < lhs.base());
}

template <class InputIterator1, class InputIterator2>
bool	operator<=(const reverseIterator<InputIterator1>& lhs,
					const reverseIterator<InputIterator2>& rhs)
{
	return (!(rhs < lhs));
}

template <class InputIterator1, class InputIterator2>
bool	operator>(const reverseIterator<InputIterator1>& lhs,
					const reverseIterator<InputIterator2>& rhs)
{
	return (rhs < lhs);
}

template <class InputIterator1, class InputIterator2>
bool	operator>=(const reverseIterator<InputIterator1>& lhs,
					const reverseIterator<InputIterator2>& rhs)
{
	return (!(lhs < rhs));
}

template <class InputIterator1, class InputIterator2>
typename reverseIterator<InputIterator1>::difference_type	operator-(
		const reverseIterator<InputIterator1>& lhs,
		const reverseIterator<InputIterator2>& rhs)
{
	return (rhs.base() - lhs.base());
}

template <class Iterator>
reverseIterator<Iterator>	operator+(
			typename reverseIterator<Iterator>::difference_type n,
			const reverseIterator<Iterator>& rev_it)
{
	return (reverseIterator<Iterator>(rev_it.base() - n));
}

};

#endif