#include "tests.hpp"

static void	vectorTests()
{
	std::ofstream outfile;

	outfile.open(VECTORFILE);

	vectorAccessOperator(outfile);
	vectorAssign(outfile);
	vectorAssignation(outfile);
	vectorAt(outfile);
	vectorBack(outfile);
	vectorBeginEnd(outfile);
	vectorCapacitySizeMaxSize(outfile);
	vectorClear(outfile);
	vectorConstructor(outfile);
	vectorEmpty(outfile);
	vectorErase(outfile);
	vectorFront(outfile);
	vectorInsert(outfile);
	vectorPopBack(outfile);
	vectorPushBack(outfile);
	vectorRbeginRend(outfile);
	vectorResize(outfile);
	vectorReserve(outfile);
	vectorSwap(outfile);

	outfile.close();
}

static void stackTests()
{
	std::ofstream outfile;

	outfile.open(STACKFILE);

	stackConstructor(outfile);
	stackEmpty(outfile);
	stackPushPop(outfile);
	stackSize(outfile);
	stackTop(outfile);

	outfile.close();
}

static void mapTests()
{
	std::ofstream outfile;

	outfile.open(MAPFILE);

	mapAccessOperator(outfile);
	// mapAssignation(outfile);
	// mapBeginEnd(outfile);
	// mapClear(outfile);
	// mapConstructor(outfile);
	// mapCount(outfile);
	// mapEmpty(outfile);
	// mapEqualRange(outfile);
	// mapErase(outfile);
	// mapFind(outfile);
	// mapGetAllocator(outfile);
	// mapInsert(outfile);
	// mapKeyComp(outfile);
	// mapLowerUpperBound(outfile);
	// mapMaxSize(outfile);
	// mapRbeginRend(outfile);
	// mapSize(outfile);
	// mapSwap(outfile);
	// mapValueComp(outfile);

	outfile.close();

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