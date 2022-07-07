// set::find
#include "tests.hpp"

#include <iostream>
#include <set>

int setFind (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] Find  --- *" << std::endl;
    WOO::set<int> myset;
    WOO::set<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

    it=myset.find(20);
    myset.erase (it);
    myset.erase (myset.find(40));

    outfile << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
      outfile << ' ' << *it;
    outfile << '\n';

    return 0;
}