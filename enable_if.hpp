/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:03:17 by vserra            #+#    #+#             */
/*   Updated: 2022/03/17 18:25:21 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	if ()
};

// value est false
// si T => bidirectionel tag
// --------> value est true
