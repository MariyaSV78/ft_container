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

namespace ft
{
//SECTION - ITERATOR TRAITS
template <class Iter> 
	class iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iterqqa::iterator_category	iterator_category;
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