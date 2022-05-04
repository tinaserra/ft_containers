/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapMaxSize.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:44:52 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::max_size
#include "tests.hpp"

int		mapMaxSize(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Max_size  --- *" << std::endl;
	int i;
	WOO::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		outfile << "The map contains 1000 elements.\n";
	}
	else outfile << "The map could not hold 1000 elements.\n";

	return 0;
}