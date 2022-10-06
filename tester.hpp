#ifndef TESTER_HPP
# define TESTER_HPP

#include "tester.hpp"

template<typename T>
void	print_ft_vector(ft::vector<T> ft_vector)
{
	std::cout << "ft_vector: "; 
	for(size_t i = 0; i < ft_vector.size(); i++)
	{
		std::cout <<  ft_vector[i] << ", ";
	}
	std::cout << "capacity = " << ft_vector.capacity() << ", size = "<< ft_vector.size() << std::endl;

	std::cout << std::endl;
}

template<typename T>
void	print_std_vector(std::vector<T> std_vector)
{
	std::cout << "std_vector: "; 
	for(size_t i = 0; i < std_vector.size(); i++)
	{
		std::cout <<  std_vector[i] << ", ";
	}
	std::cout << "capacity = " << std_vector.capacity() << ", size = "<< std_vector.size() << std::endl;

	std::cout << std::endl;
}

void 	test_stack(void);
void 	test_vector(void);

#endif