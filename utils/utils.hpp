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

 # include <iostream>
 # include <string>
 # include <vector>
 # include <stddef.h>
 # include "../vector.hpp"

const class
{
 
	public:
        template<class T>
		operator T*() const { return 0; }

        template<class C, class T>
        operator T C::*() const { return 0; }

	private:
        void operator&() const;
	

}nullpt={};

namespace ft
{
		template <class InputIterator1, class InputIterator2>
			bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
											InputIterator2 first2, InputIterator2 last2)
			{
				while (first1 != last1)
				{
					if ((first2 == last2) || (*first1 > *first2)) 
						return (false);
					else if (*first1 < *first2)
						return (true);
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

/*
    ** Base class for standard binary function objects.
    ** (Doc = http://www.cplusplus.com/reference/functional/binary_function/?kw=binary_function)
    ** (the operator "()", permet to use a class with the same syntax
    ** as a function call).
    */
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
				bool operator()(const T& x, const T& y) const { return (x < y); }
			};

}
#endif
