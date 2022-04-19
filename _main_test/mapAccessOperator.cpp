/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmapAccessOperator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:46:20 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:46:58 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// accessing mapped values
#include <iostream>
#include <map>
#include <string>
#include "map.hpp"

int		mapAccessOperator()
{
	std::cout << std::endl << "* \033[1m[MAP] Operator[]\033[0m -----------------------*" << std::endl;
	std::map<char,std::string> STLmap;

	STLmap['a']="an element";
	STLmap['b']="another element";
	STLmap['c']=STLmap['b'];

	std::cout << "STLmap['a'] is " << STLmap['a'] << '\n';
	std::cout << "STLmap['b'] is " << STLmap['b'] << '\n';
	std::cout << "STLmap['c'] is " << STLmap['c'] << '\n';
	std::cout << "STLmap['d'] is " << STLmap['d'] << '\n';

	std::cout << "STLmap now contains " << STLmap.size() << " elements.\n";

	ft::map<char,std::string> FTmap;

	FTmap['a']="an element";
	FTmap['b']="another element";
	FTmap['c']=FTmap['b'];

	std::cout << "FTmap['a'] is " << FTmap['a'] << '\n';
	std::cout << "FTmap['b'] is " << FTmap['b'] << '\n';
	std::cout << "FTmap['c'] is " << FTmap['c'] << '\n';
	std::cout << "FTmap['d'] is " << FTmap['d'] << '\n';

	std::cout << "FTmap now contains " << FTmap.size() << " elements.\n";

	return 0;
}