/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapBeginEnd.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:37:19 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:02:48 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::begin/end
#include "tests.hpp"

int		mapBeginEnd(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Begin End\033[0m --- *" << std::endl;
	WOO::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (WOO::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	return 0;
}