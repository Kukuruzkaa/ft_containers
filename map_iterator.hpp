/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:30:02 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/08 17:38:04 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP
#include "RBTree.hpp"
#include "iterator.hpp"

namespace ft {
    template <typename T> class Node;
    template <typename T> class map_citerator;
    
    template<class Value>
    class map_iterator : public
        ft::iterator<std::bidirectional_iterator_tag, Value> {
        private:
            typedef ft::iterator<std::bidirectional_iterator_tag, typename Value::value_type>  _iterator;
        public:
            typedef map_iterator                                                iterator_type;
            typedef Value                                                       value_type;
            typedef typename _iterator::difference_type                         difference_type;
            typedef typename _iterator::reference                               reference;
            typedef typename _iterator::pointer                                 pointer;
            typedef typename _iterator::iterator_category                       iterator_category;
            typedef Node<value_type>                                            node_type;
            

        public:
        // protected:
            value_type*  _node_ptr;
            
        // public:
            map_iterator() : _node_ptr(NULL) {}
            map_iterator(value_type * node) : _node_ptr(node) {}
            map_iterator(const map_iterator & it) : _node_ptr(it._node_ptr) {}
            map_iterator & operator=(const map_iterator & rhs)
            {
                _node_ptr = rhs._node_ptr;
                return *this;
            }
            ~map_iterator() {}
                
            reference operator*() const
            {
                return _node_ptr->_key;
            }
            pointer operator->() const {return &(operator*());}
        
            map_iterator& operator++()
            {
                // pointer next_node = _node_ptr->successor()->_key;
                _node_ptr = _node_ptr->successor();
                return *this;
                
            }
            
            map_iterator operator++(int)
            {
                map_iterator tmp_node = *this;
                ++(*this);
                return tmp_node;
            }
            
            map_iterator& operator--()
            {
                // pointer prev_node = _node_ptr->predecessor()->_key;
                _node_ptr = _node_ptr->predecessor();
                return *this;
            }
            
            map_iterator operator--(int)
            {
                map_iterator tmp_node = *this;
                --(*this);
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

            operator map_citerator<value_type> (void)
            {   return (map_citerator<value_type>(_node_ptr));  }
    };

    template<class const_Value>
    class map_citerator : public
        ft::iterator<std::bidirectional_iterator_tag, typename const_Value::value_type> {
        private:
            typedef ft::iterator<std::bidirectional_iterator_tag, typename const_Value::value_type const>  _const_iterator;
        public:
            typedef map_citerator                                               iterator_type;
            typedef const_Value                                                 value_type;
            typedef typename _const_iterator::difference_type                   difference_type;
            typedef typename _const_iterator::reference                         reference;
            typedef typename _const_iterator::pointer                           pointer;
            typedef typename _const_iterator::iterator_category                 iterator_category;
            

        protected:
            value_type*  _node_ptr;
            
        public:
            map_citerator() : _node_ptr(NULL) {}
            map_citerator(value_type * node) : _node_ptr(node) {}
            map_citerator(const map_citerator & cit) : _node_ptr(cit._node_ptr) {}
            map_citerator & operator=(const map_citerator & rhs)
            {
                _node_ptr = rhs._node_ptr;
                return *this;
            }
            ~map_citerator() {}
                
            reference operator*() const
            {
                return _node_ptr->_key;
            }
            pointer operator->() const{return &(operator*());}
        
            map_citerator& operator++()
            {
                _node_ptr = _node_ptr->successor();
                return *this;
                
            }
            
            map_citerator operator++(int)
            {
                map_citerator tmp_node = *this;
                ++(*this);
                return tmp_node;
            }
            
            map_citerator& operator--()
            {
                _node_ptr = _node_ptr->predecessor();
                return *this;
            }
            
            map_citerator operator--(int)
            {
                map_citerator   tmp_node = *this;
                --(*this);
                return tmp_node;
            }   

            bool    operator==(const map_citerator & rhs) const
            {
                return (_node_ptr == rhs._node_ptr);
            }

            bool    operator!=(const map_citerator & rhs) const
            {
                return (_node_ptr != rhs._node_ptr);
            }
    };
}
#endif