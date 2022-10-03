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

#ifndef UTIL_HPP
# define UTIL_HPP

 # include <iostream>
 # include <string>
 # include <stddef.h>

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

// template <typename T>
// 	class print_vector(ft::vector<T>)
// {
	
// 	std::cout << "std_vector: "; 
// 	for(size_type i = 0; i < std_vector.size(); i++)
// 	{
// 		std::cout <<  std_vector[i] << ", ";
// 	}
// 	std::cout << "capacity = " << std_vector.capacity() << ", size = "<< std_vector.size() << std::endl;

// 	std::cout << std::endl;
	
// 	std::cout << "ft_vector: "; 
// 	for(size_type i = 0; i < ft_vector.size(); i++)
// 	{
// 		std::cout <<  ft_vector[i] << ", ";
// 	}
// 	std::cout << "capacity = " << ft_vector.capacity() << ", size = "<< ft_vector.size() << std::endl;

// 	std::cout << std::endl;
// }

// void	ft_print_vector_(ft::vector<int> std_vector, ft::vector<int> ft_vector)
// {
	
// 	std::cout << "ft_vector_1: "; 
// 	for(size_type i = 0; i < std_vector.size(); i++)
// 	{
// 		std::cout <<  std_vector[i] << ", ";
// 	}
// 	std::cout << "capacity = " << std_vector.capacity() << ", size = "<< std_vector.size() << std::endl;

// 	std::cout << std::endl;
	
// 	std::cout << "ft_vector_2: "; 
// 	for(size_type i = 0; i < ft_vector.size(); i++)
// 	{
// 		std::cout <<  ft_vector[i] << ", ";
// 	}
// 	std::cout << "capacity = " << ft_vector.capacity() << ", size = "<< ft_vector.size() << std::endl;

// 	std::cout << std::endl;
// }


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

}
#endif
