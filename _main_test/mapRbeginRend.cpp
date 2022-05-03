/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapRbeginRend.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:47:10 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:10:31 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::rbegin/rend
#include "tests.hpp"

int		mapRbeginRend(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Rbegin Rend\033[0m --- *" << std::endl;
	WOO::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	WOO::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		outfile << rit->first << " => " << rit->second << '\n';

	return 0;
}