/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapCount.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:36:22 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::count
#include "tests.hpp"

int		mapCount(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Count  --- *" << std::endl;
	outfile << "STL map" << std::endl;
	WOO::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		outfile << c;
		if (mymap.count(c)>0)
			outfile << " is an element of mymap.\n";
		else
			outfile << " is not an element of mymap.\n";
	}
	return 0;
}