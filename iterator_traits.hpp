/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:22:31 by vserra            #+#    #+#             */
/*   Updated: 2022/03/25 21:52:38 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERARTOR_TRAITS_HPP
# define ITERARTOR_TRAITS_HPP

// input <- forward <- bidirectional <- random
// output

// iterator traits
/*
member				generic definition				T* specialization			const T* specialization
difference_type		Iterator::difference_type		ptrdiff_t					ptrdiff_t
value_type			Iterator::value_type			T							T
pointer				Iterator::pointer				T*							const T*
reference			Iterator::reference				T&							const T&
iterator_category	Iterator::iterator_category		random_access_iterator_tag	random_access_iterator_tag
*/

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// template <class Category,              // iterator::iterator_category
    //       class T,                         // iterator::value_type
    //       class Distance = ptrdiff_t,      // iterator::difference_type
    //       class Pointer = T*,              // iterator::pointer
    //       class Reference = T&             // iterator::reference
    //       > class iterator;

	template	<typename _Category,
				typename _Tp,
				typename _Distance = std::ptrdiff_t,
				typename _Pointer = _Tp*,
				typename _Reference = _Tp&>

	struct iterator
	{
		typedef _Category	iterator_category;
		typedef _Tp			value_type;
		typedef _Distance	difference_type; // l'ecart entre deux poineurs
		typedef _Pointer	pointer;
		typedef _Reference	reference;
	};

	// Generic definition
	template<typename _Iterator>
	struct iterator_traits
	{
		typedef typename _Iterator::value_type			value_type;
		typedef typename _Iterator::difference_type		difference_type;
		typedef typename _Iterator::pointer				pointer;
		typedef typename _Iterator::reference			reference;
	};

	// T* specialization
	template<typename Tp>
	struct iterator_traits<Tp*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Tp*							pointer;
		typedef Tp&							reference;
	};

	// const T* specialization
	template<typename Tp>
	struct iterator_traits<const Tp*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef const Tp*					pointer;
		typedef const Tp&					reference;
	};
};

#endif