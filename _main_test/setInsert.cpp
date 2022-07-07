// set::insert (C++98)
#include "tests.hpp"

#include <iostream>
#include <set>

int setInsert (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] Insert  --- *" << std::endl;
    WOO::set<int> myset;
    WOO::set<int>::iterator it;
    WOO::pair<WOO::set<int>::iterator,bool> ret;

    // set some initial values:
    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

    ret = myset.insert(20);               // no new element inserted

    if (ret.second==false) it=ret.first;  // "it" now points to element 20

    myset.insert (it,25);                 // max efficiency inserting
    myset.insert (it,24);                 // max efficiency inserting
    myset.insert (it,26);                 // no max efficiency inserting

    int myints[]= {5,10,15};              // 10 already in set, not inserted
    myset.insert (myints,myints+3);

    outfile << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
      outfile << ' ' << *it;
    outfile << '\n';

    return 0;
}