#include "vector.hpp"
#include "stack.hpp"
#include "utils/reverseIterator.hpp"

int		vectorInsert();
int		vectorResize();
int		vectorReserve();

int		stackConstructor();
int		stackEmpty();
int		stackPushPop();
int		stackSize();
int		stackTop();

static void	vectorTests()
{
	// vectorConstructor(outfile);
	// vectorAssignation(outfile);
	// vectorIterators(outfile);
	// vectorSizeMaxSizeCapacityEmpty(outfile);
	vectorResize();
	vectorReserve();
	// vectorElementAccess(outfile);
	// vectorAssign(outfile);
	// vectorPushPopBack(outfile);
	vectorInsert();
	// vectorSwap(outfile);
	// vectorRelationalOperators(outfile);
}

static void stackTests() {

	stackConstructor();
	stackEmpty();
	stackPushPop();
	stackSize();
	stackTop();
	// stackRelationalOperators(outfile);
}

static void mapTests() {
	std::cout << "MODAFUCKER" << std::endl;

	// mapConstructor(outfile);
	// mapAssignation(outfile);
	// mapIterators(outfile);
	// mapSizeMaxSizeEmpty(outfile);
	// mapElementAccess(outfile);
	// mapInsertEraseClear(outfile);
	// mapSwap(outfile);
	// mapKeyValueComp(outfile);
	// mapFindCount(outfile);
	// mapLowerUpperBoundEqualRange(outfile);

}

int main(int ac, char **av)
{
	std::string input;

	if (ac != 2)
	{
		std::cout << "met un argument ta race" << std::endl;
		return (0);
	}
	input = av[1];
	if (input.compare("vector") == 0)
		vectorTests();
	else if (input.compare("stack") == 0)
		stackTests();
	else if (input.compare("map") == 0)
		mapTests();
	return (0);
}