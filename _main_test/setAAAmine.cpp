// test pour amine
#include "tests.hpp"

#include <iostream>
#include <set>

int setAAAmine (std::ofstream &outfile)
{
		(void) outfile;
		std::cout << std::endl << "* [SET] AAAmine  --- *" << std::endl;
		WOO::set<int> myset;
		WOO::set<int>::reverse_iterator it;

		for (int i=1; i<=3; ++i) myset.insert(i*10);

		myset.clear();

		for (int i=1; i<=3; ++i) myset.insert(i*4);  

		std::cout << "myset :";
		for (it=myset.rbegin(); it!=myset.rend(); ++it)
			std::cout << "key -> " << *it << " ";
		std::cout << '\n';


		ft::set<int> a;
		ft::set<int> b;

		std::srand(42);
		a.insert(int(std::rand() % 1024));
		a.insert(int(std::rand() % 1024));
		a.insert(int(std::rand() % 1024));
		a.clear();
		a.insert(int(std::rand() % 1024));
		a.insert(int(std::rand() % 1024));
		a.insert(int(std::rand() % 1024));
		ft::set<int>::const_reverse_iterator it2 = a.rbegin();
		std::cout << "\nlove const_reverse_iterator " << *it2 << std::endl;


		a.clear();

		std::srand(42);
		a.insert(1);
		a.insert(2);
		a.insert(3);
		a.clear();
		a.insert(4);
		a.insert(5);
		a.insert(2);
		ft::set<int>::const_reverse_iterator it3 = a.rbegin();
		std::cout << "\nlove const_reverse_iterator " << *it3 << std::endl;

		return 0;
}