/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:41:48 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/14 16:59:34 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP
#include <iostream>
#include <vector>

namespace ft {

    template <class T, class Container = std::vector<T> >  
    class stack 
    {
        public:
            typedef Container                               container_type;
            typedef typename Container::value_type          value_type;
            typedef typename Container::size_type           size_type;
            typedef typename Container::reference           reference;
            typedef typename Container::const_reference     const_reference;
            
            stack(const Container & cont = Container()) : c(cont) {}
            stack(const stack & src) : c(src.c) {}
            ~stack() {}

            reference top()
            {
                return this->c.back();
            }
            
            const_reference top() const
            {
                return this->c.back();
            }
            
            void    push(const value_type & value)
            {
                this->c.push_back(value);
            }
            
            bool    empty() const
            {
                return this->c.empty();
            }
            
            size_type size() const
            {
                return this->c.size();
            }
            
            void pop()
            {
                this->c.pop_back();
            }


            stack & operator=(const stack & src)
            {
                this->c = src.c;
                return *this;
            }
            
            friend bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
            {
                return lhs.c == rhs.c;
            }
            
            friend bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
            {
                return lhs.c != rhs.c;
            }

            friend bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
            {
                return lhs.c < rhs.c;
            }

            friend bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
            {
                return lhs.c <= rhs.c;
            }

            friend bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
            {
                return lhs.c > rhs.c;
            }

            friend bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
            {
                return lhs.c >= rhs.c;
            }

        protected:
           Container  c;
        
    };

}

#endif

// template < class T >

// T   min (T v1, T v2)
// {
//     if (v1 < v2)
//         return (v1);
//     return (v2);
// }
// int   min (int v1, int v2)
// {
//     if (v1 < v2)
//         return (v1);
//     return (v2);
// }

// ft::stack<int, std::deque<int>> inst;
// ft::stack<int>  i;

// class a
// {
//     public:
//         typedef int INTEGER;
// };

// class b
// {
//     public:
//         typedef a::INTEGER  INTEGER;
// }

// explicit stack( const Container& cont = Container() );
// stack( const stack& other );

//  // typedef T& reference; => vector