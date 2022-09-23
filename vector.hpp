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
#include <iterator>
#include "./util.hpp"

namespace ft 
{
	template <class T, class Allocator = std::allocator<T> >
	class vector {

		public: // types:
			typedef T 													value_type;  	// The template parameter (T)
			typedef Allocator 											allocator_type; // The template parameter (Allocator). Defaults to: allocator<value_type>
			typedef typename Allocator::reference						reference; 		// a reference to an element stored in a vector. For the default allocator: value_type&
			typedef typename Allocator::const_reference 				const_reference;// give a reference to a const element stored. For the default allocator: const value_type&
			typedef typename Allocator::pointer 						pointer;		// a pointer to an element stored. Can be used to modify the value of an element. For the default allocator: value_type*
			typedef typename Allocator::const_pointer 					const_pointer;  //a const pointer to an element stored. Can't be used to modify the value of an element.
				
			typedef std::size_t											size_type; // See 23.1
			typedef std::ptrdiff_t										difference_type;// See 23.1

			// typedef std::random_access_iterator<value_type> 			iterator; // See 23.1
			// typedef std::random_access_iterator<const value_type>	 	const_iterator; // See 23.1
			
			// typename std::vector<T, Allocator>::iterator 				iterator;
			// typename std::vector<T, Allocator>::const_iterator 			const_iterator;



			// typedef std::reverse_iterator<iterator> 					reverse_iterator;  // can read or modify any element in a reversed vector.
			// typedef std::reverse_iterator<const_iterator> 				const_reverse_iterator; //can read any element in a reversed the vector. Can't be used to modify.
		

		private: // attributes
			pointer			_array;
			size_type		_capacity; 
			size_type		_size;		
			allocator_type	_allocator;

		//constructor
		public:
			explicit vector(const Allocator& allocator = Allocator()):	//default: Constructs an empty container, with no elements.
				_array(nullpt),
				_capacity(0),
				_size(0),
				_allocator(allocator) {}															 
			
			explicit vector(size_type n, const T& value = T(), const Allocator& allocator = Allocator())
			{															//fill: Constructs a container with n elements. Each element is a copy of value.
				_allocator = allocator;									
				_capacity = n;
				_array = _allocator.allocate(_capacity);
				_size = n;
								
				for (size_t i = 0; i < n; i++)
					_array[i] = value;
			}

			// template <class InputIterator>
			// 	vector(InputIterator first, InputIterator last, const Allocator& allocator= Allocator())  //range: Constructs a container with as many elements as the range [first,last),
			// {																							// with each element constructed from its corresponding element in that range, in the same order.
			// 	_allocator = allocator;
			// 	_capacity = last - first;
			// 	_size = _capacity;
			// 	_array = _allocator.allocare(_capacity);
			// 	for (size_type i = 0; i < _capacity; i++)
			// 	{
			// 		_array[i] = *first;
			// 		first++;
			// 	}
			// } 	 
																										

			vector(const vector<T,Allocator>& x): _array(nullpt), _capacity(0), _size(0)
			{
				*this = x;
			}

			~vector()
			{
				_allocator.deallocate(_array, _capacity);
			}


			vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
			{
				if (&x == this)
					return(*this);
				_allocator = x._allocator;
				if (_capacity)
					_allocator.deallocate(_array, _capacity);
				_capacity = x._capacity;
				_size = x._size;
				_array = _allocator.allocate(_capacity);
				
				for (size_type i = 0; i < _capacity; i++)
					_array[i] = x._array[i];
				return (*this);
			}
			
			
			template <class InputIterator>
				void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const T& u);
			allocator_type get_allocator() const;
			
		// iterators:
			// iterator begin()
			// {
			// 	return (iterator(_array));
			// }

			// const_iterator begin() const
			// {
			// 	return(const_iterator(_array));
			// }

			// iterator end()
			// {
			// 	return(iterator(_array + _size));
			// }

			// const_iterator end() const
			// {
			// 	return(const_iterator(_array + _size));
			// }

			// reverse_iterator rbegin()
			// {
			// 	return(reverse_iterator(end()));
			// }
			// const_reverse_iterator rbegin() const
			// {
			// 	return(const_reverse_iterator(end()));
			// }

			// reverse_iterator rend()
			// {
			// 	return(reverse_iterator(begin()));
			// }

			// const_reverse_iterator rend() const
			// {
			// 	return(const_reverse_iterator(end()));
			//}

			size_type			size() const 
			{
				return (_size);
			}
			
			size_type 			max_size() const 
			{
				size_type ret = _allocator.max_size();
				return (ret);
			}

			size_type capacity() const;
			bool empty() const;
			void reserve(size_type n);
			
		// element access:
			reference operator[](size_type n)
			
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
			// iterator insert(iterator position, const T& x);
			// void insert(iterator position, size_type n, const T& x);
			// template <class InputIterator>
			// 	void insert(iterator position, InputIterator first, InputIterator last);
			// iterator erase(iterator position);
			// iterator erase(iterator first, iterator last);
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

// https://github.com/Conanyedo/Ft_Containers/blob/master/vector.hpp

// https://github.com/rchallie/ft_containers/blob/master/containers/vector.hpp

// https://github.com/Aktai0n/ft_containers-42Heilbronn/blob/master/tester/stack_tests.cpp