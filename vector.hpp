/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:55:13 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/07 00:55:16 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>

namespace ft 
{
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		private: // attributes
			size_type		_capacity; 
			pointer			_begin;
			pointer			_end;
			allocator_type	_allocator;

		public: // types:
			typedef T 													value_type;  	// The template parameter (T)
			typedef Allocator 											allocator_type; // The template parameter (Allocator). Defaults to: allocator<value_type>
			typedef typename Allocator::reference						reference; 		// a reference to an element stored in a vector. For the default allocator: value_type&
			typedef typename Allocator::const_reference 				const_reference;// give a reference to a const element stored. For the default allocator: const value_type&
			typedef typename Allocator::pointer 						pointer;		// a pointer to an element stored. Can be used to modify the value of an element. For the default allocator: value_type*
			typedef typename Allocator::const_pointer 					const_pointer;  //a const pointer to an element stored. Can't be used to modify the value of an element.
				
			typedef std::size_t											size_type; // See 23.1
			typedef std::ptrdiff_t										difference_type;// See 23.1

			typedef std::random_access_iterator<value_type> 			iterator; // See 23.1
			typedef std::random_access_iterator<const value_type>	 	const_iterator; // See 23.1
			typedef std::reverse_iterator<iterator> 					reverse_iterator;  // can read or modify any element in a reversed vector.
			typedef std::reverse_iterator<const_iterator> 				const_reverse_iterator; //can read any element in a reversed the vector. Can't be used to modify.
		
		//constructor
			explicit vector(const Allocator& allocator = Allocator())	//default: Constructs an empty container, with no elements.
			{
				_capacity = u_nullptr;
				_begin = u_nullptr;
				_end = u_nullptr;
				_allocator = allocator;

			}															 
			
			explicit vector(size_type n, const T& value = T(), const Allocator& allocator = Allocator())
			{
				_allocator = allocator;									//fill: Constructs a container with n elements. Each element is a copy of value.
				_start = _allocatot.allocate(n);
				_end = _start;
				while (n--)
				{
					_allocate.construct(_end, value);
					_end++;
				}
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& = Allocator()); //range: Constructs a container with as many elements as the range [first,last), 
																							// with each element constructed from its corresponding element in that range, in the same order.

			vector(const vector<T,Allocator>& x); //copy: Constructs a container with a copy of each of the elements in x, in the same order.

			~vector();

			vector<T,Allocator>& operator=(const vecthttps://github.com/rchallie/ft_containers/blob/master/containers/vector.hpp
			allocator_type get_allocator() const;
		// iterators:
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
		
		// 23.2.4.2 capacity:
			size_type size() const;
			size_type max_size() const;
			void resize(size_type sz, T c = T());
			size_type capacity() const;
			bool empty() const;
			void reserve(size_type n);
			
		// element access:
			reference operator[](size_type n);
			const_reference operator[](size_type n) const;
			const_reference at(size_type n) const;
			reference at(size_type n);
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			
		// 23.2.4.3 modifiers:
			void push_back(const T& x);
			void pop_back();
			iterator insert(iterator position, const T& x);
			void insert(iterator position, size_type n, const T& x);
			template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last);
			iterator erase(iterator position);
			iterator erase(iterator first, iterator last);
			void swap(vector<T,Allocator>&);
			void clear();
	};

		template <class T, class Allocator>
		bool operator==(const vector<T,Allocator>& x,
		const vector<T,Allocator>& y);
		template <class T, class Allocator>
		bool operator< (const vector<T,Allocator>& x,
		const vector<T,Allocator>& y);
		template <class T, class Allocator>
		bool operator!=(const vector<T,Allocator>& x,
		const vector<T,Allocator>& y);
		template <class T, class Allocator>
		bool operator> (const vector<T,Allocator>& x,
		const vector<T,Allocator>& y);
		template <class T, class Allocator>
		bool operator>=(const vector<T,Allocator>& x,
		const vector<T,Allocator>& y);
		template <class T, class Allocator>
		bool operator<=(const vector<T,Allocator>& x,
		const vector<T,Allocator>& y);
		// specialized algorithms:
		template <class T, class Allocator>
		void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}


#endif

https://github.com/Conanyedo/Ft_Containers/blob/master/vector.hpp

https://github.com/rchallie/ft_containers/blob/master/containers/vector.hpp

https://github.com/Conanyedo/Ft_Containers/blob/master/vector.hpp