/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:34:38 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/20 21:06:19 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
    
    template <class T1, class T2 > 
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;
        
        T1 first;
        T2 second;
        pair() : first(T1()), second(T2()) {}
        pair(const T1& x, const T2& y) : first(x), second(y) {}
        template<class U, class V> pair(const pair<U, V> &p)
            : first(p.first), second(p.second) {}
        pair& operator=(const pair& rhs)
        {
            first = rhs.first;
            second = rhs.second;
            return *this;
        }
        ~pair() {}     
    };

    template <class T1, class T2 > 
    bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
        return x.first == y.first && x.second == y.second;
    }

    template <class T1, class T2 > 
    bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
        return (!(x == y));
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
        return x.first < y.first || (!(y.first < x.first) && x.second <y.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
        return (x < y || x == y);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
        return (!(x <= y));
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
        return (!(x < y));
    }

    template <class T1, class T2>
    pair<T1, T2> make_pair(const T1& x, const T2& y)
    {
        return pair<T1, T2>(x, y);
    }
}

    
#endif