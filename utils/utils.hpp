/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:44:31 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/30 13:44:35 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

 

const class my_nullptr_t
{
 
	public:
        template<class T>
		operator T*() const { return 0; }

        template<class C, class T>
        operator T C::*() const { return 0; }

	private:
        void operator&() const;
	

}my_nullptr = {};

namespace ft
{
 // Binary function object class whose call returns whether the its first argument compares less than the second (as returned by operator <).   

	template <class Arg1, class Arg2, class Result>
		struct binary_function
		{
			/* The first argument type */
			typedef Arg1 first_argument_type;

			/* The second arguement type */
			typedef Arg2 second_argument_type;

			/* The result type */
			typedef Result result_type;
		};

	template <class T>
		struct less : binary_function<T, T, bool>
		{
			bool operator() (const T& x, const T& y) const 
			{ return (x < y); }
		};
	
	
	template<class T1, class T2>
		struct  pair
		{
			typedef T1	first_type;
			typedef T2	second_type;

			first_type		first;
			second_type		second;

			pair(): first(), second() {} 

			template<class U, class V> 
				pair(const pair<U, V>& p):
				first(p.first),
				second(p.second){}

			pair(const first_type& x, const second_type& y): 
				first(x), 
				second(y) {}

			pair&	operator=(const pair& p)
				{
					if (*this == p)
						return (*this);
					this->first = p.first;
					this->second = p.second;
					return *this;
				}

		}; 

	template <class T1, class T2>
		bool operator==(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{return (x.first == y.first && x.second == y.second);}

	template <class T1, class T2>
		bool operator!=(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{return !(x == y);}

	template <class T1, class T2>
		bool operator<(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));}
	
	template <class T1, class T2>
		bool operator>(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{return (y < x);}

	template <class T1, class T2>
		bool operator>=(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{return !(x < y);}

	template <class T1, class T2>
		bool operator<=(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{return !(y < x);}

	template <class T1, class T2>	
		void swap(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{ 
			ft::pair<T1,T2>		tmp;

			tmp = x;
			x = y;
			y = tmp;
		}

	template <class T1, class T2>
		ft::pair<T1,T2> make_pair(T1 x, T2 y) // const ???
		{return (ft::pair<T1,T2>(x, y));}



//Empty class to identify the category of an "random access iterator"
	class random_access_iterator_tag { };

	class bidirectional_iterator_tag { };

	class forward_iterator_tag { };

	class input_iterator_tag { };

	class output_iterator_tag { };

//Validity of an iterator from is tag. This is the base struct for all is_..._iterator_tag.
		
	template <bool is_valid, typename T>
		struct valid_iterator_tag_res { typedef T type; const static bool value = is_valid; };

//Basic to check if the typename given is an input_iterator. Based on valid_iterator_tag_res.
	template <typename T>
		struct is_input_iterator_tagged : public valid_iterator_tag_res<false, T> { };

//Check is_input_iterator_tagged from ft::random_access_iterator_tag.
	template <>
		struct is_input_iterator_tagged<ft::random_access_iterator_tag>
			: public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

// Check is_input_iterator_tagged from ft::bidirectional_iterator_tag .
	template <>
		struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>
			: public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

// Check is_input_iterator_tagged from ft::forward_iterator_tag.
	template <>
		struct is_input_iterator_tagged<ft::forward_iterator_tag>
			: public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

// Check is_input_iterator_tagged from ft::input_iterator_tag.
	template <>
		struct is_input_iterator_tagged<ft::input_iterator_tag>
			: public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

	
	
	template <typename T>
		struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> { };
    
//Check is_ft_iterator_tagged from ft::random_access_iterator_tag 
    template <>
        struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
            : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

// Check is_ft_iterator_tagged from ft::bidirectional_iterator_tag 
    template <>
        struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>
            : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

//Check is_ft_iterator_tagged from ft::forward_iterator_tag.
    template <>
        struct is_ft_iterator_tagged<ft::forward_iterator_tag>
            : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

//Check is_ft_iterator_tagged from ft::input_iterator_tag.
    template <>
        struct is_ft_iterator_tagged<ft::input_iterator_tag>
            : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

//Check is_ft_iterator_tagged from ft::output_iterator_tag.
    template <>
        struct is_ft_iterator_tagged<ft::output_iterator_tag>
            : public valid_iterator_tag_res<true, ft::output_iterator_tag> { };



    // template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    //     class iterator
    //     {
    //         public:
    //             /* Type of elements pointed. */
    //             typedef T           value_type;

    //             /* Type to represent the difference between two iterators. */
    //             typedef Distance    difference_type;

    //             /* Type to represent a pointer to an element pointed */
    //             typedef Pointer     pointer;

    //             /* Type to represent a reference to an element pointed */
    //             typedef Reference   reference;

    //             /* Category of the iterator. */
    //             typedef Category    iterator_category;
    //     };

    // template <class T>
    //     class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    //     {  
    //         /* Category of the iterator. */
    //         typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
            
    //         /* Type of elements pointed. */
    //         typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            
    //         /* Type to represent the difference between two iterators. */
    //         typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            
    //         /* Type to represent a pointer to an element pointed */
    //         typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
            
    //         /* Type to represent a reference to an element pointed */
    //         typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;
            
    //         private:
    //             /* Element pointed by the iterator. */
    //             pointer _elem;
    //     };


//A base class for standard binary function objects. https://cplusplus.com/reference/functional/binary_function/?kw=binary_function

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
										InputIterator2 first2, InputIterator2 last2)
		{
			while (first1 != last1)
			{
				if ((first2 == last2) || (*first2 < *first1)) 
					return false;
				else if (*first1 < *first2)
					return true;
				++first1;
				++first2;
			}
			return (first2 != last2);
		}

	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
					InputIterator2 first2)
		{
			while (first1 != last1)
			{
				if (*first1 != *first2)
					return (false);
				++first1;
				++first2;
			}
			return (true);
		}

	template <class InputIterator1, class InputIterator2, class Compare>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2,
                                        Compare comp)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || comp(*first2, *first1)) 
					return false;
                else if (comp(*first1, *first2)) 
					return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
    
  
	template <typename T>
		struct BST_Node
		{
			typedef T   value_type;

			value_type 	value;
			BST_Node* 	parent;
			BST_Node* 	left;
			BST_Node* 	right;

			BST_Node ()
			:
				value(),
				parent(my_nullptr),
				left(my_nullptr),
				right(my_nullptr)
			{}

			BST_Node (BST_Node* parent = my_nullptr,
					BST_Node* left = my_nullptr, BST_Node* right = my_nullptr)
			:
				value(),
				parent(parent),
				left(left),
				right(right)
			{}
            
      
 // value defined 
			BST_Node (const value_type& value, BST_Node* parent = my_nullptr,
					BST_Node* left = my_nullptr, BST_Node* right = my_nullptr)
			:
				value(value),
				parent(parent),
				left(left),
				right(right)
			{}

			BST_Node (const BST_Node& copy_node)
			:
				value(copy_node.value),
				parent(copy_node.parent),
				left(copy_node.left),
				right(copy_node.right)
			{}

			BST_Node &operator=(const BST_Node& nd)
			{
				if (nd == *this)
					return (*this);
				
				value = nd.value;
				parent = nd.parent;
				left = nd.left;
				right = nd.right;
				
				return *this;
			}

			virtual ~BST_Node() {}

			bool operator==(const BST_Node& nd)
			{
				if (value == nd.value)
					return (true);
				return (false);
			}
    	};

 // List Node : 
    template <class Data_T>
    	struct Doubly_Linked_Node 
		{
			Doubly_Linked_Node  *prev;
			Doubly_Linked_Node  *next;
			Data_T              data;

		
	// Create a node with next and prev = nullptr
			Doubly_Linked_Node()
			:
				prev(my_nullptr),
				next(my_nullptr)
			{}

	// Create a node with next and prev = nullptr and data is itialized to "value".
			Doubly_Linked_Node(const Data_T& value)
			:
				prev(my_nullptr),
				next(my_nullptr),
				data(value)
			{}

	// Create a node with next = "next" and prev = "prev" data is itialized to "value".

			Doubly_Linked_Node(const Data_T& value,
				Doubly_Linked_Node *prev, Doubly_Linked_Node *next)
			:
				prev(prev),
				next(next),
				data(value)
			{}
		};

}
#endif
