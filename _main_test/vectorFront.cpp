/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorFront.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:11:08 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:52:15 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::front
#include <iostream>
#include <vector>
#include "vector.hpp"

int		vectorFront()
{
	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';

	return 0;
}