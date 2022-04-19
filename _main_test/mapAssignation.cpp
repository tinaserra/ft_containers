/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapAssignation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:45:36 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:47:38 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// assignment operator with maps
#include <iostream>
#include <map>
#include "map.hpp"

int		mapAssignation()
{
	std::cout << std::endl << "* \033[1m[MAP] Operator=\033[0m ------------------------*" << std::endl;
	std::map<char,int> first;
	std::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=std::map<char,int>();  // and first is now empty

	std::cout << "STL: Size of first: " << first.size() << '\n';
	std::cout << "STL: Size of second: " << second.size() << '\n';

	/* ---------------------------------------------------------------------- */

	ft::map<char,int> first;
	ft::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=ft::map<char,int>();  // and first is now empty

	std::cout << "FT: Size of first: " << first.size() << '\n';
	std::cout << "FT: Size of second: " << second.size() << '\n';
	return 0;
}