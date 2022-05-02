// vector::empty
#include "tests.hpp"

int		vectorEmpty(std::ofstream &outfile)
{
	WOO::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	outfile << "total: " << sum << '\n';

	return 0;
}