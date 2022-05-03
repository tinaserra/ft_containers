/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackEmpty.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:20:27 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:14:59 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int		stackEmpty(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[STACK] Empty\033[0m --- *" << std::endl;
	WOO::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	outfile << "total: " << sum << '\n';

	return 0;
}