/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAssign.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:00:36 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int		vectorAssign(std::ofstream &outfile)
{
	outfile << std::endl << "* [VECTOR] Assign  --- *" << std::endl;
	WOO::vector<int> first;
	WOO::vector<int> second;
	WOO::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	outfile << "first" << std::endl;
	for (unsigned int i = 0; i < first.size(); i++)
	{
		outfile << first[i] << " ";
	}
	outfile << std::endl;

	WOO::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	outfile << "second" << std::endl;
	for (unsigned int i = 0; i < second.size(); i++)
	{
		outfile << second[i] << " ";
	}
	outfile << std::endl;
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	outfile << "third" << std::endl;
	for (unsigned int i = 0; i < third.size(); i++)
	{
		outfile << third[i] << " ";
	}
	outfile << std::endl;
	outfile << "vector:" << std::endl;
	outfile << "Size of first: " << int (first.size()) << '\n';
	outfile << "Size of second: " << int (second.size()) << '\n';
	outfile << "Size of third: " << int (third.size()) << '\n';
	return 0;
}