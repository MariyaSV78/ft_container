#include "../incs/vector.hpp"
#include "../incs/tester.hpp"
#include "../utils/colors.hpp"

int    main()
{
	size_t	i;
	
	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "vector" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;

//constructors

	std::cout << "Default constructor " << std::endl;
		NAMESPACE::vector<int> def_vector;
 		print_vector(def_vector);
		std::cout << std::endl;
	
	std::cout << "Default constructor pointer "<< std::endl;
		NAMESPACE::vector<int> *ptr_vector = new NAMESPACE::vector<int>;
 		print_vector(*ptr_vector);
		std::cout << std::endl;		
	
 	 std::cout << "Fill constructor "<< std::endl;
		NAMESPACE::vector<int>		fill_vector(0);
		print_vector(fill_vector);
		std::cout << std::endl;   

 	std::cout << "Fill constructor sized"<< std::endl;
        NAMESPACE::vector<int>	fill_vector_sized(9);
		print_vector(fill_vector_sized);
		std::cout << std::endl;
    
 	std::cout << "Fill constructor sized & valued"<< std::endl;
        NAMESPACE::vector<int>	fill_vector_size_value(9, 42);
		print_vector(fill_vector_size_value);
		std::cout << std::endl;

  	std::cout << "Copy constructor "<< std::endl;
		NAMESPACE::vector<int>	copy_vector(fill_vector_size_value);
		print_vector(copy_vector);
		std::cout << std::endl;
	
   	std::cout << "Assign operator"<< std::endl;
		NAMESPACE::vector<int>	assign_vector = fill_vector_size_value;
		print_vector(assign_vector);
		std::cout << std::endl;
    
    std::cout << "Iterator constructor "<< std::endl;
		NAMESPACE::vector<int>	iter_vector(fill_vector_size_value.begin(), fill_vector_size_value.end());
		print_vector(iter_vector);
		for (NAMESPACE::vector<int>::iterator it = iter_vector.begin(); it != iter_vector.end(); it++ )
				*it = *it + 5;
		print_vector(iter_vector);
		std::cout << std::endl;

 	std::cout << "Iterator constructor (const)"<< std::endl;
		NAMESPACE::vector<int> 	const_iter_v(fill_vector_size_value.size());
		i = 0;
		print_vector(const_iter_v);
		for (NAMESPACE::vector<int>::const_iterator it = fill_vector_size_value.begin(); it != fill_vector_size_value.end(); it++ )
		{
			const_iter_v[i] = *it;
			i++;
		}
		print_vector(const_iter_v);
		std::cout << std::endl;

	std::cout << "Reverse Iterator"<< std::endl;
		NAMESPACE::vector<int> rev_iter_v(iter_vector.rbegin(), iter_vector.rend());
		i = 0;
		print_vector(rev_iter_v);

		for (NAMESPACE::vector<int>::reverse_iterator it = rev_iter_v.rbegin(); it != rev_iter_v.rend(); it++)
			*it = *it + i++;
		print_vector(rev_iter_v);
		std::cout << std::endl;

	std::cout << "Reverse Iterator (const)"<< std::endl;
		NAMESPACE::vector<int> rev_const_iter_v(rev_iter_v.rbegin(), rev_iter_v.rend());
		i = 0;
		print_vector(rev_const_iter_v);
		for (NAMESPACE::vector<int>::const_reverse_iterator  it = rev_const_iter_v.rbegin(); it != rev_const_iter_v.rend(); it++)
		{
			rev_const_iter_v[i] = *it; i++;
		}
		print_vector(rev_const_iter_v);
	
	std::cout << "==========================================================================" << std::endl << std::endl;
	NAMESPACE::vector<int>	vector = iter_vector;

	std::cout << "Max_size:"  << std::endl; 
		std::cout << "max size for def_vector = " << def_vector.max_size()<< std::endl;
		std::cout << "max size for copy_vector = " << copy_vector.max_size()<< std::endl;
		std::cout <<  std::endl;	

	std::cout << "resize(15,42)" << std::endl;
		vector.resize(15, 42);
		print_vector(vector);
		std::cout << std::endl;


	std::cout << "reserve(10)" << std::endl;
		vector.reserve(10);
		print_vector(vector);
		std::cout << std::endl;

	std::cout << "push_back(10)" << std::endl;
		vector.push_back(10);
		vector.push_back(15);
		vector.push_back(20);
		vector.push_back(10);
		print_vector(vector);
		std::cout << std::endl;

	std::cout << "pop_back()" << std::endl;
		vector.pop_back();
		vector.pop_back();
		print_vector(vector);
		std::cout << std::endl;

	std::cout << "assign(4, 10)" << std::endl;
		vector.assign(4, 10);
		vector.pop_back();
		print_vector(vector);
		std::cout << std::endl;

	std::cout << "insert(position, value)" << std::endl;
		vector.insert(vector.begin()+2, 42);
		print_vector(vector);
		std::cout << std::endl;
	
	std::cout << "insert(position, n, value)" << std::endl;
		vector.insert(vector.begin()+2, 4, 42);
		print_vector(vector);
		std::cout << std::endl;
			
	std::cout << "insert(position, first, last)" << std::endl;
		NAMESPACE::vector<int> test(3, 1);

		vector.insert(vector.begin()+2, test.begin(), test.end());
		print_vector(vector);
		std::cout << std::endl;

 	std::cout << "erase(position)" << std::endl;
		vector.erase(vector.begin()+1);
		print_vector(vector);
		std::cout << std::endl;
		
 	std::cout << "erase(range)" << std::endl;
		vector.erase(vector.begin()+1, vector.begin()+5);
		print_vector(vector);
		std::cout << std::endl;

	std::cout << "swap" << std::endl;
		std::cout << "vector_1: "; 
		print_vector(vector); 
		std::cout << "vector_2: "; 
		print_vector(iter_vector); 
		std::cout << std::endl;
		std::cout << "===swap===" << std::endl;	
		vector.swap(iter_vector);
		std::cout << "map_1: "; 
		print_vector(vector); 
		std::cout << "map_2: "; 
		print_vector(iter_vector); 
		std::cout << std::endl;


	std::cout << "clear" << std::endl;
		vector.clear();
		print_vector(vector); 
		std::cout << std::endl;


		delete (ptr_vector);
	return 0;
}