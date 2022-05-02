#include "node.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"

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
		typedef T*																iterator;
		typedef const T*														const_iterator;
		typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef ft::pair<iterator, bool>										pair_type;
		typedef ft::pair<iterator, iterator>									pair_range;
		typedef ft::pair<const_iterator, const_iterator>						const_pair_range;
	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBERS                                                        */
	/* ---------------------------------------------------------------------- */

	private:
        node_allocator  _node_alloc;
        data_allocator  _data_alloc;
		Cmp            	_key_compare;
		node_type		*_root;
		node_type		*_nil;
		size_type		_size;

		node_pointer	_minimum(node_pointer node) const {
			if (node == _nil)
				return _nil;
			node_pointer	res = node;
			while (res->left != _nil)
				res = res->left;
			return res;
		}
		node_pointer	_maximum(node_pointer node) const {
			if (node == _nil)
				return _nil;
			node_pointer res = node;
			while (res->right != _nil)
				res = res->right;
			return res;
		}
		bool	_is_equal(value_type const & x, value_type const & y) const {
			return !_key_compare(x, y) && !_key_compare(y, x);
		}

		void _rotate_right(node_type *_x) {
			node_pointer   _y = _x->left;
			_x->left = _y->right;
			if (_y->right != _nil)
				_y->right->parent = _x;
			_y->parent = _x->parent;
			if (_x->parent == _nil)
				_root = _y;
			else if (_x == _x->parent->right)
				_x->parent->right = _y;
			else
				_x->parent->left = _y;
			_y->right = _x;
			_x->parent = _y;
		}

		void _rotate_left(node_type *_x) {
			node_pointer   _y = _x->right;
			_x->right = _y->left;
			if (_y->left != _nil)
				_y->left->parent = _x;
			_y->parent = _x->parent;
			if (_x->parent == _nil)
				_root = _y;
			else if (_x == _x->parent->left)
				_x->parent->left = _y;
			else
				_x->parent->right = _y;
			_y->left = _x;
			_x->parent = _y;
		}

		void _insert_node_fix(node_pointer node) {
			 while (node->parent->red == true)
			{
				if (node->parent == node->parent->parent->left)     // if aunt is red
				{
					node_pointer y = node->parent->parent->right;   // check uncle
					if (y->red == true)
					{
						node->parent->red = false;
						y->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{    
							node = node->parent;
							_rotate_left(node);
						}
						node->parent->red = false;
						node->parent->parent->red = true;
						_rotate_right(node->parent->parent);
					}
				}
				else    // if uncle 
				{
					node_pointer y = node->parent->parent->left;
					if (y->red == true)
					{
						node->parent->red = false;
						y->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					}
					else
					{ 
						if (node == node->parent->left)
						{
							node = node->parent;
							_rotate_right(node);
						}
						node->parent->red = false;
						node->parent->parent->red = true;
						_rotate_left(node->parent->parent);
					}
				}
			}
			_root->red = false;
			_nil->max = _maximum(_root);
			_nil->min = _minimum(_root);
		}

	public:
		// Default constructor
		RedBlackTree() {}

		// Fill constructor	
		explicit RedBlackTree(const Cmp compare, const Alloc allocator) : _data_alloc(allocator), _key_compare(compare) {
			_nil = _node_alloc.allocate(1);
			_nil->red = false;
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
		RedBlackTree(const RedBlackTree & src) {}

		// Destructor
		~RedBlackTree() {}

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

		void printHelper(node_type *root, std::string indent, bool last) {
			if (root != _nil) {
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = root->red ? "\033[31m" : "\033[0m";
				std::cout << sColor << root->data->first << "\033[0m" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		void printTree() {
			if (_root) {
				printHelper(this->_root, "", true);
			}
		}

		size_type	get_size() const { return _size; }

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
		/* PUBLIC MEMBER FUNCTIONS                                                */
		/* ---------------------------------------------------------------------- */

		pair_type	insert_node(const value_type &val, node_pointer pos) {
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
					return pair_type(iterator(x), false);
				else if (_key_compare(val, *x->data))
					x = x->left;
				else
					x = x->right;
			}
			node_pointer new_node = create_node(val);
			new_node->parent = y;
			if (y == _nil)
				_root = new_node;
			else if (_key_compare(val, *y->data))
				y->left = new_node;
			else
				y->right = new_node;
			new_node->left = _nil;
			new_node->right = _nil;
			new_node->red = true;
			_insert_node_fix(new_node);
			_size++;
			return pair_type(iterator(new_node), true);
					
		}

		pair_type	insert(const value_type &val) {
			return (insert_node(val, _root));
		}

		iterator	insert_it(const_iterator it, const value_type & val) {
			iterator pos;
			if (it != _end() && _key_compare(val, *(it._node->data))
			&& it._node->parent != _nil
			&& _key_compare(*(it._node->parent->data), val))
				pos = insert_node(val, const_cast<typename self::node_pointer>(it._node)).first;
			else
				pos = insert_node(val, _root).first;
			return pos;
		}

		node_pointer create_node(const value_type &val)
		{
			node_pointer	node = _node_alloc.allocate(1);

			node->parent = _nil;
			node->left = _nil;
			node->right = _nil;
			node->red = false;
			node->data = _data_alloc.allocate(1);
			_data_alloc.construct(node->data, val);
			return (node);
		}

		data_allocator	get_allocator() const { return _data_alloc; }
		Cmp				get_key_compare() const { return _key_compare; }
	
};
