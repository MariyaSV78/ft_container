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
#include "stack.hpp"
#include <stack>
#include <ctime>

int main()
{
	clock_t	ft_start, ft_end, std_start, std_end;
	double	std_time, ft_time; 
	int i;

	ft::stack<int> ft_stack;
	std::stack<int> std_stack;

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


	std::cout << "Push " << i << " elements...";
	if (std_time/ft_time < 20)
		std::cout << "OK" << std::endl;
	else 
		std::cout << "KO" << std::endl;
	
	std::cout << "std_start" << std_start << "   " << std_end << "  " << std_time << std::endl;
	std::cout << "ft_start" << ft_start << "   " << ft_end << "  " << ft_time << std::endl;

	std::cout << "The size of ft_stack = " << ft_stack.size();
	std::cout << " and std_stack = " << std_stack.size() << "  ";
	if (ft_stack.size() == std_stack.size())
		std::cout << "OK" << std::endl;
	else 
		std::cout << "KO" << std::endl;

	std::cout << "The top element of ft_stack = " << ft_stack.top();
	std::cout << " and ft_stack = " << std_stack.top() << "  ";
	if (ft_stack.top() == std_stack.top())
		std::cout << "OK" << std::endl;
	else 
		std::cout << "KO" << std::endl;


	ft_start = clock();
	for (i = 0; i < 3; i++)
		ft_stack.pop();
	ft_end = clock();
	ft_time = (ft_end - ft_start);

	std_start = clock();
	for (i = 0; i < 3; i++)
		std_stack.pop();
	std_end = clock();
	std_time = (std_end - std_start);


	std::cout << "Pop " << i << " elements...";
	if (std_time/ft_time < 20)
		std::cout << "OK" << std::endl;
	else 
		std::cout << "KO" << std::endl;

	std::cout << "The size of ft_stack = " << ft_stack.size();
	std::cout << " and std_stack = " << std_stack.size() << "  ";
	if (ft_stack.size() == std_stack.size())
		std::cout << "OK" << std::endl;
	else 
		std::cout << "KO" << std::endl;
}



