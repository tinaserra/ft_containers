/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapInsert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:41:18 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::insert (C++98)
#include "tests.hpp"

int		mapInsert(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Insert  --- *" << std::endl;
	WOO::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( WOO::pair<char,int>('a',100) );
	mymap.insert ( WOO::pair<char,int>('z',200) );

	WOO::pair<WOO::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( WOO::pair<char,int>('z',500) );
	if (ret.second==false) {
		outfile << "element 'z' already existed";
		outfile << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	WOO::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, WOO::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, WOO::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	WOO::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	outfile << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	outfile << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	return 0;
}