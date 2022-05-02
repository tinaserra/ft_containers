/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorPushBack8.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:13:55 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 13:01:09 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::push_back
#include "tests.hpp"

int		vectorPushBack(std::ofstream &outfile)
{
	WOO::vector<int> myvector;
	int myint;

	outfile << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		myvector.push_back (myint);
	} while (myint);

	outfile << "myvector stores " << int(myvector.size()) << " numbers.\n";

	return 0;
}