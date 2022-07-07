// swap sets
#include "tests.hpp"

#include <iostream>
#include <set>

int setSwap (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] Swap  --- *" << std::endl;
    int myints[]={12,75,10,32,20,25};
    WOO::set<int> first (myints,myints+3);     // 10,12,75
    WOO::set<int> second (myints+3,myints+6);  // 20,25,32

    first.swap(second);

    outfile << "first contains:";
    for (WOO::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
      outfile << ' ' << *it;
    outfile << '\n';

    outfile << "second contains:";
    for (WOO::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
      outfile << ' ' << *it;
    outfile << '\n';

    return 0;
}