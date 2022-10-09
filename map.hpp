/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:01:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/09 19:58:14 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include <iostream>
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "RBTree.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
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
                :_val_comp(src._key_comp), _alloc(src._alloc), _key_comp(src._key_comp), _size(0), _tree(src._tree) {}
            
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
                _size = rhs._size;
                _tree = rhs._tree;
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
            bool empty() const {return _tree.getRoot() == _tree.getSentinel();}
            
            size_type size() const {return(_size);}
            
            size_type max_size() const {return _tree.max_size();}

            // element access:
            T& operator[](const key_type& x)
            {
                return ((insert(ft::make_pair(x, T()))).first)->second;
            }
            
            // modifiers:
            pair<iterator, bool> insert(const value_type& new_pair)
            { 
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
                    erase(first);
                    first = tmp;
                }
            }
            
// template < typename T >
// void    swap    (T & lhs, T & rhs)
// {
//     T   tmp = lhs;
//     lhs = rhs;
//     rhs = tmp;
// }
            
            void swap (map& other)
            {
                value_compare   val_comp = other._val_comp;
                allocator_type  alloc = other._alloc;
                key_compare     key_comp = other._key_comp;
                size_t          size = other._size;
                // _Tree           tree = other._tree;           

                other._val_comp = _val_comp;
                other._alloc = _alloc;
                other._key_comp = _key_comp;
                other._size = _size;
                // other._tree = _tree;

                _val_comp = val_comp;
                _alloc = alloc;
                _key_comp = key_comp;
                _size = size;
                // _tree = tree;
                _tree.swap(other._tree);
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

            allocator_type get_allocator() const {return _alloc;}

            // // map operations:
            iterator find(const key_type& key)
            {
                value_type new_pair = ft::make_pair(key, mapped_type());
                return iterator(_tree.TreeSearch(new_pair));
            }
            
            const_iterator find(const key_type& key) const
            {
                value_type new_pair = ft::make_pair(key, mapped_type());
                return const_iterator(_tree.TreeSearch(new_pair));
            }
            
            size_type count(const key_type& key) const
            {
                if (find(key) != end())
                    return 1;
                return 0;
            }
            
            iterator lower_bound(const key_type& key)
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if (!(_key_comp((*it).first, key)))
                        return it;
                    ++it;
                }
                return ite;          
            }
            
            const_iterator lower_bound(const key_type& key) const
            {
                const_iterator cit = begin();
                const_iterator cite = end();

                while (cit != cite)
                {
                    if (!(_key_comp((*cit).first, key)))
                        return cit;
                    ++cit;
                }
                return cite;      
            }
            
            iterator upper_bound(const key_type& key)
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if ((_key_comp(key, (*it).first)))
                        return it;
                    ++it;
                }
                return ite;  
            }
            
            const_iterator upper_bound(const key_type& key) const
            {
                const_iterator cit = begin();
                const_iterator cite = end();

                while (cit != cite)
                {
                    if ((_key_comp(key, (*cit).first)))
                        return cit;
                    ++cit;
                }
                return cite; 
            }
            
            pair<iterator,iterator>
                equal_range(const key_type& key)
            {
                return pair<iterator, iterator>(iterator(lower_bound(key)), iterator(upper_bound(key)));
            }
            
            pair<const_iterator,const_iterator>
                equal_range(const key_type& key) const
            {
                return pair<const_iterator, const_iterator>(const_iterator(lower_bound(key)), const_iterator(upper_bound(key)));
            }

            
                
        private:
            value_compare       _val_comp;
            allocator_type      _alloc;
            key_compare         _key_comp;
            
            size_t               _size;
            _Tree                _tree;
            
    };
        // specialized algorithms:
    template <class _Key, class _T, class _Compare, class _Allocator>
        void swap(map<_Key,_T,_Compare,_Allocator>& lhs, map<_Key,_T,_Compare,_Allocator>& rhs) {lhs.swap(rhs);}
    
    template <class _Key, class _T, class _Compare, class _Allocator>
    bool operator==(const map<_Key,_T,_Compare,_Allocator>& lhs, const map<_Key,_T,_Compare,_Allocator>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), lhs._key_comp());
    }
    
    template <class _Key, class _T, class _Compare, class _Allocator>
    bool operator<(const map<_Key,_T,_Compare,_Allocator>& lhs, const map<_Key,_T,_Compare,_Allocator>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), lhs._key_comp());
    }
    
    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs)
    {
        return (!(lhs == rhs));
    }
        
    template <class Key, class T, class Compare, class Allocator>
    bool operator>(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs)
    {
        return (!(lhs <= rhs));
    }
        
    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs)
    {
       return (lhs > rhs || lhs == rhs);
    }
    
    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs)
    {
        return (lhs < rhs || lhs == rhs);
    }
}
#endif