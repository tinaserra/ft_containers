/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackSize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:31:29 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int		stackSize(std::ofstream &outfile)
{
	outfile << std::endl << "* [STACK] Size  --- *" << std::endl;
	WOO::stack<int> myints;
	outfile << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	outfile << "1. size: " << myints.size() << '\n';

	myints.pop();
	outfile << "2. size: " << myints.size() << '\n';

	return 0;
}