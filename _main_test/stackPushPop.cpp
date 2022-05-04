/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackPushPop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:27:08 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int		stackPushPop(std::ofstream &outfile)
{
	outfile << std::endl << "* [STACK] PushPop  --- *" << std::endl;
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