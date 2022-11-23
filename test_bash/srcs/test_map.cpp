#include "../../incs/map.hpp"
// #include "../tmp_rchalie/containers/map.hpp"
#include "../../incs/tester.hpp"
#include "../../utils/colors.hpp"

int	main()
{
	std::cout << "==========================================================================" << std::endl; 
	std::cout << GREEN << std::setw(40) << std::right << "map" << RESET << std::endl;
	std::cout << "==========================================================================" << std::endl;

	std::cout << "Default constructor: ";
		NAMESPACE::map<char,int> def_map;
		print_map(def_map);
		std::cout << std::endl << std::endl;

	std::cout << "Filling map: ";
		def_map['a'] = 97;
		def_map['b'] = 98;
		def_map['c'] = 99;
		def_map['d'] = 100;
		def_map['e'] = 101;
		print_map(def_map);
		std::cout << std::endl << std::endl;

	std::cout << "Range constructor: ";
		NAMESPACE::map<char,int>	range_map(def_map.begin(), def_map.end());
		print_map(range_map);
		std::cout << std::endl << std::endl;

	std::cout << "Copy constructor: ";
		NAMESPACE::map<char,int>	copy_map(def_map);
		print_map(copy_map);
		std::cout << std::endl << std::endl;

	std::cout << "Assignement operator: ";
		NAMESPACE::map<char,int> assign_map = copy_map;
		print_map(assign_map);
		std::cout << std::endl << std::endl;


std::cout << "==========================================================================" << std::endl << std::endl;
	print_map(def_map);
	std::cout << "Max_size:"  << std::endl; 
		std::cout << "max size for def_map = " << def_map.max_size()<< std::endl;
		std::cout << "max size for copy_map = " << copy_map.max_size()<< std::endl;
		std::cout <<  std::endl;	


	std::cout << "Iterators: begin, end: "<< std::endl;
		NAMESPACE::map<char, int>::iterator begin, end;
		begin = def_map.begin();
		end = def_map.end();
		end--;
		std::cout << "first element = " << begin->first << "; last element = " << end->second << std::endl; 
		std::cout << std::endl;

	std::cout << "Iterators: rbegin, rend: "<< std::endl;
		std::cout << "def_map.rend()-> first: first element key= " << (--def_map.rend())->first << "; def_map.rend()->second: first element value =" << (--def_map.rend())->second << std::endl; 
		std::cout << "def_map.rbegin()->first(): last element key = " << (def_map.rbegin())->first << "; def_map.rbegin()->second: last element value=" << (def_map.rbegin())->second << std::endl; 
		std::cout << std::endl ;

	std::cout << "Element accesse []: "  << std::endl;
		copy_map['b'] = 1000;
		copy_map['x'] = 350;

		std::cout << "copy_map['b'] is " << copy_map['b'] << std::endl;
		std::cout << "copy_map['x'] is " << copy_map['x'] << std::endl;

		print_map (copy_map);
		std::cout << std::endl << std::endl;

	std::cout << "Insert (single parameter): ";
		def_map.insert(NAMESPACE::pair<char, int>('f',102));
		def_map.insert(NAMESPACE::pair<char, int>('g',103));
		def_map.insert(NAMESPACE::pair<char, int>('a',9117));
		print_map (def_map);
		std::cout << std::endl << std::endl;

	std::cout << "Insert (with hint position): ";
		def_map.insert(begin,NAMESPACE::pair<char, int>('i',105));
		def_map.insert(begin,NAMESPACE::pair<char, int>('g',103));
		print_map (def_map);
		std::cout << std::endl << std::endl;

	std::cout << "Insert (range insertion): ";
		NAMESPACE::map<char,int>  new_map;
		new_map['i'] = 105;
		new_map['j'] = 106;
		new_map['A'] = 65;
		new_map.insert(def_map.begin(),def_map.find('d'));
		print_map (new_map);
		std::cout << std::endl << std::endl;

	std::cout << "Erase: position " ;
		begin = new_map.find('a');
		new_map.erase(begin);
		print_map (new_map);
		std::cout << std::endl << std::endl;

	std::cout << "Erase: by key"  << std::endl;
		size_t i;
		i=new_map.erase('i');
		std::cout << "erase" << i << " element(s)" << i << std::endl;
		print_map (new_map);
		std::cout << std::endl << std::endl;

	std::cout << "Erase: by range: "  << std::endl;
		begin =new_map.find('b');
		new_map.erase(begin, new_map.end());
		print_map (new_map);
		std::cout << std::endl << std::endl;


	std::cout << "Swap:"  << std::endl;
		std::cout << "map_1: "; 
		print_map(def_map); 
		std::cout << "map_2: "; 
		print_map(new_map); 
		std::cout << std::endl;
		std::cout << "===swap===" << std::endl;	
		def_map.swap(new_map);
		std::cout << "map_1: "; 
		print_map(def_map); 
		std::cout << "map_2: "; 
		print_map(new_map); 
		std::cout << std::endl << std::endl;

	std::cout << "Clear:";
		new_map.clear();
		new_map['B'] = 66;
		print_map(new_map); 
		std::cout << std::endl << std::endl;

	std::cout << "Key compare:"  << std::endl;
		NAMESPACE::map<char,int>::key_compare  compar = NAMESPACE::map<char, int>().key_comp();
		bool  res = compar(115, 116);
		std::cout << "compare keys: 115 and 116: ";
		if (res)
			std::cout  << "the first argument is considered to go before the second" << std::endl << std::endl;
		else
			std::cout << "the second argument is considered to go before the first" << std::endl << std::endl;

	std::cout << "Key value:";
		NAMESPACE::map<char,int>::value_compare		key = NAMESPACE::map<char, int>().value_comp();
		bool res1 = key(NAMESPACE::make_pair('s', 115),NAMESPACE::make_pair('t', 116));
		if	(res1)
			std::cout << std::setw(12) <<  GREEN << "OK" << RESET;
		else
			std::cout << std::setw(12) <<  RED << "KO" << RESET;
		std::cout << std::endl << std::endl;

	std::cout << "Find:"  << std::endl;
		NAMESPACE::map<char, int>::iterator	it = copy_map.find('a');
		std::cout << "[" << it->first << ":" << it->second << "]" << std::endl;
		print_map (copy_map);
		copy_map.erase(it);
		print_map (copy_map);
		std::cout <<  std::endl << std::endl;	

	std::cout << "Count:"  << std::endl;
		size_type	N1, N2;
		N1= copy_map.count('c');
		N2 = copy_map.count('v');
		std::cout << "N elements with key c = " << N1 << std::endl;
		std::cout << "N elements with key x = " << N2 << std::endl;
		std::cout <<  std::endl << std::endl;	

		std::cout << "Lower_bound and upper_bound:"  << std::endl;
		NAMESPACE::map<char, int>::iterator	it_low, it_up;
		print_map(copy_map);
		it_low = copy_map.lower_bound('c'); // points to c
		it_up =  copy_map.upper_bound('d');	//points to e (not d!)
		std::cout << "Lower_bound point: [" << it_low->first <<" : " << it_low->second << "]" << std::endl; 
		std::cout << "Upper_bound point: [" << it_up->first <<" : " << it_up->second << "]" << std::endl; 
		std::cout << "After erase: ";
		copy_map.erase(it_low, it_up); //erases [it_low,it_up)
		print_map(copy_map);
		std::cout <<  std::endl << std::endl;	

		std::cout << "Equal range:"  << std::endl; //Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
		// NAMESPACE::pair<NAMESPACE::map<char,int>::iterator, NAMESPACE::map<char,int>::iterator> ret;
		// ret = copy_map.equal_range('b');
		// ret = copy_map.equal_range('a');
		// std::cout << "The bounds of a range that includes all the elements in the container with the key = b: " << ret.firts->first<< ""=>"" ret.firts->second << std::endl;
		// std::cout << "The bounds of a range that includes all the elements in the container with the key = a: " << ret.firts->first<< ""=>"" ret.firts->second << std::endl;
		// std::cout <<  std::endl << std::endl;	

		// std::cout << "Lower bound points to: ";
  		// std::cout << ret.first->first << " => " << ret.first->second << std::endl;

		NAMESPACE::map<char,int> my_map;

		my_map['a']=10;
		my_map['b']=20;
		my_map['c']=30;

		NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
		ret = my_map.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		std::cout <<  std::endl;	

	return 0;

}