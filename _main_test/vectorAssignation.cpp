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
#include <iostream>
#include <vector>
#include "vector.hpp"

int		vectorAssignation()
{
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	return 0;
}