/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackConstructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:30:13 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:34:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// constructing stacks
#include "tests.hpp"

int		stackConstructor(std::ofstream &outfile)
{
	outfile << std::endl << "* [STACK] Constructor  --- *" << std::endl;

	std::deque<int> mydeque (3,100);          // deque with 3 elements
	WOO::vector<int> myvector (2,200);        // vector with 2 elements

	WOO::stack<int> first;                    // empty stack
	WOO::stack<int> second (mydeque);         // stack initialized to copy of deque

	WOO::stack<int,WOO::vector<int> > third;  // empty stack using vector
	WOO::stack<int,WOO::vector<int> > fourth (myvector);

	outfile << "size of first: " << first.size() << '\n';
	outfile << "size of second: " << second.size() << '\n';
	outfile << "size of third: " << third.size() << '\n';
	outfile << "size of fourth: " << fourth.size() << '\n';
	return 0;
}
