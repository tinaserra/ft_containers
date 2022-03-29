/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:01:59 by vserra            #+#    #+#             */
/*   Updated: 2022/03/25 22:05:50 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <iostream>
# include <fstream>
# include <limits>

# include <vector>
# include <stack>
# include <map>

# include "lexicographical_compare.hpp"
// # include "equal_compare.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
// # include "iterator_traits.hpp"
// # include "vectorIterator.hpp"
# include "reverse_iterator.hpp"
// # include "utils.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
// # include "redBlackIterator.hpp"
# include "map.hpp"
// # include "set.hpp"

#if (STD == 1)
	#define NAMESP			std
	#define VECTORNAME		"stdVectorLog"
	#define STACKNAME		"stdStackLog"
	#define MAPNAME			"stdMapLog"
	#define SETNAME			"stdSetLog"
#else
	#define NAMESP			ft
	#define VECTORNAME		"ftVectorLog"
	#define STACKNAME		"ftStackLog"
	#define MAPNAME			"ftMapLog"
	#define SETNAME			"ftSetLog"
#endif

# define LOG1(x)	outfile << x << std::endl;
# define LOG2(x,y)	outfile << x << y << std::endl;

/* VECTOR ------------------------------------------------------------------- */

void	vectorConstructor(std::ofstream &outfile);
void	vectorAssignation(std::ofstream &outfile);
void	vectorIterators(std::ofstream &outfile);
void	vectorSizeMaxSizeCapacityEmpty(std::ofstream &outfile);
void	vectorResize(std::ofstream &outfile);
void	vectorReserve(std::ofstream &outfile);
void	vectorElementAccess(std::ofstream &outfile);
void	vectorAssign(std::ofstream &outfile);
void	vectorPushPopBack(std::ofstream &outfile);
void	vectorInsertEraseClear(std::ofstream &outfile);
void	vectorSwap(std::ofstream &outfile);
void	vectorRelationalOperators(std::ofstream &outfile);

/* STACK -------------------------------------------------------------------- */

void	stackConstructor(std::ofstream &outfile);
void	stackEmptySizeTop(std::ofstream &outfile);
void	stackPushPop(std::ofstream &outfile);
void	stackRelationalOperators(std::ofstream &outfile);

/* MAP ---------------------------------------------------------------------- */

void	mapConstructor(std::ofstream &outfile);
void	mapAssignation(std::ofstream &outfile);
void	mapIterators(std::ofstream &outfile);
void	mapSizeMaxSizeEmpty(std::ofstream &outfile);
void	mapElementAccess(std::ofstream &outfile);
void	mapInsertEraseClear(std::ofstream &outfile);
void	mapSwap(std::ofstream &outfile);
void	mapKeyValueComp(std::ofstream &outfile);
void	mapFindCount(std::ofstream &outfile);
void	mapLowerUpperBoundEqualRange(std::ofstream &outfile);

#endif