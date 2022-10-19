#ifndef TESTER_HPP
# define TESTER_HPP


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <stack>
#include <vector>
#include <map>
#include <iterator>

typedef struct 			timespec Time;
typedef std::size_t		size_type;

template<typename T>
void	print_vector(const T& vector)
{
	for(size_t i = 0; i < vector.size(); i++)
	{
		std::cout <<  vector[i] << ", ";
	}
	std::cout << "capacity = " << vector.capacity() << ", size = "<< vector.size() << std::endl; 
}


template<class T >
void	print_map(const T& map)
{
	if (map.size() == 0)
		std::cout << "empty map" <<std::endl;
	else{
		for(typename T::const_iterator i = map.begin(); i != map.end(); ++i)
		{
			std::cout << "[" << i->first << ": " <<  i->second << "], ";
		}
		std::cout <<  " size = "<< map.size() << std::endl; 
	}
}

template<typename T>
void	print_stack(T stack)
{
	size_t		size;

	size = stack.size();
	for(size_t i = 0; i < size; i++)
	{
		std::cout <<  stack.top() << ", ";
		stack.pop();
	}
	std::cout <<  "size = "<< size << std::endl; 
}

template<typename T1, typename T2>
void	vector_is_identic(const T1& std_vector, const T2& ft_vector)
{
	int i = 0;
	
	if (std_vector.size() == ft_vector.size())
		std::cout <<  GREEN << "OK" << RESET;
	else
	{
		std::cout <<  RED << "KO" << RESET;
		i = 1;
	}
	if (std_vector.capacity() == ft_vector.capacity())
		std::cout << std::setw(12) <<  GREEN << "OK" << RESET;
	else
	{
		std::cout << std::setw(12) <<  RED << "KO" << RESET;
		i = 2;
	}
	if (std_vector.size() == ft_vector.size())
	{
		for(size_t i = 0; i < std_vector.size(); i++)
			if (std_vector[i] != ft_vector[i])
			{
				std::cout << std::setw(14) <<  RED << "KO" << RESET;
				i = 3;
				break;
			}
	}
	if(i != 3)
		std::cout << std::setw(14) <<  GREEN << "OK" << RESET;
	if (i > 0)
	{
		std::cout << std::endl;
		std::cout << " std.size = " << std_vector.size() << ", std.size = " << ft_vector.size() << std::endl;
		std::cout << " std.capacity = " << std_vector.capacity() << ", ft.capacity = " << ft_vector.capacity() << std::endl;
		print_vector(std_vector);
		print_vector(ft_vector);
		std::cout << i << std::endl;
	}
}

template<typename T1, typename T2>
void	map_is_identic(const T1& std_map, const T2& ft_map)
{
	int i = 0;
	
	if (std_map.size() == ft_map.size())
		std::cout <<  GREEN << "OK" << RESET;
	else
	{
		std::cout <<  RED << "KO" << RESET;
		i = 1;
	}
	if (std_map.size() == ft_map.size())
	{
		typename T1::const_iterator i1 = std_map.begin();
		typename T2::const_iterator i2 = ft_map.begin();
		for(; i1 != std_map.end(); ++i1, ++i2)
		{
			if ((i1->first != i2->first)|| (i1->second != i2->second))
			{
				std::cout << std::setw(13) <<  RED << "KO" << RESET;
				i = 2;
				break;
			}
		}
	}
	if(i != 2)
		std::cout << std::setw(13) <<  GREEN << "OK" << RESET;
	if (i > 0)
	{
		std::cout << std::endl;
		std::cout << " std.size = " << std_map.size() << ", ft.size = " << ft_map.size() << std::endl;
		print_map(std_map);
		print_map(ft_map);
		
	}
}

void	is_time(double std_time, double ft_time);
void 	test_stack(void);
void 	test_vector(void);
void	test_map(void);

#endif