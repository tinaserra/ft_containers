/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapAccessOperator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:46:20 by vserra            #+#    #+#             */
/*   Updated: 2022/05/05 13:28:22 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// accessing mapped values
#include "tests.hpp"

int		mapAccessOperator(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Operator[]  --- *" << std::endl;
	WOO::map<char,std::string> myMap;

	myMap['a']="an element";
	myMap['b']="another element";
	myMap['c']=myMap['b'];

	outfile << "myMap['a'] is " << myMap['a'] << '\n';
	outfile << "myMap['b'] is " << myMap['b'] << '\n';
	outfile << "myMap['c'] is " << myMap['c'] << '\n';
	outfile << "myMap['d'] is " << myMap['d'] << '\n';

	outfile << "myMap now contains " << myMap.size() << " elements.\n";

	return 0;
}