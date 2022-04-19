/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapBeginEnd.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:37:19 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:07:02 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::begin/end
#include <iostream>
#include <map>
#include "map.hpp"

int		mapBeginEnd()
{
	std::cout << std::endl << "* \033[1m[MAP] Begin End\033[0m ------------------------*" << std::endl;
	std::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	std::cout << "STL map" << std::endl;
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	/* ---------------------------------------------------------------------- */

	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	std::cout << "FT map" << std::endl;
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}