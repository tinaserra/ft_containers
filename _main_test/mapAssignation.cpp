/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapAssignation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:45:36 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:02:53 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// assignment operator with maps
#include "tests.hpp"

int		mapAssignation(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Operator=\033[0m --- *" << std::endl;
	WOO::map<char,int> first;
	WOO::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=WOO::map<char,int>();  // and first is now empty

	outfile << "STL: Size of first: " << first.size() << '\n';
	outfile << "STL: Size of second: " << second.size() << '\n';

	return 0;
}