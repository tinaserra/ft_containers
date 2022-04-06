/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:43:02 by vserra            #+#    #+#             */
/*   Updated: 2022/03/14 17:54:31 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout

int make_pair() {
  std::pair <int,int> foo;
  std::pair <int,int> bar;

  foo = std::make_pair (10,20);
  bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

  return 0;
}
