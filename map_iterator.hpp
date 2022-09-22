/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:30:02 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/22 22:38:06 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP
#include "RBTree.hpp"
#include "iterator.hpp"

namespace ft {
    
    template<class Iterator>
    class map_iterator : public
        ft::iterator<typename iterator_traits<Iterator>::iterator_category,
                    typename iterator_traits<Iterator>::value_type> {
        public:
            typedef map_iterator                                            iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::reference           reference;
            typedef typename iterator_traits<Iterator>::pointer             pointer;

        protected:
            pointer   _Node_ptr;
        
        public:
            map_iterator() : _Node_ptr(NULL) {}
            explicit map_iterator(const map_iterator & node) : _Node_ptr(node) {}
            map_iterator & operator=(const map_iterator & rhs)
            {
                _Node_ptr = rhs._Node_ptr;
                return *this;
            }
            ~map_iterator() {}
                        
    };
}
#endif