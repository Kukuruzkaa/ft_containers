/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:01:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/01 22:32:32 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include <iostream>
#include "pair.hpp"
#include "reverse_iterator.hpp"

namespace ft {
    template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> > >
    
    class map {

        private:
            typedef typename Allocator::template rebind< T >::other _Pair_alloc;
            typedef RBTree<ft::pair<const Key, T>, Compare, _Pair_alloc>    _Tree;
            
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
            typedef typename _Tree::iterator                iterator;
            typedef typename _Tree::const_iterator          const_iterator;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;


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
            
            // template <class InputIt>
            // map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& = Allocator());
            
            map(const map<Key,T,Compare,Allocator> & src)
                : _alloc(src._alloc), _key_comp(src._key_comp), _size(src._size) {}
            
            ~map()
            {
                //clear();
                std::cout << "Destructor" << std::endl;
            }
            
            map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& rhs);
            
            // iterators:
            iterator begin() {return iterator(_tree.getMin());}
            const_iterator begin() const {return const_iterator(_tree.getMin());}
            iterator end() {return iterator(_tree.getMax());}
            const_iterator end() const {return const_iterator(_tree.Max());}
            reverse_iterator rbegin() {return reverse_iterator(end());}
            const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
            reverse_iterator rend() {return reverse_iterator(begin());}
            const_reverse_iterator rend() const {return const_reverse_iterator(begin());}
            
            // capacity:
            bool empty() const
            {
                if(!_size)
                    return true;
            }
            
            size_type size() const {return(_size);}
            
            size_type max_size() const {return _alloc.max_size();}

            // element access:
            T& operator[](const key_type& x)
            {
                return (*((insert(make_pair(x, T()))).first)).second;
            }
            
            // modifiers:
            pair<iterator, bool> insert(const value_type& new_pair)
            { 
                // bool    b = _tree.insertNode(new_pair);
                
                // return pair<iterator, bool>(iterator(_tree.TreeSearch(new_pair)), b);
                if (_tree.insertNode(new_pair))
                    return pair<iterator, bool>(iterator(_tree.TreeSearch(new_pair)), true);
                return pair<iterator, bool>(iterator(_tree.TreeSearch(new_pair)), false);
            }
            
            void    print   (void)
            {
                _tree.print();
            }

            // iterator insert(iterator position, const value_type& x);
            
            // template <class InputIterator>
            // void insert(InputIterator first, InputIterator last);
            
            // void erase(iterator position);
            
            // size_type erase(const key_type& x);
            
            // void erase(iterator first, iterator last);
            
            // void swap(multimap<Key,T,Compare,Allocator>&);
            
            // void clear();
            
            // // observers:
            key_compare key_comp() const {return _key_comp;}
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
            //     equal_range(const key_type& key);
            // pair<const_iterator,const_iterator>
            //     qual_range(const key_type& x) const3;

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