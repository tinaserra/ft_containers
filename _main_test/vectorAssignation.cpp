/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAssignation2.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:12:03 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:49:40 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vector assignment
#include "tests.hpp"

int		vectorAssignation(std::ofstream &outfile)
{
	WOO::vector<int> foo (3,0);
	WOO::vector<int> bar (5,0);

	bar = foo;
	foo = WOO::vector<int>();

	outfile << "Size of foo: " << int(foo.size()) << '\n';
	outfile << "Size of bar: " << int(bar.size()) << '\n';
	return 0;
}