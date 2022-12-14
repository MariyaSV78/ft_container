#include "../incs/map.hpp"
// #include "../tmp_rchalie/containers/map.hpp"
#include "../incs/tester.hpp"
#include "../utils/colors.hpp"

void	test_map()
{
	Time	start, end;
	double	std_time, ft_time; 

	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "map" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(40) << "size"  << std::setw(12) << "elements" << std::setw(7) << "time" << std::endl;


	std::cout << "Default constructor " << std::setw(22);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char,int>  ft_def_map;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int> 	std_def_map;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_def_map, ft_def_map);
		is_time(std_time, ft_time); //std::cout << " time " << std_time << "  " << ft_time ; 
		std::cout << std::endl;
		std::cout << std::endl;

	std::cout << "Filling map <char, int>" << std::setw(19);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_def_map['a'] = 97;
		ft_def_map['b'] = 98;
		ft_def_map['c'] = 99;
		ft_def_map['d'] = 100;
		ft_def_map['e'] = 101;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_def_map['a'] = 97;
		std_def_map['b'] = 98;
		std_def_map['c'] = 99;
		std_def_map['d'] = 100;
		std_def_map['e'] = 101;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_def_map, ft_def_map);
		is_time(std_time, ft_time);  
		std::cout << std::endl;
		std::cout << std::endl;

	std::cout << "Filling map <string, int>" << std::setw(17);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<std::string, int>  ft_map_string;
		ft_map_string[std::string("avril")] = 4;
		ft_map_string[std::string("may")] = 5;
		ft_map_string[std::string("juin")] = 6;
		ft_map_string[std::string("july")] = 7;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<std::string, int>  std_map_string;
		std_map_string[std::string("avril")] = 4;
		std_map_string[std::string("may")] = 5;
		std_map_string[std::string("juin")] = 6;
		std_map_string[std::string("july")] = 7;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_map_string, ft_map_string);
		is_time(std_time, ft_time);  
		std::cout << std::endl;
		std::cout << std::endl;


	std::cout << "Range constructor " << std::setw(24);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char,int> ft_range_map(ft_def_map.begin(), ft_def_map.end());
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int> std_range_map(std_def_map.begin(), std_def_map.end());
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_range_map, ft_range_map);
		is_time(std_time, ft_time);  
		std::cout << std::endl;
		std::cout << std::endl;

	std::cout << "Copy constructor " << std::setw(25);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char,int> ft_copy_map(ft_def_map);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int> std_copy_map(std_def_map);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_copy_map, ft_copy_map);
		is_time(std_time, ft_time); 
		std::cout << std::endl;
		std::cout << std::endl;

std::cout << "Assignement operator"  << std::setw(22);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char,int> ft_assign_map;
		ft_assign_map = ft_copy_map;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int> std_assign_map;
		std_assign_map = std_copy_map;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_assign_map, ft_assign_map);
		is_time(std_time, ft_time); 
		std::cout << std::endl;
		std::cout << std::endl;

std::cout << "==========================================================================" << std::endl << std::endl;
std::cout << std::setw(40) << "size"  << std::setw(12) << "elements" << std::setw(7) << "time" << std::endl;
	
	std::cout << "Max_size:"  << std::setw(39); //returns true if the first argument is considered to go before the second
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_copy_map.max_size();
		ft_def_map.max_size();
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_copy_map.max_size();
		std_def_map.max_size();
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		if	(std_copy_map.max_size() == ft_copy_map.max_size() && ft_def_map.max_size() == std_def_map.max_size())
			std::cout << std::setw(43) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(43) <<  RED << "KO" << RESET;

		is_time(std_time, ft_time); //std::cout << "   std_time = " << std_time << " , ft_time = " << ft_time ; 
		std::cout <<  std::endl;
		std::cout <<  std::endl;	

	std::cout << "begin, end" ;
		ft::map<char, int>::iterator begin_ft, end_ft;
		std::map<char, int>::iterator begin_std, end_std;
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_ft = ft_def_map.begin();
		end_ft = ft_def_map.end();
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_std= std_def_map.begin();
		end_std = std_def_map.end();
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		end_ft--; end_std--;
		if	(begin_ft->first == begin_std->first && end_ft->first == end_std->first && 
			begin_ft->second == begin_std->second && end_ft->second == end_std->second){
			std::cout << std::setw(42) <<  GREEN << "OK" << RESET;}
		else
			std::cout << std::setw(42) <<  RED << "KO" << RESET;
		is_time(std_time, ft_time);  
		std::cout << std::endl;
		std::cout << std::endl;
	
	std::cout << "rbegin, rend"  << std::setw(48);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_def_map.rbegin();
		ft_def_map.rend();
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_def_map.rbegin();
		std_def_map.rend();
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		if	(ft_def_map.rbegin()->first == std_def_map.rbegin()->first && (++ft_def_map.rend())->first == (++std_def_map.rend())->first && 
			ft_def_map.rbegin()->second == std_def_map.rbegin()->second && (++ft_def_map.rend())->second == (++std_def_map.rend())->second)
			std::cout << std::setw(40) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(40) <<  RED << "KO" << RESET;
		is_time(std_time, ft_time);
		std::cout << std::endl;
		std::cout << std::endl;

	 std::cout << "Iterator"<< std::setw(34);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char, int> ft_iter_map(ft_def_map.begin(), ft_def_map.end());
		for (ft::map<char, int>::iterator ft_it = ft_iter_map.begin(); ft_it != ft_iter_map.end(); ft_it++ )
		{
			ft_it->second = (ft_it->second)++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char, int> std_iter_map(std_def_map.begin(), std_def_map.end());
		for (std::map<char, int>::iterator std_it = std_iter_map.begin(); std_it != std_iter_map.end(); std_it++ )
		{
			std_it->second = (std_it->second)++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_iter_map, ft_iter_map);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;


 	std::cout << "Iterator (const)"<< std::setw(26);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char, int> 	ft_const_iter(ft_def_map.begin(), ft_def_map.end());
		ft::map<char, int>::iterator it = ft_const_iter.begin();
		for (ft::map<char,int>::const_iterator ft_it = ft_const_iter.begin(); ft_it != ft_const_iter.end(); ft_it++, it++)
		{
			it->second = ft_it->first;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char, int> 	std_const_iter(std_def_map.begin(), std_def_map.end());
		std::map<char, int>::iterator it2 = std_const_iter.begin();
		for (std::map<char,int>::const_iterator std_it = std_const_iter.begin(); std_it != std_const_iter.end(); std_it++, it2++ )
		{
			it2->second = std_it->first;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		map_is_identic(std_const_iter, ft_const_iter);

		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;
	

	 std::cout << "Reverse Iterator"<< std::setw(26);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char, int> ft_rev_iter_map(ft_def_map.rbegin(), ft_def_map.rend());
		for (ft::map<char, int>::reverse_iterator ft_it = ft_rev_iter_map.rbegin(); ft_it != ft_rev_iter_map.rend(); ft_it++ )
		{
			ft_it->second = (ft_it->second)++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char, int> std_rev_iter_map(std_def_map.rbegin(), std_def_map.rend());
		for (std::map<char, int>::reverse_iterator std_it = std_rev_iter_map.rbegin(); std_it != std_rev_iter_map.rend(); std_it++ )
		{
			std_it->second = (std_it->second)++;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_rev_iter_map, ft_rev_iter_map);
		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;


	std::cout << "Reverse Iterator (const)"<< std::setw(18);
	  	clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char, int> 	ft_rev_const_iter(ft_def_map.rbegin(), ft_def_map.rend());
		ft::map<char, int>::iterator it3 = ft_rev_const_iter.begin();
		for (ft::map<char,int>::const_reverse_iterator ft_it = ft_rev_const_iter.rbegin(); ft_it != ft_rev_const_iter.rend(); ft_it++, it3++)
		{
			it3->second = ft_it->first;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char, int> 	std_rev_const_iter(std_def_map.rbegin(), std_def_map.rend());
		std::map<char, int>::iterator it4 = std_rev_const_iter.begin();
		for (std::map<char,int>::const_reverse_iterator std_it = std_rev_const_iter.rbegin(); std_it != std_rev_const_iter.rend(); std_it++, it4++ )
		{
			it4->second = std_it->first;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		map_is_identic(std_rev_const_iter, ft_rev_const_iter);

		is_time(std_time, ft_time);
		std::cout << std::endl;	
		std::cout << std::endl;


	std::cout << "Element accesse: []"  << std::setw(23);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_copy_map['b'] = 1000;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_copy_map['b'] = 1000;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_copy_map, ft_copy_map);
		is_time(std_time, ft_time);
		std::cout << std::endl;
		std::cout << std::endl;

	std::cout << "Insert (single parameter)"  << std::setw(17);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_def_map.insert(ft::pair<char, int>('f',102));
		ft_def_map.insert(ft::pair<char, int>('g',103));
		ft_def_map.insert(ft::pair<char, int>('a',9117));
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_def_map.insert(std::pair<char, int>('f',102));
		std_def_map.insert(std::pair<char, int>('g',103));
		std_def_map.insert(std::pair<char, int>('a',917));
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_def_map, ft_def_map);
		is_time(std_time, ft_time); 
		std::cout << std::endl;
		std::cout << std::endl;

	std::cout << "Insert (with hint position)"  << std::setw(15);
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_ft = ft_def_map.begin();
		ft_def_map.insert(begin_ft, ft::pair<char, int>('i',105));
		ft_def_map.insert(begin_ft, ft::pair<char, int>('g',103));
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_std = std_def_map.begin();
		std_def_map.insert(begin_std, std::pair<char, int>('i',105));
		std_def_map.insert(begin_std, std::pair<char, int>('g',103));
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_def_map, ft_def_map);
		is_time(std_time, ft_time); 
		std::cout << std::endl;
		std::cout << std::endl;

	std::cout << "Insert (range insertion)"  << std::setw(18);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char,int>  ft_new_map;
		ft_new_map['i'] = 105;
		ft_new_map['j'] = 106;
		ft_new_map['A'] = 65;
		ft_new_map.insert(ft_def_map.begin(), ft_def_map.find('d'));
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int>  std_new_map;
		std_new_map['i'] = 105;
		std_new_map['j'] = 106;
		std_new_map['A'] = 65;
		std_new_map.insert(std_def_map.begin(), std_def_map.find('d'));		
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_new_map, ft_new_map);
		is_time(std_time, ft_time);  
		std::cout << std::endl;
		std::cout << std::endl;

	std::cout << "Erase: position"  << std::setw(27);
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_ft = ft_new_map.find('a');
		ft_new_map.erase(begin_ft);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_std = std_new_map.find('a');
		std_new_map.erase(begin_std);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_new_map, ft_new_map);
		is_time(std_time, ft_time); 
		std::cout << std::endl;
		std::cout << std::endl;

	
	std::cout << "Erase: by key"  << std::setw(29);
		size_t i_ft, i_std;
		clock_gettime(CLOCK_MONOTONIC, &start);
		i_ft= ft_new_map.erase('i');
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		i_std =std_new_map.erase('i');
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_new_map, ft_new_map);
		is_time(std_time, ft_time); 
		std::cout << std::endl;
//		std::cout << "ft:  " << i_ft << ", std: " << i_std;
		std::cout << std::endl;		

	
	std::cout << "Erase: by range"  << std::setw(27);
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_ft = ft_new_map.find('b');
		ft_new_map.erase(begin_ft, ft_new_map.end());
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		begin_std = std_new_map.find('b');
		std_new_map.erase(begin_std, std_new_map.end());
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_new_map, ft_new_map);
		is_time(std_time, ft_time); 
		std::cout <<  std::endl;
		std::cout <<  std::endl;	
	

	std::cout << "Swap:"  << std::setw(37);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_def_map.swap(ft_new_map);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_def_map.swap(std_new_map);		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_def_map, ft_def_map);
		is_time(std_time, ft_time); 
		std::cout << std::endl;
		std::cout << std::endl;


	std::cout << "Clear:"  << std::setw(36);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft_new_map.clear();
		ft_new_map['B'] = 66;
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std_new_map.clear();
		std_new_map['B'] = 66;
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_new_map, ft_new_map);
		is_time(std_time, ft_time);
		std::cout <<  std::endl;
		std::cout <<  std::endl;	


	std::cout << "Key compare:"  << std::setw(39); //returns true if the first argument is considered to go before the second
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char,int>::key_compare  ft_compar = ft::map<char, int>().key_comp(); // ft_new_map.key_comp();
		bool ft_res = ft_compar(115, 116);
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int>::key_compare  std_compar = std::map<char, int>().key_comp(); //std_new_map.key_comp();
		bool std_res = std_compar(115, 116);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		if	(std_res  && ft_res )
			std::cout << std::setw(40) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(40) <<  RED << "KO" << RESET;

		is_time(std_time, ft_time); //std::cout << "   std_time = " << std_time << " , ft_time = " << ft_time ; 
		std::cout <<  std::endl;
		std::cout <<  std::endl;	


	std::cout << "Key value:"  << std::setw(40); //Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char,int>::value_compare ft_key = ft::map<char, int>().value_comp();
		bool ft_res1 = ft_key(ft::make_pair('s', 115), ft::make_pair('t', 116));
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char,int>::value_compare std_key =std::map<char, int>().value_comp();
		bool std_res1 = std_key(std::make_pair('s', 115), std::make_pair('t', 116));
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		if	(std_res1  && ft_res1)
			std::cout << std::setw(42) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(42) <<  RED << "KO" << RESET;

		is_time(std_time, ft_time); 
		std::cout <<  std::endl;
		std::cout <<  std::endl;


	std::cout << "Find:"  << std::setw(40);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char, int>::iterator	ft_it = ft_copy_map.find('c');
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char, int>::iterator	std_it = std_copy_map.find('c');
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		if	((ft_it->first == std_it->first) && (ft_it->second == std_it->second))
			std::cout << std::setw(47) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(47) <<  RED << "KO" << RESET;

		is_time(std_time, ft_time); 
		std::cout <<  std::endl;
		std::cout <<  std::endl;	


	std::cout << "Count:"  << std::setw(40);
		size_type	ft, std;
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft = ft_copy_map.count('c');
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std = std_copy_map.count('c');
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		if	(ft == std)
			std::cout << std::setw(46) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(46) <<  RED << "KO" << RESET;

		is_time(std_time, ft_time); 
		std::cout <<  std::endl;
		std::cout <<  std::endl;


	std::cout << "Lower_bound and upper_bound:"  << std::setw(14);
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::map<char, int>::iterator	ft_it_low, ft_it_up;
		ft_it_low = ft_copy_map.lower_bound('c'); // points to c
		ft_it_up = ft_copy_map.upper_bound('d');	//points to e (not d!)
		ft_copy_map.erase(ft_it_low, ft_it_up); //erases [it_low,it_up)
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::map<char, int>::iterator	std_it_low, std_it_up;
		std_it_low = std_copy_map.lower_bound('c');
		std_it_up = std_copy_map.upper_bound('d');
		std_copy_map.erase(std_it_low, std_it_up);
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		map_is_identic(std_copy_map, ft_copy_map);
		is_time(std_time, ft_time);
		std::cout <<  std::endl;
		std::cout <<  std::endl;


	std::cout << "Equal range:"  << std::setw(38); // The function returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
		clock_gettime(CLOCK_MONOTONIC, &start);
		ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ft_ret;
		ft_ret = ft_copy_map.equal_range('b');
		clock_gettime(CLOCK_MONOTONIC, &end);
        ft_time = (end.tv_nsec - start.tv_nsec)* 1e-3;
		clock_gettime(CLOCK_MONOTONIC, &start);
		std::pair<std::map<char,int>::iterator, std::map<char,int>::iterator> std_ret;
		std_ret = std_copy_map.equal_range('b');
		clock_gettime(CLOCK_MONOTONIC, &end);
        std_time = (end.tv_nsec - start.tv_nsec)* 1e-3;

		if	((ft_ret.first)->first == (std_ret.first)->first && (ft_ret.second)->first == (std_ret.second)->first)
			std::cout << std::setw(40) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(40) <<  RED << "KO" << RESET;		
		is_time(std_time, ft_time); 
		std::cout <<  std::endl;
		std::cout <<  std::endl;
}
		//std::cout << "   std_time = " << std_time << " , ft_time = " << ft_time ;