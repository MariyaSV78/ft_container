/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:55:48 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/07 00:55:52 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "stack.hpp"
#include "vector.hpp"
#include <stack>
#include <vector>
#include <ctime>

typedef struct 			timespec Time;
typedef std::size_t		size_type;


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"


void	ft_print_vector(std::vector<int> std_vector, ft::vector<int> ft_vector)
{
	
	std::cout << "std_vector: "; 
	for(size_type i = 0; i < std_vector.size(); i++)
	{
		std::cout <<  std_vector[i] << ", ";
	}
	std::cout << "capacity = " << std_vector.capacity() << ", size = "<< std_vector.size() << std::endl;

	std::cout << std::endl;
	
	std::cout << "ft_vector: "; 
	for(size_type i = 0; i < ft_vector.size(); i++)
	{
		std::cout <<  ft_vector[i] << ", ";
	}
	std::cout << "capacity = " << ft_vector.capacity() << ", size = "<< ft_vector.size() << std::endl;

	std::cout << std::endl;
}

void	ft_print_vector_(ft::vector<int> std_vector, ft::vector<int> ft_vector)
{
	
	std::cout << "ft_vector_1: "; 
	for(size_type i = 0; i < std_vector.size(); i++)
	{
		std::cout <<  std_vector[i] << ", ";
	}
	std::cout << "capacity = " << std_vector.capacity() << ", size = "<< std_vector.size() << std::endl;

	std::cout << std::endl;
	
	std::cout << "ft_vector_2: "; 
	for(size_type i = 0; i < ft_vector.size(); i++)
	{
		std::cout <<  ft_vector[i] << ", ";
	}
	std::cout << "capacity = " << ft_vector.capacity() << ", size = "<< ft_vector.size() << std::endl;

	std::cout << std::endl;
}

int main()
{
	Time	start, end;
	double	std_time, ft_time; 
	int i;

	ft::stack<int> ft_stack;
	std::stack<int> std_stack;
	
	
	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "stack" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;
	
// push elements


	clock_gettime(CLOCK_MONOTONIC, &start);
	for (i = 0; i < 50; i++)
		std_stack.push(i);
	clock_gettime(CLOCK_MONOTONIC, &end);
	std_time = (end.tv_nsec - start.tv_nsec)* 1e-3; //us


	clock_gettime(CLOCK_MONOTONIC, &start);
	for (i = 0; i < 50; i++)
		ft_stack.push(i);
	clock_gettime(CLOCK_MONOTONIC, &end);
	ft_time = (end.tv_nsec - start.tv_nsec) * 1e-3; //us


	std::cout.fill('.');
	std::cout << "Push " << i << std::setw(61) << std::left <<  " elements";
	if (ft_time < std_time*20)
		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	else 
		std::cout <<  GREEN << "KO" << RESET<< std::endl;
	
	std::cout << "std_time " << std_time << std::endl;
	std::cout << "ft_time " << ft_time << std::endl;

//size stacks

	std::cout << "The size of ft_stack = " << ft_stack.size();
	std::cout << " and std_stack = " << std::setw(26) << std::left << std_stack.size();
	if (ft_stack.size() == std_stack.size())
		std::cout << GREEN << "OK" << RESET<< std::endl;
	else 
		std::cout <<  RED << "KO" << RESET<< std::endl;

//top....

	std::cout << "The top element of ft_stack = " << ft_stack.top();
	std::cout << " and ft_stack = " << std::setw(20) << std::left << std_stack.top();
	if (ft_stack.top() == std_stack.top())
		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	else 
		std::cout <<  RED << "KO" << RESET<< std::endl;

// pop...

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (i = 0; i < 30; i++)
		ft_stack.pop();
	clock_gettime(CLOCK_MONOTONIC, &end);
	ft_time = (end.tv_nsec - start.tv_nsec) * 1e-3; //us

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (i = 0; i < 30; i++)
		std_stack.pop();
	clock_gettime(CLOCK_MONOTONIC, &end);
	std_time = (end.tv_nsec - start.tv_nsec) * 1e-3; //us


	std::cout << "Pop " << i << std::setw(62) << std::left << " elements...";
	if (ft_time < std_time*20)
		std::cout <<  GREEN  << "OK" << RESET << std::endl;
	else 
		std::cout <<  RED  << "KO" << RESET<< std::endl;

	std::cout << "std_time " << std_time << std::endl;
	std::cout << "ft_time " << ft_time << std::endl;

	std::cout << "The size of ft_stack = " << ft_stack.size();
	std::cout << " and std_stack = " << std::setw(26) << std::left << std_stack.size();
	if (ft_stack.size() == std_stack.size())
		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	else 
		std::cout <<  RED  << "KO" << RESET<< std::endl;
	



	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "vector" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;
	
	{
	 std::cout << "Default constructor "<< std::endl;

		ft::vector<int> ft_def_vector;
		std::vector<int> std_def_vector;
		ft_print_vector(std_def_vector, ft_def_vector);
		std::cout << std::endl;	
	}

	{
	 std::cout << "Default constructor pointer "<< std::endl;
		ft::vector<int> *ft_def_ptr_vector = new ft::vector<int>;
		std::vector<int> *std_def_ptr_vector = new std::vector<int>;
		ft_print_vector(*std_def_ptr_vector, *ft_def_ptr_vector);
		std::cout << std::endl;			
	}

    {
 	 std::cout << "Fill constructor "<< std::endl;
	    std::vector<int> std_fill_vector(0);
        ft::vector<int> ft_fill_vector(0);
	
		ft_print_vector(std_fill_vector, ft_fill_vector);
		std::cout << std::endl;	

	}

    {
 	 std::cout << "Fill constructor sized"<< std::endl;
        std::vector<int> stl_fill_vector_sized(9);
        ft::vector<int> ft_fill_vector_sized(9);

		ft_print_vector(stl_fill_vector_sized, ft_fill_vector_sized);
		std::cout << std::endl;	

	}

    {
 	 std::cout << "Fill constructor sized & valued"<< std::endl;
        std::vector<int> std_fill_vector_size_value(9, 42);
        ft::vector<int> ft_fill_vector_size_value(9, 42);

		ft_print_vector(std_fill_vector_size_value, ft_fill_vector_size_value);
		std::cout << std::endl;	

	}

    {
  	 std::cout << "Copy constructor "<< std::endl;
       std::vector<int> std_fill_vector_size_value(9, 42);
        ft::vector<int> ft_fill_vector_size_value(9, 42);

		std::vector<int> std_copy_vector(std_fill_vector_size_value);
		ft::vector<int> ft_copy_vector(ft_fill_vector_size_value);

		ft_print_vector(std_copy_vector, ft_copy_vector);
		std::cout << std::endl;	

	}

    {
   	 std::cout << "Assign operator"<< std::endl;
       std::vector<int> std_fill_vector_size_value(9, 42);
        ft::vector<int> ft_fill_vector_size_value(9, 42);

		std::vector<int> std_assign_vector = std_fill_vector_size_value;
		ft::vector<int> ft_assign_vector = ft_fill_vector_size_value;
		
		ft_print_vector(std_assign_vector, ft_assign_vector);
		std::cout << std::endl;	

		std::cout << "resize(5, 45)" << std::endl;
		std_assign_vector.resize(5, 45);
		ft_assign_vector.resize(5, 45);

		ft_print_vector(std_assign_vector, ft_assign_vector);

		std::cout << "resize(20, 45)" << std::endl;
		std_assign_vector.resize(20, 45);
		ft_assign_vector.resize(20, 45);

		ft_print_vector(std_assign_vector, ft_assign_vector);
		

		// std::cout << "reserve (100)" << std::endl;
		// try
		// {
		// 	std_assign_vector.reserve(100);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cout << e.what() << '\n';
		// }
		// try
		// {
		// 	ft_assign_vector.reserve(100);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cout << e.what() << '\n';
		// }
		
		ft_print_vector(std_assign_vector, ft_assign_vector);

		std::cout << "reserve (10)" << std::endl;
		std_assign_vector.reserve(10);
		ft_assign_vector.reserve(10);

		ft_print_vector(std_assign_vector, ft_assign_vector);
		
		
		std::cout << "push_back(10)" << std::endl;
		std_assign_vector.push_back(10);
		ft_assign_vector.push_back(10);

		ft_print_vector(std_assign_vector, ft_assign_vector);

		std::cout << "pop_back()" << std::endl;
		std_assign_vector.pop_back();
		ft_assign_vector.pop_back();

		ft_print_vector(std_assign_vector, ft_assign_vector);	

		std::cout << "assign(4, 10)" << std::endl;
		std_assign_vector.assign(4,10);
		ft_assign_vector.assign(4,10);

		ft_print_vector(std_assign_vector, ft_assign_vector);	
		
		
		std::cout << "ft_vector.swap(std_vector)" << std::endl;

		ft::vector<int> std_vector(9, 42);
        ft::vector<int> ft_vector(9, 5);
		
		ft_print_vector_(std_vector, ft_vector);
		ft_vector.swap(std_vector);
		ft_print_vector_(std_vector, ft_vector);
	}
		
	{
		std::cout << "insert(position, value)" << std::endl;
		std::vector<int> std_vector(9, 42);
        ft::vector<int> ft_vector(9, 42);
		
		ft_print_vector(std_vector, ft_vector);
		std_vector.insert(std_vector.begin()+5, 3, 0);
//		ft_vector.insert(ft_vector.begin(), 0);
		ft_print_vector(std_vector, ft_vector);


	}

	{
       std::cout << "Assign operator"<< std::endl;
		
		int range_array[] = { 74, 569, -8822, 8515, 5, 7, 67};

    	std::vector<int> std_range_vector(range_array, range_array + 4);
       	ft::vector<int> ft_range_vector(range_array, range_array + 4);
		ft::vector<int> vector;
		ft::vector<int> vector2(std_range_vector.begin(), std_range_vector.end());

		ft_print_vector(std_range_vector, ft_range_vector);
		ft_print_vector(std_range_vector, vector2);



		// ft::myIterator<int> it, it_2;
		// it = ft_range_vector.begin();
		// it_2 = ft_range_vector.end();

		// vector.assign(std_range_vector.begin(), std_range_vector.end());		
		// ft_print_vector(std_range_vector, vector);

	}

	{
	 std::cout << "Iterator constructor "<< std::endl;

		std::vector<int> std_def_vector(3, 5);

		
		ft::vector<int> ft_def_vector(std_def_vector.begin(), std_def_vector.end());
		ft_print_vector(std_def_vector, ft_def_vector);
		std::cout << std::endl;	
	}




	// push elements


	// 	clock_gettime(CLOCK_MONOTONIC, &start);
	// 	for (i = 0; i < 50; i++)
	// 		std_stack.push(i);
	// 	clock_gettime(CLOCK_MONOTONIC, &end);
	// 	std_time = (end.tv_nsec - start.tv_nsec)* 1e-3; //us


	// 	clock_gettime(CLOCK_MONOTONIC, &start);
	// 	for (i = 0; i < 50; i++)
	// 		ft_stack.push(i);
	// 	clock_gettime(CLOCK_MONOTONIC, &end);
	// 	ft_time = (end.tv_nsec - start.tv_nsec) * 1e-3; //us


	// 	std::cout.fill('.');
	// 	std::cout << "Push " << i << std::setw(61) << std::left <<  " elements";
	// 	if (ft_time < std_time*20)
	// 		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	// 	else 
	// 		std::cout <<  GREEN << "KO" << RESET<< std::endl;
		
	// 	std::cout << "std_time " << std_time << std::endl;
	// 	std::cout << "ft_time " << ft_time << std::endl;

	// //size stacks

	// 	std::cout << "The size of ft_stack = " << ft_stack.size();
	// 	std::cout << " and std_stack = " << std::sestd::cout << "length_error"<< std::endl;
	// 		std::cout <<  RED << "KO" << RESET<< std::endl;

	// //top....

	// 	std::cout << "The top element of ft_stack = " << ft_stack.top();
	// 	std::cout << " and ft_stack = " << std::setw(20) << std::left << std_stack.top();
	// 	if (ft_stack.top() == std_stack.top())
	// 		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	// 	else 
	// 		std::cout <<  RED << "KO" << RESET<< std::endl;

	// // pop...

	// 	clock_gettime(CLOCK_MONOTONIC, &start);
	// 	for (i = 0; i < 30; i++)
	// 		ft_stack.pop();
	// 	clock_gettime(CLOCK_MONOTONIC, &end);
	// 	ft_time = (end.tv_nsec - start.tv_nsec) * 1e-3; //us

	// 	clock_gettime(CLOCK_MONOTONIC, &start);
	// 	for (i = 0; i < 30; i++)
	// 		std_stack.pop();
	// 	clock_gettime(CLOCK_MONOTONIC, &end);
	// 	std_time = (end.tv_nsec - start.tv_nsec) * 1e-3; //us


	// 	std::cout << "Pop " << i << std::setw(62) << std::left << " elements...";
	// 	if (ft_time < std_time*20)
	// 		std::cout <<  GREEN  << "OK" << RESET << std::endl;
	// 	else 
	// 		std::cout <<  RED  << "KO" << RESET<< std::endl;

	// 	std::cout << "std_time " << std_time << std::endl;
	// 	std::cout << "ft_time " << ft_time << std::endl;

	// 	std::cout << "The size of ft_stack = " << ft_stack.size();
	// 	std::cout << " and std_stack = " << std::setw(26) << std::left << std_stack.size();
	// 	if (ft_stack.size() == std_stack.size())
	// 		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	// 	else 
	// 		std::cout <<  RED  << "KO" << RESET<< std::endl;
	

}

