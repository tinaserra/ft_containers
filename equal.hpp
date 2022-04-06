/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:59 by vserra            #+#    #+#             */
/*   Updated: 2022/04/06 17:44:29 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft {

	template <class InputIterator1, class InputIterator2>
	bool equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*(first1) == *(first2)))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

};

#endif