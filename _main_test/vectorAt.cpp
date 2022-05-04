/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:02:56 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::at
#include "tests.hpp"

int		vectorAt(std::ofstream &outfile)
{
	outfile << std::endl << "* [VECTOR] At  --- *" << std::endl;
	WOO::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
	myvector.at(i)=i;

	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	outfile << ' ' << myvector.at(i);
	outfile << '\n';

	return 0;
}