/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:49:50 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/30 13:49:56 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#ifndef ENABLE_IF_HPP
    # define ENABLE_IF_HPP

namespace ft
{
    template <bool Cond, class T = void> //NOTE - Main template struct
	struct enable_if
	{
	};

	template <class T> //NOTE - Specialized template struct
	struct enable_if<true, T> //ANCHOR - in case of true
	{
		typedef T type;
	};



	// template <typename T>
    //     struct is_integral : public is_integral_type<T> { };
	
	// template <> //NOTE - Specialized template struct for int type
	// struct is_integral<int>
	// {
	// 	static const bool value = true;
	// };
	
	// template <> //NOTE - Specialized template struct for bool type
	// struct is_integral<bool>
	// {
	// 	static const bool value = true;
	// };
	
	// template <> //NOTE - Specialized template struct for char type
	// struct is_integral<char>
	// {
	// 	static const bool value = true;
	// };
	
	// // template <> //NOTE - Specialized template struct ...
	// // struct is_integral<char16_t>
	// // {
	// // 	static const bool value = true;
	// // };
	
	// // template <> //NOTE - Specialized template struct ...
	// // struct is_integral<char32_t>
	// // {
	// // 	static const bool value = true;
	// // };
	
	// template <> //NOTE - Specialized template struct ...
	// struct is_integral<wchar_t>
	// {
	// 	static const bool value = true;
	// };
	
	// template <> //NOTE - Specialized template struct ...
	// struct is_integral<short>
	// {
	// 	static const bool value = true;
	// };
	
	// template <> //NOTE - Specialized template struct ...
	// struct is_integral<long>
	// {
	// 	static const bool value = true;
	// };
	
	// template <> //NOTE - Specialized template struct ...
	// struct is_integral<long long>
	// {
	// 	static const bool value = true;
	// };

	template <bool is_integral, typename T>
        struct is_integral_res 
		{
            typedef T type;
            static const bool value = is_integral;
        };

    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    
	template <typename T>
        struct is_integral : public is_integral_type<T> { };
}
#endif