/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapSize.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:47:39 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:10:49 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::size
#include "tests.hpp"

int		mapSize(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[MAP] Size\033[0m --- *" << std::endl;
	WOO::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	outfile << "mymap.size() is " << mymap.size() << '\n';

	return 0;
}