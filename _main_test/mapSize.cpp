/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapSize2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:47:39 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:48:43 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::size
#include "tests.hpp"

int		mapSize(std::ofstream &outfile)
{
	WOO::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	outfile << "mymap.size() is " << mymap.size() << '\n';

	return 0;
}