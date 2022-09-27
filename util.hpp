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

namespace ft
{
//SECTION - ITERATOR TRAITS
template <class Iterator> 
        class iterator_traits
        {
                public:
                        typedef typename Iterator::difference_type		difference_type;
                        typedef typename Iterator::value_type			value_type;
                        typedef typename Iterator::pointer			pointer;
                        typedef typename Iterator::reference			reference;
                        typedef typename Iterator::iterator_category	iterator_category;
        };

template <class T> 
        class iterator_traits<T*> //ANCHOR - Specialized for T pointer
        {
                public:
                        typedef 	ptrdiff_t							difference_type;
                        typedef		T									value_type;
                        typedef		T*									pointer;
                        typedef		T&									reference;
                        typedef		std::random_access_iterator_tag		iterator_category;
        };

template <class T> 
        class iterator_traits<const T*> //ANCHOR - Specialized for T const pointer
        {
                public:
                        typedef 	ptrdiff_t							difference_type;
                        typedef		T									value_type;
                        typedef		const T*							pointer;
                        typedef		const T&							reference;
                        typedef		std::random_access_iterator_tag		iterator_category;
        };
}
#endif