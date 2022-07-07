// set::lower_bound/upper_bound
#include "tests.hpp"

#include <iostream>
#include <set>

int setLowerUpperBound (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] LowerUpperBound  --- *" << std::endl;
    WOO::set<int> myset;
    WOO::set<int>::iterator itlow,itup;

    for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

    itlow=myset.lower_bound (30);                //       ^
    itup=myset.upper_bound (60);                 //                   ^

    myset.erase(itlow,itup);                     // 10 20 70 80 90

    outfile << "myset contains:";
    for (WOO::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
      outfile << ' ' << *it;
    outfile << '\n';

    return 0;
}