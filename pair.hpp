/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:34:38 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/19 21:31:36 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

template <class T1, class T2 > 
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;
        
        T1 first;
        T2 second;
        pair() : first(T1()), second(T2()) {}
        pair(const T1& x, const T2& y) : first(x), second(y) {}
        pair& operator=(const pair& rhs)
        {
            first = rhs.first;
            second = rhs.second;
            return *this;
        }
        
        template<class U, class V> pair(const pair<U, V> &p);
            bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
            {
                return x.first == y.first && x.second == y.second;
            }
    };

#endif