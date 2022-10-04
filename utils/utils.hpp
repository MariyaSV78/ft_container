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

template <typename T>
	class print_vector
{
	private:
		ft::vector<T>	_ft_vector;
		std::vector<T>	_std_vector;
	public:
		print_vector(){}
		print_vector(ft::vector<T> ft_vector, std::vector<T> std_vector): _ft_vector(ft_vector), _std_vector(std_vector){}
		~print_vector(){}

		void ft_print(ft::vector<T> _ft_vector)
		{
			std::cout << "ft_vector: "; 
			for(size_t i = 0; i < _ft_vector.size(); i++)
			{
				std::cout <<  _ft_vector[i] << ", ";
			}
			std::cout << "capacity = " << _ft_vector.capacity() << ", size = "<< _ft_vector.size() << std::endl;

			std::cout << std::endl;
		}

		void std_print(std::vector<T> _std_vector)
		{
			std::cout << "std_vector: "; 
			for(size_t i = 0; i < _std_vector.size(); i++)
			{
				std::cout <<  _std_vector[i] << ", ";
			}
			std::cout << "capacity = " << _std_vector.capacity() << ", size = "<< _std_vector.size() << std::endl;

			std::cout << std::endl;
		}
};


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
