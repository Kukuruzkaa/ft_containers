/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:24:14 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/24 21:55:18 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
#include <iostream>
#include <iterator>

namespace ft {

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag: public input_iterator_tag {};
    struct bidirectional_iterator_tag: public forward_iterator_tag {};
    struct random_access_iterator_tag: public bidirectional_iterator_tag {};

   template<class Iterator> 
    struct iterator_traits 
    {
            typedef typename Iterator::iterator_category    iterator_category;
            typedef typename Iterator::value_type           value_type;
            typedef typename Iterator::difference_type      difference_type;
            typedef typename Iterator::pointer              pointer;
            typedef typename Iterator::reference            reference;
            
        };

    template<typename T> 
        struct iterator_traits<T*> 
        {
            typedef ptrdiff_t   difference_type;
            typedef             T value_type;
            typedef             T* pointer;
            typedef             T& reference;
            typedef             random_access_iterator_tag iterator_category;
        };

    template<typename T> 
        struct iterator_traits<const T*> 
        {
            typedef ptrdiff_t   difference_type;
            typedef             T value_type;
            typedef const       T* pointer;
            typedef const       T& reference;
            typedef             random_access_iterator_tag iterator_category;
        };

    // template <class InputIterator, class Distance>
    //     void advance(InputIterator& i, Distance n);
        
    // template <class InputIterator>
    //     typename iterator_traits<InputIterator>::difference_type
    //     distance(InputIterator first, InputIterator last);

};

#endif