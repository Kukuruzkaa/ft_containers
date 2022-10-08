/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:01:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/08 19:04:56 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include <iostream>
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "RBTree.hpp"
// # define __DEBUG__

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
                : _val_comp(key_comp), _alloc(alloc), _key_comp(key_comp), _size(0)
            {
                #ifdef __DEBUG__
                std::cout << "Default vector constructor" << std::endl;
                #endif   
            }
            
            template <class InputIt>
            map(InputIt first, InputIt last, const key_compare & key_comp = key_compare(), const allocator_type & alloc = allocator_type())
                : _val_comp(key_comp), _alloc(alloc), _key_comp(key_comp), _size(0)
            {
                insert(first, last);
            }
            
            map(const map<Key,T,Compare,Allocator> & src)
                :_val_comp(src._key_comp), _alloc(src._alloc), _key_comp(src._key_comp), _size(0)
            {
                this->insert(src.begin(), src.end());
            }
            
            ~map()
            {
                clear();
                #ifdef __DEBUG__
                std::cout << "Destructor" << std::endl;
                #endif
            }
            
            map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& rhs)
            {
                clear();
                _alloc = rhs._alloc;
                _key_comp = rhs._key_comp;
                insert(rhs.begin(), rhs.end());
                return *this;
            }
            
            // iterators:
            iterator begin() {return iterator(_tree.getMin());}
            const_iterator begin() const {return const_iterator(_tree.getMin());}
            iterator end() {return iterator(_tree.getSentinel());}
            const_iterator end() const {return const_iterator(_tree.getSentinel());}
            reverse_iterator rbegin() {return reverse_iterator(end());}
            const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
            reverse_iterator rend() {return reverse_iterator(begin());}
            const_reverse_iterator rend() const {return const_reverse_iterator(begin());}
            
            // capacity:
            bool empty() const
            {
                return _tree.getRoot() == _tree.getSentinel();
            }
            
            size_type size() const {return(_size);}
            
            size_type max_size() const {return _alloc.max_size();}

            // element access:
            T& operator[](const key_type& x)
            {
                return ((insert(make_pair(x, T()))).first)->second;
            }
            
            // modifiers:
            pair<iterator, bool> insert(const value_type& new_pair)
            { 
                // bool    b = _tree.insertNode(new_pair);
                
                // return pair<iterator, bool>(iterator(_tree.TreeSearch(new_pair)), b);
                if (_tree.insertNode(new_pair))
                {
                    ++_size;
                    return pair<iterator, bool>(iterator(_tree.TreeSearch(new_pair)), true);   
                }
                return pair<iterator, bool>(iterator(_tree.TreeSearch(new_pair)), false);
            }
            
            void    print   (void)
            {
                _tree.print();
            }

            iterator insert(iterator position, const value_type& new_pair)
            {
                // (void) position;
                // return (insert(new_pair).first);
                _tree.insertNode(new_pair, position);
                ++_size;
                return (iterator(_tree.TreeSearch(new_pair)));
            }
            
            template <class InputIt>
            void insert(InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = 0)
            {
                while (first != last)
                {
                    insert(*first);
                    ++first;
                }
            }
            
            void erase(iterator position)
            {
                if (position != end())
                {
                    _tree.deleteNode(*position);
                    --_size;
                }
            }
            
            size_type erase(const key_type& key)
            {
                iterator it = find(key);
                if (it == end())
                    return 0;
                erase(it);
                return 1;
            }
            
            void erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    iterator tmp = first;
                    ++tmp;
                    erase(*first);
                    // ++first;
                    first = tmp;
                }
            }
            
            void    test    (void) const
            {
                _tree.test();
            }
            
            void clear()
            {
                _tree._destroy(_tree.getRoot());
                _size = 0;
            }
            
            // // observers:
            key_compare key_comp() const {return _key_comp;}
            
            value_compare value_comp() const {return _val_comp;}

            // // map operations:
            iterator find(const key_type& key)
            {
                value_type new_pair = make_pair(key, mapped_type());
                return iterator(_tree.TreeSearch(new_pair));
            }
            
            const_iterator find(const key_type& key) const
            {
                value_type new_pair = make_pair(key, mapped_type());
                return const_iterator(_tree.TreeSearch(new_pair));
            }
            
            size_type count(const key_type& key) const
            {
                if (find(key) != end())
                    return 1;
                return 0;
            }
            
            // iterator lower_bound(const key_type& x);
            // const_iterator lower_bound(const key_type& x) const;
            // iterator upper_bound(const key_type& x);
            // const_iterator upper_bound(const key_type& x) const;
            
            // pair<iterator,iterator>
            //     equal_range(const key_type& key);
            // pair<const_iterator,const_iterator>
            //     equal_range(const key_type& x) const3;

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
            value_compare                                       _val_comp;
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