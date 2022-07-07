// set::empty
#include "tests.hpp"

#include <iostream>
#include <set>

int setEmpty (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] Empty  --- *" << std::endl;
    WOO::set<int> myset;

    myset.insert(20);
    myset.insert(30);
    myset.insert(10);

    outfile << "myset contains:";
    while (!myset.empty())
    {
      outfile << ' ' << *myset.begin();
      myset.erase(myset.begin());
    }
    outfile << '\n';

    return 0;
}