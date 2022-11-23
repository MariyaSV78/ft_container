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

#include "../incs/vector.hpp"
#include "../incs/tester.hpp"
#include <ctime>
#include "../utils/colors.hpp"

void	is_time(double std_time, double ft_time)
{
	if (ft_time < std_time*20)
		std::cout << std::setw(12) <<  GREEN << "OK" << RESET;
	else 
		std::cout << std::setw(12) <<  RED << "KO" << RESET << ": std_time = " << std_time << " ft_time = " << ft_time << std::endl;
}


void    test_vector()
{
	Time	start, end;
	double	std_time, ft_time;
	size_t	i, j; 

	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "vector" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(40) << "size" << std::setw(11) << "capacity" << std::setw(11) << "elements" << std::setw(7) << "time" << std::endl;

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
		is_time(std_time, ft_time);
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
        ft::vector<int> ft_int_vector_sized(9);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
        std::vector<int> stl_int_vector_sized(9);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic (stl_int_vector_sized, ft_int_vector_sized);
		is_time(std_time, ft_time);
		std::cout << std::endl << std::endl;

    
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


   	std::cout << "Assign operator "<< std::setw(26);
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


	std::cout << "Assign operator (range)"<< std::setw(19);
		int range_array[] = { 74, 569, -8822, 8515, 5, 7, 67};
		clock_gettime(CLOCK_MONOTONIC, &start);
     	ft::vector<int> ft_range_vector(range_array, range_array + 4);	
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
    	std::vector<int> std_range_vector(range_array, range_array + 4);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_range_vector, ft_range_vector);
		is_time(std_time, ft_time);
		std::cout << std::endl;
		std::cout << std::endl;	
 		
    
	 std::cout << "Iterator constructor "<< std::setw(21);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_iter_vector(ft_fill_vector_size_value.begin(), ft_fill_vector_size_value.end());
		for (ft::vector<int>::iterator ft_it = ft_iter_vector.begin(); ft_it != ft_iter_vector.end(); ft_it++ )
		{
			*ft_it = *ft_it + 5;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int> std_iter_vector(std_fill_vector_size_value.begin(), std_fill_vector_size_value.end());
		for (std::vector<int>::iterator std_it = std_iter_vector.begin(); std_it != std_iter_vector.end(); std_it++ )
		{
			*std_it = *std_it + 5;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_iter_vector, ft_iter_vector);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;


 	std::cout << "Iterator constructor (const)"<< std::setw(14);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int>::const_iterator ft_it;
		ft::vector<int> 	ft_const_iter_v(ft_fill_vector_size_value.size());
		j = 0;
		for (ft_it = ft_fill_vector_size_value.begin(); ft_it != ft_fill_vector_size_value.end(); ft_it++ )
		{
			ft_const_iter_v[j] = *ft_it;
			j++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int>::const_iterator std_it;
		std::vector<int> 	std_const_iter_v(std_fill_vector_size_value.size());
		i = 0;
		for (std_it = std_fill_vector_size_value.begin(); std_it != std_fill_vector_size_value.end(); std_it++ )
		{
			std_const_iter_v[i] = *std_it;
			i++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		vector_is_identic(std_const_iter_v, ft_const_iter_v);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;
	

	 std::cout << "Reverse Iterator"<< std::setw(26);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_rev_iter_v(ft_iter_vector.rbegin(), ft_iter_vector.rend());
		i = 0;
		for (ft::vector<int>::reverse_iterator it = ft_rev_iter_v.rbegin(); it != ft_rev_iter_v.rend(); it++)
		{
			*it = *it+ i++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int> std_rev_iter_v(std_iter_vector.rbegin(), std_iter_vector.rend());
		i = 0;
		for (std::vector<int>::reverse_iterator it = std_rev_iter_v.rbegin(); it != std_rev_iter_v.rend(); it++)
		{
			*it = *it+ i++;
		}	
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		vector_is_identic(std_rev_iter_v, ft_rev_iter_v);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;


	std::cout << "Reverse Iterator (const)"<< std::setw(18);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::vector<int> ft_rev_const_iter_v(ft_rev_iter_v.rbegin(), ft_rev_iter_v.rend());
		i = 0;
		for (ft::vector<int>::const_reverse_iterator  it = ft_rev_const_iter_v.rbegin(); it != ft_rev_const_iter_v.rend(); it++)
		{
			ft_rev_const_iter_v[i] = *it; i++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::vector<int> std_rev_const_iter_v(std_rev_iter_v.rbegin(), std_rev_iter_v.rend());
		i = 0;
		for (std::vector<int>::const_reverse_iterator  it = std_rev_const_iter_v.rbegin(); it != std_rev_const_iter_v.rend(); it++)
		{
			std_rev_const_iter_v[i] = *it; i++;
		}
	
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		vector_is_identic(std_rev_iter_v, ft_rev_iter_v);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;
	std::cout << "==========================================================================" << std::endl << std::endl;
	std::cout << std::setw(40) << "size" << std::setw(11) << "capacity" << std::setw(11) << "elements" << std::setw(7) << "time" << std::endl;
	
	ft::vector<int> ft_vector = ft_iter_vector;
	std::vector<int> std_vector = std_iter_vector;

	std::cout << "max_size" << std::setw(29);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft_vector.max_size();
		ft_copy_vector.max_size();
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_vector.max_size();
		std_copy_vector.max_size();
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		if	(ft_vector.max_size() == std_vector.max_size() && ft_copy_vector.max_size() == std_copy_vector.max_size())
			std::cout << std::setw(54) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(54) <<  RED << "KO" << RESET;

		is_time(std_time, ft_time); 
		std::cout << std::endl;	
		std::cout << std::endl;


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
		is_time(std_time, ft_time);
		std::cout << std::endl;
		std::cout << std::endl;

	
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
		is_time(std_time, ft_time); 
		std::cout << std::endl;
		std::cout << std::endl;
		

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
		is_time(std_time, ft_time);  
		std::cout << std::endl;
		std::cout << std::endl;

			
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

	
	std::cout << "erase(range)" << std::setw(30);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_vector.erase(ft_vector.begin()+1, ft_vector.begin()+11);
		clock_gettime(CLOCK_MONOTONIC, &end);
		ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_vector.erase(std_vector.begin()+1, std_vector.begin()+11);
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
}

//std::cout << std_time << "  " << ft_time ; 