/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorSwap2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:15:00 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:53:49 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// swap vectors
#include "tests.hpp"

int		vectorSwap(std::ofstream &outfile)
{
	WOO::vector<int> foo (3,100);   // three ints with a value of 100
	WOO::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	outfile << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		outfile << ' ' << foo[i];
	outfile << '\n';

	outfile << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		outfile << ' ' << bar[i];
	outfile << '\n';

	return 0;
}