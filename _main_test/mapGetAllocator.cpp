/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapGetAllocator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:40:42 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 11:26:09 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::get_allocator
#include <iostream>
#include <map>
#include "map.hpp"

int		mapGetAllocator()
{
	int psize;
	std::map<char,int> mymap;
	std::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(std::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);

	return 0;
}