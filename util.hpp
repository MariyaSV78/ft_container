#ifndef UTIL_HPP
# define UTIL_HPP
 # include  <iostream>
 # include <string>

const class
{
 
	public:
        template<class T>
		operator T*() const { return 0; }

        template<class C, class T>
        operator T C::*() const { return 0; }

	private:
        void operator&() const;
	

}nullpt={};


#endif