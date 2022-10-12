#ifndef TESTER_HPP
# define TESTER_HPP


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

template<typename T>
void	print_vector(const T& vector)
{
	for(size_t i = 0; i < vector.size(); i++)
	{
		std::cout <<  vector[i] << ", ";
	}
	std::cout << "capacity = " << vector.capacity() << ", size = "<< vector.size() << std::endl; 
}

template<typename T>
void	print_stack(const T& stack)
{
	for(size_t i = 0; i < stack.size(); i++)
	{
		std::cout <<  stack[i] << ", ";
	}
	std::cout << " size = "<< stack.size() << std::endl;

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
		
	}
}


void	is_time(double std_time, double ft_time);

void 	test_stack(void);
void 	test_vector(void);

#endif