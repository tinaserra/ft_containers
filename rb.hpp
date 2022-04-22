#include "node.hpp"
#include "utils/reverseIterator.hpp"

template<class T, class Cmp, class Alloc>
class RedBlackTree
{
	public:
		typedef T 																value_type;
		typedef size_t															site_type;
		typedef	Node<T>															*node_pointer;
		typedef Node<T>															node_type;
		typedef typename Alloc::template rebind<value_type>::other  			data_allocator;
        typedef typename Alloc::template rebind<Node<value_type> >::other		node_allocator;
		typedef T*																iterator;
		typedef const T*														const_iterator;
		typedef typename ft::reverseIterator<iterator>							reverse_iterator;
		typedef typename ft::reverseIterator<const_iterator>					const_reverse_iterator;

	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBERS                                                        */
	/* ---------------------------------------------------------------------- */

	private:
        node_allocator  _node_alloc;
        data_allocator  _data_alloc;
		Cmp            _key_compare;
		node_pointer	*_root;
		node_pointer	*_nil;

	public:
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

		iterator				begin() { return iterator(this->minimum(_root)); }

		const_iterator			begin() const { return const_iterator(this->minimum(_root)); }

		iterator				end() { return iterator(this->maximum(_nil)); }

		const_iterator			end() const { return const_iterator(this->maximum(_nil)); }

		reverse_iterator		rbegin() { return reverse_iterator(this->end()); }

		const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->end()); }

		reverse_iterator		rend() { return reverse_iterator(this->begin()); }
		
		const_reverse_iterator	rend() const { return const_reverse_iterator(this->begin()); }

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

		node_pointer	minimum(node_pointer node) const
		{
			if (node == _nil)
				return _nil;
			node_pointer	res = node;
			while (res->_left != _nil)
				res = res->_left;
			return res;
		}
		node_pointer	maximum(node_pointer node) const
		{
			if (node == _nil)
				return _nil;
			node_pointer res = node;
			while (res->_right != _nil)
				res = res->_right;
			return res;
		}


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

		// For balancing the tree after deletion
		void _deleteFix(node_pointer x) {
			node_pointer s;
			while (x != _root && x->color == 0) {
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
						x = _root;
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
						x = _root;
					}
				}
			}
			x->color = 0;
		}

		void _rbTransplant(node_pointer u, node_pointer v)
		{
			if (u->parent == nullptr)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

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
				if (k == _root)
					break;
			}
			_root->color = 0;
		}

		// Inserting a node
		void insert(value_type &val)
		{
			node_pointer node = newNode(val); //new
			node->parent = nullptr;
			node->key = val->first;
			node->data = val->second;
			node->left = _nil;
			node->right = _nil;
			node->color = 1;

			node_pointer y = nullptr;
			node_pointer x = this->root;

			while (x != _nil)
			{
				y = x;
				if (node->key < x->key)
					x = x->left;
				else
					x = x->right;
			}

			node->parent = y;
			if (y == nullptr)
				_root = node;
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




		node_pointer _successor(node_pointer x)
		{
			if (x->right != _nil)
				return _minimum(x->right);

			node_pointer y = x->parent;
			while (y != _nil && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		node_pointer _predecessor(node_pointer x)
		{
			if (x->left != _nil)
				return _maximum(x->left);
			node_pointer y = x->parent;
			while (y != _nil && x == y->left)
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
			if (_root)
				_printHelper(this->root, "", true);
		}

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
