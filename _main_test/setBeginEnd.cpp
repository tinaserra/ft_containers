// set::begin/end
#include "tests.hpp"

#include <iostream>
#include <set>

int setBeginEnd(std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] BeginEnd  --- *" << std::endl;
    int myints[] = {75,23,65,42,13};
    WOO::set<int> myset (myints,myints+5);

    outfile << "myset contains:";
    for (WOO::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        outfile << ' ' << *it;

    outfile << '\n';

    return 0;
}