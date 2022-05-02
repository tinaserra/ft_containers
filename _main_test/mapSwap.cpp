/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapSwap2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:48:06 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 12:48:29 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// swap maps
#include "tests.hpp"

int		mapSwap(std::ofstream &outfile)
{
	WOO::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	outfile << "foo contains:\n";
	for (WOO::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	outfile << "bar contains:\n";
	for (WOO::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		outfile << it->first << " => " << it->second << '\n';

	return 0;
}