/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:11 by vserra            #+#    #+#             */
/*   Updated: 2022/04/19 14:12:00 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include <iostream>
# include <sstream>
# include "utils/pair.hpp"
# include "utils/iterator_traits.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/equal.hpp"
#include "rb.hpp"
// # include "utils/node.hpp"
// # include "utils/mapIterator.hpp"

namespace ft {

template < class Key, class T, class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {

	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;


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

		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef RedBlackTree<value_type, value_compare, allocator_type>		tree_type;
		typedef Node<value_type>											node_type;
		typedef node_type*													node_pointer;
		typedef typename tree_type::iterator 						iterator;
		typedef typename tree_type::const_iterator					const_iterator;
		typedef typename tree_type::reverse_iterator				reverse_iterator;
		typedef typename tree_type::const_reverse_iterator			const_reverse_iterator;
		typedef std::ptrdiff_t												difference_type;
		typedef size_t														size_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator;

	/* ---------------------------------------------------------------------- */
	/* PROTECTED & PRIVATE MEMBERS                                            */
	/* ---------------------------------------------------------------------- */
	// protected:
	// 	key_compare		_comp;
	// 	node_allocator	_alloc;
	// 	size_type		_size;
	// 	node_pointer	_root;

	private:
		node_pointer	_last;
		tree_type	_tree;

	/* ---------------------------------------------------------------------- */
	/* PUBLIC MEMBER FUNCTIONS                                                */
	/* ---------------------------------------------------------------------- */

	public:
		// Default constructor
		explicit map(const key_compare & comp = key_compare(),
						const allocator_type & alloc = allocator_type())
						: _tree(comp , alloc)
		{}
			
		// // Range constructor
		// template <class InputIterator>
		// map(InputIterator first, InputIterator last,
		// 		const key_compare & comp = key_compare(),
		// 		const allocator_type & alloc = allocator_type())
		// 		: _comp(comp), _alloc(alloc), _size(0), _root(NULL)
		// {
		// 	_last = _newNode();
		// 	insert(first, last);
		// }
	
		// // Copy constructor
		// map(const map & x) : _comp(x._comp), _alloc(x._alloc), _size(0), _root(NULL)
		// {
		// 	_last = _newNode();
		// 	*this = x;
		// }

		// Destructor
		// virtual ~map()
		// {
		// 	clear();
		// 	_alloc.destroy(_last);
		// 	_alloc.deallocate(_last, 1);
		// }

		// Assignation operator
		// map &	operator=(const map & rhs)
		// {
		// 	if (this != &rhs)
		// 	{
		// 		clear();
		// 		if (rhs._size)
		// 			insert(rhs.begin(), rhs.end());
		// 	}
		// 	return (*this);
		// }

		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		iterator				begin() { return _tree.begin(); }

		const_iterator			begin() const { return _tree.begin(); }

		iterator				end() { return (_tree.end()); }

		const_iterator			end() const { return (_tree.end()); }

		reverse_iterator		rbegin() { return (_tree.rbegin()); }

		const_reverse_iterator	rbegin() const { return (_tree.rbegin()); }

		reverse_iterator		rend() { return (_tree.rend()); }

		const_reverse_iterator	rend() const { return (_tree.rend()); }

		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		bool		empty() const { return (this->_size == 0); }

		size_type	size() const { return (this->_size); }

		// size_type	max_size() const { return (_alloc.max_size()); }


		/* ------------------------------------------------------------------ */
		/* ELEMENT ACCESS                                                     */
		/* ------------------------------------------------------------------ */

		mapped_type &		operator[](const key_type & k)
		{
			
			// node_pointer	tmp = _find_key(k, this->_root);

			// if (tmp)
			// 	return (tmp->data.second);
			// insert(value_type(k, mapped_type()));
			// return (_find_key(k, this->_root)->value.second);
		}

		node_pointer	_find_key(key_type const & key, node_pointer node) const
		{
			// if (!node || node == _last)
			// 	return (NULL);
			// value_type	tmp = ft::make_pair<key_type, mapped_type>(key, mapped_type());
			// if (_is_equal(tmp, node->data))
			// 	return (node);
			// if (this->_comp(key, node->data.first))
			// 	return (_find_key(key, node->left));
			// else if (this->_comp(node->data.first, key))
			// 	return (_find_key(key, node->right));
			// return (NULL);
		}

		bool			_is_equal(value_type const & x, value_type const & y) const
		{
			// return (!_comp(x.first, y.first) && !_comp(y.first, x.first));
		}

		/* ------------------------------------------------------------------ */
		/* MODIFIERS                                                          */
		/* ------------------------------------------------------------------ */

		// insert single element
		ft::pair<iterator, bool>	insert(value_type const & val) // ft::pair<const key_type, mapped_type>
		{
			std::cout << "ntm\n";
			_tree.insert(val);

			return val;
		}

		// insert with hint
		iterator	insert(iterator position, value_type const & val)
		{

		}

		// insert range
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last) 
		{

		}

		// erase position
		void	erase(iterator position)
		{

		}

		// erase key
		size_type	erase(const key_type & k)
		{

		}

		// erase range
		void	erase(iterator first, iterator last)
		{

		}

		void	swap(map & x)
		{
			// std::swap(this->_comp, x._comp);
			// std::swap(this->_alloc, x._alloc);
			// std::swap(this->_size, x._size);
			// std::swap(this->_root, x._root);
			// std::swap(this->_last, x._last);
		}

		void	clear()
		{

		}

		/* ------------------------------------------------------------------ */
		/* OBSERVERS                                                          */
		/* ------------------------------------------------------------------ */

		key_compare		key_comp() const { return (this->_comp); }

		value_compare	value_comp() const { return (value_compare(key_compare())); }


		/* ------------------------------------------------------------------ */
		/* OPERATIONS                                                         */
		/* ------------------------------------------------------------------ */

		iterator	find(key_type const & k)
		{
			// node_pointer	res = _find_key(k, _root);

			// if (res)
			// 	return (iterator(res));
			// return (end());
		}

		const_iterator	find(key_type const & k) const
		{

		}

		size_type	count(key_type const & k) const
		{

		}

		iterator	lower_bound(key_type const & k)
		{

		}

		const_iterator	lower_bound(key_type const & k) const
		{

		}

		iterator	upper_bound(key_type const & k)
		{

		}

		const_iterator	upper_bound(key_type const & k) const
		{

		}

		pair<iterator, iterator>		equal_range(key_type const & k)
		{
			// return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator, const_iterator>		equal_range(key_type const & k) const
		{
			// return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

		/* ------------------------------------------------------------------ */
		/* ALLOCATOR                                                          */
		/* ------------------------------------------------------------------ */

		allocator_type	get_allocator() const { return (this->_alloc); }

	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBER FUNCTIONS                                               */
	/* ---------------------------------------------------------------------- */
	private:

		
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
	return (lhs < rhs || lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
{
	return (lhs > rhs || lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
void	swap(map<Key, T, Compare, Alloc> & x, map<Key, T, Compare, Alloc> & y)
{
	x.swap(y);
}

};

#endif