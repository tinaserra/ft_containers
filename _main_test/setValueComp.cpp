// set::value_comp
#include "tests.hpp"

#include <iostream>
#include <set>

int setValueComp (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] ValueComp  --- *" << std::endl;
    WOO::set<int> myset;

    WOO::set<int>::value_compare mycomp = myset.value_comp();

    for (int i=0; i<=5; i++) myset.insert(i);

    outfile << "myset contains:";

    int highest=*myset.rbegin();
    WOO::set<int>::iterator it=myset.begin();
    do {
      outfile << ' ' << *it;
    } while ( mycomp(*(++it),highest) );

    outfile << '\n';

    return 0;
}