/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapKeyComp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:41:55 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 11:26:48 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::key_comp
#include <iostream>
#include <map>
#include "map.hpp"

int		mapKeyComp()
{
	std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	return 0;
}