/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:24:13 by vserra            #+#    #+#             */
/*   Updated: 2022/04/07 19:52:40 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

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

		iterator_type base() const { return (current); }

		pointer operator->() const { return (&(operator*())); }

		reference operator*() const
		{
			Iterator tmp = current;
			return *(--tmp);
		}

		reverseIterator operator+		(difference_type n) const
		{
			return reverseIterator(current - n);
		}

		reverseIterator operator-		(difference_type n) const
		{
			return reverseIterator(current + n);
		}

		reverseIterator& operator++() // pre-incrementation
		{
			--current;
			return *this;
		}

		reverseIterator operator++		(int) // post-incrementation
		{
			reverseIterator tmp = (*this);
			--current;
			// ++(*this);
			return tmp;
		}

		reverseIterator& operator--()
		{
			++current;
			return *this;
		}

		reverseIterator operator--		(int)
		{
			reverseIterator tmp = (*this);
			++current;
			// --(*this);
			return tmp;
		}

		reverseIterator& operator+=		(difference_type n)
		{
			current -= n;
			return *this;
		}

		reverseIterator& operator-=		(difference_type n)
		{
			current += n;
			return *this;
		}

		reference operator[]			(difference_type n) const
		{
			return *(*this + n);
		}
};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

template <typename InputIterator>
bool operator==	(const reverseIterator<InputIterator>& lhs,
					const reverseIterator<InputIterator>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename InputIterator>
bool operator!=	(const reverseIterator<InputIterator>& lhs,
					const reverseIterator<InputIterator>& rhs)
{
	return (!(lhs == rhs));
}

template <typename InputIterator>
bool operator<	(const reverseIterator<InputIterator>& lhs,
					const reverseIterator<InputIterator>& rhs)
{
	return (rhs.base() < lhs.base());
}

template <typename InputIterator>
bool operator<=	(const reverseIterator<InputIterator>& lhs,
					const reverseIterator<InputIterator>& rhs)
{
	return (!(rhs < lhs));
}

template <typename InputIterator>
bool operator>	(const reverseIterator<InputIterator>& lhs,
					const reverseIterator<InputIterator>& rhs)
{
	return (rhs < lhs);
}

template <typename InputIterator>
bool operator>=	(const reverseIterator<InputIterator>& lhs,
					const reverseIterator<InputIterator>& rhs)
{
	return (!(lhs < rhs));
}

template <typename InputIterator>
typename reverseIterator<InputIterator>::difference_type operator- (
		const reverseIterator<InputIterator>& lhs,
		const reverseIterator<InputIterator>& rhs)
{
	return (rhs.base() - lhs.base());
}

template <typename Iterator>
reverseIterator<Iterator> operator+ (
			typename reverseIterator<Iterator>::difference_type n,
			const reverseIterator<Iterator>& rev_it)
{
	return (reverseIterator<Iterator>(rev_it.base() - n));
}

// template<typename InputIteratorL, typename InputIteratorR>
// bool	operator==(const reverseIterator<InputIteratorL>& lhs,
//					const reverseIterator<InputIteratorR>& rhs) {
// 	return (lhs.base() == rhs.base());
// }

// template<typename InputIteratorL, typename InputIteratorR>
// bool	operator<(const reverseIterator<InputIteratorL>& lhs,
//					const reverseIterator<InputIteratorR>& rhs) {
// 	return (rhs.base() < lhs.base());
// }

// template<typename InputIteratorL, typename InputIteratorR>
// bool	operator!=(const reverseIterator<InputIteratorL>& lhs,
//					const reverseIterator<InputIteratorR>& rhs) {
// 	return (!(lhs == rhs));
// }

// template<typename InputIteratorL, typename InputIteratorR>
// bool	operator>(const reverseIterator<InputIteratorL>& lhs,
//					const reverseIterator<InputIteratorR>& rhs) {
// 	return (rhs < lhs);
// }

// template<typename InputIteratorL, typename InputIteratorR>
// bool	operator<=(const reverseIterator<InputIteratorL>& lhs,
//					const reverseIterator<InputIteratorR>& rhs) {
// 	return (!(rhs < lhs));
// }

// template<typename InputIteratorL, typename InputIteratorR>
// bool	operator>=(const reverseIterator<InputIteratorL>& lhs,
//					const reverseIterator<InputIteratorR>& rhs) {
// 	return (!(lhs < rhs));
// }

// template<typename InputIteratorL, typename InputIteratorR>
// typename reverseIterator<InputIteratorL>::difference_type operator- (
//		const reverseIterator<InputIteratorL>& lhs,
// 		const reverseIterator<InputIteratorR>& rhs) {
// 	return (rhs.base() - lhs.base());
// }

};

#endif