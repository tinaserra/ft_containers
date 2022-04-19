/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAssign.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:00:36 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:50:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

int		vectorAssign()
{
	std::cout << std::endl << "* \033[1m[VECTOR] Assign\033[0m ------------------------------- *" << std::endl;
	std::vector<int> STLfirst;
	std::vector<int> STLsecond;
	std::vector<int> STLthird;

	STLfirst.assign (7,100);             // 7 ints with a value of 100

	std::cout << "STLfirst" << std::endl;
	for (unsigned int i = 0; i < STLfirst.size(); i++)
	{
		std::cout << STLfirst[i] << " ";
	}
	std::cout << std::endl;

	std::vector<int>::iterator it;
	it=STLfirst.begin()+1;

	STLsecond.assign (it,STLfirst.end()-1); // the 5 central values of STLfirst

	std::cout << "STLsecond" << std::endl;
	for (unsigned int i = 0; i < STLsecond.size(); i++)
	{
		std::cout << STLsecond[i] << " ";
	}
	std::cout << std::endl;
	int myints[] = {1776,7,4};
	STLthird.assign (myints,myints+3);   // assigning from array.

	std::cout << "STLthird" << std::endl;
	for (unsigned int i = 0; i < STLthird.size(); i++)
	{
		std::cout << STLthird[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "STL vector:" << std::endl;
	std::cout << "Size of STLfirst: " << int (STLfirst.size()) << '\n';
	std::cout << "Size of STLsecond: " << int (STLsecond.size()) << '\n';
	std::cout << "Size of STLthird: " << int (STLthird.size()) << '\n';

	/* ---------------------------------------------------------------------- */

	ft::vector<int> myfirst;
	ft::vector<int> mysecond;
	ft::vector<int> mythird;

	myfirst.assign (7,100);             // 7 ints with a value of 100

	std::cout << "myfirst" << std::endl;
	for (unsigned int i = 0; i < myfirst.size(); i++)
	{
		std::cout << myfirst[i] << " ";
	}
	std::cout << std::endl;

	ft::vector<int>::iterator myit;
	myit=myfirst.begin()+1;

	mysecond.assign (myit,myfirst.end()-1); // the 5 central values of myfirst

	std::cout << "mysecond" << std::endl;
	for (unsigned int i = 0; i < mysecond.size(); i++)
	{
		std::cout << mysecond[i] << " ";
	}
	std::cout << std::endl;
	int myints[] = {1776,7,4};
	mythird.assign (myints,myints+3);   // assigning from array.

	std::cout << "mythird" << std::endl;
	for (unsigned int i = 0; i < mythird.size(); i++)
	{
		std::cout << mythird[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "My vector:" << std::endl;
	std::cout << "Size of myfirst: " << int (myfirst.size()) << '\n';
	std::cout << "Size of mysecond: " << int (mysecond.size()) << '\n';
	std::cout << "Size of mythird: " << int (mythird.size()) << '\n';
	return 0;
}