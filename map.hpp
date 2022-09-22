/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:01:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/22 17:41:40 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include <iostream>
#include "pair.hpp"

namespace ft {
    template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> > >
    
    class map {

        private:
            typedef typename Allocator::template rebind< T >::other _Pair_alloc;
            
        public:
            // types:
            typedef Key                                     key_type;
            typedef T                                       mapped_type;
            typedef ft::pair<const Key, T>                  value_type;
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef Compare                                 key_compare;
            typedef Allocator                               allocator_type;
            typedef value_type &                            reference;
            typedef const value_type &                      const_reference;
            typedef typename Allocator::pointer             pointer;
            typedef typename Allocator::const_pointer       const_pointer;
            // typedef implementation defined iterator; 
            // typedef implementation defined const_iterator; 
            // typedef std::reverse_iterator<iterator>         reverse_iterator;
            // typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;


            class value_compare : public std::binary_function<value_type,value_type,bool> 
            {
                friend class map;
                    protected:
                        Compare comp;
                        value_compare(Compare c) : comp(c) {}
                    public:
                        bool operator()(const value_type& lhs, const value_type& rhs) const 
                        {
                            return comp(lhs.first, rhs.first);
                        }
            };
            // construct/copy/destroy:
            explicit map(const key_compare & key_comp = key_compare(), const allocator_type & alloc = allocator_type())
                : _alloc(alloc), _key_comp(key_comp), _size(0)
            {
                std::cout << "Default vector constructor" << std::endl;   
            }
            
            template <class InputIt>
            map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& = Allocator());
            
            map(const map<Key,T,Compare,Allocator> & src)
                : _alloc(src._alloc), _key_comp(src._key_comp), _size(src._size) {}
            
            ~map()
            {
                //clear();
                std::cout << "Destructor" << std::endl;
            }
            
            map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& rhs);
            
            // iterators:
            // iterator begin();
            // const_iterator begin() const;
            // iterator end();
            // const_iterator end() const;
            // reverse_iterator rbegin();
            // const_reverse_iterator rbegin() const;
            // reverse_iterator rend();
            // const_reverse_iterator rend() const;
            
            // capacity:
            // bool empty() const;
            // size_type size() const;
            // size_type max_size() const;
            
            // element access:
            T& operator[](const key_type& x)
            {
                return (*((insert(make_pair(x, T()))).first)).second;
            }
            
            // modifiers:
            // pair<iterator, bool> insert(const value_type& x);
            // iterator insert(iterator position, const value_type& x);
            // template <class InputIterator>
            // void insert(InputIterator first, InputIterator last);     _key_comp;
            
            // value_compare value_comp() const;

            // // map operations:
            // iterator find(const key_type& x);
            // const_iterator find(const key_type& x) const;
            // size_type count(const key_type& x) const;
            
            // iterator lower_bound(const key_type& x);
            // const_iterator lower_bound(const key_type& x) const;
            // iterator upper_bound(const key_type& x);
            // const_iterator upper_bound(const key_type& x) const;
            
            // pair<iterator,iterator>
            //     equal_range(const key_type& x);
            // pair<const_iterator,const_iterator>
            //     qual_range(const key_type& x) const;

            // template <class Key, class T, class Compare, class Allocator>
            //     bool operator==(const map<Key,T,Compare,Allocator>& x,
            //     const map<Key,T,Compare,Allocator>& y);
            
            // template <class Key, class T, class Compare, class Allocator>
            //     bool operator< (const map<Key,T,Compare,Allocator>& x,
            //     const map<Key,T,Compare,Allocator>& y);
            
            // template <class Key, class T, class Compare, class Allocator>
            //     bool operator!=(const map<Key,T,Compare,Allocator>& x,
            //     const map<Key,T,Compare,Allocator>& y);
                
            // template <class Key, class T, class Compare, class Allocator>
            //     bool operator> (const map<Key,T,Compare,Allocator>& x,
            //     const map<Key,T,Compare,Allocator>& y);
                
            // template <class Key, class T, class Compare, class Allocator>
            //     bool operator>=(const map<Key,T,Compare,Allocator>& x,
            //     const map<Key,T,Compare,Allocator>& y);
            
            // template <class Key, class T, class Compare, class Allocator>
            //     bool operator<=(const map<Key,T,Compare,Allocator>& x,
            //     const map<Key,T,Compare,Allocator>& y);
                
        private:
            allocator_type                                      _alloc;
            key_compare                                         _key_comp;
            size_t                                              _size;
            RBTree<value_type, key_compare, allocator_type>     _tree;
            
        
        
    };
        // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
        void swap(map<Key,T,Compare,Allocator>& lhs, map<Key,T,Compare,Allocator>& rhs) {lhs.swap(rhs);}
}
#endif