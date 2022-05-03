/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:26:19 by vserra            #+#    #+#             */
/*   Updated: 2022/05/03 14:28:52 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# define RED false
# define BLACK true

# include <iostream>

template<typename T>
class Node
{
	public:
		typedef Node    node;
		typedef Node*   node_pointer;
		typedef T*      data_pointer;

		bool            color;
		node_pointer    nil_node;
		node_pointer    parent;
		node_pointer    left;
		node_pointer    right;
		data_pointer    data;

		node_pointer    min;
		node_pointer    max;

		// Default constructor
		Node() : color(RED) {}

		// Copy constructor
		Node(const Node &copy) { *this = copy; }

		// Destructor
		~Node() {}

		// Assignation operator
		Node &operator=(const Node &rhs)
		{
			color = rhs.color;
			nil_node = rhs.nil_node;
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			data = rhs.data;
			min = rhs.min;
			max = rhs.max;
			return *this;
		}

	template<typename T>
	std::ostream	&operator<<(std::ostream &stream, const Node<T> & n)
	{
		if (n.data == NULL)
		{
			stream << "Nil node" << std::endl;
			return stream;
		}
		if (n.data != NULL)
			stream << "color " <<  n.color << " " << *n.data;
		return stream;
	}

};

#endif