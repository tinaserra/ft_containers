/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_top.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:34:23 by vserra            #+#    #+#             */
/*   Updated: 2022/04/12 17:59:44 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack::top
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include "stack.hpp"

int		stackTop()
{
	std::cout << std::endl << "* \033[1m[STACK] Top\033[0m --------------------------------*" << std::endl;
	std::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';

	return 0;
}