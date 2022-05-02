#include "Node.hpp" // a mettre dans utils/
#include "utils/reverseIterator.hpp"
#include "utils/redBlackIterator.hpp"

template<class T, class Cmp, class Alloc>
class RedBlackTree
{
	public:

		typedef T 																value_type;
		typedef size_t															size_type;
		typedef	Node<T>															*node_pointer;
		typedef Node<T>															node_type;
		typedef typename Alloc::template rebind<value_type>::other  			data_allocator;
        typedef typename Alloc::template rebind<Node<value_type> >::other		node_allocator;
		typedef ft::redBlackIterator<value_type, node_type>						iterator;
		typedef	ft::redBlackIterator<value_type const, node_type const>			const_iterator;
		// typedef T*															iterator;
		// typedef const T*														const_iterator;
		typedef typename ft::reverseIterator<iterator>							reverse_iterator;
		typedef typename ft::reverseIterator<const_iterator>					const_reverse_iterator;

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

		// Fill constructor	
		explicit RedBlackTree(const Cmp compare, const Alloc allocator);

		// Copy constructor
		RedBlackTree(const RedBlackTree & src);

		// Destructor
		~RedBlackTree();

		// Assignation operator
		RedBlackTree&	operator=(const RedBlackTree & src)
		{
			if (this != &src)
			{
				// _clean();
				// for (const_iterator i = src.rb_begin(); i != src.rb_end(); i++)
				// 	insert(*i);
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

		node_pointer 	getRoot() { return this->_root; }

		size_type		getSize() const { return _size; }

		data_allocator	get_allocator() const { return _data_alloc; }

		Cmp				get_key_compare() const { return _key_compare; }
	
		/* ---------------------------------------------------------------------- */
		/* PUBLIC MEMBER FUNCTIONS                                                */
		/* ---------------------------------------------------------------------- */

		node_pointer newNode(const value_type &val)
		{
			node_pointer	node = _node_alloc.allocate(1);

			node->parent = _nil;
			node->left = _nil;
			node->right = _nil;
			node->color = BLACK;
			node->data = _data_alloc.allocate(1);
			_data_alloc.construct(node->data, val);
			return (node);
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
		node_pointer	__(node_pointer node) const
		{
			if (node == _nil)
				return _nil;
			node_pointer res = node;
			while (res->_right != _nil)
				res = res->_right;
			return res;
		}

		bool	_is_equal(value_type const & x, value_type const & y) const {
			return !_key_compare(x, y) && !_key_compare(y, x);
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


		void _deleteNode(int data)
		{
			_deleteNodeHelper(this->root, data);
		}

		void _printTree()
		{
			if (_root)
				_printHelper(this->root, "", true);
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
		void insert(value_type &val, node_pointer pos)
		{
			node_pointer y = _nil;
			node_pointer x;
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
			node_pointer new_node = newNode(val);
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
			if (it != _end() && _key_compare(val, *(it._node->data))
			&& it._node->parent != _nil
			&& _key_compare(*(it._node->parent->data), val))
				pos = insert(val, const_cast<typename self::node_pointer>(it._node)).first;
			else
				pos = insert(val, _root).first;
			return pos;
		}

		/* SEARCH --------------------------------------------------------------- */
		/* ---------------------------------------------------------------------- */

		// node_pointer _searchTreeHelper(node_pointer node, key_type key) {
		// 	if (node == _nil || key == node->key)
		// 		return node;
		// 	if (key < node->key) 
		// 		return _searchTreeHelper(node->left, key);
		// 	return _searchTreeHelper(node->right, key);
		// }

		// node_pointer _searchTree(int k)
		// {
		// 	return _searchTreeHelper(this->root, k);
		// }

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

		// void _rbTransplant(node_pointer u, node_pointer v)
		// {
		// 	if (u->parent == nullptr)
		// 		_root = v;
		// 	else if (u == u->parent->left)
		// 		u->parent->left = v;
		// 	else
		// 		u->parent->right = v;
		// 	v->parent = u->parent;
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

		void _printHelper(node_pointer root, std::string indent, bool last)
		{
			if (root != _nil)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->key << "(" << sColor << ")" << std::endl;
				_printHelper(root->left, indent, false);
				_printHelper(root->right, indent, true);
			}
		}




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
};
