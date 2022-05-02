/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pop.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:27:08 by vserra            #+#    #+#             */
/*   Updated: 2022/04/12 17:59:41 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int		stackPushPop(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[STACK] PushPop\033[0m ----------------------------*" << std::endl;
	WOO::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	outfile << "Popping out elements...";
	while (!mystack.empty())
	{
		outfile << ' ' << mystack.top();
		mystack.pop();
	}
	outfile << '\n';

	return 0;
}