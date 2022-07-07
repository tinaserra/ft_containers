// set::clear
#include "tests.hpp"

#include <iostream>
#include <set>

int setClear (std::ofstream &outfile)
{
  outfile << std::endl << "* [SET] setClear  --- *" << std::endl;
  WOO::set<int> myset;

  myset.insert (100);
  myset.insert (200);
  myset.insert (300);

  outfile << "myset contains:";
  for (WOO::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    outfile << ' ' << *it;
  outfile << '\n';

  myset.clear();
  myset.insert (1101);
  myset.insert (2202);

  outfile << "myset contains:";
  for (WOO::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    outfile << ' ' << *it;
  outfile << '\n';

  return 0;
}