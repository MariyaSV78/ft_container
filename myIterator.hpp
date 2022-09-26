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

#include "iteratorTraits.hpp"
#include "./util.hpp"	

namespace ft
{
	//SECTION - ITERATOR
	template <class T>
	class myIterator
	{
		//SECTION - MEMBER TYPES
		public:
			typedef T												iterator_type;
			typedef typename iterator_traits<T>::difference_type  	difference_type;
			typedef typename iterator_traits<T>::value_type  		value_type;
			typedef typename iterator_traits<T>::pointer  			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category  iterator_category;
		private:
			iterator_type	_ptr;
		//SECTION - MEMBER FUNCTIONS
		public:
			myIterator() : _ptr(nullptr) {}
			explicit myIterator(iterator_type ptr) : _ptr(ptr) {}
			template <class Iter>
  			myIterator (const myIterator<Iter>& it) : _ptr(it._ptr) {}

			iterator_type base() const{return _ptr;}
			reference operator*() const{return *_ptr;}
			myIterator operator+ (difference_type n) const{return myIterator(_ptr + n);}
			myIterator& operator++()
			{
				++_ptr;
				return *this;
			}
			myIterator operator++(int)
			{
				myIterator tmp(*this);
				++_ptr;
				return tmp;
			}
			myIterator& operator+= (difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			myIterator operator- (difference_type n) const{return myIterator(_ptr - n);}
			myiterator& operator--()
			{
				--_ptr;
				return (*this);
			}
			myIterator operator--(int)
			{
				myiterator tmp(*this);
				--_ptr;
				return (tmp);
			}
			myIterator& operator-= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			pointer operator->() const
			{
				return (&(*_ptr));
			}
			reference operator[] (difference_type n) const {return (_ptr[n]);}
	};
	//SECTION - NON MEMBER FUNCTION OVERLOADS
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
		bool operator> (const myIterator<Iterator>& lhs, const myiterator<Iterator>& rhs)
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
