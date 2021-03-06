/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorRbeginRend.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:14:26 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::rbegin/rend
#include "tests.hpp"

int		vectorRbeginRend(std::ofstream &outfile)
{
	outfile << std::endl << "* [VECTOR] Rbegin Rend  --- *" << std::endl;
	WOO::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	WOO::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	outfile << "myvector contains:";
	for (WOO::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		outfile << ' ' << *it;
	outfile << '\n';

	return 0;
}