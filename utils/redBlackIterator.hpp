/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:03:41 by admin             #+#    #+#             */
/*   Updated: 2022/05/04 15:14:07 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKITERATOR_HPP
# define REDBLACKITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft {

template< typename T, typename node_type >
class redBlackIterator
{
	public:
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef const T&						const_reference;
		typedef const T*						const_pointer;
		typedef	ft::bidirectional_iterator_tag	iterator_categorie;
		typedef ptrdiff_t						difference_type;
		typedef node_type*						node_pointer;

		node_pointer	_node;

		/* ------------------------------------------------------------------ */
		/* CONSTRUCTORS & DESTRUCTORS                                         */
		/* ------------------------------------------------------------------ */
		
		// Default constructor 
		redBlackIterator() : _node() {}

		// Init constructor
		redBlackIterator(node_pointer src) : _node(src) {}

		// Copy constructor
		redBlackIterator(redBlackIterator const & src) : _node(src._node) {}

		// Assignement
		redBlackIterator&	operator=(redBlackIterator const & src)
		{
			if (this != &src)
				this->_node = src._node;
			return *this;
		}

		/* ------------------------------------------------------------------ */
		/* PUBLIC MEMBER FUNCTIONS                                            */
		/* ------------------------------------------------------------------ */

		//to const
		operator	redBlackIterator<value_type const, node_type const>() const
		{
			return redBlackIterator<value_type const, node_type const>(_node);
		}

		reference operator*()
		{
			return *_node->data;
		}

		pointer	operator->()
		{
			return _node->data;
		}

		const_reference operator*() const
		{
			return *_node->data;
		}

		const_pointer	operator->() const
		{
			return _node->data;
		}

		// pre-incrementation
		redBlackIterator&	operator++()
		{
			increment();
			return *this;
		}
		
		// post-incrementation
		redBlackIterator operator++(int)
		{
			redBlackIterator tmp(*this);
			increment();
			return tmp;
		}
		
		// pre-incrementation
		redBlackIterator& operator--()
		{
			decrement();
			return *this;
		}
		
		// post-incrementation
		redBlackIterator operator--(int)
		{
			redBlackIterator tmp(*this);
			decrement();
			return tmp;
		}
		
		bool	operator==(redBlackIterator const & val) const
		{
			return _node == val._node;
		}
		
		bool	operator!=(redBlackIterator const & val) const
		{
			return _node != val._node;
		}

	protected:

		/* ------------------------------------------------------------------ */
		/* PROTECTED MEMBER FUNCTIONS                                         */
		/* ------------------------------------------------------------------ */

		void	increment()
		{
			if (_node == _node->nil_node)
				return ;
			if (_node->right != _node->nil_node)
			{
				_node = _node->right;
				while (_node->left != _node->nil_node)
					_node = _node->left;
			}
			else
			{
				node_pointer tmp = _node->parent;
				while (tmp != _node->nil_node && _node == tmp->right)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				_node = tmp;
			}
		}
		void	decrement()
		{
			if (_node == _node->nil_node)
			{
				_node = _node->nil_node->max;
				return ;
			}
			if (_node->left != _node->nil_node)
			{
				_node = _node->left;
				while (_node->right != _node->nil_node)
					_node = _node->right;
			}
			else
			{
				node_pointer tmp = _node->parent;
				while(tmp != _node->nil_node && _node == tmp->left)
				{
					_node = tmp;
					tmp = tmp->parent;
				}
				_node = tmp;
			}
		}
};


};

#endif