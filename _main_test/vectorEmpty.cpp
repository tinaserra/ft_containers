/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorEmpty.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:25:14 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:25:23 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector::empty
#include "tests.hpp"

int		vectorEmpty(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[VECTOR] Empty\033[0m --- *" << std::endl;
	WOO::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	outfile << "total: " << sum << '\n';

	return 0;
}