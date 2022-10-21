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

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "iteratorTraits.hpp"
#include "myIterator.hpp"
#include "utils.hpp"

namespace ft
{
	//SECTION - REVERSE ITERATOR
	template <class Iterator>
	class reveres_iterator
	{
		//SECTION - MEMBER TYPES
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type  	difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer  			pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category  	iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type      	value_type;
		protected:
			iterator_type							_elem;
			
		//SECTION - MEMBER FUNCTIONS
		public:
			reveres_iterator() : _elem() {}
			
			explicit reveres_iterator(iterator_type x) : _elem(x) {}
			
			template <class Iter>
  				reveres_iterator (const reveres_iterator<Iter>& x) : _elem(x.base()) {}
			  
			virtual ~reveres_iterator(){}
			
			iterator_type base() const
			{return _elem;}


			reference operator*() const
			{
				iterator_type tmp = _elem;
				return *--tmp;
			}

			pointer operator->() const
			{
				iterator_type tmp = _elem;
				--tmp;
				return  &(*tmp);
			}
			
			
			reveres_iterator& operator++()
			{
				--_elem;
				return *this;
			}
			
			
			reveres_iterator operator++(int)
			{
				reveres_iterator tmp=*this;
				--_elem;
				return tmp;
			}

			reveres_iterator& operator--()
			{
				++_elem;
				return *this;
			}
			
			reveres_iterator operator--(int)
			{
				reveres_iterator tmp=*this;
				++_elem;
				return tmp;
			}
			
			reveres_iterator operator+ (difference_type n) const
			{return reveres_iterator(_elem - n);}
			
			reveres_iterator& operator+= (difference_type n)
			{
				_elem -= n;
				return *this;
			}

			reveres_iterator operator- (difference_type n) const
			{return reveres_iterator(_elem + n);}

			reveres_iterator& operator-= (difference_type n)
			{
				_elem += n;
				return *this;
			}
			
			reference operator[] (difference_type n) const 
			{return *(*this + n);}
	};
	
	//SECTION - NON MEMBER FUNCTION OVERLOADS
	template <class Iterator>
	bool operator==(const reveres_iterator<Iterator>& x,
					const reveres_iterator<Iterator>& y)
		{return (x.base() == y.base());}

	template <class Iterator_L, class Iterator_R>
        bool operator== (const reveres_iterator<Iterator_L>& x,
                        const reveres_iterator<Iterator_R>& y) 
		{ return (x.base() == y.base());}
			
	template <class Iterator>
		bool operator!=(const reveres_iterator<Iterator>& x,
					const reveres_iterator<Iterator>& y)
		{return (x.base() != y.base());}
			
	template <class Iterator_L, class Iterator_R>
        bool operator!= (const reveres_iterator<Iterator_L>& x,
                        const reveres_iterator<Iterator_R>& y) 
		{ return (x.base() != y.base());}
	

	template <class Iterator>
		bool operator<(const reveres_iterator<Iterator>& lhs,
						const reveres_iterator<Iterator>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

	template <class Iterator>
		bool operator<=(const reveres_iterator<Iterator>& x,
						const reveres_iterator<Iterator>& y)
		{return (x.base() >= y.base());}
	
	template <class Iterator_L, class Iterator_R>
		bool operator<=(const reveres_iterator<Iterator_L>& x,
						const reveres_iterator<Iterator_R>& y)
		{return (x.base() >= y.base());}
	

	template <class Iterator>
		bool operator>(const reveres_iterator<Iterator>& x,
						const reveres_iterator<Iterator>& y)
		{return (x.base() < y.base());}
	
	template <class Iterator_L, class Iterator_R>
		bool operator>(const reveres_iterator<Iterator_L>& x,
						const reveres_iterator<Iterator_R>& y)
		{return (x.base() < y.base());}
		
	
	template <class Iterator>
		bool operator>=(const reveres_iterator<Iterator>& x,
						const reveres_iterator<Iterator>& y)
		{return (x.base() <= y.base());}
	
	template <class Iterator_L, class Iterator_R>
		bool operator>=(const reveres_iterator<Iterator_L>& x,
						const reveres_iterator<Iterator_R>& y)
		{return (x.base() <= y.base());}
	
	
	template <class Iterator>
		reveres_iterator<Iterator> operator+ (
			typename reveres_iterator<Iterator>::difference_type n,
			const reveres_iterator<Iterator>& r_it)
		{return (r_it + n);}
	
	
	template <class Iterator>
		typename reveres_iterator<Iterator>::difference_type operator- (
			const reveres_iterator<Iterator>& x,
			const reveres_iterator<Iterator>& y)
		{return(x.base() - y.base());}

	template <class Iterator_L, class Iterator_R>
        bool operator-(const reveres_iterator<Iterator_L>& x,
                        const reveres_iterator<Iterator_R>& y) 
		{ return (x.base() - y.base()); } 	
}

#endif
