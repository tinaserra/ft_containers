/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorPushBack.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:13:55 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:27:50 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::push_back
#include "tests.hpp"

int		vectorPushBack(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[VECTOR] Push_back\033[0m --- *" << std::endl;
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