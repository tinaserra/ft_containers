/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:19:57 by vserra            #+#    #+#             */
/*   Updated: 2022/04/05 19:05:09 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int enable_if();
int equal();
int is_integral();
int iterator_traits();
int lexicographical_compare();
int make_pair();
int pair();
int reverse_iterator();
int assign();

int main() {

    std::cout << std::endl << std::endl << "ITERATOR TRAITS" << std::endl;
    iterator_traits();
    std::cout << std::endl << std::endl << "REVERSE ITERATOR" << std::endl;
    reverse_iterator();
    std::cout << std::endl << "ENABLE_IF" << std::endl;
    enable_if();
    std::cout << std::endl << "IS_INTEGRAL" << std::endl;
    is_integral();
    std::cout << std::endl << "EQUAL" << std::endl;
    equal();
    std::cout << std::endl << "LEXICOGRAPHICAL_COMPARE" << std::endl;
    lexicographical_compare();
    std::cout << std::endl << "PAIR" << std::endl;
    pair();
    std::cout << std::endl << "MAKE PAIR" << std::endl;
    make_pair();
    std::cout << std::endl << "ASSIGN" << std::endl;
    assign();
    return 0;
}