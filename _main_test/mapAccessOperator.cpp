/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapAccessOperator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:46:20 by vserra            #+#    #+#             */
/*   Updated: 2022/07/07 14:54:35 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// accessing mapped values
#include "tests.hpp"

int		mapAccessOperator(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Operator[]  --- *" << std::endl;
	WOO::map<char,std::string> myMap;

	myMap['a']="1";
	myMap['b']="2";
	myMap['c']="3";
	myMap['d']="4";
	myMap['e']=myMap['d'];

	outfile << "myMap['a'] is " << myMap['a'] << '\n';
	outfile << "myMap['b'] is " << myMap['b'] << '\n';
	outfile << "myMap['c'] is " << myMap['c'] << '\n';
	outfile << "myMap['d'] is " << myMap['d'] << '\n';
	outfile << "myMap['e'] is " << myMap['e'] << '\n';

	outfile << "myMap now contains " << myMap.size() << " elements.\n";

	return 0;
}