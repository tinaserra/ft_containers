/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorReserve.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:16:10 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::reserve
#include "tests.hpp"

int		vectorReserve(std::ofstream &outfile)
{
	outfile << std::endl << "* [VECTOR] Reserve  --- *" << std::endl;
	WOO::vector<int>::size_type sz;

	WOO::vector<int> foo;
	sz = foo.capacity();
	outfile << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
		sz = foo.capacity();
		outfile << "capacity changed: " << sz << '\n';
		}
	}

	WOO::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	outfile << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
		sz = bar.capacity();
		outfile << "capacity changed: " << sz << '\n';
		}
	}

	return 0;
}