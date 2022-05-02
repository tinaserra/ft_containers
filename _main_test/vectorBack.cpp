/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorBack2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:04:10 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:47:52 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::back
#include "tests.hpp"

int		vectorBack(std::ofstream &outfile)
{
	WOO::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';

	return 0;
}