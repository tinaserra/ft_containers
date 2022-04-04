/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:39:19 by vserra            #+#    #+#             */
/*   Updated: 2022/04/04 09:00:29 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTITERATOR_HPP
#define INPUTITERATOR_HPP

namespace ft {

	template<class inputIterator>
	typename iterator_traits<inputIterator>::difference_type itDiff(
				inputIterator start, inputIterator end)
	{
		typename iterator_traits<inputIterator>::difference_type len = 0;

		while (start != end)
		{
			len++;
			++start;
		}
		return len;
	}

};

#endif