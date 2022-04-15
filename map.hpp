/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:11 by vserra            #+#    #+#             */
/*   Updated: 2022/04/15 17:31:35 by vserra           ###   ########.fr       */
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
			_last = _newNode(value_type());
		}
			
		// Range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare & comp = key_compare(),
				const allocator_type & alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _size(0), _root(NULL)
		{
			_last = _newNode(value_type());
			insert(first, last);
		}
	
		// Copy constructor
		map(const map & x) : _comp(x._comp), _alloc(x._alloc), _size(0), _root(NULL)
		{
			_last = _newNode(value_type());
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

		int		_max(int a, int b);

		// Calculate height
		int		_height(node_pointer N)
		{
			if (N == NULL)
				return 0;
			return N->height;
		}

		int		_max(int a, int b)
		{
			return (a > b) ? a : b;
		}

		// New node creation
		node_pointer	_newNode(key_type key)
		{
			node_pointer node = new Node();
			node->key = key;
			node->left = NULL;
			node->right = NULL;
			node->height = 1;
			return (node);
		}

		// Rotate right
		node_pointer _rightRotate(node_pointer y)
		{
			node_pointer x = y->left;
			node_pointer T2 = x->right;
			x->right = y;
			y->left = T2;
			y->height = _max(_height(y->left), _height(y->right)) + 1;
			x->height = _max(_height(x->left), _height(x->right)) + 1;
			return x;
		}

		// Rotate left
		node_pointer _leftRotate(node_pointer x)
		{
			Node *y = x->right;
			Node *T2 = y->left;
			y->left = x;
			x->right = T2;
			x->height = _max(_height(x->left), _height(x->right)) + 1;
			y->height = _max(_height(y->left), _height(y->right)) + 1;
			return y;
		}

		// Get the balance factor of each node
		int _getBalanceFactor(node_pointer N)
		{
			if (N == NULL)
				return 0;
			return _height(N->left) - _height(N->right);
		}

		// Insert a node
		node_pointer	_insertNode(node_pointer node, key_type key)
		{
			// Find the correct postion and insert the node
			if (node == NULL)
				return (_newNode(key));
			if (key < node->key)
				node->left = _insertNode(node->left, key);
			else if (key > node->key)
				node->right = _insertNode(node->right, key);
			else
				return node;

			// Update the balance factor of each node and
			// balance the tree
			node->height = 1 + _max(height(node->left), _height(node->right));
			int balanceFactor = _getBalanceFactor(node);
			if (balanceFactor > 1)
			{
				if (key < node->left->key)
					return _rightRotate(node);
				else if (key > node->left->key)
				{
					node->left = _leftRotate(node->left);
					return _rightRotate(node);
				}
			}
			if (balanceFactor < -1)
			{
				if (key > node->right->key)
					return _leftRotate(node);
				else if (key < node->right->key)
				{
					node->right = _rightRotate(node->right);
					return _leftRotate(node);
				}
			}
			return node;
		}

		// Node with minimum value
		node_pointer _nodeWithMimumValue(node_pointer node)
		{
			node_pointer current = node;
			while (current->left != NULL)
				current = current->left;
			return current;
		}


		// Delete a node
		node_pointer	_deleteNode(node_pointer root, key_type key)
		{
			// Find the node and delete it
			if (root == NULL)
				return root;
			if (key < root->key)
				root->left = _deleteNode(root->left, key);
			else if (key > root->key)
				root->right = _deleteNode(root->right, key);
			else
			{
				if ((root->left == NULL) || (root->right == NULL))
				{
					node_pointer temp = root->left ? root->left : root->right;
					if (temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
						*root = *temp;
					free(temp);
				}
				else 
				{
					node_pointer temp = _nodeWithMimumValue(root->right);
					root->key = temp->key;
					root->right = _deleteNode(root->right, temp->key);
				}
			}
			if (root == NULL)
				return root;

			// Update the balance factor of each node and
			// balance the tree
			root->height = 1 + _max(_height(root->left), _height(root->right));
			int balanceFactor = _getBalanceFactor(root);
			if (balanceFactor > 1)
			{
				if (_getBalanceFactor(root->left) >= 0)
					return _rightRotate(root);
				else
				{
					root->left = _leftRotate(root->left);
					return _rightRotate(root);
				}
			}
			if (balanceFactor < -1)
			{
				if (_getBalanceFactor(root->right) <= 0)
					return _leftRotate(root);
				else
				{
					root->right = _rightRotate(root->right);
					return _leftRotate(root);
				}
			}
			return root;
		}


		void	_printTree(node_pointer root, string indent, bool last)
		{
			if (root != nullptr)
			{
				cout << indent;
				if (last)
				{
					cout << "R----";
					indent += "   ";
				}
				else
				{
					cout << "L----";
					indent += "|  ";
				}
				cout << root->key << endl;
				_printTree(root->left, indent, false);
				_printTree(root->right, indent, true);
			}
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