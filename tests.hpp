#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>
# include <fstream>
# include <limits>
# include <vector>
# include <map>
# include <stack>
# include <deque>
# include <set>

# include "vector.hpp"
# include "stack.hpp"
# include "set.hpp"
# include "reverseIterator.hpp"
# include "map.hpp"

# ifdef STL
#  define WOO			std
#  define VECTORFILE	"stdVectorOutput"
#  define STACKFILE		"stdStackOutput"
#  define MAPFILE		"stdMapOutput"
#  define SETFILE		"stdSetOutput"
# else
#  define WOO			ft
#  define VECTORFILE	"ftVectorOutput"
#  define STACKFILE		"ftStackOutput"
#  define MAPFILE		"ftMapOutput"
#  define SETFILE		"ftSetOutput"
# endif

int		vectorAccessOperator(std::ofstream &outfile);
int		vectorAssign(std::ofstream &outfile);
int		vectorAssignation(std::ofstream &outfile);
int		vectorAt(std::ofstream &outfile);
int		vectorBack(std::ofstream &outfile);
int		vectorBeginEnd(std::ofstream &outfile);
int		vectorCapacitySizeMaxSize(std::ofstream &outfile);
int		vectorClear(std::ofstream &outfile);
int		vectorConstructor(std::ofstream &outfile);
int		vectorEmpty(std::ofstream &outfile);
int		vectorErase(std::ofstream &outfile);
int		vectorFront(std::ofstream &outfile);
int		vectorInsert(std::ofstream &outfile);
int		vectorPopBack(std::ofstream &outfile);
int		vectorPushBack(std::ofstream &outfile);
int		vectorRbeginRend(std::ofstream &outfile);
int		vectorResize(std::ofstream &outfile);
int		vectorReserve(std::ofstream &outfile);
int		vectorSwap(std::ofstream &outfile);

int		stackConstructor(std::ofstream &outfile);
int		stackEmpty(std::ofstream &outfile);
int		stackPushPop(std::ofstream &outfile);
int		stackSize(std::ofstream &outfile);
int		stackTop(std::ofstream &outfile);

int		mapAccessOperator(std::ofstream &outfile);
int		mapAssignation(std::ofstream &outfile);
int		mapBeginEnd(std::ofstream &outfile);
int		mapClear(std::ofstream &outfile);
int		mapConstructor(std::ofstream &outfile);
int		mapCount(std::ofstream &outfile);
int		mapEmpty(std::ofstream &outfile);
int		mapEqualRange(std::ofstream &outfile);
int		mapErase(std::ofstream &outfile);
int		mapFind(std::ofstream &outfile);
int		mapGetAllocator(std::ofstream &outfile);
int		mapInsert(std::ofstream &outfile);
int		mapKeyComp(std::ofstream &outfile);
int		mapLowerUpperBound(std::ofstream &outfile);
int		mapMaxSize(std::ofstream &outfile);
int		mapRbeginRend(std::ofstream &outfile);
int		mapSize(std::ofstream &outfile);
int		mapSwap(std::ofstream &outfile);
int		mapValueComp(std::ofstream &outfile);

int     setAAAmine (std::ofstream &outfile);
int     setAssignation(std::ofstream &outfile);
int 	setBeginEnd(std::ofstream &outfile);
int 	setClear(std::ofstream &outfile);
int 	setCount(std::ofstream &outfile);
int 	setEmpty(std::ofstream &outfile);
int 	setEqualRange(std::ofstream &outfile);
int 	setErase(std::ofstream &outfile);
int 	setFind(std::ofstream &outfile);
int 	setGetAllocator(std::ofstream &outfile);
int 	setInsert(std::ofstream &outfile);
int 	setKeyComp(std::ofstream &outfile);
int 	setLowerUpperBound(std::ofstream &outfile);
int 	setMaxSize(std::ofstream &outfile);
int 	setRbeginRend(std::ofstream &outfile);
int 	setSize(std::ofstream &outfile);
int 	setSwap(std::ofstream &outfile);
int 	setValueComp(std::ofstream &outfile);


#endif