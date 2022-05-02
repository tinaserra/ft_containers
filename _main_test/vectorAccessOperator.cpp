/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAccessOperator2.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:12:44 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:48:17 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::operator[]

#include "tests.hpp"

int		vectorAccessOperator(std::ofstream &outfile)
{
	WOO::vector<int> myvector (10);   // 10 zero-initialized elements

	WOO::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	outfile << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';

	return 0;
}