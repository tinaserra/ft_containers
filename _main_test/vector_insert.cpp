/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:28:59 by vserra            #+#    #+#             */
/*   Updated: 2022/04/08 20:41:06 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inserting into a vector
#include <iostream>
#include <vector>
#include "aLaSalope.hpp"

int		vectorInsert()
{
	std::cout << std::endl << "* Insert tests -------------------------- *" << std::endl;
	std::vector<int> STLvector (3,100);
	std::vector<int>::iterator it;

	ft::vector<int> pute (3,100);
	ft::vector<int>::iterator itPute;

	it = STLvector.begin();
	it = STLvector.insert ( it , 200 );

	itPute = pute.begin();
	itPute = pute.insert ( itPute , 200 );

	STLvector.insert (it,2,300);
	pute.insert (itPute,2,300);

	// "it" no longer valid, get a new one:
	it = STLvector.begin();
	itPute = pute.begin();

	std::vector<int> anothervector (2,400);
	STLvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	STLvector.insert (STLvector.begin(), myarray, myarray+3);

	std::cout << "STLvector contains:";
	for (it=STLvector.begin(); it<STLvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}