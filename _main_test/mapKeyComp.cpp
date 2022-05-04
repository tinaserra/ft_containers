/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapKeyComp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:41:55 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::key_comp
#include "tests.hpp"
int		mapKeyComp(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Key_comp  --- *" << std::endl;
	WOO::map<char,int> mymap;

	WOO::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	outfile << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	WOO::map<char,int>::iterator it = mymap.begin();
	do {
		outfile << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	outfile << '\n';

	return 0;
}