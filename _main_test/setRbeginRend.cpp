// set::rbegin/rend
#include "tests.hpp"

#include <iostream>
#include <set>

int setRbeginRend (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] RbeginRend  --- *" << std::endl;
    int myints[] = {21,64,17,78,49};
    WOO::set<int> myset (myints,myints+5);

    WOO::set<int>::reverse_iterator rit;

    outfile << "myset contains:";
    for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
      outfile << ' ' << *rit;

    outfile << '\n';

    return 0;
}