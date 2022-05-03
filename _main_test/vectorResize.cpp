/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorResize.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:29 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:31:02 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int		vectorResize(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[VECTOR] Resize\033[0m --- *" << std::endl;

	WOO::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	outfile << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';

	return 0;
}