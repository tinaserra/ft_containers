// set::count
#include "tests.hpp"

#include <iostream>
#include <set>

int setCount (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] Count  --- *" << std::endl;
    WOO::set<int> myset;

    // set some initial values:
    for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

    for (int i=0; i<10; ++i)
    {
      outfile << i;
      if (myset.count(i)!=0)
        outfile << " is an element of myset.\n";
      else
        outfile << " is not an element of myset.\n";
    }

    return 0;
}