/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:30:02 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/28 21:21:41 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP
#include "RBTree.hpp"
#include "iterator.hpp"

namespace ft {
    template <typename T> class Node;
    
    template<class Value>
    class map_iterator : public
        ft::iterator<std::bidirectional_iterator_tag, Value> {
        private:
            typedef ft::iterator<std::bidirectional_iterator_tag, Value>        _iterator;
        public:
            typedef map_iterator                                                iterator_type;
            typedef Value                              value_type;
            typedef typename _iterator::difference_type                         difference_type;
            typedef typename _iterator::reference                               reference;
            typedef typename _iterator::pointer                                 pointer;
            typedef typename _iterator::iterator_category                       iterator_category;
            typedef Node<value_type>                                            node_type;
            

        protected:
            node_type*  _node_ptr;
            
        public:
            map_iterator() : _node_ptr(NULL) {}
            map_iterator(node_type * node) : _node_ptr(node) {}
            map_iterator(const map_iterator & it) : _node_ptr(it._node_ptr) {}
            // template < typename U >
            // map_iterator (const map_iterator<U> & it) : _node_ptr(it.base()) {}
            map_iterator & operator=(const map_iterator & rhs)
            {
                _node_ptr = rhs._node_ptr;
                return *this;
            }
            ~map_iterator() {}
            
            // node_type *     base    (void) const
            // {   return _node_ptr;   }
                
            reference operator*() const
            {
                return static_cast<node_type*>(_node_ptr)->_key;
            }
            pointer operator->() const {return &(operator*());}
        
            map_iterator& operator++()
            {
                pointer next_node = _cast()->successor();
                _node_ptr = next_node;
                return *this;
                
            }
            
            map_iterator operator++(int)
            {
                pointer tmp_node = *this;
                --*this;
                return tmp_node;
            }
            
            map_iterator& operator--()
            {
            pointer prev_node = _cast()->predecessor();
                _node_ptr = prev_node;
                return *this;
            }
            
            map_iterator operator--(int)
            {
            pointer tmp_node = *this;
                ++*this;
                return tmp_node;
            }   

            bool    operator==(const map_iterator & rhs) const
            {
                return _node_ptr == rhs._node_ptr;
            }

            bool    operator!=(const map_iterator & rhs) const
            {
                return _node_ptr != rhs._node_ptr;
            }
        private:
            node_type * _cast    (void)
            {   return (static_cast<node_type *>(_node_ptr));    }
    };
}
#endif