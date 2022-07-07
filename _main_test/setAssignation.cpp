// assignment operator with sets
#include "tests.hpp"

#include <iostream>
#include <set>

int setAssignation (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] setAssignation  --- *" << std::endl;
    int myints[]={ 12,82,37,64,15 };
    WOO::set<int> first (myints,myints+5);   // set with 5 ints
    WOO::set<int> second;                    // empty set

    second = first;                          // now second contains the 5 ints
    first = WOO::set<int>();                 // and first is empty

    outfile << "Size of first: " << int (first.size()) << '\n';
    outfile << "Size of second: " << int (second.size()) << '\n';
    return 0;
}