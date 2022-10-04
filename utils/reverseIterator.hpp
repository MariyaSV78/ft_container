/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reveres_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:57:29 by msosnova          #+#    #+#             */
/*   Updated: 2022/10/03 23:57:47 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef reveresIterator_HPP
# define reveresIterator_HPP

#include "iteratorTraits.hpp"
#include "utils.hpp"

namespace ft
{
	//SECTION - REVERSE ITERATOR
	template <class Iterator>
	class reveres_iterator: public 
		std::iterator<typename iterator_traits<_Iterator>::iterator_category,
		      typename iterator_traits<_Iterator>::value_type,
		      typename iterator_traits<_Iterator>::difference_type,
		      typename iterator_traits<_Iterator>::pointer,
              typename iterator_traits<_Iterator>::reference>
	{
		//SECTION - MEMBER TYPES
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type  	difference_type;
			typedef typename iterator_traits<Iterator>::pointer  			pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category  iterator_category;
		protected:
			iterator_type	_current;
			
		//SECTION - MEMBER FUNCTIONS
		public:
			reveres_iterator() : _current(nullpt) {}
			
			explicit reveres_iterator(iterator_type x) : _current(x) {}
			
			template <class Iter>
  			reveres_iterator (const reveres_iterator<Iter>& it) : _current(it._current) {}
			  
			iterator_type base() const{return _current;}
			reference operator*() const
			{
				Iterator tmp = _current;
				return *--tmp;
			}

	/*!*/	pointer operator->() const
			{
				return (&(*(--base())));
			}
			
			reveres_iterator& operator++()
			{
				--_current;
				return (*this);
			}
			reveres_iterator operator++(int)
			{
				reveres_iterator tmp=*this;
				--_current;
				return tmp;
			}

			reveres_iterator& operator--()
			{
				++_current;
				return *this;
			}
			reveres_iterator operator--(int)
			{
				reveres_iterator tmp=*this;
				++_current;
				return tmp;
			}
			
			reveres_iterator operator+ (difference_type n) const
			{return reveres_iterator(_current - n);}
			
			reveres_iterator& operator+= (difference_type n)
			{
				_current -= n;
				return *this;
			}

			reveres_iterator operator- (difference_type n) const
			{return reveres_iterator(_current + n);}

			reveres_iterator& operator-= (difference_type n)
			{
				_current += n;
				return *this;
			}
			reference operator[] (difference_type n) const 
			{return (*this + n);}
	};
	//SECTION - NON MEMBER FUNCTION OVERLOADS
	template <class Iterator>
	bool operator==(const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!=(const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator<(const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator<=(const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	bool operator>(const reveres_iterator<Iterator>& lhs,
					const reveres_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator>=(const reveres_iterator<Iterator>& lhs,
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
