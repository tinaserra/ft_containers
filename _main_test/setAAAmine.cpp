// test pour amine
#include "tests.hpp"

#include <iostream>
#include <set>

int setAAAmine (std::ofstream &outfile)
{
    (void) outfile;
    std::cout << std::endl << "* [SET] AAAmine  --- *" << std::endl;
    WOO::set<int> myset;
    WOO::set<int>::reverse_iterator it;

    for (int i=1; i<=3; ++i) myset.insert(i*10);

    myset.clear();

    for (int i=1; i<=3; ++i) myset.insert(i*4);  

    std::cout << "myset :";
    for (it=myset.begin(); it!=myset.end(); ++it)
      std::cout << "key -> " << *it << " ";
    std::cout << '\n';

    return 0;
}