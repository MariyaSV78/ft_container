/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:44:06 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/30 13:44:09 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITERATORTRAITS_HPP
#define ITERATORTRAITS_HPP

# include <iostream>
# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>

namespace ft
{
//SECTION - ITERATOR TRAITS
template <class Iterator> 
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

template <class T> 
	struct iterator_traits<T*> //ANCHOR - Specialized for T pointer
	{
		typedef 	ptrdiff_t							difference_type;
		typedef		T									value_type;
		typedef		T*									pointer;
		typedef		T&									reference;
		typedef		std::random_access_iterator_tag		iterator_category;
	};

template <class T> 
	struct iterator_traits<const T*> //ANCHOR - Specialized for T const pointer
	{
		typedef 	ptrdiff_t							difference_type;
		typedef		T									value_type;
		typedef		const T*							pointer;
		typedef		const T&							reference;
		typedef		std::random_access_iterator_tag		iterator_category;
	};
}
#endif