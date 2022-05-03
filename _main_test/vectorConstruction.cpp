/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorConstruction.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:24:55 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:25:08 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// constructing vectors
#include "tests.hpp"

int		vectorConstructor(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[VECTOR] Constructors\033[0m --- *" << std::endl;
	// constructors used in the same order as described above:
	WOO::vector<int> first;                                // empty vector of ints
	WOO::vector<int> second (4,100);                       // four ints with value 100
	WOO::vector<int> third (second.begin(),second.end());  // iterating through second
	WOO::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	WOO::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	outfile << "The contents of fifth are:";
	for (WOO::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		outfile << ' ' << *it;
	outfile << '\n';

	return 0;
}