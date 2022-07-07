// set::size
#include "tests.hpp"

#include <iostream>
#include <set>

int setSize (std::ofstream &outfile)
{
    outfile << std::endl << "* [SET] Size  --- *" << std::endl;
    WOO::set<int> myints;
    outfile << "0. size: " << myints.size() << '\n';

    for (int i=0; i<10; ++i) myints.insert(i);
    outfile << "1. size: " << myints.size() << '\n';

    myints.insert (100);
    outfile << "2. size: " << myints.size() << '\n';

    myints.erase(5);
    outfile << "3. size: " << myints.size() << '\n';

    return 0;
}