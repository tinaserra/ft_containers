/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_constructor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:30:13 by vserra            #+#    #+#             */
/*   Updated: 2022/04/12 17:59:31 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// constructing stacks
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "stack.hpp"

int		stackConstructor()
{
	std::cout << std::endl << "* \033[1m[STACK] Constructor\033[0m ------------------------*" << std::endl;
	// std::deque<int> mydeque1 (3,100);          // deque with 3 elements
	std::vector<int> myvector1 (2,200);        // vector with 2 elements
	// std::deque<int> mydeque2 (3,100);          // deque with 3 elements
	std::vector<int> myvector2 (2,200);        // vector with 2 elements

	std::stack<int> STLfirst;                  // empty stack
	// std::stack<int> STLsecond (mydeque1);      // stack initialized to copy of deque

	ft::stack<int> FTfirst;
	// ft::stack<int> FTsecond (mydeque2);

	std::stack<int,std::vector<int> > STLthird;  // empty stack using vector
	std::stack<int,std::vector<int> > STLfourth (myvector1);

	std::stack<int,std::vector<int> > FTthird;
	std::stack<int,std::vector<int> > FTfourth (myvector2);

	std::cout << "STL stack:" << std::endl;
	std::cout << "size of first: " << STLfirst.size() << '\n';
	// std::cout << "size of second: " << STLsecond.size() << '\n';
	std::cout << "size of third: " << STLthird.size() << '\n';
	std::cout << "size of fourth: " << STLfourth.size() << '\n';

	std::cout << std::endl << "My stack:" << std::endl;
	std::cout << "size of first: " << FTfirst.size() << '\n';
	// std::cout << "size of second: " << FTsecond.size() << '\n';
	std::cout << "size of third: " << FTthird.size() << '\n';
	std::cout << "size of fourth: " << FTfourth.size() << '\n';

	return 0;
}