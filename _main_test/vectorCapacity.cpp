/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorCapacity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:04:56 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:24:20 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// comparing size, capacity and max_size
#include "tests.hpp"

int		vectorCapacitySizeMaxSize(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[VECTOR] Capacity Size Max_size\033[0m --- *" << std::endl;
	WOO::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	outfile << "size: " << (int) myvector.size() << '\n';
	outfile << "capacity: " << (int) myvector.capacity() << '\n';
	outfile << "max_size: " << (int) myvector.max_size() << '\n';
	return 0;
}