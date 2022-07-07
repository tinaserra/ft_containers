// set::get_allocator
#include "tests.hpp"

#include <iostream>
#include <set>

int setGetAllocator (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] GetAllocator  --- *" << std::endl;
    WOO::set<int> myset;
    int * p;
    unsigned int i;

    // allocate an array of 5 elements using myset's allocator:
    p=myset.get_allocator().allocate(5);

    // assign some values to array
    for (i=0; i<5; i++) p[i]=(i+1)*10;

    outfile << "The allocated array contains:";
    for (i=0; i<5; i++) outfile << ' ' << p[i];
    outfile << '\n';

    myset.get_allocator().deallocate(p,5);

    return 0;
}