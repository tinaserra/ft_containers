/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapFind.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:40:12 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 11:25:50 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::find
#include "tests.hpp"

int		mapFind(std::ofstream &outfile)
{
	WOO::map<char,int> mymap;
	WOO::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
	  mymap.erase (it);

	// print content:
	outfile << "elements in mymap:" << '\n';
	outfile << "a => " << mymap.find('a')->second << '\n';
	outfile << "c => " << mymap.find('c')->second << '\n';
	outfile << "d => " << mymap.find('d')->second << '\n';

	return 0;
}