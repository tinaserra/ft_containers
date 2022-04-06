// vector assign
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::cout << "first" << std::endl;
  for (unsigned int i = 0; i < first.size(); i++)
	{
		std::cout << first[i] << " ";
	}
  std::cout << std::endl;

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  std::cout << "second" << std::endl;
  for (unsigned int i = 0; i < second.size(); i++)
	{
		std::cout << second[i] << " ";
	}
  std::cout << std::endl;
  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "third" << std::endl;
  for (unsigned int i = 0; i < third.size(); i++)
	{
		std::cout << third[i] << " ";
	}
  std::cout << std::endl;
  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
  return 0;
}