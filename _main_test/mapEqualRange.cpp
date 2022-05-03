/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapEqualRange.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:39:11 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:03:40 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::equal_range
#include "tests.hpp"

int		mapEqualRange(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Equal_range\033[0m --- *" << std::endl;
	WOO::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	WOO::pair<WOO::map<char,int>::iterator,WOO::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	outfile << "lower bound points to: ";
	outfile << ret.first->first << " => " << ret.first->second << '\n';

	outfile << "upper bound points to: ";
	outfile << ret.second->first << " => " << ret.second->second << '\n';

	return 0;
}