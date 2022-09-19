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

namespace ft 
{
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		protected:

		public:
		// types:
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef implementation defined iterator; // See 23.1
			typedef implementation defined const_iterator; // See 23.1
			typedef implementation defined size_type; // See 23.1
			typedef implementation defined difference_type;// See 23.1
			//typedef T 										value_type;
			//typedef Allocator 								allocator_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer
			typedef std::reverse_iterator<iterator> 		reverse_iterator;
			typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;
		
		//constructor
			explicit vector(const Allocator& = Allocator()); //default: Constructs an empty container, with no elements.
			explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator()); //fill: Constructs a container with n elements. Each element is a copy of value.

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& = Allocator()); //range: Constructs a container with as many elements as the range [first,last), 
																							// with each element constructed from its corresponding element in that range, in the same order.

			vector(const vector<T,Allocator>& x); //copy: Constructs a container with a copy of each of the elements in x, in the same order.

			~vector();

			vector<T,Allocator>& operator=(const vector<T,Allocator>& x);

			template <class InputIterator>
				void assign(InputIterator first, InputIterator last);
				void assign(size_type n, const T& u);

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