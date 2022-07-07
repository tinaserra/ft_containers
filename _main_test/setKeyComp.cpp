// set::key_comp
#include "tests.hpp"

#include <iostream>
#include <set>

int setKeyComp (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] KeyComp  --- *" << std::endl;
    WOO::set<int> myset;
    int highest;

    WOO::set<int>::key_compare mycomp = myset.key_comp();

    for (int i=0; i<=5; i++) myset.insert(i);

    outfile << "myset contains:";

    highest=*myset.rbegin();
    WOO::set<int>::iterator it=myset.begin();
    do {
      outfile << ' ' << *it;
    } while ( mycomp(*(++it),highest) );

    outfile << '\n';

    return 0;
}