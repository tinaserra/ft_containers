/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:23:57 by vserra            #+#    #+#             */
/*   Updated: 2022/04/06 17:49:36 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template<class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	first_type first;
	second_type second;

	/* ---------------------------------------------------------------------- */
	/* CONSTRUCTORS                                                           */
	/* ---------------------------------------------------------------------- */

	// Default constructor
	pair() : first(), second() {}

	// Copy constructor
	template<class U, class V>
	pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

	// Initialization constructor
	pair (const first_type& a, const second_type& b) : first(a), second(b) {}

	/* ---------------------------------------------------------------    --- */
	/* MEMBER FUNCTIONS                                                       */
	/* ---------------------------------------------------------------------- */

	pair&	operator= (const pair& pr)
	{
		if (this == &pr)
			return (*this);
		this->first = pr.first;
		this->second = pr.second;
		return (*this);
	}

};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(lhs == rhs));
}

template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(lhs < rhs));
}

};

#endif