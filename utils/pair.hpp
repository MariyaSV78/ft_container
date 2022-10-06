/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:45:44 by msosnova          #+#    #+#             */
/*   Updated: 2022/10/05 16:45:58 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
		struct  pair
		{
			typedef T1	first_type;
			typedef T2	second_type;

			T1		first;
			T2		second;

			pair(): first(), second() {} //first(T1()), second(T2())

			pair(const T1& x, const T2& y): 
				first(x), 
				second(y) {}

			template<class U, class V> 
				pair(const pair<U, V> &p):
				first(p.first),
				second(p.second){}

			pair&	operator=(const pair<T1, T2>& p)
				{
					if (*this == pr)
                        return (*this);
					first = p.first;
					second = p.second;
					return *this;
				}
	//	}; ?

			template <class T1, class T2>
				bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
				{return (x.first == y.first && x.second == y.second)}

			template <class T1, class T2>
				bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
				{return (x.first < y.first || (!(y.first < x.first) && x.second < y.second))}
			
			template <class T1, class T2>
				bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
				{return (x.first > y.first || (!(y.first > x.first) && x.second > y.second))}

			template <class T1, class T2>
				bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
				{return !(x == y)}

			template <class T1, class T2>
				bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
				{return !(x < y)}

			template <class T1, class T2>
				bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
				{return !(y < x)}

				void swap(pair<T1, T2>& x, pair<T1, T2>& y)
				{ 
					pair<T1,T2>		tmp;

					tmp = x;
					x = y;
					y = tmp;
				}

			template <class T1, class T2>
				ft::pair<T1, T2> make_pair(const T1& x, const T2& y)
				{return (ft::pair<T1, T2>(x, y))}
		};
		
}

#endif

