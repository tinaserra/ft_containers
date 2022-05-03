/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapValueComp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:48:43 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:11:23 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::value_comp
#include "tests.hpp"

int		mapValueComp(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Value Comp\033[0m --- *" << std::endl;
	WOO::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	outfile << "mymap contains:\n";

	WOO::pair<char,int> highest = *mymap.rbegin();          // last element

	WOO::map<char,int>::iterator it = mymap.begin();
	do {
		outfile << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );

	return 0;
}