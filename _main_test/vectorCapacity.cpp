/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorCapacity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:04:56 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:50:48 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// comparing size, capacity and max_size
#include <iostream>
#include <vector>
#include "vector.hpp"

int		vectorCapacitySizeMaxSize()
{
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	return 0;
}