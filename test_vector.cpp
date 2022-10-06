/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:19 by msosnova          #+#    #+#             */
/*   Updated: 2022/10/03 17:04:23 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include <iostream>
//#include <string>
#include <iomanip>
#include "vector.hpp"
#include <vector>
#include <ctime>

#include "tester.hpp"

typedef struct 			timespec Time;
typedef std::size_t		size_type;


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void    test_vector()
{
std::cout << "==========================================================================" << std::endl; 
std::cout << GREEN << std::setw(40) << std::right << "vector" << RESET << std::endl;
std::cout << "==========================================================================" << std::endl;

//constructors
	{
	 std::cout << "Default constructor "<< std::endl;

		ft::vector<int> ft_def_vector;
		std::vector<int> std_def_vector;
		print_ft_vector(ft_def_vector);
        print_std_vector(std_def_vector);
		std::cout << std::endl;	
	}

	{
	 std::cout << "Default constructor pointer "<< std::endl;
		ft::vector<int> *ft_def_ptr_vector = new ft::vector<int>;
		std::vector<int> *std_def_ptr_vector = new std::vector<int>;
		print_ft_vector(*ft_def_ptr_vector);
        print_std_vector(*std_def_ptr_vector);
		std::cout << std::endl;			
	}

    {
 	 std::cout << "Fill constructor "<< std::endl;
	    std::vector<int> std_fill_vector(0);
        ft::vector<int> ft_fill_vector(0);
		print_ft_vector(ft_fill_vector);
 		print_std_vector(std_fill_vector);
        std::cout << std::endl;	
	}

    {
 	 std::cout << "Fill constructor sized"<< std::endl;
        std::vector<int> stl_fill_vector_sized(9);
        ft::vector<int> ft_fill_vector_sized(9);
		print_ft_vector(ft_fill_vector_sized);
 		print_std_vector(stl_fill_vector_sized);
		std::cout << std::endl;	
	}

    {
 	 std::cout << "Fill constructor sized & valued"<< std::endl;
        std::vector<int> std_fill_vector_size_value(9, 42);
        ft::vector<int> ft_fill_vector_size_value(9, 42);
		print_ft_vector(ft_fill_vector_size_value);
 		print_std_vector(std_fill_vector_size_value);
		std::cout << std::endl;	
	}

    {
  	 std::cout << "Copy constructor "<< std::endl;
        std::vector<int> std_fill_vector_size_value(9, 42);
        ft::vector<int> ft_fill_vector_size_value(9, 42);

		std::vector<int> std_copy_vector(std_fill_vector_size_value);
		ft::vector<int> ft_copy_vector(ft_fill_vector_size_value);

		print_ft_vector(ft_copy_vector);
 		print_std_vector(std_copy_vector);
		std::cout << std::endl;	
	}

    {
   	 std::cout << "Assign operator"<< std::endl;
        std::vector<int> std_fill_vector_size_value(9, 42);
        ft::vector<int> ft_fill_vector_size_value(9, 42);

		std::vector<int> std_assign_vector = std_fill_vector_size_value;
		ft::vector<int> ft_assign_vector = ft_fill_vector_size_value;
		
		print_ft_vector(ft_assign_vector);
 		print_std_vector(std_assign_vector);
		std::cout << std::endl;	
    }
    
    {
	 std::cout << "Iterator constructor "<< std::endl;
		std::vector<int> std_def_vector(3, 5);
		ft::vector<int> ft_def_vector(std_def_vector.begin(), std_def_vector.end());
		print_ft_vector(ft_def_vector);
        print_std_vector(std_def_vector);
		std::cout << std::endl;	
	}
//methods:
    {
        Time	start, end;
	    double	std_time, ft_time; 
//ft:
		clock_gettime(CLOCK_MONOTONIC, &start);
        ft::vector<int> ft_vector;

		std::cout << "resize(5, 42)" << std::endl;
		ft_vector.resize(5, 42);
		print_ft_vector(ft_vector);

		std::cout << "reserve (10)" << std::endl;
		ft_vector.reserve(10);
		print_ft_vector(ft_vector);
 			
		std::cout << "push_back(10)" << std::endl;
		ft_vector.push_back(10);

		std::cout << "pop_back()" << std::endl;
		ft_vector.pop_back();
		print_ft_vector(ft_vector);	

		std::cout << "assign(4, 10)" << std::endl;
		ft_vector.assign(4,10);
		print_ft_vector(ft_vector);	
		
		std::cout << "ft_vector.swap(vector)" << std::endl;

		ft::vector<int> vector(4, 24);
  		
		print_ft_vector(vector);
		ft_vector.swap(vector);
		print_ft_vector(ft_vector);
		print_ft_vector(vector);
	
		std::cout << "insert(position, n, value)" << std::endl;
		ft_vector.insert(ft_vector.begin()+2, 3, 0);
		print_ft_vector(ft_vector);

		std::cout << "clear" << std::endl;
		ft_vector.clear();
		print_ft_vector(ft_vector);

        clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3; //us
//std:
		clock_gettime(CLOCK_MONOTONIC, &start);
        std::vector<int> std_vector;

		std::cout << "resize(5, 42)" << std::endl;
		std_vector.resize(5, 42);
		print_std_vector(std_vector);

		std::cout << "reserve (10)" << std::endl;
		std_vector.reserve(10);
		print_std_vector(std_vector);
 			
		std::cout << "push_back(10)" << std::endl;
		std_vector.push_back(10);

		std::cout << "pop_back()" << std::endl;
		std_vector.pop_back();
		print_std_vector(std_vector);

		std::cout << "assign(4, 10)" << std::endl;
		std_vector.assign(4,10);
		print_std_vector(std_vector);
		
		std::cout << "ft_vector.swap(vector)" << std::endl;

		std::vector<int> svector(4, 24);
  		
		print_std_vector(svector);
		std_vector.swap(svector);
		print_std_vector(std_vector);
		print_std_vector(svector);
	
		std::cout << "insert(position, n, value)" << std::endl;
		std_vector.insert(std_vector.begin(), 3, 0);
		print_std_vector(std_vector);

		std::cout << "clear" << std::endl;
		std_vector.clear();
		print_std_vector(std_vector);

        clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3; //us

        std::cout.fill('.');
	    std::cout << "The time for ft_vector > std_vector in " << ft_time/std_time <<  std::setw(61) << std::left <<  " elements";
        if (ft_time < std_time*20)
            std::cout <<  GREEN << "OK" << RESET<< std::endl;
        else 
            std::cout <<  GREEN << "KO" << RESET<< std::endl;
        
        std::cout << "std_time " << std_time << std::endl;
        std::cout << "ft_time " << ft_time << std::endl;
	}

	{
       std::cout << "Assign operator"<< std::endl;
		
		int range_array[] = { 74, 569, -8822, 8515, 5, 7, 67};

    	std::vector<int> std_range_vector(range_array, range_array + 4);
       	ft::vector<int> ft_range_vector(range_array, range_array + 4);
		ft::vector<int> vector;
		ft::vector<int> vector2(std_range_vector.begin(), std_range_vector.end());

		print_ft_vector(ft_range_vector);
		print_std_vector(std_range_vector);



		// ft::myIterator<int> it, it_2;
		// it = ft_range_vector.begin();
		// it_2 = ft_range_vector.end();

		// vector.assign(std_range_vector.begin(), std_range_vector.end());		
		// ft_print_vector(std_range_vector, vector);

	}


}

