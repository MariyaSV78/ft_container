/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:41 by msosnova          #+#    #+#             */
/*   Updated: 2022/10/03 17:04:44 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/stack.hpp"
#include "../../incs/tester.hpp"
#include "../../utils/colors.hpp"


int	main()
{

	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "stack" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;

std::cout << "Stack creation and push elements:" << std::endl;
	NAMESPACE::stack<int>  stack;
	for (int i = 0; i < 30; i++)
		stack.push(i);
	std::cout << "Top stack = " << stack.top(); 
	std::cout << std::endl;
	print_stack(stack);
	std::cout << std::endl;

std::cout << "Pop elements" << std::endl;
	for (int i = 0; i < 10; i++)
		stack.pop();
	std::cout << "Top stack = " << stack.top();
	std::cout << std::endl;
	print_stack(stack);
	std::cout << std::endl;
	return 0;
}