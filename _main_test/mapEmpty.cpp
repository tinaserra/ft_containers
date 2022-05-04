/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapEmpty.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:36:54 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::empty
#include "tests.hpp"

int		mapEmpty(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Empty[]  --- *" << std::endl;
	WOO::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		outfile << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}

	return 0;
}