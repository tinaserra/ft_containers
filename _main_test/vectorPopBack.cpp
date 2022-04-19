/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorPopBack2.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:13:15 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:52:47 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::pop_back
#include <iostream>
#include <vector>
#include "vector.hpp"

int		vectorPopBack()
{
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';

	return 0;
}