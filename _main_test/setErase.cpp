// erasing from set
#include "tests.hpp"

#include <iostream>
#include <set>

int setErase (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] Erase  --- *" << std::endl;
    WOO::set<int> myset;
    WOO::set<int>::iterator it;

    // insert some values:
    for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

    it = myset.begin();
    ++it;                                         // "it" points now to 20

    myset.erase (it);

    myset.erase (40);

    it = myset.find (60);
    myset.erase (it, myset.end());

    outfile << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
      outfile << ' ' << *it;
    outfile << '\n';

    return 0;
}