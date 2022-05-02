/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorBeginEnd.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:08:27 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:50:44 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::begin/end
#include "tests.hpp"

int		vectorBeginEnd(std::ofstream &outfile)
{
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	outfile << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		outfile << ' ' << *it;
	outfile << '\n';

	return 0;
}