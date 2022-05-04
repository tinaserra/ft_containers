// constructing maps
#include "tests.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{ return lhs<rhs; }
};

int		mapConstructor(std::ofstream &outfile)
{
	outfile << std::endl << "* [MAP] Constructor  --- *" << std::endl;
	outfile << "STL map" << std::endl;
	WOO::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	WOO::map<char,int> second (first.begin(),first.end());

	WOO::map<char,int> third (second);

	WOO::map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	WOO::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	return 0;
}