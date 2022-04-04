/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:36:24 by vserra            #+#    #+#             */
/*   Updated: 2022/04/04 09:37:46 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>
#include "enable_if.hpp"
#include "is_integral.hpp"

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type is_odd (T i)
{
  return bool(i%2);
}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename ft::enable_if<ft::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

class nimportequoi {
  public:
    nimportequoi() {};
};

int enable_if() {

  short int i = 1;    // code does not compile if type of i is not integral
  
  nimportequoi tamere;

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
  return 0;
}
