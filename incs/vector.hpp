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


#include "../utils/utils.hpp"
#include "../utils/myIterator.hpp"
#include "../utils/reverseIterator.hpp"
#include "../utils/enable_if.hpp"

namespace ft 
{
	template <class T, class Allocator = std::allocator<T> >
	class vector 
	{

	// types:
		public: 
			typedef T 													value_type;  	// The template parameter (T)
			typedef Allocator 											allocator_type; // The template parameter (Allocator). Defaults to: allocator<value_type>
			typedef typename allocator_type::reference					reference; 		// a reference to an element stored in a vector. For the default allocator: value_type&
			typedef typename allocator_type::const_reference 			const_reference;// give a reference to a const element stored. For the default allocator: const value_type&
			typedef typename allocator_type::pointer 					pointer;		// a pointer to an element stored. Can be used to modify the value of an element. For the default allocator: value_type*
			typedef typename allocator_type::const_pointer 				const_pointer;  //a const pointer to an element stored. Can't be used to modify the value of an element.
				
			typedef typename allocator_type::size_type					size_type; 
			typedef typename allocator_type::difference_type			difference_type;
			typedef ft::myIterator<value_type> 							iterator; 
			typedef ft::myIterator<const value_type>	 				const_iterator; 
			typedef ft::reveres_iterator<iterator> 						reverse_iterator;  // can read or modify any element in a reversed vector.
			typedef ft::reveres_iterator<const_iterator> 				const_reverse_iterator; //can read any element in a reversed the vector. Can't be used to modify.
		
	// attributes
		private: 
			pointer			_array;
			size_type		_capacity; 
			size_type		_size;		
			allocator_type	_allocator;

		//constructor
		public:
			explicit vector(const Allocator& allocator = Allocator()):	//default: Constructs an empty container, with no elements.
				_array(my_nullptr),
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



			template <class InputIterator>
				vector(InputIterator first, InputIterator last, const Allocator& allocator= Allocator(),
						typename enable_if<!is_integral <InputIterator>::value, InputIterator>::type * = my_nullptr)  //range: Constructs a container with as many elements as the range [first,last),
			{																			// with each element constructed from its corresponding element in that range, in the same order.
				_allocator = allocator;
				_capacity = ft::distance(first, last);
				_array = _allocator.allocate(_capacity);
				for (_size=0; first != last; first++, _size++)
					_array[_size] = *first;
			} 	 
																										
			vector(const vector<T,Allocator>& x): _array(my_nullptr), _capacity(0), _size(0)
			{*this = x;}

			~vector()
			{_allocator.deallocate(_array, _capacity);}

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
				return *this;
			}
			
			
			template <class InputIterator>
				void assign(InputIterator first, InputIterator last, 
							typename enable_if<!is_integral <InputIterator>::value, InputIterator>::type * = my_nullptr)
			{
				_allocator.deallocate(_array, _capacity);
				_capacity = last - first;
				_array = _allocator.allocate(_capacity);
				for (_size=0; first != last; first++, _size++)
					_array[_size] = *first;
			}


			void assign(size_type n, const value_type& value)
			{
				_size = n;
				if (_size <= _capacity)
				{
					for (size_type i = 0; i < _size; i++)
						_array[i] = value;
				}
				else
				{
					_allocator.deallocate(_array, _capacity);
					_capacity = _size;
					_array = _allocator.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_array[i] = value;
				}
			}

			allocator_type get_allocator() const
			{return _allocator;}
			
		// iterators:
			iterator begin()
			{return iterator(_array);}

			const_iterator begin() const
			{	return const_iterator(_array);}

			iterator end()
			{	return iterator(_array + _size);}

			const_iterator end() const
			{	return const_iterator(_array + _size);}

			reverse_iterator rbegin()
			{	return reverse_iterator(end());}

			const_reverse_iterator rbegin() const
			{	return const_reverse_iterator(end());}

			reverse_iterator rend()
			{	return  reverse_iterator(begin());}

			const_reverse_iterator rend() const
			{	return  const_reverse_iterator(end());}

		// capacity:
			size_type			size() const  // The number of elements in the container.
			{	return _size;}
			
			size_type 			max_size() const  // The maximum potential number of elements the container can hold.
			{
				size_type m_s = _allocator.max_size();
				return m_s;
			}

			void resize(size_type n, value_type value = value_type())
			{
				pointer		tmp;
				size_type	capac;
				size_type	i = 0;

				if (n < _size)
				{
					while (_size > n)
						_allocator.destroy(&_array[(_size--) - 1]);
				}
				else if (n <= _capacity)
				{
					while (_size < n)
						_array[_size++] = value;
				}
				else if (n > _capacity)
				{
					tmp = _array;
					capac = _capacity;
					_capacity = (n <= (_capacity * 2) ? _size * 2 : n);
					_array = _allocator.allocate(_capacity);
					while(i < _size)
					{
						_array[i] = tmp[i];
						i++;
					}
					_allocator.deallocate(tmp, capac);
					while (_size < n)
						_array[_size++] = value;
				}
			}

			size_type capacity() const
			{	return _capacity;}			
						
			bool empty() const
			{
				if (!_size)
					return true;
				return false;
			}
			
			void reserve(size_type n)
			{
				pointer		tmp;
				
				if (n > max_size())
					throw (std::length_error("vector::reserve"));
				if(n > _capacity)
				{
					tmp = _array;
					_array = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++)
						_array[i] = tmp[i];
					_allocator.deallocate(tmp,_capacity);
					_capacity = n;
				}
			}
			
		// element access:
			reference operator[](size_type n)
			{	return _array[n];}
			
			const_reference operator[](size_type n) const
			{ return _array[n];}

			const_reference at(size_type n) const
			{
				if (n < _size)
					return _array[n];
				throw(std::out_of_range("vector"));
			}

			reference at(size_type n)
			{
				if (n < _size)
					return _array[n];
				throw(std::out_of_range("vector"));
			}
			
			reference front()
			{	return *_array;}

			const_reference front() const
			{	return *_array;}
			
			reference back()
			{	return _array[_size - 1];}
			
			const_reference back() const
			{	return _array[_size - 1];}

			
			void push_back(const value_type& value)
			{                
				size_type	new_capacity;
	
				if (_size == _capacity)
				{
					new_capacity = (_size > 0) ? (_size * 2) : 1;
					this->reserve(new_capacity);
				}
				_array[_size] = value;
				_size++;
			}

			void pop_back()
			{
				if(_size > 0)
				{
					_allocator.destroy(_array + _size);
					_size--;
				}
			}
			
			iterator insert(iterator position, const value_type& value)
			{
				size_type x = (_size == 0) ? 0 : (position - begin());
				insert(position, 1, value);
				return begin() + x;
			}
			
			void insert(iterator position, size_type n, const value_type& value)
			{
				size_type 	old_size = _size;
				size_type	i = 0;
				size_type	shift = (position - begin());
				pointer		tmp = _array;

				if (n == 0)
					return;
				else if ((max_size() - _size) < n)
					throw (std::length_error("vector::insert (fill)"));
				_size = old_size + n;
				if (_size > _capacity )
				{
					_capacity = (_size  < 2 * old_size) ? 2 * old_size : _size;
					_array = _allocator.allocate(_capacity, (void*)0);
					for(; i < shift; i++)
						_array[i] = tmp[i];					
				}
				for(i = _size - 1; i > shift + n -1; i--)
					_array[i] = tmp[i - n];
				for(i = shift; i < (shift + n); i++ )
					_array[i] = value;
				if (_array != tmp)
					_allocator.deallocate(tmp, _capacity);
			}
			
			template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = my_nullptr)
				{
					size_type 	old_size = _size;
					size_type	i;
					size_type	n = last - first;
					size_type	shift = position - begin();
					pointer		tmp = _array;

					if (n == 0)
						return;
					else if ((max_size() - _size) < n)
						throw (std::length_error("vector::insert (fill)"));
					_size = old_size + n;
					if (_size > _capacity )
					{
						_capacity = (_size  < 2 * old_size) ? 2 * old_size : _size;
						_array = _allocator.allocate(_capacity, (void*)0);
						for(i = 0; i < shift; i++)
							_array[i] = tmp[i];					
					}
					for(i = _size - 1; i > shift + n - 1; i--)
						_array[i] = tmp[i - n];
					for(i = shift; i < (shift + n); i++ )
						_array[i] = *first++;
					if (_array != tmp)
						_allocator.deallocate(tmp, _capacity);
				}
			
			iterator erase(iterator position)
			{
				size_type	pos = position - begin();

				if (pos < _size)
				{
					for(size_type i = pos; i < _size - 1; i++)
						_array[i] = _array[i + 1];
					_allocator.destroy(_array +(_size - 1));
					_size--;	
				}
				else
					std::cout << "vector::position > _size";
				return position;
 			}

			iterator erase(iterator first, iterator last)
			{
				size_type	pos_1 = first - begin();
				size_type	pos_2 = last - begin();
				size_type	n = last - first;

				if (pos_2 >= _size){
					for (size_type i = pos_1; i < _size; i++)
						_allocator.destroy(_array + i);
					_size = pos_1;
				}
				else{
					for (size_type i = pos_2; i <  _size; i++)
						_array[i - n] = _array[i];
					for (size_type i = _size - n; i < _size; i++)
						_allocator.destroy(_array + i);
					_size -= n;
				}
				return first;
			}

			
			void swap(vector& x)
			{
				size_type	size = x._size;
				size_type	capac = x._capacity;
				pointer		arr = x._array;
				allocator_type alloc = x._allocator;

				x._size = this->_size;
				x._capacity = this->_capacity;
				x._array = this->_array;
				x._allocator = this->_allocator;
				this->_size = size;
				this->_capacity = capac;
				this->_array = arr;
				this->_allocator = alloc;
			}
			
			void clear()
			{
				for(size_type i = (_size - 1); i > 0; i--)
					_allocator.destroy(_array+i);
				_size = 0;
			}
	};

		template <class T, class Allocator>
			bool operator==(const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y)
			{
				if (x.size() != y.size())
					return(false);
				else 
					return (equal(x.begin(), x.end(), y.begin()));
			}

		template <class T, class Allocator>
			bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
			{	return !(x == y);}

		template <class T, class Allocator>
			bool operator< (const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y)
			{ return (lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));}

		template <class T, class Allocator>
			bool operator> (const vector<T,Allocator>& x,const vector<T,Allocator>& y)
			{ return x < y;}

		template <class T, class Allocator>
			bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
			{ return !(x < y);}
		
		template <class T, class Allocator>
			bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
			{	return !(x > y);}

		template <class T, class Allocator>
			void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
			{	x.swap(y);}

		template< class T >
			struct is_integral;
}

#endif
