/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapClear.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:35:42 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:02:43 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::clear
#include "tests.hpp"

int		mapClear(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Clear\033[0m --- *" << std::endl;
	
	WOO::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	outfile << "mymap contains:\n";
	for (WOO::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	outfile << "mymap contains:\n";
	for (WOO::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	return 0;
}