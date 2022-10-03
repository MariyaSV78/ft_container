/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myIterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:01:08 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/26 16:01:14 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYITERATOR_HPP
# define MYITERATOR_HPP

# include "utils.hpp"	
# include "iteratorTraits.hpp"

namespace ft
{
	template <typename T>
	class myIterator
	{
//MEMBER TYPES
	public:
		typedef T												iterator_type;
		typedef typename iterator_traits<T>::difference_type  	difference_type;
		typedef typename iterator_traits<T>::value_type  		value_type;
		typedef typename iterator_traits<T>::pointer  			pointer;
		typedef typename iterator_traits<T>::reference			reference; 			// Type to represent the difference between two iterators.
		typedef typename iterator_traits<T>::iterator_category  iterator_category;  // Category of the iterator
	private:
		iterator_type	_ptr;
//MEMBER FUNCTIONS
	public:
		myIterator() : _ptr(nullpt) {}									// Default construtor
		
		explicit myIterator(iterator_type ptr) : _ptr(ptr) {}		 	// Constructor from pointer
		
		 // Allow iterator to const_iterator conversion ?
		template <class Iter>
			myIterator (const myIterator<Iter>& it) : _ptr(it.base()) {} // Copy constructor
		
		myIterator &operator=(const myIterator & copy)					// Copy assignation
		{
			if (this == &copy)
				return *this;
			_ptr = copy._ptr;
			return *this;
		}

		virtual ~myIterator(){}

      // Forward iterator requirements
		reference operator*() const // a reference to the rvalue pointed by the random access iterator
		{ return *_ptr;}

		pointer operator->() const
		{ return _ptr;}
		
		myIterator& operator++() 	// preincrement the iterator to point to the next element in memory.
		{	 
			++_ptr;
			return *this;
		}

		myIterator operator++(int)
		{ return myIterator(_ptr++);}

      // Bidirectional iterator requirements
		myIterator& operator--()
		{
			--_ptr;
			return *this;
		}

		myIterator operator--(int)
		{return myIterator(--_ptr);}
 
	// Random access iterator requirements
		reference operator[](difference_type n) const 
		{ return _ptr[n];}

		myIterator& operator+=(difference_type n)
		{
			_ptr += n;
			return *this;
		}

		myIterator operator+(difference_type n) const
		{ return myIterator(_ptr + n);}

		myIterator& operator-=(difference_type n)
		{
			_ptr -= n;
			return *this;
		}
		
		myIterator operator-(difference_type n) const
		{ return myIterator(_ptr - n);}

		iterator_type base() const // a pointer to the element where the iterator point
		{ return _ptr;}
	};

//NON MEMBER FUNCTION OVERLOADS
	template <class Iterator>
		bool operator== (const myIterator<Iterator>& lhs, const myIterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
		bool operator!= (const myIterator<Iterator>& lhs, const myIterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
		bool operator< (const myIterator<Iterator>& lhs, const myIterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	
	template <class Iterator>
		bool operator<= (const myIterator<Iterator>& lhs, const myIterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
		bool operator> (const myIterator<Iterator>& lhs, const myIterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
		bool operator>= (const myIterator<Iterator>& lhs, const myIterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
		myIterator<Iterator> operator+ (typename myIterator<Iterator>::difference_type n,
										const myIterator<Iterator>& it)
	{
		return (myIterator<Iterator>(it.base() + n));
	}
	template <class Iterator>
		typename myIterator<Iterator>::difference_type operator- (const myIterator<Iterator>& lhs,
																const myIterator<Iterator>& rhs)
	{
		return(lhs.base() - rhs.base());
	}
}

#endif
