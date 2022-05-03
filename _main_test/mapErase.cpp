/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapErase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:39:41 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:04:33 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// erasing from map
#include "tests.hpp"

int		mapErase()
{
	outfile << std::endl << "* \033[1m[MAP] Erase\033[0m --- *" << std::endl;
	WOO::map<char,int> mymap;
	WOO::map<char,int>::iterator it;

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
		outfile << it->first << " => " << it->second << '\n';

	return 0;
}