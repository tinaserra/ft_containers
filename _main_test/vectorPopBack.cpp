/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorPopBack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:13:15 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:27:25 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::pop_back
#include "tests.hpp"

int		vectorPopBack()
{
	outfile << std::endl << "* \033[1m[VECTOR] Pop_back\033[0m --- *" << std::endl;
	WOO::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	outfile << "The elements of myvector add up to " << sum << '\n';

	return 0;
}