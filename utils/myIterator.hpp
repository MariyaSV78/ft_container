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

#ifndef MY_ITERATOR_HPP
# define MY_ITERATOR_HPP

# include "utils.hpp"	
# include "iteratorTraits.hpp"

namespace ft
{
	template <typename T>
	class myIterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
//MEMBER TYPES
	public:
                
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
		typedef T*               				pointer;
		typedef T&            					reference;

	private:
		pointer	_ptr; /* Element pointed by the iterator. */
//MEMBER FUNCTIONS
	public:
		myIterator() : _ptr(my_nullptr) {}					// Default construtor
		
		myIterator(pointer ptr) : _ptr(ptr) {}		 	// Constructor from pointer
		
		myIterator (const myIterator& x) : _ptr(x._ptr) {} // Copy constructor
		
		myIterator& operator=(const myIterator& x)
		{												// Copy assignation
			if (this == &x)
				return *this;
			_ptr = x._ptr;
			return *this;
		}

		virtual ~myIterator(){}						

    // Forward iterator requirements
		reference operator*() const // a reference to the rvalue pointed by the random access iterator
		{ return *_ptr;}

		pointer operator->() const //return _ptr; pointer operator->() const 
		{return &(this->operator*());}						
		
		
		myIterator& operator++() 	// preincrement the iterator to point to the next element in memory.
		{	 
			_ptr++;
			return *this;
		}

		myIterator operator++(int) // Postincrement the iterator to point to the next element in memory.
		{ 	
			myIterator tmp(*this);
			operator++();
			return tmp;}

      // Bidirectional iterator requirements
		myIterator& operator--()
		{
			_ptr--;
			return *this;
		}

		myIterator operator--(int)	//return myIterator(--_ptr);
		{
			myIterator	tmp(*this);
			operator--();
			return tmp;
		} 							
 
	// reference to the elements at an arbitrary offset position
		reference operator[](difference_type n) const 
		{ return (*(operator+(n)));} // return _ptr[n];

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

		pointer base() const // a pointer to the element where the iterator point
		{ return _ptr;}

		operator myIterator<const T> () const
        { return (myIterator<const T>(this->_ptr)); }

	};

//NON MEMBER FUNCTION OVERLOADS

 //Check if the pointer of "x" is equal than "y" in the memory.
	template <typename T>
	typename ft::myIterator<T>::difference_type
	operator==(const ft::myIterator<T> x, const ft::myIterator<T> y)
	{return (x.base() == y.base());}

//For iterator == const_iterator .
    template<typename T_L, typename T_R>
    typename ft::myIterator<T_L>::difference_type
    operator==(const ft::myIterator<T_L> x,
              const ft::myIterator<T_R> y)
    {return (x.base() == y.base());}

// if the pointer of "lhs" is different than "rhs" in the memory.
	template <typename T>
    typename ft::myIterator<T>::difference_type
    operator!=(const ft::myIterator<T> x,
              const ft::myIterator<T> y)
    {return (x.base() != y.base());}         

// For iterator != const_iterator
    template<typename T_L, typename T_R>
    typename ft::myIterator<T_L>::difference_type
    operator!=(const ft::myIterator<T_L> x,
              const ft::myIterator<T_R> y)
    {return (x.base() != y.base());}
 
  // if the pointer of "x" is lower than "y" in the memory.
	template <typename T>
    typename ft::myIterator<T>::difference_type
    operator<(const ft::myIterator<T> x,
              const ft::myIterator<T> y)
    {return (x.base() < y.base());}

// For iterator < const_iterator.
    template<typename T_L, typename T_R>
    typename ft::myIterator<T_L>::difference_type
    operator<(const ft::myIterator<T_L> x,
              const ft::myIterator<T_R> y)
    {return (x.base() < y.base());}
  

// if the pointer of "x" is upper than "y" in the memory.
    template <typename T>
    typename ft::myIterator<T>::difference_type
    operator>(const ft::myIterator<T> x,
              const ft::myIterator<T> y)
    { return (x.base() > y.base());}
  
// For iterator > const_iterator
    template<typename T_L, typename T_R>
    typename ft::myIterator<T_L>::difference_type
    operator>(const ft::myIterator<T_L> x,
              const ft::myIterator<T_R> y)
    {return (x.base() > y.base());}
 

// if the pointer of "lhs" is lower or equal than "rhs" in the memory.
    template <typename T>
    typename ft::myIterator<T>::difference_type
    operator<=(const ft::myIterator<T> x,
              const ft::myIterator<T> y)
    {return (x.base() <= y.base());}

// For iterator <= const_iterator 
    template<typename T_L, typename T_R>
    typename ft::myIterator<T_L>::difference_type
    operator<=(const ft::myIterator<T_L> x,
              const ft::myIterator<T_R> y)
    {return (x.base() <= y.base());}
   

// if the pointer of "x" is upper or equal than "y" in the memory.
    template <typename T>
    typename ft::myIterator<T>::difference_type
    operator>=(const ft::myIterator<T> x,
              const ft::myIterator<T> y)
    {return (x.base() >= y.base());}
 
// For iterator >= const_iterator 
    template<typename T_L, typename T_R>
    typename ft::myIterator<T_L>::difference_type
    operator>=(const ft::myIterator<T_L> x,
              const ft::myIterator<T_R> y)
    {return (x.base() >= y.base());}
 
//iterator pointing to n element after x pointed element
	template<typename T>
    ft::myIterator<T> operator+(typename ft::myIterator<T>::difference_type n,
        						typename ft::myIterator<T>& x)
	{return (&(*x) + n);}
	
// difference between the address of two iterators	
	template <typename T>
    typename ft::myIterator<T>::difference_type
    operator-(const ft::myIterator<T> x,
              const ft::myIterator<T> y)
    {return (x.base() - y.base());}
   
    /* For iterator - const_iterator */
    template<typename T_L, typename T_R>
    typename ft::myIterator<T_L>::difference_type
    operator-(const ft::myIterator<T_L> x,
              const ft::myIterator<T_R> y)
    {return (x.base() - y.base());}  
}

#endif