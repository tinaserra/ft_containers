/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorClear.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:06:48 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:50:51 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clearing vectors
#include "tests.hpp"

int		vectorClear(std::ofstream &outfile)
{
	WOO::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';

	return 0;
}