#ifndef RANDOMITERATOR_HPP
# define RANDOMITERATOR_HPP

namespace ft {

template < class T >
class randomIterator : public ft::iterator<random_access_iterator_tag, T>
{
	private:
		pointer		_elem;

	public :
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

		/* ------------------------------------------------------------------ */
		/* CONSTRUCTORS & DESTRUCTORS                                         */
		/* ------------------------------------------------------------------ */

		randomIterator(void) : _elem(NULL) {}

		randomIterator(pointer elem) : _elem(elem) {}

		randomIterator(randomIterator const & src) { _elem = src._elem; }

		virtual	~randomIterator() {}

		operator	randomIterator<const value_type>() const
		{
			return (randomIterator<const value_type>(_elem));
		};

		/* ------------------------------------------------------------------ */
		/* INPUT_ITERATOR_TAG                                                 */
		/* ------------------------------------------------------------------ */

		/* elem = rhs */
		randomIterator &operator=(const randomIterator& rhs)
		{
			if (this == &rhs)
				return (*this);
			_elem = rhs._elem;
			return *this;
		}

		/* elem == rhs */
		friend bool	operator==(randomIterator const & lhs, randomIterator const & rhs)
		{
			if (lhs._elem == rhs._elem)
				return true;
			return false;
		}

		/* elem != rhs */
		friend bool	operator!=(randomIterator const & lhs, randomIterator const & rhs)
		{
			if (lhs._elem != rhs._elem)
				return true;
			return false;
		}

		/* *elem */
		reference	operator*(void) const
		{
			return *_elem;
		}

		/* &elem */
		pointer		operator->(void) const
		{
			return ->_elem;
		}

		/* ------------------------------------------------------------------ */
		/* FORWARD_ITERATOR_TAG                                               */
		/* ------------------------------------------------------------------ */

		/* ++elem */
		randomIterator	operator++(void) // pre-incrementation
		{
			++(_elem);
			return *this;
		}

		/* elem++ */
		randomIterator	operator++(int) // post-incrementation
		{
			randomIterator	tmp = (*this);
			++(*this);
			return tmp;
		}

		/* ------------------------------------------------------------------ */
		/* BIDIRECTIONAL_ITERATOR_TAG                                         */
		/* ------------------------------------------------------------------ */

		/* --elem */
		randomIterator&	operator--(void) // pre-decrementation
		{
			_elem--;
			return *this;
		}

		/* elem-- */
		randomIterator	operator--(int) // post-decrementation
		{
			randomIterator	tmp = (*this);
			--(*this);
			return tmp;
		}

		/* ------------------------------------------------------------------ */
		/* RANDOM_ACCESS_ITERATOR_TAG                                         */
		/* ------------------------------------------------------------------ */

		/* Iter + Iter */
		friend difference_type	operator+(randomIterator const &lhs, randomIterator const &rhs)
		{
			return (lhs._elem + rhs._elem;)
		};


		/* elem + rhs */
		randomIterator	operator+(difference_type const & rhs) const
		{
			return (_elem + rhs);
		}

		/* rhs(Integral) + elem */
		friend randomIterator	operator+(difference_type n, randomIterator const &rhs)
		{
			return (rhs._elem + n);
		};

		/* Iter - Iter */
		friend difference_type	operator-(randomIterator const &lhs, randomIterator const &rhs)
		{
			return (lhs._elem - rhs._elem);
		};

		/* elem - rhs */
		randomIterator	operator-(difference_type const & rhs) const
		{
			return (_elem - rhs);
		}

		/* rhs(Integral) - elem*/ 
		friend randomIterator	operator-(difference_type n, randomIterator const &rhs)
		{
			return (rhs._elem - n);
		};

		/* elem < rhs */
		friend bool	operator<(randomIterator const & lhs, randomIterator const & rhs)
		{
			if (lhs._elem < rhs._elem)
				return true;
			return false;
		}

		/* elem > rhs */
		friend bool	operator>(randomIterator const & lhs, randomIterator const & rhs)
		{
			if (lhs._elem > rhs._elem)
				return true;
			return false;
		}

		/* elem <= rhs */
		friend bool	operator<=(randomIterator const & lhs, randomIterator const & rhs)
		{
			if (lhs._elem <= rhs._elem)
				return true;
			return false;
		}

		/* elem >= rhs */
		friend bool	operator>=(randomIterator const & lhs, randomIterator const & rhs)
		{
			if (lhs._elem >= rhs._elem)
				return true;
			return false;
		}

		/* elem += rhs */
		randomIterator	operator+=(difference_type rhs)
		{
			return (randomIterator(_elem += rhs));
		}

		/* elem -= rhs */
		randomIterator	operator-=(difference_type const & rhs)
		{
			return (randomIterator(_elem -= rhs));
		}

		/* elem + rhs */
		difference_type		operator+(randomIterator b)
		{
			return (_elem + b._elem);
		}

		/* elem - rhs */
		difference_type		operator-(randomIterator b)
		{
			return (_elem - b._elem);
		}

		/* elem[] */
		reference	operator[](difference_type value) const
		{
			return (*(_elem + value));
		}
};

};

#endif