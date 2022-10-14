#include "map.hpp"
#include "tester.hpp"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void	test_map()
{
	Time	start, end;
	double	std_time, ft_time; 

	std::cout.fill(' ');
	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "vector" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(40) << "size" << std::setw(11) << "capacity" << std::setw(11) << "elements" << std::setw(7) << "time" << std::endl;

//constructors

	std::cout << "Default constructor " << std::setw(22);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<const char,int>  ft_def_map;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int> 	std_def_map;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		//map_is_identic(std_def_map, ft_def_map);
		is_time(std_time, ft_time); std::cout << std_time << "  " << ft_time ; 
		std::cout << std::endl;
		std::cout << std::endl;


}