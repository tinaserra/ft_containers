#ifndef SET_HPP
#define SET_HPP

# include <memory>
# include <stdexcept>
# include "utils/pair.hpp"
# include "utils/iterator_traits.hpp"
# include "utils/reverseIterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/equal.hpp"
# include "RedBlackTree.hpp"

namespace ft {
		
template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set {
	public:
		typedef	T 														key_type;
		typedef T														value_type;
		typedef Compare													key_compare
		typedef Compare													value_compare;
		typedef Alloc													allocator_type;

		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;

		typedef	RedBlackTree<const value_type, value_compare, allocator_type>	tree_type;
		typedef typename tree_type::const_iterator						iterator;
		typedef typename tree_type::const_iterator						const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef std::size_t											size_type;

	/* ---------------------------------------------------------------------- */
	/* PRIVATE MEMBERS                                                        */
	/* ---------------------------------------------------------------------- */

	private:
		tree_type		_redBlackTree;
		key_compare		_key_comp; // _key_comp

	/* ---------------------------------------------------------------------- */
	/* PUBLIC MEMBER FUNCTIONS                                                */
	/* ---------------------------------------------------------------------- */

	public:
		// Default constructor
		explicit set (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
						: _redBlackTree(comp, alloc){}

		// Range constructor
		template <class InputIterator>
		set (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _redBlackTree(comp, alloc)
		{
			while (first != last)
				insert(*first++);
		}

		// Copy constructor
		set (const set& x) : _redBlackTree(x.key_comp(), x.get_allocator())
		{
			const_iterator pos = x.begin();
			while (pos != x.end())
				insert(*pos++);
		}

		// Destructor
		~set() {}

		//Assignation operator
		set& operator= (const set& x)
		{
			if (!empty())
				clear();
			_key_comp = x.key_comp();
			const_iterator pos = x.begin();
			while (pos != x.end())
				insert(*pos++);
			return *this;
		}
		
		/* ------------------------------------------------------------------ */
		/* ITERATORS                                                          */
		/* ------------------------------------------------------------------ */

		iterator				begin() { return (_redBlackTree.begin()); }

		const_iterator			begin() const { return (_redBlackTree.begin()); }

		iterator				end() { return (_redBlackTree.end()); }

		const_iterator			end() const { return (_redBlackTree.end()); }

		reverse_iterator		rbegin() { return (reverse_iterator(_redBlackTree.end())); }

		const_reverse_iterator	rbegin() const { return (const_reverse_iterator(_redBlackTree.end())); }

		reverse_iterator		rend() { return (reverse_iterator(_redBlackTree.begin())); }

		const_reverse_iterator	rend() const { return (const_reverse_iterator(_redBlackTree.begin())); }


		/* ------------------------------------------------------------------ */
		/* CAPACITY                                                           */
		/* ------------------------------------------------------------------ */

		bool		empty() const
		{
			if (size() == 0)
				return (true);
			return (false);
		}

		size_type	size() const { return _redBlackTree.size(); }

		size_type	max_size() const {}

		/* ------------------------------------------------------------------ */
		/* MODIFIERS                                                          */
		/* ------------------------------------------------------------------ */

		pair<iterator,bool> insert (const value_type& val)
		{

		}

		iterator insert (iterator position, const value_type& val)
		{

		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{

		}

		void erase (iterator position)
		{
			_redBlackTree.deleteNode(*(position));
		}

		size_type erase (const key_type& k)
		{

		}

		void erase (iterator first, iterator last)
		{
			while(first != last)
				erase(first++);
		}

		void swap (set& x)
		{
			_redBlackTree.swap(x._redBlackTree);
		}

		void clear()
		{
			_redBlackTree._clear_tree();
		}

		/* ------------------------------------------------------------------ */
		/* OBSERVERS                                                          */
		/* ------------------------------------------------------------------ */

		key_compare key_comp() const{return (_key_comp);}
		value_compare value_comp() const {return (_redBlackTree.getComp());}

		/* ------------------------------------------------------------------ */
		/* OPERATIONS                                                         */
		/* ------------------------------------------------------------------ */

		iterator	find (const key_type & k)
		{
			return _redBlackTree.searchTree(k);
		}

		const_iterator	find (const key_type & k) const
		{
			return _redBlackTree.searchTree(k);
		}

		size_type	count (const key_type & k) const
		{
			if (find(k) == end())
				return (0);
			return (1);
		}

		iterator	lower_bound (const key_type & k) const
		{
			return (_redBlackTree.lower_bound(k));
		}

		iterator	upper_bound (const key_type & k) const
		{
			return (_redBlackTree.upper_bound(k));
		}

		pair<iterator,iterator>	equal_range (const key_type & k) const
		{

		}

		/* ------------------------------------------------------------------ */
		/* ALLOCATOR                                                          */
		/* ------------------------------------------------------------------ */

		allocator_type get_allocator() const {
			return (_redBlackTree.getAllocator());
		}
		
};

/* -------------------------------------------------------------------------- */
/* NON-MEMBER FUNCTION OVERLOADS                                              */
/* -------------------------------------------------------------------------- */

friend bool operator==(const set<T,Compare,Alloc>& lhs,
					const set<T,Compare,Alloc>& rhs)
{
	return (!(lhs < rhs || rhs < lhs));
}

friend bool operator!=(const set<T,Compare,Alloc>& lhs,
	const set<T,Compare,Alloc>& rhs)
{
	return (lhs < rhs || rhs < lhs);
}

friend bool operator<(const set<T,Compare,Alloc>& lhs,
	const set<T,Compare,Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

friend bool operator<=(const set<T,Compare,Alloc>& lhs,
	const set<T,Compare,Alloc>& rhs)
{
	return (!(lhs > rhs));
}

friend bool operator>(const set<T,Compare,Alloc>& lhs,
	const set<T,Compare,Alloc>& rhs)
{
	return (rhs < lhs);
}

friend bool operator>(const set<T,Compare,Alloc>& lhs,
	const set<T,Compare,Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
{
	x.swap(y);
}

}

#endif