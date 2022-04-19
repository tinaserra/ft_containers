/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapEmpty.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:36:54 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 11:40:44 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::empty
#include <iostream>
#include <map>
#include "map.hpp"

int		mapEmpty()
{
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}

	return 0;
}