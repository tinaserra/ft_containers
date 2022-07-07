// set::max_size
#include "tests.hpp"

#include "tests.hpp"

#include <iostream>
#include <set>

int setMaxSize(std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] MaxSize  --- *" << std::endl;
    int i;
    WOO::set<int> myset;

    if (myset.max_size()>1000)
    {
        for (i=0; i<1000; i++) myset.insert(i);
        outfile << "The set contains 1000 elements.\n";
    }
    else outfile << "The set could not hold 1000 elements.\n";

    return 0;
}