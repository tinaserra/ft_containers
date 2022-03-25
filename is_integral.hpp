/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:38:07 by vserra            #+#    #+#             */
/*   Updated: 2022/03/25 19:20:49 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template < class T, T v >
	struct integral_fundamental
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_fundamental<T, v> type;
		operator T() {
			return (v);
		}
	};

	// Set true_type with true value at compile time.
	typedef integral_fundamental<bool, true>	true_type;

	// Set true_type with false value at compile time.
	typedef integral_fundamental<bool, false>	false_type;

	template < class T > struct is_integral : public false_type {};

	// fundamental integral types

	template <>
	struct is_integral<char> : public true_type {};

	template <>
	struct is_integral<wchar_t> : public true_type {};

	template <>
	struct is_integral<signed char> : public true_type {};

	template <>
	struct is_integral<short int> : public true_type {};
	
	template <>
	struct is_integral<int> : public true_type {};

	template <>
	struct is_integral<long int> : public true_type {};

	template <>
	struct is_integral<long long int> : public true_type {};

	template <>
	struct is_integral<unsigned char> : public true_type {};

	template <>
	struct is_integral<unsigned short int> : public true_type {};

	template <>
	struct is_integral<unsigned int> : public true_type {};

	template <>
	struct is_integral<unsigned long int> : public true_type {};
	
	template <>
	struct is_integral<unsigned long long> : public true_type {};

	// template <>
	// struct is_integral<char16_t> : public true_type {};

	// template <>
	// struct is_integral<char32_t> : public true_type {};
};

#endif