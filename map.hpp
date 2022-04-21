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
			_last = _newNode(); // allocate
			_last->color = 0;
			_root = _last;
		}
			
		// Range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare & comp = key_compare(),
				const allocator_type & alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _size(0), _root(NULL)
		{
			_last = _newNode();
			insert(first, last);
		}
	
		// Copy constructor
		map(const map & x) : _comp(x._comp), _alloc(x._alloc), _size(0), _root(NULL)
		{
			_last = _newNode();
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
			// if (this->_size == 0)
			// 	return (iterator(_last));
			// if (!_root || _root == _last)
			// 	return (_root);
			// node_pointer	res = _root;
			// while (res->left)
			// 	res = res->left;
			// return (res);
		}

		const_iterator			begin() const
		{
			// if (this->_size == 0)
			// 	return (const_iterator(_last));
			// if (!_root || _root == _last)
			// 	return (_root);
			// node_pointer	res = _root;
			// while (res->left)
			// 	res = res->left;
			// return (res);
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
			node_pointer	tmp = _find_key(k, this->_root);

			if (tmp)
				return (tmp->data.second);
			insert(value_type(k, mapped_type()));
			return (_find_key(k, this->_root)->value.second);
		}

		node_pointer	_find_key(key_type const & key, node_pointer node) const
		{
			if (!node || node == _last)
				return (NULL);
			value_type	tmp = ft::make_pair<key_type, mapped_type>(key, mapped_type());
			if (_is_equal(tmp, node->data))
				return (node);
			if (this->_comp(key, node->data.first))
				return (_find_key(key, node->left));
			else if (this->_comp(node->data.first, key))
				return (_find_key(key, node->right));
			return (NULL);
		}

		bool			_is_equal(value_type const & x, value_type const & y) const
		{
			return (!_comp(x.first, y.first) && !_comp(y.first, x.first));
		}

		/* ------------------------------------------------------------------ */
		/* MODIFIERS                                                          */
		/* ------------------------------------------------------------------ */

		// insert single element
		ft::pair<iterator, bool>	insert(value_type const & val) // ft::pair<const key_type, mapped_type>
		{
			_insert(val);
			_printTree();
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
			node_pointer	res = _find_key(k, _root);

			if (res)
				return (iterator(res));
			return (end());
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

		// struct Node {
		// 	int key;
		// 	int data;
		// 	Node *parent;
		// 	Node *left;
		// 	Node *right;
		// 	int color;
		// };

		node_pointer root;
		node_pointer TNULL;

		// constructor ?
		// void _initializeNULLNode(node_pointer node, node_pointer parent)
		// {
		// 	node->key = 0;
		// 	node->parent = parent;
		// 	node->left = nullptr;
		// 	node->right = nullptr;
		// 	node->color = 0;
		// }

		node_pointer _newNode(const value_type &val)
		{
			node_pointer	node = node_allocator.allocate(1);

			node->parent = nullptr;
			node->left = nullptr;
			node->right = nullptr;
			node->color = 1;
			node->data = _alloc.allocate(1);
			_alloc.construct(node->data, val);
			return (node);
		}

		// Preorder
		void _preOrderHelper(node_pointer node) {
			if (node != TNULL) {
			cout << node->key << " ";
			_preOrderHelper(node->left);
			_preOrderHelper(node->right);
			}
		}

		// Inorder
		void _inOrderHelper(node_pointer node) {
			if (node != TNULL) {
			_inOrderHelper(node->left);
			cout << node->key << " ";
			_inOrderHelper(node->right);
			}
		}

		// Post order
		void _postOrderHelper(node_pointer node) {
			if (node != TNULL) {
			_postOrderHelper(node->left);
			_postOrderHelper(node->right);
			cout << node->key << " ";
			}
		}

		node_pointer _searchTreeHelper(node_pointer node, key_type key) {
			if (node == TNULL || key == node->key) {
			return node;
			}

			if (key < node->key) {
			return _searchTreeHelper(node->left, key);
			}
			return _searchTreeHelper(node->right, key);
		}

		// For balancing the tree after deletion
		void _deleteFix(node_pointer x) {
			node_pointer s;
			while (x != root && x->color == 0) {
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == 1)
					{
						s->color = 0;
						x->parent->color = 1;
						_leftRotate(x->parent);
						s = x->parent->right;
					}

					if (s->left->color == 0 && s->right->color == 0)
					{
						s->color = 1;
						x = x->parent;
					}
					else
					{
						if (s->right->color == 0)
						{
							s->left->color = 0;
							s->color = 1;
							_rightRotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = 0;
						s->right->color = 0;
						_leftRotate(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == 1)
					{
						s->color = 0;
						x->parent->color = 1;
						_rightRotate(x->parent);
						s = x->parent->left;
					}

					if (s->right->color == 0 && s->right->color == 0) {
						s->color = 1;
						x = x->parent;
					}
					else
					{
						if (s->left->color == 0)
						{
							s->right->color = 0;
							s->color = 1;
							_leftRotate(s);
							s = x->parent->left;
						}

						s->color = x->parent->color;
						x->parent->color = 0;
						s->left->color = 0;
						_rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = 0;
		}

		void _rbTransplant(node_pointer u, node_pointer v)
		{
			if (u->parent == nullptr)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void _deleteNodeHelper(node_pointer node, key_type key)
		{
			node_pointer z = TNULL;
			node_pointer x, y;

			while (node != TNULL)
			{
				if (node->key == key)
					z = node;
				if (node->key <= key)
					node = node->right;
				else
					node = node->left;
			}

			if (z == TNULL)
			{
				cout << "Key not found in the tree" << endl;
				return;
			}

			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL)
			{
				x = z->right;
				_rbTransplant(z, z->right);
			}
			else if (z->right == TNULL)
			{
				x = z->left;
				_rbTransplant(z, z->left);
			}
			else
			{
				y = _minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					_rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				_rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			delete z;
			if (y_original_color == 0)
				_deleteFix(x);
		}

		// For balancing the tree after insertion
		void _insertFix(node_pointer k)
		{
			node_pointer u;
			while (k->parent->color == 1)
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (u->color == 1)
					{
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							_rightRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						_leftRotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right;

					if (u->color == 1)
					{
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right)
						{
							k = k->parent;
							_leftRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						_rightRotate(k->parent->parent);
					}
				}
				if (k == root)
					break;
			}
			root->color = 0;
		}

		void _printHelper(node_pointer root, std::string indent, bool last)
		{
			if (root != TNULL)
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
				string sColor = root->color ? "RED" : "BLACK";
				cout << root->key << "(" << sColor << ")" << endl;
				_printHelper(root->left, indent, false);
				_printHelper(root->right, indent, true);
			}
		}

		void _preorder()
		{
			_preOrderHelper(this->root);
		}

		void _inorder()
		{
			_inOrderHelper(this->root);
		}

		void _postorder()
		{
			_postOrderHelper(this->root);
		}

		node_pointer _searchTree(int k)
		{
			return _searchTreeHelper(this->root, k);
		}

		node_pointer _minimum(node_pointer node)
		{
			while (node->left != TNULL)
				node = node->left;
			return node;
		}

		node_pointer _maximum(node_pointer node)
		{
			while (node->right != TNULL)
				node = node->right;
			return node;
		}

		node_pointer _successor(node_pointer x)
		{
			if (x->right != TNULL)
				return _minimum(x->right);

			node_pointer y = x->parent;
			while (y != TNULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		node_pointer _predecessor(node_pointer x)
		{
			if (x->left != TNULL)
				return _maximum(x->left);
			node_pointer y = x->parent;
			while (y != TNULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		void _leftRotate(node_pointer x)
		{
			node_pointer y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void _rightRotate(node_pointer x)
		{
			node_pointer y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		// Inserting a node
		void _insert(value_type val)
		{
			node_pointer node = _newNode(); //new
			node->parent = nullptr;
			node->key = val->first;
			node->data = val->second;
			node->left = TNULL;
			node->right = TNULL;
			node->color = 1;

			node_pointer y = nullptr;
			node_pointer x = this->root;

			while (x != TNULL)
			{
				y = x;
				if (node->key < x->key)
					x = x->left;
				else
					x = x->right;
			}

			node->parent = y;
			if (y == nullptr)
				root = node;
			else if (node->key < y->key)
				y->left = node;
			else
				y->right = node;

			if (node->parent == nullptr)
			{
				node->color = 0;
				return;
			}

			if (node->parent->parent == nullptr)
				return;

			_insertFix(node);
		}

		node_pointer _getRoot()
		{
			return this->root;
		}

		void _deleteNode(int data)
		{
			_deleteNodeHelper(this->root, data);
		}

		void _printTree()
		{
			if (root)
				_printHelper(this->root, "", true);
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