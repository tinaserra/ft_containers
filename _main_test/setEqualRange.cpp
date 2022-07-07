// set::equal_elements
#include "tests.hpp"

#include <iostream>
#include <set>

int setEqualRange (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] EqualRange  --- *" << std::endl;
    WOO::set<int> myset;

    for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

    WOO::pair<WOO::set<int>::const_iterator,WOO::set<int>::const_iterator> ret;
    ret = myset.equal_range(30);

    outfile << "the lower bound points to: " << *ret.first << '\n';
    outfile << "the upper bound points to: " << *ret.second << '\n';

    return 0;
}