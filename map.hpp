/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:11 by vserra            #+#    #+#             */
/*   Updated: 2022/07/07 16:56:29 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include <algorithm>
// # include <iostream>
// # include <sstream>
# include "utils/pair.hpp"
# include "utils/iterator_traits.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/equal.hpp"
# include "RedBlackTree.hpp" // a mettre dans utils/

namespace ft {

template < class Key, class T, class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {

	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;


		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			public:
				bool	operator()(const value_type &x, const value_type &y) const
				{
					return comp(x.first, y.first);
				}
				value_compare(Compare c) : comp(c) {}

			protected:
				Compare comp;
		};

		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;

		typedef RedBlackTree<value_type, value_compare, allocator_type>		tree_type;
		typedef typename tree_type::pair_type								pair_type;
		typedef typename tree_type::pair_range								pair_range;
		typedef typename tree_type::const_pair_range						const_pair_range;
		typedef typename tree_type::iterator 								iterator;
		typedef typename tree_type::const_iterator							const_iterator;
		typedef typename tree_type::reverse_iterator						reverse_iterator;
		typedef typename tree_type::const_reverse_iterator					const_reverse_iterator;
		
		typedef typename iterator_traits<iterator>::difference_type			difference_type;
		typedef size_t														size_type;
		
		// typedef Node<value_type>											node_type;
		// typedef node_type*												node_pointer;
		// typedef std::ptrdiff_t											difference_type;
		// typedef typename allocator_type::template rebind<node_type>::other	node_allocator;

	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBERS                                                        */
	/* ---------------------------------------------------------------------- */

	private:
		key_compare		_key_comp;
		tree_type		_redBlackTree;

	/* ---------------------------------------------------------------------- */
	/* PUBLIC MEMBER FUNCTIONS                                                */
	/* ---------------------------------------------------------------------- */

	public:
		// Default constructor
		explicit map(const key_compare & comp = key_compare(),
						const allocator_type & alloc = allocator_type())
						: _redBlackTree(comp , alloc) {}
			
		// Range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare & comp = key_compare(),
				const allocator_type & alloc = allocator_type())
				: _redBlackTree(comp , alloc)
			{
				while (first != last)
					_redBlackTree.insert(*first++);
			}

		// Copy constructor
		map(const map & x) : _redBlackTree(x.key_comp(), x.get_allocator())
		{
			// for (const_iterator pos = x.begin(); pos != x.end(); pos++)
			// 	_redBlackTree.insert(*pos);

			const_iterator pos = x.begin();
    		while (pos != x.end())
        		_redBlackTree.insert(*pos++);
		}

		// Destructor
		~map() {}

		//Assignation operator
		map &	operator=(const map & rhs)
		{
			_redBlackTree = rhs._redBlackTree;
			_key_comp = rhs._key_comp;
			return *this;
		}

		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		iterator				begin() { return _redBlackTree.begin(); }

		const_iterator			begin() const { return _redBlackTree.begin(); }

		iterator				end() { return (_redBlackTree.end()); }

		const_iterator			end() const { return (_redBlackTree.end()); }

		reverse_iterator		rbegin() { return (_redBlackTree.rbegin()); }

		const_reverse_iterator	rbegin() const { return (_redBlackTree.rbegin()); }

		reverse_iterator		rend() { return (_redBlackTree.rend()); }

		const_reverse_iterator	rend() const { return (_redBlackTree.rend()); }

		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		bool		empty() const { return (_redBlackTree.empty() == true); }

		size_type	size() const { return (_redBlackTree.get_size()); }

		size_type	max_size() const
		{
			return _redBlackTree.get_max_size();
		}

		/* ------------------------------------------------------------------ */
		/* ELEMENT ACCESS                                                     */
		/* ------------------------------------------------------------------ */

		mapped_type	&		operator[](const key_type &k)
		{
			value_type val = ft::make_pair(k, mapped_type());
			return (((_redBlackTree.insert(val)).first)->second);
		}

		/* ------------------------------------------------------------------ */
		/* MODIFIERS                                                          */
		/* ------------------------------------------------------------------ */

		// insert single element
		pair_type	insert(value_type const & val)
		{
			return _redBlackTree.insert(val);
		}

		// insert with hint
		iterator	insert(iterator position, value_type const & val)
		{
			return _redBlackTree.insertIter(position, val);
		}

		// insert range
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last) 
		{
			while (first != last)
				_redBlackTree.insert(*first++);	
		}

		// erase position
		void	erase(iterator position)
		{
			if (position == end())
					return;
			key_type key = position->first;
			value_type val = ft::make_pair(key, mapped_type());

			_redBlackTree.deleteNode(_redBlackTree.searchTree(val));
		}

		// erase key
		size_type	erase(const key_type & k)
		{
			value_type val = ft::make_pair(k, mapped_type());

			iterator pos(_redBlackTree.searchTree(val));
			if (pos != end())
			{
				_redBlackTree.deleteNode(_redBlackTree.searchTree(val));
				return 1;
			}
			return 0;
		}

		// erase range
		void	erase(iterator first, iterator last)
		{
			if (first != end())
			{
				while(first != last)
					_redBlackTree.deleteNode(_redBlackTree.searchTree(*first++));
			}
		}

		void	swap(map& x)
		{
			_redBlackTree.swap(x._redBlackTree);
		}

		void	clear()
		{
			_redBlackTree.clean();
		}

		/* ------------------------------------------------------------------ */
		/* OBSERVERS                                                          */
		/* ------------------------------------------------------------------ */

		key_compare		key_comp() const { return (this->_key_comp); }

		value_compare	value_comp() const { return _redBlackTree.get_key_compare(); }


		/* ------------------------------------------------------------------ */
		/* OPERATIONS                                                         */
		/* ------------------------------------------------------------------ */

		iterator	find(key_type const & k) // search
		{
			value_type val = ft::make_pair(k, mapped_type());
			return iterator(_redBlackTree.searchTree(val));
		}

		const_iterator	find(key_type const & k) const
		{
			value_type val = ft::make_pair(k, mapped_type());
			return const_iterator(_redBlackTree.searchTree(val));
		}

		size_type	count(key_type const & k) const
		{
			value_type val = ft::make_pair(k, mapped_type());
			const_iterator res = _redBlackTree.searchTree(val);
			if (res == end())
				return 0;
			else
				return 1;
		}

		iterator	lower_bound(const key_type & k)
		{
			value_type val = ft::make_pair(k, mapped_type());
			return (iterator(_redBlackTree.get_lower_bound(val)));
		}

		const_iterator	lower_bound(const key_type & k) const
		{
			value_type val = ft::make_pair(k, mapped_type());
			return (const_iterator(_redBlackTree.get_lower_bound(val)));
		}

		iterator	upper_bound(const key_type & k)
		{
			value_type val = ft::make_pair(k, mapped_type());
			return (iterator(_redBlackTree.get_upper_bound(val)));
		}

		const_iterator	upper_bound(const key_type & k) const
		{
			value_type val = ft::make_pair(k, mapped_type());
			return (const_iterator(_redBlackTree.get_upper_bound(val)));
		}

		pair_range	equal_range(const key_type & k)
		{
			value_type val = ft::make_pair(k, mapped_type());
			return (_redBlackTree.get_equal_range(val));
		}

		const_pair_range	equal_range(const key_type & k) const
		{
			value_type val = ft::make_pair(k, mapped_type());
			return (_redBlackTree.get_equal_range(val));
		}

		/* ------------------------------------------------------------------ */
		/* ALLOCATOR                                                          */
		/* ------------------------------------------------------------------ */

		allocator_type	get_allocator() const { return _redBlackTree.get_data_allocator(); }

	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBER FUNCTIONS                                               */
	/* ---------------------------------------------------------------------- */
	private:

		void	_print() { _redBlackTree.printTree(); }
	};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */


template <class Key, class T, class Compare, class Alloc>
bool	operator==(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator!=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	if (lhs == rhs || lhs < rhs)
		return true;
	return false;
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	if (lhs == rhs || lhs > rhs)
		return true;
	return false;
}

template <class Key, class T, class Compare, class Alloc>
void	swap(map<Key, T, Compare, Alloc> & x, map<Key, T, Compare, Alloc> & y)
{
	x.swap(y);
}

};

#endif