/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:03:17 by vserra            #+#    #+#             */
/*   Updated: 2022/03/25 19:20:18 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> 
	{
		typedef T type;
	};
};

template <typename T>
struct is_iterator
{
	typedef bool value;
	// const value value;
};

template <typename T>
struct res
{
	static const bool value = false;
	// if ()
};

// namespace ft
// {
// 	template<typename T, typename = void>
// 	struct is_iterator
// 	{
// 		static const bool value = false;
// 	};

// 	template<typename T>
// 	struct is_iterator<T, typename ft::enable_if<!std::is_same<typename std::iterator_traits<T>::value_type, void>::value>::type>
// 	{
// 		static const bool value = true;
// 	};
// }

// value est false
// si T => bidirectionel tag
// --------> value est true

#endif