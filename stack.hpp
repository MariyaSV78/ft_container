/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:16 by msosnova          #+#    #+#             */
/*   Updated: 2022/09/07 00:54:38 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <vector>
#include <iostream>
#include <string>
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        protected:
            Container _c;
        public:
            /*
                value_type	    -The first template parameter (T)	            -Type of the elements
                container_type	-The second template parameter (Container)      -Type of the underlying container
                size_type	    -an unsigned integral type	                    -usually the same as size_t
            */

            typedef typename Container::value_type value_type; // The behavior is undefined if T is not the same type as Container::value_type

            typedef typename Container::size_type size_type; //typedef Container container_type;

            
        //constructor
            explicit stack(const Container& c = Container()): _c(c) {} 


            
            bool empty() const { return _c.empty(); }
            
            size_type size() const { return _c.size(); }
            
            value_type& top() { return _c.back(); }
            
            const value_type& top() const { return _c.back(); }
            
            void push(const value_type& x) { _c.push_back(x); }
            
            void pop() { _c.pop_back(); }

        
            template <class T_, class Container_>
                friend bool operator==(const ft::stack<T_, Container_>& x, const ft::stack<T_, Container_>& y);

            template <class T_, class Container_>
                friend bool operator< (const ft::stack<T_, Container_>& x, const ft::stack<T_, Container_>& y);

            template <class T_, class Container_>
                friend bool operator!=(const ft::stack<T_, Container_>& x, const ft::stack<T_, Container_>& y);

            template <class T_, class Container_>
                friend bool operator>(const ft::stack<T_, Container_>& x, const ft::stack<T_, Container_>& y);
            
            template <class T_, class Container_>
                friend bool operator>=(const ft::stack<T_, Container_>& x, const ft::stack<T_, Container_>& y);

            template <class T_, class Container_>
                friend bool operator<=(const ft::stack<T_, Container_>& x, const ft::stack<T_, Container_>& y);

    };
   
            template <class T, class Container>
                bool operator==(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return  x._c == y._c; }
            
            template <class T, class Container>
                bool operator< (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return  x._c < y._c;}
            
            template <class T, class Container>
                bool operator!=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return x._c != y._c;}
            
            template <class T, class Container>
                bool operator>(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return  x._c > y._c; }
            
            template <class T, class Container>
                bool operator>=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return x._c >= y._c;}

            template <class T, class Container>
                bool operator<=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return (x._c <= y._c);}
}
#endif
