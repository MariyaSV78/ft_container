/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:41 by msosnova          #+#    #+#             */
/*   Updated: 2022/10/03 17:04:44 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <iomanip>
#include "stack.hpp"
#include <stack>
#include <ctime>



typedef struct 			timespec Time;
typedef std::size_t		size_type;


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"


void	test_stack()
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
}
