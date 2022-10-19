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
            Container c;
        public:
            /*
                value_type	    -The first template parameter (T)	            -Type of the elements
                container_type	-The second template parameter (Container)      -Type of the underlying container
                size_type	    -an unsigned integral type	                    -usually the same as size_t
            */

            typedef T   value_type; // The behavior is undefined if T is not the same type as Container::value_type

            typedef Container   container_type;
            typedef size_t      size_type;

            
        //constructor
            explicit stack(const Container& cont = Container()): c(cont) {} 


            
            bool empty() const { return c.empty(); }
            
            size_type size() const { return c.size(); }
            
            value_type& top() { return c.back(); }
            
            const value_type& top() const { return c.back(); }
            
            void push(const value_type& x) { c.push_back(x); }
            
            void pop() { c.pop_back(); }

        
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
                { return  x.c == y.c; }
            
            template <class T, class Container>
                bool operator< (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return  x.c < y.c;}
            
            template <class T, class Container>
                bool operator!=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return x.c != y.c;}
            
            template <class T, class Container>
                bool operator>(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return  x.c > y.c; }
            
            template <class T, class Container>
                bool operator>=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return x.c >= y.c;}

            template <class T, class Container>
                bool operator<=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
                { return (x.c <= y.c);}
}
#endif
