/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorPushBack.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:13:55 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:43:04 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::push_back
#include "tests.hpp"

int		vectorPushBack(std::ofstream &outfile)
{
	outfile << std::endl << "* [VECTOR] Push_back  --- *" << std::endl;
	WOO::vector<int> myvector;

	myvector.push_back(900);
	myvector.push_back(34);
	myvector.push_back(654);
	myvector.push_back(87);
	myvector.push_back(785);
	myvector.push_back(42674);
	myvector.push_back(9809760);
	myvector.push_back(0);
	myvector.push_back(-2354);


	outfile << "myvector stores " << int(myvector.size()) << " numbers.\n";
	for (size_t i = 0; i < myvector.size(); i++)
		outfile << myvector[i] << " ";
	outfile << std::endl;

	return 0;
}