/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:54:30 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/19 21:11:09 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft {
    
    template<
            class Category,
            class T,
            class Distance = std::ptrdiff_t,
            class Pointer = T*,
            class Reference = T&
            >
    struct iterator
    {
        typedef Category            iterator_category;
        typedef T                   value_type;
        typedef Distance            difference_type;
        typedef Pointer             pointer;
        typedef Reference           reference;
    };
}

#endif