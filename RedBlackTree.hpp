/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:25:59 by vserra            #+#    #+#             */
/*   Updated: 2022/05/04 13:27:22 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <cstddef>
# include <iostream>
# include <sstream>
# include <functional>
# include "utils/Node.hpp"
# include "utils/pair.hpp"
# include "utils/iterator_traits.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/equal.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/redBlackIterator.hpp"

// namespace ft
// {

template<class T, class Cmp, class Alloc>
class RedBlackTree
{
	public:

		typedef T 																value_type;
		typedef size_t															size_type;
		typedef ptrdiff_t														difference_type;

		typedef Node<T>															node_type;
		// typedef ft::rb_tree_node<T>												node_type;
		typedef	Node<T>															*node_pointer;
		// typedef ft::rb_tree_node<T>*											node_pointer;
		typedef typename Alloc::template rebind<value_type>::other				data_allocator;
        typedef typename Alloc::template rebind<Node<value_type> >::other		node_allocator;
		// typedef typename Alloc::template rebind<node_type>::other				node_allocator;
		typedef ft::redBlackIterator<value_type, node_type>						iterator;
		typedef	ft::redBlackIterator<value_type const, node_type const>			const_iterator;
		typedef ft::reverseIterator<iterator>									reverse_iterator;
		typedef ft::reverseIterator<const_iterator>								const_reverse_iterator;

		typedef ft::pair<iterator, bool>										pair_type;
		typedef ft::pair<iterator, iterator>									pair_range;
		typedef ft::pair<const_iterator, const_iterator>						const_pair_range;

	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBERS                                                        */
	/* ---------------------------------------------------------------------- */

	private:
        node_allocator  _node_alloc;
        data_allocator  _data_alloc;
		Cmp            _key_compare;
		node_pointer	*_root;
		node_pointer	*_nil;
		size_type		_size;

	public:

		/* ------------------------------------------------------------------ */
		/* CONSTRUCTORS & DESTRUCTORS                                         */
		/* ------------------------------------------------------------------ */

		// Default constructor
		RedBlackTree();

		// Fill constructor	
		explicit RedBlackTree(const Cmp compare, const Alloc allocator)
			: _data_alloc(allocator), _key_compare(compare)
		{
			_size = 0;
			_nil = _node_alloc.allocate(1);
			_nil->color = false;
			_nil->data = _data_alloc.allocate(1);
			_nil->nil_node = _nil;
			_nil->parent = _nil;
			_nil->left = _nil;
			_nil->right = _nil;
			_nil->min = _nil;
			_nil->max = _nil;
			_root = _nil;
		}

		// Copy constructor
		RedBlackTree(const RedBlackTree & src);

		// Destructor
		~RedBlackTree()
		{
			if (this->_root != _nil)
				clean();
			_data_alloc.deallocate(_nil->_data, 1);
			_node_alloc.deallocate(_nil, 1);
		}

		// Assignation operator
		RedBlackTree&	operator=(const RedBlackTree & src)
		{
			if (this != &src)
			{
				clean();
				for (const_iterator i = src.begin(); i != src.end(); i++)
					insert(*i);
			}
			return *this;
		}

		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		iterator				begin() { return iterator(this->_minimum(_root)); }

		const_iterator			begin() const { return const_iterator(this->_minimum(_root)); }

		iterator				end() { return iterator(this->_maximum(_nil)); }

		const_iterator			end() const { return const_iterator(this->_maximum(_nil)); }

		reverse_iterator		rbegin() { return reverse_iterator(this->end()); }

		const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->end()); }

		reverse_iterator		rend() { return reverse_iterator(this->begin()); }
		
		const_reverse_iterator	rend() const { return const_reverse_iterator(this->begin()); }

		/* ---------------------------------------------------------------------- */
		/* ACCESS FUNCTIONS                                                       */
		/* ---------------------------------------------------------------------- */

		size_type		get_size() const { return _size; }

		size_type		get_max_size() const { return _node_alloc.max_size() ; }

		data_allocator	get_data_allocator() const { return _data_alloc; }

		Cmp				get_key_compare() const { return _key_compare; }

		bool			empty() const
		{
			if (_size == 0)
				return true;
			return false;
		}

		void			swap(RedBlackTree & x)
		{
			std::swap(_root, x._root);
			std::swap(_nil, x._nil);
			std::swap(_size, x._size);
		}

		iterator		get_lower_bound(const value_type & val)
		{
			iterator it = begin();
			while (it != end())
			{
				if (!_key_compare(*it , val))
					return it;
				it++;
			}
			return it;
		}

		const_iterator	get_lower_bound(const value_type & val) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (!_key_compare(*it , val))
					return it;
				it++;
			}
			return it;
		}

		iterator		get_upper_bound(const value_type & val)
		{
			iterator it = begin();
			while (it != end())
			{
				if (_key_compare(val , *it))
					return it;
				it++;
			}
			return it;
		}

		const_iterator	get_upper_bound(const value_type & val) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (_key_compare(val , *it))
					return it;
				it++;
			}
			return it;
		}

		pair_range		get_equal_range(const value_type & val)
		{
			iterator b = get_lower_bound(val);
			iterator e = get_upper_bound(val);
			return pair_range(b, e);  
		}

		const_pair_range		get_equal_range(const value_type & val) const
		{
			const_iterator b = get_lower_bound(val);
			const_iterator e = get_upper_bound(val);
			return const_pair_range(b, e);  
		}
	
		/* ---------------------------------------------------------------------- */
		/* PUBLIC MEMBER FUNCTIONS                                                */
		/* ---------------------------------------------------------------------- */

		// void	deleteNode(int data)
		// {
		// 	_deleteNodeHelper(this->root, data);
		// }

		void	clean()
		{
			_clean_tree(_root);
			_root = _nil;
			_root->left = _nil;
			_root->right = _nil;
		}

		void	printTree()
		{
			if (get_size() < 1)
				return ;
			std::stringstream buffer;
			this->_printHelper(this->_root, buffer, true, "");
			std::cout << buffer.str();
		}

		/* INSERT --------------------------------------------------------------- */
		/* ---------------------------------------------------------------------- */

		void _insertFix(node_pointer node)
		{
			while (node->parent->color == BLACK)
			{
				if (node->parent == node->parent->parent->left) // if aunt is red
				{
					node_pointer y = node->parent->parent->right; // check uncle
					if (y->color == BLACK)
					{
						node->parent->color = RED;
						y->color = RED;
						node->parent->parent->color = BLACK;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{    
							node = node->parent;
							_leftRotate(node);
						}
						node->parent->color = RED;
						node->parent->parent->color = BLACK;
						_rightRotate(node->parent->parent);
					}
				}
				else // if uncle 
				{
					node_pointer y = node->parent->parent->left;
					if (y->color == BLACK)
					{
						node->parent->color = RED;
						y->color = RED;
						node->parent->parent->color = BLACK;
						node = node->parent->parent;
					}
					else
					{ 
						if (node == node->parent->left)
						{
							node = node->parent;
							_rightRotate(node);
						}
						node->parent->color = RED;
						node->parent->parent->color = BLACK;
						_leftRotate(node->parent->parent);
					}
				}
			}
			_root->color = RED;
			_nil->max = _maximum(_root);
			_nil->min = _minimum(_root);
		}

		// Inserting a node
		pair_type	insert(value_type &val, node_pointer pos)
		{
			node_pointer y = _nil;
			node_pointer x;
			// if (_root == _nil)
			// {
			// 	_root = _newNode(val);
			// 	_nil->_min = _minimum(_root);
			// 	_nil->_max = _maximum(_root);
			// 	_size++;
			// 	return pair_type(iterator(_root), BLACK);
			// }
			if (pos != _nil)
				x = pos;
			else
				x = _root;
			while (x != _nil)
			{
				y = x;
				if (_is_equal(val, *x->data))
					return pair_type(iterator(x), RED);
				else if (_key_compare(val, *x->data))
					x = x->left;
				else
					x = x->right;
			}
			node_pointer new_node = _newNode(val);
			new_node->parent = y;
			if (y == _nil)
				_root = new_node;
			else if (_key_compare(val, *y->data))
				y->left = new_node;
			else
				y->right = new_node;
			new_node->left = _nil;
			new_node->right = _nil;
			new_node->color = BLACK;
			_insertFix(new_node);
			_size++;
			return pair_type(iterator(new_node), BLACK);
		}

		pair_type	insert(const value_type &val)
		{
			return (insert(val, _root));
		}

		iterator	insert_it(const_iterator it, const value_type & val)
		{
			iterator pos;
			if (it != end() && _key_compare(val, *(it._node->data))
			&& it._node->parent != _nil
			&& _key_compare(*(it._node->parent->data), val))
				pos = insert(val, /*const_cast<typename ft::node_pointer>(*/it._node).first;
			else
				pos = insert(val, _root).first;
			return pos;
		}

		/* SEARCH --------------------------------------------------------------- */
		/* ---------------------------------------------------------------------- */

		node_pointer	searchTree(const value_type & val) const
		{
			node_pointer node = _root;
			while (node != _nil && !_is_equal(val, *node->data))
			{
				if (_key_compare(val, *node->data))
					node = node->left;
				else
					node = node->right;
			}
			return node;
		}

		/* DELETE --------------------------------------------------------------- */
		/* ---------------------------------------------------------------------- */

		// void _deleteFix(node_pointer x) {
		// 	node_pointer s;
		// 	while (x != _root && x->color == 0) {
		// 		if (x == x->parent->left)
		// 		{
		// 			s = x->parent->right;
		// 			if (s->color == 1)
		// 			{
		// 				s->color = 0;
		// 				x->parent->color = 1;
		// 				_leftRotate(x->parent);
		// 				s = x->parent->right;
		// 			}

		// 			if (s->left->color == 0 && s->right->color == 0)
		// 			{
		// 				s->color = 1;
		// 				x = x->parent;
		// 			}
		// 			else
		// 			{
		// 				if (s->right->color == 0)
		// 				{
		// 					s->left->color = 0;
		// 					s->color = 1;
		// 					_rightRotate(s);
		// 					s = x->parent->right;
		// 				}
		// 				s->color = x->parent->color;
		// 				x->parent->color = 0;
		// 				s->right->color = 0;
		// 				_leftRotate(x->parent);
		// 				x = _root;
		// 			}
		// 		}
		// 		else
		// 		{
		// 			s = x->parent->left;
		// 			if (s->color == 1)
		// 			{
		// 				s->color = 0;
		// 				x->parent->color = 1;
		// 				_rightRotate(x->parent);
		// 				s = x->parent->left;
		// 			}

		// 			if (s->right->color == 0 && s->right->color == 0) {
		// 				s->color = 1;
		// 				x = x->parent;
		// 			}
		// 			else
		// 			{
		// 				if (s->left->color == 0)
		// 				{
		// 					s->right->color = 0;
		// 					s->color = 1;
		// 					_leftRotate(s);
		// 					s = x->parent->left;
		// 				}

		// 				s->color = x->parent->color;
		// 				x->parent->color = 0;
		// 				s->left->color = 0;
		// 				_rightRotate(x->parent);
		// 				x = _root;
		// 			}
		// 		}
		// 	}
		// 	x->color = 0;
		// }

		// void _deleteNodeHelper(node_pointer node, key_type key)
		// {
		// 	node_pointer z = _nil;
		// 	node_pointer x, y;

		// 	while (node != _nil)
		// 	{
		// 		if (node->key == key)
		// 			z = node;
		// 		if (node->key <= key)
		// 			node = node->right;
		// 		else
		// 			node = node->left;
		// 	}

		// 	if (z == _nil)
		// 	{
		// 		std::cout << "Key not found in the tree" << std::endl;
		// 		return;
		// 	}

		// 	y = z;
		// 	int y_original_color = y->color;
		// 	if (z->left == _nil)
		// 	{
		// 		x = z->right;
		// 		_rbTransplant(z, z->right);
		// 	}
		// 	else if (z->right == _nil)
		// 	{
		// 		x = z->left;
		// 		_rbTransplant(z, z->left);
		// 	}
		// 	else
		// 	{
		// 		y = _minimum(z->right);
		// 		y_original_color = y->color;
		// 		x = y->right;
		// 		if (y->parent == z)
		// 			x->parent = y;
		// 		else
		// 		{
		// 			_rbTransplant(y, y->right);
		// 			y->right = z->right;
		// 			y->right->parent = y;
		// 		}

		// 		_rbTransplant(z, y);
		// 		y->left = z->left;
		// 		y->left->parent = y;
		// 		y->color = z->color;
		// 	}
		// 	delete z;
		// 	if (y_original_color == 0)
		// 		_deleteFix(x);
		// }

		/* ---------------------------------------------------------------------- */
		/* PRIVATE MEMBER FUNCTIONS                                               */
		/* ---------------------------------------------------------------------- */

		node_pointer _newNode(const value_type &val) // private
		{
			node_pointer	node = _node_alloc.allocate(1);

			node->parent = _nil;
			node->nil_node = _nil;
			node->left = _nil;
			node->right = _nil;
			node->color = RED;
			node->data = _data_alloc.allocate(1);
			_data_alloc.construct(node->data, val);
			return node;
		}

		node_pointer	_minimum(node_pointer node) const
		{
			if (node == _nil)
				return _nil;
			node_pointer	res = node;
			while (res->_left != _nil)
				res = res->_left;
			return res;
		}
		node_pointer	_maximum(node_pointer node) const
		{
			if (node == _nil)
				return _nil;
			node_pointer res = node;
			while (res->_right != _nil)
				res = res->_right;
			return res;
		}

		bool	_is_equal(value_type const & x, value_type const & y) const
		{
			return !_key_compare(x, y) && !_key_compare(y, x);
		}

		void	_clean_node(node_pointer node)
		{
			if (node != _nil)
			{
				_data_alloc.destroy(node->data);
				_data_alloc.deallocate(node->data, 1);
				_node_alloc.deallocate(node, 1);
				node = _nil;
			}
		}

		void	_clean_tree(node_pointer node)
		{
			if (node != _nil)
			{
				_clean_tree(node->left);
				_clean_tree(node->right);
				_clean_node(node);
			}
			_size = 0;
		}

		void _leftRotate(node_pointer x)
		{
			node_pointer y = x->right;
			x->right = y->left;
			if (y->left != _nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->_root = y;
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
			if (y->right != _nil)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				this->_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		void _rbTransplant(node_pointer node_a, node_pointer node_b)
		{
			if (node_a->parent == _nil)
				_root = node_b;
			else if (node_a->parent->_left == node_a)
				node_a->parent->_left = node_b;
			else
				node_a->parent->right = node_b;
			node_b->parent = node_a->parent;
		}


		// void	_print(node_pointer node, std::stringstream &buffer, bool is_tail, std::string prefix);
		void _printHelper(node_pointer node, std::stringstream &buffer, bool is_tail, std::string prefix)
		{
			if (node->_right != _nil)
				this->_print(node->_right, buffer, false, std::string(prefix).append(is_tail != 0 ? "|	" : " 	"));
			buffer << prefix <<  (is_tail != 0 ? "└── " : "┌── ");
			if (node->_isRed == true)
					buffer << "\033[31m";
			if (node != _nil)
				buffer << node->_data->first << "\033[0m" << std::endl;
			if (node->_left != _nil)
				this->_print(node->_left, buffer, true, std::string(prefix).append(is_tail != 0 ? "    " : "│   "));
		}


};

// };

#endif





























		// node_pointer _successor(node_pointer x)
		// {
		// 	if (x->right != _nil)
		// 		return _minimum(x->right);

		// 	node_pointer y = x->parent;
		// 	while (y != _nil && x == y->right)
		// 	{
		// 		x = y;
		// 		y = y->parent;
		// 	}
		// 	return y;
		// }

		// node_pointer _predecessor(node_pointer x)
		// {
		// 	if (x->left != _nil)
		// 		return _maximum(x->left);
		// 	node_pointer y = x->parent;
		// 	while (y != _nil && x == y->left)
		// 	{
		// 		x = y;
		// 		y = y->parent;
		// 	}
		// 	return y;
		// }


		// // Preorder
		// void _preOrderHelper(node_pointer node) {
		// 	if (node != _nil) {
		// 		cout << node->key << " ";
		// 		_preOrderHelper(node->left);
		// 		_preOrderHelper(node->right);
		// 	}
		// }

		// // Inorder
		// void _inOrderHelper(node_pointer node) {
		// 	if (node != _nil) {
		// 		_inOrderHelper(node->left);
		// 		cout << node->key << " ";
		// 		_inOrderHelper(node->right);
		// 	}
		// }

		// // Post order
		// void _postOrderHelper(node_pointer node) {
		// 	if (node != _nil) {
		// 		_postOrderHelper(node->left);
		// 		_postOrderHelper(node->right);
		// 		cout << node->key << " ";
		// 	}
		// }

		// void _preorder()
		// {
		// 	_preOrderHelper(this->root);
		// }

		// void _inorder()
		// {
		// 	_inOrderHelper(this->root);
		// }

		// void _postorder()
		// {
		// 	_postOrderHelper(this->root);
		// }