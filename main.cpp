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
	for(size_type i = 0; i < ft_vector.size(); i++)
	{
		std::cout <<  ft_vector[i] << ", ";
	}
	for(size_type i = 0; i < std_vector.size(); i++)
	{
		std::cout <<  std_vector[i] << ", ";
	}

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
	 /* Default constructor */
		ft::vector<int> ft_def_vector;
		std::vector<int> std_def_vector;
		ft_print_vector(std_def_vector, ft_def_vector);
	}

	{
	/* Default constructor pointer */
		ft::vector<int> *ft_def_ptr_vector = new ft::vector<int>;
		std::vector<int> *std_def_ptr_vector = new std::vector<int>;
		ft_print_vector(*std_def_ptr_vector, *ft_def_ptr_vector);


		// for(size_type i = 0; i < ft_def_ptr_vector.size(); i++)
		// {
		// 	std::cout <<  ft_def_ptr_vector[i] << ", ";
		// }
		// for(size_type i = 0; i < std_def_ptr_vector.size(); i++)
		// {
		// 	std::cout <<  std_def_ptr_vector[i] << ", ";
		// }

		std::cout << std::endl;			
	}

	/* Fill constructor */
    {
        std::vector<int> std_fill_vector(0);
        ft::vector<int> ft_fill_vector(0);
	
		ft_print_vector(std_fill_vector, ft_fill_vector);

	
		// for(size_type i = 0; i < std_fill_vector.size(); i++)
		// {
		// 	std::cout <<  std_fill_vector[i] << ", ";
		// }
		// for(size_type i = 0; i < ft_fill_vector.size(); i++)
		// {
		// 	std::cout <<  ft_fill_vector[i] << ", ";
		// }

		// std::cout << std::endl;	

	}

  	/* Fill constructor sized */
    {
        std::vector<int> stl_fill_vector_sized(19);
        ft::vector<int> ft_fill_vector_sized(19);

		ft_print_vector(stl_fill_vector_sized, ft_fill_vector_sized);

	}

	 /* Fill constructor sized & valued */
    {
        std::vector<int> std_fill_vector_size_value(19, 42);
        ft::vector<int> ft_fill_vector_size_value(19, 42);

		ft_print_vector(std_fill_vector_size_value, ft_fill_vector_size_value);

	}

	 /* Copy constructor */
    {
        std::vector<int> std_fill_vector_size_value(19, 42);
        ft::vector<int> ft_fill_vector_size_value(19, 42);

		std::vector<int> std_copy_vector(std_fill_vector_size_value);
		ft::vector<int> ft_copy_vector(ft_fill_vector_size_value);

		ft_print_vector(std_copy_vector, ft_copy_vector);



	}

	/* Assign operator */
    {
        std::vector<int> std_fill_vector_size_value(19, 42);
        ft::vector<int> ft_fill_vector_size_value(19, 42);

		std::vector<int> std_assign_vector = std_fill_vector_size_value;
		ft::vector<int> ft_assign_vector = ft_fill_vector_size_value;
		
		ft_print_vector(std_assign_vector, ft_assign_vector);
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
	// 	std::cout << " and std_stack = " << std::setw(26) << std::left << std_stack.size();
	// 	if (ft_stack.size() == std_stack.size())
	// 		std::cout << GREEN << "OK" << RESET<< std::endl;
	// 	else 
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

