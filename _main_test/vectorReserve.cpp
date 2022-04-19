/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorReserve.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:16:10 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:53:35 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::reserve
#include <iostream>
#include <vector>
#include "vector.hpp"

int		vectorReserve()
{
	std::cout << std::endl << "* \033[1m[VECTOR] Reserve\033[0m ------------------------------- *" << std::endl;
	std::vector<int>::size_type sz;
	ft::vector<int>::size_type ft_sz;

	std::vector<int> STLvector;
	ft::vector<int> pute;

	sz = STLvector.capacity();
	std::cout << "making STLvector grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		STLvector.push_back(i);
		if (sz!=STLvector.capacity())
		{
			sz = STLvector.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft_sz = pute.capacity();
	std::cout << "making pute grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		pute.push_back(i);
		if (ft_sz != pute.capacity())
		{
			ft_sz = pute.capacity();
			std::cout << "capacity changed: " << ft_sz << '\n';
		}
	}

	// std::vector<int> bar;
	// sz = bar.capacity();
	// bar.reserve(100);   // this is the only difference with STLvector above
	// std::cout << "making bar grow:\n";
	// for (int i=0; i<100; ++i)
	// {
	// 	bar.push_back(i);
	// 	if (sz!=bar.capacity())
	// 	{
	// 		sz = bar.capacity();
	// 		std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }
	return 0;
}