/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapRbeginRend2.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:47:10 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:48:55 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::rbegin/rend
#include <iostream>
#include <map>
#include "map.hpp"

int		mapRbeginRend()
{
	std::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

	return 0;
}