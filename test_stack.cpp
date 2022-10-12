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
#include "tester.hpp"



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

	size_t			ft_size, std_size;
	size_t			ft_top, std_top;
	
	
	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "stack" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(40) << "size" << std::setw(9) << "top" << std::setw(9) << "time" << std::endl << std::endl;
std::cout.fill(' ');	
// push elements

std::cout << "Stack creation and push elements" << std::setw(10);
	clock_gettime(CLOCK_MONOTONIC, &start);
	std::stack<int>  std_stack;
	for (i = 0; i < 50; i++)
		std_stack.push(i);
	std_size = std_stack.size();
	std_top = std_stack.top();
	clock_gettime(CLOCK_MONOTONIC, &end);
	std_time = (end.tv_nsec - start.tv_nsec)* 1e-3; //us
	clock_gettime(CLOCK_MONOTONIC, &start);
	ft::stack<int> ft_stack;
	for (i = 0; i < 50; i++)
		ft_stack.push(i);
	ft_size = ft_stack.size();
	ft_top = ft_stack.top();
	clock_gettime(CLOCK_MONOTONIC, &end);
	ft_time = (end.tv_nsec - start.tv_nsec) * 1e-3; //us


//size stacks
	if (ft_stack.size() == std_stack.size())
		std::cout << GREEN << "OK" << RESET;
	else 
		std::cout <<  RED  << "KO" << RESET;

//top....

	if (ft_stack.top() == std_stack.top())
		std::cout <<  GREEN << std::setw(9) << "OK" << RESET;
	else 
		std::cout <<  RED <<  std::setw(9) << "KO" << RESET;

//time
	is_time(std_time, ft_time);
 
	std::cout << std::endl;	
	std::cout << std::endl;	

// pop...
std::cout << "Pop elements" << std::setw(30);
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


//size stacks
	if (ft_stack.size() == std_stack.size())
		std::cout << GREEN << "OK" << RESET;
	else 
		std::cout <<  RED  << "KO" << RESET;

//top....

	if (ft_stack.top() == std_stack.top())
		std::cout <<  GREEN << std::setw(9) << "OK" << RESET;
	else 
		std::cout <<  RED <<  std::setw(9) << "KO" << RESET;

//time
	is_time(std_time, ft_time);
 
	std::cout << std::endl;	
	std::cout << std::endl;	
}
