#include "vector.hpp"
#include "stack.hpp"
#include "utils/reverseIterator.hpp"
#include "map.hpp"

int		vectorAccessOperator();
int		vectorAssign();
int		vectorAssignation();
int		vectorAt();
int		vectorBack();
int		vectorBeginEnd();
int		vectorCapacitySizeMaxSize();
int		vectorClear();
int		vectorConstructor();
int		vectorEmpty();
int		vectorErase();
int		vectorFront();
int		vectorInsert();
int		vectorPopBack();
int		vectorPushBack();
int		vectorRbeginRend();
int		vectorResize();
int		vectorReserve();
int		vectorSwap();

int		stackConstructor();
int		stackEmpty();
int		stackPushPop();
int		stackSize();
int		stackTop();

int		mapAccessOperator();
int		mapAssignation();
int		mapBeginEnd();
int		mapClear();
int		mapConstructor();
int		mapCount();
int		mapEmpty();
int		mapEqualRange();
int		mapErase();
int		mapFind();
int		mapGetAllocator();
int		mapInsert();
int		mapKeyComp();
int		mapLowerUpperBound();
int		mapMaxSize();
int		mapRbeginRend();
int		mapSize();
int		mapSwap();
int		mapValueComp();



static void	vectorTests()
{
	vectorAccessOperator();
	vectorAssign();
	vectorAssignation();
	vectorAt();
	vectorBack();
	vectorBeginEnd();
	vectorCapacitySizeMaxSize();
	vectorClear();
	vectorConstructor();
	vectorEmpty();
	vectorErase();
	vectorFront();
	vectorInsert();
	vectorPopBack();
	vectorPushBack();
	vectorRbeginRend();
	vectorResize();
	vectorReserve();
	vectorSwap();
}

static void stackTests()
{
	stackConstructor();
	stackEmpty();
	stackPushPop();
	stackSize();
	stackTop();
}

static void mapTests()
{
	// mapAccessOperator();
	// mapAssignation();
	// mapBeginEnd();
	// mapClear();
	// mapConstructor();
	// mapCount();
	// mapEmpty();
	// mapEqualRange();
	// mapErase();
	// mapFind();
	// mapGetAllocator();
	mapInsert();
	// mapKeyComp();
	// mapLowerUpperBound();
	// mapMaxSize();
	// mapRbeginRend();
	// mapSize();
	// mapSwap();
	// mapValueComp();

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