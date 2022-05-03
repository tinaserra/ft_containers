/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorErase.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:10:27 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:25:35 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// erasing from vector
#include "tests.hpp"

int		vectorErase(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[VECTOR] Erase\033[0m --- *" << std::endl;
	WOO::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		outfile << ' ' << myvector[i];
	outfile << '\n';

	return 0;
}