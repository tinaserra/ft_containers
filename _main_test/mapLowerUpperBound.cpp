/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapLowerUpperBound.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:44:14 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:09:47 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::lower_bound/upper_bound
#include "tests.hpp"

int		mapLowerUpperBound(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Lower Upper bound\033[0m --- *" << std::endl;
	WOO::map<char,int> mymap;
	WOO::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (WOO::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	return 0;
}