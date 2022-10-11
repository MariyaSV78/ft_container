#ifndef TESTER_HPP
# define TESTER_HPP

#include "tester.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

template<typename T>
void	print_vector(T vector)
{
	std::cout << "vector: "; 
	for(size_t i = 0; i < vector.size(); i++)
	{
		std::cout <<  vector[i] << ", ";
	}
	std::cout << "capacity = " << vector.capacity() << ", size = "<< vector.size() << std::endl;
}


template<typename T1, typename T2>
void	is_identic(const T1& std_vector, const T2& ft_vector)
{

	if (std_vector.size() == ft_vector.size())
		std::cout << std::setw(42) <<  GREEN << "OK" << RESET;
	else
	{
		std::cout << std::setw(42) <<  RED << "KO" << RESET;
		std::cout << " " << std_vector.size() << " " << ft_vector.size();
	}
	if (std_vector.capacity() == ft_vector.capacity())
		std::cout << std::setw(12) <<  GREEN << "OK" << RESET;
	else
	{
		std::cout << std::setw(12) <<  RED << "KO" << RESET;
		std::cout << " " << std_vector.capacity() << " " << ft_vector.capacity();
	}
	if (std_vector.size() == ft_vector.size())
	{
		for(size_t i = 0; i < std_vector.size(); i++)
			if (std_vector[i] != ft_vector[i])
			{
				std::cout << std::setw(14) <<  RED << "KO" << RESET;
				print_vector(std_vector);
				print_vector(ft_vector);
				break;
			}
		std::cout << std::setw(14) <<  GREEN << "OK" << RESET;
	}
}

void	is_time(double std_time, double ft_time);

void 	test_stack(void);
void 	test_vector(void);

#endif