/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapEqualRange.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:39:11 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 11:41:28 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::equal_range
#include <iostream>
#include <map>
#include "map.hpp"

int		mapEqualRange()
{
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	return 0;
}