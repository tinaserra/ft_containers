/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorInsert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:28:59 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int		vectorInsert(std::ofstream &outfile)
{
	outfile << std::endl << "* [VECTOR] Insert  --- *" << std::endl;
	
	WOO::vector<int> myvector (3,100);
	WOO::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	WOO::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	outfile << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		outfile << ' ' << *it;
	outfile << '\n';

	return 0;
	return 0;
}