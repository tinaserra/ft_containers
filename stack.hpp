/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:07 by vserra            #+#    #+#             */
/*   Updated: 2022/04/12 15:25:37 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template < class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t			size_type;

		/* ------------------------------------------------------------------ */
		/* MEMBER FUNCTIONS                                                   */
		/* ------------------------------------------------------------------ */

		explicit stack(container_type const &ctnr = container_type()) : _ctnr(ctnr) {}

		/* ------------------------------------------------------------------ */
		/* MEMBER FUNCTIONS                                                   */
		/* ------------------------------------------------------------------ */

		bool				empty() const { return _ctnr.empty(); }

		size_type			size() const { return _ctnr.size(); }

		value_type			&top() { return _ctnr.back(); }

		const value_type	&top() const { return _ctnr.back(); }

		void				push(value_type const &val) { _ctnr.push_back(val); }

		void				pop() { _ctnr.pop_back(); }


		template <typename _T, typename _Container>
		friend bool			ft::operator==(stack<_T, _Container> const &lhs, stack<_T, _Container> const &rhs);

		template <typename _T, typename _Container>
		friend bool			ft::operator<(stack<_T, _Container> const &lhs, stack<_T, _Container> const &rhs);

	/* ---------------------------------------------------------------------- */
	/* PROTECTED MEMBERS                                                      */
	/* ---------------------------------------------------------------------- */

	protected:
		container_type		_ctnr;

};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

template <typename T, typename Container>
bool	operator==(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
	return (lhs._ctnr == rhs._ctnr);
}

template <typename T, typename Container>
bool	operator!=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
	return (!(lhs == rhs));
}

template <typename T, typename Container>
bool	operator<(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
	return (lhs._ctnr < rhs._ctnr);
}

template <typename T, typename Container>
bool	operator<=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
	return (!(rhs < lhs));
}

template <typename T, typename Container>
bool	operator>(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
	return (rhs < lhs);
}

template <typename T, typename Container>
bool	operator>=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
	return (!(lhs < rhs));
}

};

#endif