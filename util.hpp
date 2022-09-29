#ifndef UTIL_HPP
# define UTIL_HPP

 # include <iostream>
 # include <string>
 # include <stddef.h>

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
template <class Iterator> struct iterator_traits
        {
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
        };

template <class T> struct iterator_traits<T*> //ANCHOR - Specialized for T pointer
        {
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		T*									pointer;
			typedef		T&									reference;
			typedef		std::random_access_iterator_tag		iterator_category;
        };

template <class T> 
        class iterator_traits<const T*> //ANCHOR - Specialized for T const pointer
        {
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		const T*							pointer;
			typedef		const T&							reference;
			typedef		std::random_access_iterator_tag		iterator_category;
        };


	template <bool Cond, class T = void> //NOTE - Main template struct
	struct enable_if
	{
	};

	template <class T> //NOTE - Specialized template struct
	struct enable_if<true, T> //ANCHOR - in case of true
	{
		typedef T type;
	};

	template <class T> //NOTE - Main template struct
	struct is_integral
	{
		static const bool value = false;
	};
	template <> //NOTE - Specialized template struct for int type
	struct is_integral<int>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct for bool type
	struct is_integral<bool>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct for char type
	struct is_integral<char>
	{
		static const bool value = true;
	};
	// template <> //NOTE - Specialized template struct ...
	// struct is_integral<char16_t>
	// {
	// 	static const bool value = true;
	// };
	// template <> //NOTE - Specialized template struct ...
	// struct is_integral<char32_t>
	// {
	// 	static const bool value = true;
	// };
	template <> //NOTE - Specialized template struct ...
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<short>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<long>
	{
		static const bool value = true;
	};
	template <> //NOTE - Specialized template struct ...
	struct is_integral<long long>
	{
		static const bool value = true;
	};


	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
										InputIterator2 first2, InputIterator2 last2)
		{
			while (first1 != last1)
			{
				if ((first2 == last2) || (*first1 > *first2)) 
					return (false);
				else if (*first1 < *first2)
					return (true);
				++first1;
				++first2;
			}
			return (first2 != last2);
		}

	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
					InputIterator2 first2)
		{
			while (first1 != last1)
			{
				if (*first1 != *first2)
					return (false);
				++first1;
				++first2;
			}
			return (true);
		}
}

#endif