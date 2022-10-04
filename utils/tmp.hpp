#ifndef reveresIterator_HPP
# define reveresIterator_HPP

#include "iteratorTraits.hpp"
#include "utils.hpp"

namespace ft
{
	//SECTION - REVERSE ITERATOR
	template <class Iterator>
	class reveres_iterator: 
	{
		//SECTION - MEMBER TYPES
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type  	difference_type;
			typedef typename iterator_traits<Iterator>::value_type  		value_type;
			typedef typename iterator_traits<Iterator>::pointer  			pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category  iterator_category;
		private:
			iterator_type	_ptr;
			
		//SECTION - MEMBER FUNCTIONS
		public:
			reveres_iterator() : _ptr(nullpt) {}
			explicit reveres_iterator(iterator_type ptr) : _ptr(ptr) {}
			template <class Iter>
  			reveres_iterator (const reveres_iterator<Iter>& it) : _ptr(it._ptr) {}
			  
			iterator_type base() const{return _ptr;}
			reference operator*() const{return *(--base());}
			reveres_iterator operator+ (difference_type n) const{return reveres_iterator(_ptr - n);}
			reveres_iterator& operator++()
			{
				--_ptr;
				return (*this);
			}
			reveres_iterator operator++(int)
			{
				reveres_iterator tmp(*this);
				--(_ptr);
				return (tmp);
			}
			reveres_iterator& operator+= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			reveres_iterator operator- (difference_type n) const{return reveres_iterator(_ptr + n);}
			reveres_iterator& operator--()
			{
				++_ptr;
				return (*this);
			}
			reveres_iterator operator--(int)
			{
				reveres_iterator tmp(*this);
				++(_ptr);
				return (tmp);
			}
			reveres_iterator& operator-= (difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			pointer operator->() const
			{
				return (&(*(--base())));
			}
			reference operator[] (difference_type n) const {return (*(--base() - n));}
	};
	//SECTION - NON MEMBER FUNCTION OVERLOADS
	template <class Iterator>
	bool operator== (const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!= (const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator< (const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator<= (const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	bool operator> (const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator>= (const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	reveres_iterator<Iterator> operator+ (
				typename reveres_iterator<Iterator>::difference_type n,
				const reveres_iterator<Iterator>& it)
	{
		return (reveres_iterator<Iterator>(it.base() - n));
	}
	template <class Iterator>
	typename reveres_iterator<Iterator>::difference_type operator- (
		const reveres_iterator<Iterator>& lhs,
		const reveres_iterator<Iterator>& rhs)
	{
		return(rhs.base() - lhs.base());
	}
}

#endif
