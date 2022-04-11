/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:38:07 by vserra            #+#    #+#             */
/*   Updated: 2022/04/11 11:28:17 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

	template <class T, T v>
	struct integral_constant
	{
		static const T	value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator T() { return v; }
	};

	typedef integral_constant<bool, true>	true_type;

	typedef integral_constant<bool, false>	false_type;

	template <class T>
	struct is_integral : public false_type {};

	template <>
	struct is_integral<bool> : public true_type {};

	template <>
	struct is_integral<char> : public true_type {};

	template <>
	struct is_integral<signed char> : public true_type {};

	template <>
	struct is_integral<unsigned char> : public true_type {};

	template <>
	struct is_integral<wchar_t> : public true_type {};

	template <>
	struct is_integral<short> : public true_type {};

	template <>
	struct is_integral<unsigned short> : public true_type {};

	template <>
	struct is_integral<int> : public true_type {};

	template <>
	struct is_integral<unsigned int> : public true_type {};

	template <>
	struct is_integral<long> : public true_type {};

	template <>
	struct is_integral<long long> : public true_type {};

	template <>
	struct is_integral<unsigned long> : public true_type {};

	template <>
	struct is_integral<unsigned long long> : public true_type {};

};

#endif