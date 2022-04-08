/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:29 by vserra            #+#    #+#             */
/*   Updated: 2022/04/08 18:50:10 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aLaSalope.hpp"

// resizing vector
#include <iostream>
#include <vector>

int		vectorResize()
{
	std::cout << std::endl << "* Resize tests --------------------------- *" << std::endl;
	
	std::vector<int> STLvector;
	ft::vector<int> pute;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		STLvector.push_back(i);
	
	for (int i = 1; i < 10; i++)
		pute.push_back(i);

	STLvector.resize(5);
	STLvector.resize(8,100);
	STLvector.resize(12);

	pute.resize(5);
	pute.resize(8,100);
		std::cout << pute.capacity() << std::endl;
	pute.resize(12);

	std::cout << "STLvector contains:" << std::endl;
	for (unsigned long i = 0; i < STLvector.size(); i++)
		std::cout << ' ' << STLvector[i];
	std::cout << '\n';

	std::cout << "pute contains:" << std::endl;
	std::cout << pute.capacity() << std::endl;
	for (unsigned long i = 0; i < pute.size(); i++)
		std::cout << ' ' << pute[i];
	std::cout << '\n';

	return 0;
}