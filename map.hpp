/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:11 by vserra            #+#    #+#             */
/*   Updated: 2022/04/13 16:28:27 by vserra           ###   ########.fr       */
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
		typedef node<value_type>											node_type;
		typedef node_type*													node_pointer;
		typedef mapIterator<value_type, node_pointer>						iterator;
		typedef mapIterator<const value_type, node_pointer>					const_iterator;
		typedef ft::reverseIterator<iterator>								reverse_iterator;
		typedef ft::reverseIterator<const_iterator>							const_reverse_iterator;
		typedef std::ptrdiff_t												difference_type;
		typedef size_t														size_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator;

	/* ---------------------------------------------------------------------- */
	/* PROTECTED & PRIVATE MEMBERS                                            */
	/* ---------------------------------------------------------------------- */
	protected:
		key_compare		_comp;
		node_allocator	_alloc;
		size_type		_size;
		node_pointer	_root;

	private:
		node_pointer	_last;

	/* ---------------------------------------------------------------------- */
	/* PUBLIC MEMBER FUNCTIONS                                                */
	/* ---------------------------------------------------------------------- */

	public:
		// Default constructor
		explicit map(const key_compare & comp = key_compare(),
						const allocator_type & alloc = allocator_type())
						: _comp(comp), _alloc(alloc), _size(0), _root(NULL)
		{
			_last = _create_node(value_type());
		}
			
		// Range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare & comp = key_compare(),
				const allocator_type & alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _size(0), _root(NULL)
		{
			_last = _create_node(value_type());
			insert(first, last);
		}
	
		// Copy constructor
		map(const map & x) : _comp(x._comp), _alloc(x._alloc), _size(0), _root(NULL)
		{
			_last = _create_node(value_type());
			*this = x;
		}

		// Destructor
		virtual ~map()
		{
			clear();
			_alloc.destroy(_last);
			_alloc.deallocate(_last, 1);
		}

		// Assignation operator
		map &	operator=(const map & rhs)
		{
			if (this != &rhs)
			{
				clear();
				if (rhs._size)
					insert(rhs.begin(), rhs.end());
			}
			return (*this);
		}

		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		iterator				begin()
		{
			if (this->_size == 0)
				return (iterator(_last));
			return (_minimum(_root));
		}

		const_iterator			begin() const
		{
			if (this->_size == 0)
				return (const_iterator(_last));
			return (_minimum(_root));
		}

		iterator				end() { return (iterator(_last)); }

		const_iterator			end() const { return (const_iterator(_last)); }

		reverse_iterator		rbegin() { return (reverse_iterator(end()--)); }

		const_reverse_iterator	rbegin() const { return (const_reverse_iterator(end()--)); }

		reverse_iterator		rend() { return (reverse_iterator(begin())); }

		const_reverse_iterator	rend() const { return (const_reverse_iterator(begin())); }

		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		bool		empty() const { return (this->_size == 0); }

		size_type	size() const { return (this->_size); }

		size_type	max_size() const { return (_alloc.max_size()); }


		/* ------------------------------------------------------------------ */
		/* ELEMENT ACCESS                                                     */
		/* ------------------------------------------------------------------ */

		mapped_type &		operator[](const key_type & k)
		{

		}

		/* ------------------------------------------------------------------ */
		/* MODIFIERS                                                          */
		/* ------------------------------------------------------------------ */

		// insert single element
		ft::pair<iterator, bool>	insert(value_type const & val)
		{

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
			std::swap(this->_comp, x._comp);
			std::swap(this->_alloc, x._alloc);
			std::swap(this->_size, x._size);
			std::swap(this->_root, x._root);
			std::swap(this->_last, x._last);
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
			return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator, const_iterator>		equal_range(key_type const & k) const
		{
			return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

		/* ------------------------------------------------------------------ */
		/* ALLOCATOR                                                          */
		/* ------------------------------------------------------------------ */

		allocator_type	get_allocator() const { return (this->_alloc); }

	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBER FUNCTIONS                                               */
	/* ---------------------------------------------------------------------- */
	private:

		void	_print_tree()
		{

		}

		void	_recursive_print(node_pointer node, std::stringstream & buffer, bool is_tail, std::string prefix)
		{

		}

		node_pointer	_minimum(node_pointer node) const
		{

		}

		node_pointer	_maximum(node_pointer node) const
		{

		}

		bool	is_in_tree(const_iterator pos) const
		{

		}

		node_pointer	_find_key(key_type const & key, node_pointer node) const
		{

		}

		bool			_is_equal(value_type const & x, value_type const & y) const
		{

		}

		node_pointer	_create_node(value_type const & val)
		{

		}

		bool	_insert_node(const value_type &val, node_pointer current)
		{

		}

		bool	_insert_node_root(const value_type &val)
		{

		}

		void	_delete_node(node_pointer node)
		{

		}

		void	_clean_recursive(node_pointer node)
		{

		}

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