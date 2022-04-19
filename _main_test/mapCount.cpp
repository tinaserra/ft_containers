/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapCount.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:36:22 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:11:23 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::count
#include <iostream>
#include <map>
#include "map.hpp"

int		mapCount()
{
	std::cout << std::endl << "* \033[1m[MAP] Count\033[0m ------------------------*" << std::endl;
	std::cout << "STL map" << std::endl;
	std::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}

	std::cout << "FT map" << std::endl;

	ft::map<char,int> ftMap;
	char w;

	ftMap ['a']=101;
	ftMap ['c']=202;
	ftMap ['f']=303;

	for (w='a'; w<'h'; w++)
	{
		std::cout << w;
		if (ftMap.count(w)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}
	return 0;
}