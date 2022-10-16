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


#include "vector.hpp"
#include "tester.hpp"
#include <ctime>


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void	is_time(double std_time, double ft_time)
{
	if (ft_time < std_time*20)
		std::cout << std::setw(12) <<  GREEN << "OK" << RESET;
	else 
		std::cout << std::setw(12) <<  RED << "KO" << RESET;
}



void    test_vector()
{

	Time	start, end;
	double	std_time, ft_time; 

	std::cout.fill(' ');
	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "vector" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(40) << "size" << std::setw(11) << "capacity" << std::setw(11) << "elements" << std::setw(7) << "time" << std::endl;
std::cout.fill(' ');
//constructors

	std::cout << "Default constructor " << std::setw(22);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_def_vector;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int> std_def_vector;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_def_vector, ft_def_vector);
		is_time(std_time, ft_time); std::cout << std_time << "  " << ft_time ; 
		std::cout << std::endl;
		std::cout << std::endl;
	
	std::cout << "Default constructor pointer "<< std::setw(14);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> *ft_def_ptr_vector = new ft::vector<int>;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int> *std_def_ptr_vector = new std::vector<int>;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(*std_def_ptr_vector, *ft_def_ptr_vector);
		is_time(std_time, ft_time);
		std::cout << std::endl;
		std::cout << std::endl;		
	

 	 std::cout << "Fill constructor "<< std::setw(25);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_fill_vector(0);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int> std_fill_vector(0);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_fill_vector, ft_fill_vector);
		is_time(std_time, ft_time);
        std::cout << std::endl;	
		std::cout << std::endl;
	    

 	std::cout << "Fill constructor sized"<< std::setw(20);
 		clock_gettime(CLOCK_MONOTONIC, &start);
        ft::vector<int> ft_fill_vector_sized(9);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
        std::vector<int> stl_fill_vector_sized(9);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic (stl_fill_vector_sized, ft_fill_vector_sized);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;

    
 	std::cout << "Fill constructor sized & valued"<< std::setw(11);
		clock_gettime(CLOCK_MONOTONIC, &start);
        ft::vector<int> ft_fill_vector_size_value(9, 42);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
        std::vector<int> std_fill_vector_size_value(9, 42);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_fill_vector_size_value, ft_fill_vector_size_value);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;

  	std::cout << "Copy constructor "<< std::setw(25);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_copy_vector(ft_fill_vector_size_value);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
     	std::vector<int> std_copy_vector(std_fill_vector_size_value);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_copy_vector, ft_copy_vector);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;
	
   	std::cout << "Assign operator"<< std::setw(27);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_assign_vector = ft_fill_vector_size_value;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
    	std::vector<int> std_assign_vector = std_fill_vector_size_value;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_assign_vector, ft_assign_vector);
		is_time(std_time, ft_time);
		std::cout << std::endl;
		std::cout << std::endl;	
    
    
	 std::cout << "Iterator constructor "<< std::setw(21);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_iter_vector(ft_fill_vector_size_value.begin(), ft_fill_vector_size_value.end());
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int> std_iter_vector(std_fill_vector_size_value.begin(), std_fill_vector_size_value.end());
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_iter_vector, ft_iter_vector);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;
	
	std::cout << "==========================================================================" << std::endl << std::endl;
	ft::vector<int> ft_vector = ft_iter_vector;
	std::vector<int> std_vector = std_iter_vector;

	std::cout << "resize(15,42)" << std::setw(29);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft_vector.resize(15, 42);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_vector.resize(15, 42);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_vector, ft_vector);
		is_time(std_time, ft_time); 
		
        std::cout << std::endl;	
		std::cout << std::endl;


	std::cout << "reserve(10)" << std::setw(31);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_vector.reserve(10);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_vector.reserve(10);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_vector, ft_vector);
		is_time(std_time, ft_time); 
        std::cout << std::endl;
		std::cout << std::endl;	
		
		// print_vector(std_vector);
		// print_vector(ft_vector);	

	std::cout << "push_back(10)" << std::setw(29);

		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_vector.push_back(10);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_vector.push_back(10);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_vector, ft_vector); 
		is_time(std_time, ft_time);

		std::cout << std::endl;	
		std::cout << std::endl;
		// print_vector(std_vector);
		// print_vector(ft_vector);

 		std::cout << "pop_back()" << std::setw(32);
			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.pop_back();
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.pop_back();
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time);
			std::cout << std::endl;
			std::cout << std::endl;

	std::cout << "assign(4, 10)" << std::setw(29);
			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.assign(4, 10);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.assign(4, 10);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time); // std::cout << std_time << "  " << ft_time ; 
			std::cout << std::endl;
			std::cout << std::endl;
		
		// print_vector(std_vector);
		// print_vector(ft_vector);	
		

	std::cout << "insert(position, value)" << std::setw(19);
			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.insert(ft_vector.begin()+2, 42);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.insert(std_vector.begin()+2, 42);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time); //std::cout << std_time << "  " << ft_time ; 
			std::cout << std::endl;
			std::cout << std::endl;
		
		// print_vector(std_vector);
		// print_vector(ft_vector);	
	

	std::cout << "insert(position, n, value)" << std::setw(16);
			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.insert(ft_vector.begin()+2, 4, 42);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.insert(std_vector.begin()+2, 4, 42);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time); //std::cout << std_time << "  " << ft_time ; 
			std::cout << std::endl;
			std::cout << std::endl;

		// print_vector(ft_vector);	
		// print_vector(std_vector);	
			
		std::cout << "insert(position, first, last)" << std::setw(13);
		std::vector<int> test_std(3, 1);

			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.insert(ft_vector.begin()+2, test_std.begin(), test_std.end());
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.insert(std_vector.begin()+2, test_std.begin(), test_std.end());
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time); 
			std::cout << std::endl;
			std::cout << std::endl;

		// print_vector(std_vector);	
		// print_vector(ft_vector);	

 		std::cout << "erase(position)" << std::setw(27);
			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.erase(ft_vector.begin()+1);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.erase(std_vector.begin()+1);
			clock_gettime(CLOCK_MONOTONIC, &end);
			std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time); 
			std::cout << std::endl;	
			std::cout << std::endl;

		// print_vector(std_vector);
		// print_vector(ft_vector);
		
 		std::cout << "erase(range)" << std::setw(30);
			clock_gettime(CLOCK_MONOTONIC, &start);
			//ft::vector<int>::iterator ft_i = 
			ft_vector.erase(ft_vector.begin()+1, ft_vector.begin()+11);
			// if(ft_i== ft_vector.begin()+1)
			// 	std::cout << "okk";
			// else
			// 	std::cout << "ko="<<ft_i-ft_vector.begin();
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			//std::vector<int>::iterator std_i = 
			std_vector.erase(std_vector.begin()+1, std_vector.begin()+11);
			// if(std_i== std_vector.begin()+1)
			// 	std::cout << "sokk";
			// else
			// 	std::cout << "sko="<<std_i-std_vector.begin();

			clock_gettime(CLOCK_MONOTONIC, &end);
			std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time); 
			std::cout << std::endl;	
			std::cout << std::endl;

		std::cout << "swap" << std::setw(38);
			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.swap(ft_iter_vector);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.swap(std_iter_vector);
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time);

			std::cout << std::endl;	
			std::cout << std::endl;
			
			// print_vector(std_vector);
			// print_vector(ft_vector);	
 		
		 std::cout << "clear" << std::setw(37);
			clock_gettime(CLOCK_MONOTONIC, &start);
			ft_vector.clear();
			clock_gettime(CLOCK_MONOTONIC, &end);
			ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
			clock_gettime(CLOCK_MONOTONIC, &start);
			std_vector.clear();
			clock_gettime(CLOCK_MONOTONIC, &end);
			std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

			vector_is_identic(std_vector, ft_vector); 
			is_time(std_time, ft_time); 
			std::cout << std::endl;	
			std::cout << std::endl;	


		delete (ft_def_ptr_vector);
		delete (std_def_ptr_vector);

//      std::cout << "Assign operator"<< std::endl;
		
// 		int range_array[] = { 74, 569, -8822, 8515, 5, 7, 67};

//     	std::vector<int> std_range_vector(range_array, range_array + 4);
//      ft::vector<int> ft_range_vector(range_array, range_array + 4);
}

