/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapSize.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:47:39 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::size
#include "tests.hpp"

int		mapSize(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Size  --- *" << std::endl;
	WOO::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	outfile << "mymap.size() is " << mymap.size() << '\n';

	return 0;
}