/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapErase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:39:41 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 11:42:02 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// erasing from map
#include <iostream>
#include <map>
#include "map.hpp"

int		mapErase()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}