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
#include <stack>
#include <ctime>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"


int main()
{
	clock_t	ft_start, ft_end, std_start, std_end;
	clock_t	std_time, ft_time; 
	int i;





	ft::stack<int> ft_stack;
	std::stack<int> std_stack;

	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "stack" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;

// push elements

	ft_start = clock();//time(&ft_start);
	for (i = 0; i < 50; i++)
		ft_stack.push(i);
	ft_end = clock();//time(&ft_end);
	ft_time = (ft_end - ft_start);

	std_start = clock();//time(&std_start);
	for (i = 0; i < 50; i++)
		std_stack.push(i);
	std_end = clock();//std_end = time(NULL);
	std_time = (std_end - std_start);


	std::cout.fill('.');
	std::cout << "Push " << i << std::setw(61) << std::left <<  " elements";
	if (ft_time < std_time*20)
		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	else 
		std::cout <<  GREEN << "KO" << RESET<< std::endl;
	
	std::cout << "std_start " << std_start << "   " << std_end << "  " << std_time << std::endl;
	std::cout << "ft_start " << ft_start << "   " << ft_end << "  " << ft_time << std::endl;

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

	ft_start = clock();
	for (i = 0; i < 30; i++)
		ft_stack.pop();
	ft_end = clock();
	ft_time = (ft_end - ft_start);

	std_start = clock();
	for (i = 0; i < 30; i++)
		std_stack.pop();
	std_end = clock();
	std_time = (std_end - std_start);


	std::cout << "Pop " << i << std::setw(62) << std::left << " elements...";
	if (ft_time < std_time*20)
		std::cout <<  GREEN  << "OK" << RESET << std::endl;
	else 
		std::cout <<  RED  << "KO" << RESET<< std::endl;

	std::cout << "std_start " << std_start << "   " << std_end << "  " << std_time << std::endl;
	std::cout << "ft_start " << ft_start << "   " << ft_end << "  " << ft_time << std::endl;

	std::cout << "The size of ft_stack = " << ft_stack.size();
	std::cout << " and std_stack = " << std::setw(26) << std::left << std_stack.size();
	if (ft_stack.size() == std_stack.size())
		std::cout <<  GREEN << "OK" << RESET<< std::endl;
	else 
		std::cout <<  RED  << "KO" << RESET<< std::endl;
	

}

