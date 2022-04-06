/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:39:19 by vserra            #+#    #+#             */
/*   Updated: 2022/04/06 16:34:17 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTITERATOR_HPP
#define INPUTITERATOR_HPP

namespace ft {

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type itDiff(
				InputIterator start, InputIterator end)
	{
		typename iterator_traits<InputIterator>::difference_type len = 0;

		while (start != end)
		{
			len++;
			++start;
		}
		return len;
	}

};

#endif