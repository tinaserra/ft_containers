/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:23:39 by vserra            #+#    #+#             */
/*   Updated: 2022/04/06 17:45:12 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

namespace ft {

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		ft::pair<T1, T2>	retPair(x, y);

		return (retPair);
	}
};

#endif