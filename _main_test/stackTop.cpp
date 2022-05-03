/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:34:23 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 15:15:30 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack::top
#include "tests.hpp"

int		stackTop(std::ofstream &outfile)
{
	outfile << std::endl << "* \033[1m[STACK] Top\033[0m --- *" << std::endl;
	WOO::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	outfile << "mystack.top() is now " << mystack.top() << '\n';

	return 0;
}