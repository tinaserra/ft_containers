/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:25:59 by vserra            #+#    #+#             */
/*   Updated: 2022/08/08 01:13:01 by tinaserra        ###   ########.fr       */
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

		typedef RedBlackTree<T, Cmp, Alloc>										self;
		typedef T 																value_type;
		typedef size_t															size_type;
		typedef ptrdiff_t														difference_type;

		typedef Node<T>															node_type;
		// typedef ft::rb_tree_node<T>												node_type;
		typedef	Node<T>*														node_pointer;
		// typedef ft::rb_tree_node<T>*											node_pointer;
		typedef typename Alloc::template rebind<NodeTmp<value_type> >::other	tmp_allocator;
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
        node_allocator	_node_alloc;
        data_allocator	_data_alloc;
		Cmp				_key_compare;
		node_type		*_root;
		node_type		*_nil;
		size_type		_size;

	public:

		/* ------------------------------------------------------------------ */
		/* CONSTRUCTORS & DESTRUCTORS                                         */
		/* ------------------------------------------------------------------ */

		// Default constructor
		// RedBlackTree();

		// Fill constructor	
		explicit RedBlackTree(const Cmp compare, const Alloc allocator)
			: _data_alloc(allocator), _key_compare(compare)
		{
			_size = 0;
			_nil = _node_alloc.allocate(1);
			_nil->color = BLACK;
			_nil->data = _data_alloc.allocate(1); // NULL? _data_alloc.allocate(1)
			_nil->nil_node = _nil;
			_nil->parent = 0;
			_nil->left = 0;
			_nil->right = 0;
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
			_data_alloc.deallocate(_nil->data, 1);
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

		// size_type		get_max_size() const { return (_node_alloc.max_size() * sizeof(node_type)) / (sizeof(node_type) - sizeof(void*) + sizeof(value_type)) ; }
		// size_type		get_max_size() const
		// {
		// 	// std::cout << sizeof(NodeTmp<value_type>) << std::endl;
		// 	// std::cout << sizeof(Node<value_type>) << std::endl;
		// 	// std::cout << sizeof(value_type) << std::endl;
		// 	// std::cout << sizeof(void*) << std::endl;
		// 	// std::cout << sizeof(node_pointer) << std::endl;

		// 	return (_node_alloc.max_size() * 40 / 64) * 2.13333333333333333333;
		// }
		
		size_type		get_max_size() const
		{
			tmp_allocator node_size;
			// return (10 * _node_alloc.max_size() / node_size.max_size()) ;
			return node_size.max_size();
		}

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

		void	clean()
		{
			_cleanTree(_root);
			_root = _nil;
			_nil->max = _nil;
			_nil->min = _nil;
			_size = 0;
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
			node_pointer y;
			while (node->parent->color == RED)
			{
				if (node->parent == node->parent->parent->right) // if uncle 
				{
					y = node->parent->parent->left;
					if (y->color == RED)
					{
						node->parent->color = BLACK;
						y->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else
					{ 
						if (node == node->parent->left)
						{
							node = node->parent;
							_rightRotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						_leftRotate(node->parent->parent);
					}
				}
				else // if aunt is red
				{
					y = node->parent->parent->right; // check uncle
					if (y->color == RED)
					{
						node->parent->color = BLACK;
						y->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{    
							node = node->parent;
							_leftRotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						_rightRotate(node->parent->parent);
					}
				}
				if (node == _root)
					break;
			}
			_root->color = BLACK;
			_nil->max = _maximum(_root);
			_nil->min = _minimum(_root);
		}

		// Inserting a node
		pair_type	insertNode(const value_type &val, node_pointer pos)
		{
			node_pointer y = 0;
			node_pointer x;

			if (pos != _nil)
				x = pos;
			else
				x = _root;
			while (x != _nil)
			{
				y = x;
				if (_isEqual(val, *x->data))
				{
					_nil->max = _maximum(_root);
					_nil->min = _minimum(_root);	
					return pair_type(iterator(x), BLACK);
				}
				else if (_key_compare(val, *x->data))
					x = x->left;
				else
					x = x->right;
			}
			node_pointer new_node = _newNode(val);
			new_node->parent = y;
			if (y == 0)
				_root = new_node;
			else if (_key_compare(val, *y->data))
				y->left = new_node;
			else
				y->right = new_node;
			_size++;
			if (new_node->parent == 0)
			{
				new_node->color = BLACK;
				_nil->max = _maximum(_root);
				_nil->min = _minimum(_root);
				return pair_type(iterator(new_node), RED);
			}
			if (new_node->parent->parent == 0)
			{
				_nil->max = _maximum(_root);
				_nil->min = _minimum(_root);
				return pair_type(iterator(new_node), RED);
			}
			_insertFix(new_node);
			return pair_type(iterator(new_node), RED);
		}

		pair_type	insert(const value_type &val)
		{
			return insertNode(val, _root);
		}

		iterator	insertIter(const_iterator it, const value_type & val)
		{
			iterator pos;
			if (it != end() && _key_compare(val, *(it._node->data))
					&& it._node->parent != _nil
					&& _key_compare(*(it._node->parent->data), val))
				pos = insertNode(val, const_cast<typename self::node_pointer>(it._node)).first;
			else
				pos = insertNode(val, _root).first;
			return pos;
		}

		/* SEARCH --------------------------------------------------------------- */
		/* ---------------------------------------------------------------------- */

		node_pointer	searchTree(const value_type & val) const
		{
			node_pointer node = _root;
			while (node != _nil && !_isEqual(val, *node->data))
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

		void _deleteFix(node_pointer node)
		{
			node_pointer tmp_w;
			while (node != _root && node->color == BLACK)
			{
				if (node == node->parent->left)
				{
					tmp_w = node->parent->right;
					if (tmp_w->color == RED)
					{
						tmp_w->color = BLACK;
						node->parent->color = RED;
						_leftRotate(node->parent);
						tmp_w = node->parent->right;
					}
					if (tmp_w->left->color == BLACK && tmp_w->right->color == BLACK)
					{
						tmp_w->color = RED;
						node = node->parent;
					}
					else
					{   
						if (tmp_w->right->color == BLACK)
						{
							tmp_w->left->color = BLACK;
							tmp_w->color = RED;
							_rightRotate(tmp_w);
							tmp_w = node->parent->right;
						}
						tmp_w->color = node->parent->color;
						node->parent->color = BLACK;
						tmp_w->right->color = BLACK;
						_leftRotate(node->parent);
						node = _root;
					}
				}
				else
				{
					tmp_w = node->parent->left;
					if (tmp_w->color == RED)
					{
						tmp_w->color = BLACK;
						node->parent->color = RED;
						_rightRotate(node->parent);
						tmp_w = node->parent->left;
					}
					if (tmp_w->right->color == BLACK && tmp_w->left->color == BLACK)
					{
						tmp_w->color = RED;
						node = node->parent;
					}
					else
					{
						
						if (tmp_w->left->color == BLACK)
						{
							tmp_w->right->color = BLACK;
							tmp_w->color = RED;
							_leftRotate(tmp_w);
							tmp_w = node->parent->left;
						}
						tmp_w->color = node->parent->color;
						node->parent->color = BLACK;
						tmp_w->left->color = BLACK;
						_rightRotate(node->parent);
						node = _root;
					}
				}
			}
			node->color = BLACK;
		}
		
		void	deleteNode(node_pointer node)
		{
			node_pointer tmp_x;
			node_pointer tmp_y;
			if (node == _nil)
				return;
			tmp_y = node;
			bool color = node->color;
			if (node->left == _nil)
			{
				tmp_x = node->right;
				_rbTransplant(node, node->right);
			}
			else if (node->right == _nil)
			{
				tmp_x = node->left;
				_rbTransplant(node, node->left);
			}
			else
			{
				tmp_y = _minimum(node->right);
				color = tmp_y->color;
				tmp_x = tmp_y->right;
				if (tmp_y->parent == node)
					tmp_x->parent = tmp_y;
				else
				{
					_rbTransplant(tmp_y, tmp_y->right);
					tmp_y->right = node->right;
					tmp_y->right->parent = tmp_y;
				}
				_rbTransplant(node, tmp_y);
				tmp_y->left = node->left;
				tmp_y->left->parent = tmp_y;
				tmp_y->color = node->color;
			}
			_cleanNode(node);
			if (color == BLACK)
				_deleteFix(tmp_x);
			_nil->max = _maximum(_root);
			_nil->min = _minimum(_root);
			_nil->parent = _nil;
			_size--;
		}

		/* ---------------------------------------------------------------------- */
		/* PRIVATE MEMBER FUNCTIONS                                               */
		/* ---------------------------------------------------------------------- */

		node_pointer _newNode(const value_type &val) // private
		{
			node_pointer	node = _node_alloc.allocate(1);

			node->parent = 0;
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
			while (res->left != _nil)
				res = res->left;
			return res;
		}
		node_pointer	_maximum(node_pointer node) const
		{
			if (node == _nil)
				return _nil;
			node_pointer res = node;
			while (res->right != _nil)
				res = res->right;
			return res;
		}

		bool	_isEqual(value_type const & x, value_type const & y) const
		{
			return !_key_compare(x, y) && !_key_compare(y, x);
		}

		void	_cleanNode(node_pointer node)
		{
			if (node != _nil)
			{
				_data_alloc.destroy(node->data);
				_data_alloc.deallocate(node->data, 1);
				_node_alloc.deallocate(node, 1);
			}
		}

		void	_cleanTree(node_pointer node)
		{
			if (node != _nil)
			{
				_cleanTree(node->left);
				_cleanTree(node->right);
				_cleanNode(node);
			}
		}

		void _leftRotate(node_pointer x)
		{
			node_pointer y = x->right;
			x->right = y->left;
			if (y->left != _nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == 0)
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
			if (x->parent == 0)
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
			if (node_a->parent == 0)
				_root = node_b;
			else if (node_a->parent->left == node_a)
				node_a->parent->left = node_b;
			else
				node_a->parent->right = node_b;
			node_b->parent = node_a->parent;
		}


		// void	_print(node_pointer node, std::stringstream &buffer, bool is_tail, std::string prefix);
		// void _printHelper(node_pointer node, std::stringstream &buffer, bool is_tail, std::string prefix)
		// {
		// 	if (node->right != _nil)
		// 		this->_printHelper(node->right, buffer, false, std::string(prefix).append(is_tail != 0 ? "|	" : " 	"));
		// 	buffer << prefix <<  (is_tail != 0 ? "└── " : "┌── ");
		// 	if (node->color == BLACK)
		// 			buffer << "\033[31m";
		// 	if (node != _nil)
		// 		buffer << node->data->first << "\033[0m" << std::endl;
		// 	if (node->left != _nil)
		// 		this->_printHelper(node->left, buffer, BLACK, std::string(prefix).append(is_tail != 0 ? "    " : "│   "));
		// }
		void _printHelper(node_pointer root, std::stringstream &buffer, bool last, std::string indent) {
			if (root != _nil) {
			buffer << indent;
			if (last) {
				buffer << "R----";
				indent += "   ";
			} else {
				buffer << "L----";
				indent += "|  ";
			}

			std::string sColor = root->color ? "🔴" : "⚫️";
			buffer << (root->data)->first << "(" << sColor << ")" << std::endl;
			_printHelper(root->left, buffer, false, indent);
			_printHelper(root->right, buffer, true,indent);
			}
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