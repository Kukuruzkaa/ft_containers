/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:36:52 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/14 22:08:05 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP
#include <iostream>
#include <memory>
#include <iterator>

namespace ft {
    
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            //MEMMBER TYPES  
            typedef T                                                   value_type;
            typedef Allocator                                           allocator_type;
            typedef             size_t                                  size_type;
            typedef             ptrdiff_t                               difference_type;
            
            typedef typename    allocator_type::reference               reference;
            typedef typename    allocator_type::const_reference         const_reference;
            typedef typename    allocator_type::pointer                 pointer;
            typedef typename    allocator_type::const_pointer           const_pointer;
            
            typedef pointer                                                   iterator;
            // typedef const T                                             const_iterator;
            // typedef             std::reverse_iterator<iterator>         reverse_iterator;
            // typedef             std::reverse_iterator<const_iterator>   const_reverse_ieterator;

            // MEMBER FUNCTIONS  
            explicit vector(const allocator_type & alloc = allocator_type()) 
                : _arr(NULL), _size(0), _capacity(0), _alloc(alloc) {}
            
            explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()) 
                : _size(n), _capacity(n), _alloc(alloc)
            {
                _arr = _alloc.alocate(_capacity);
                for (size_t i = 0; i < _size; ++i)
                    _alloc.construct(&_arr[i], val);
            }
            
            // template < class InputIt>
            //     vector (InputIt first, InputIt last, const allocator_type & alloc = alocator_type())
            //     {
            //         // ???
                    
            //     }
            
            vector (const vector & src)
                : _size(src._size), _capacity(src._capacity), _alloc(src._alloc)
            {
                // capacity > max_size ?
                _arr = _alloc.allocate(_capacity);
                for (size_t i = 0; i < _size; ++i)
                    _alloc.construct(&_arr[i], src._arr[i]);
            }
           
            ~vector()
            {
                for (size_t i = 0; i < _size; ++i)
                    _alloc.destroy(&_arr[i]);
                _alloc.deallocate(_arr, _capacity);
            }
            
            vector & operator=(const vector & rhs) //? ; may throw exception?
            {
                for (size_t i = 0; i < _size; ++i)
                    this->_arr[i] = rhs._arr[i];
                this->_size = rhs._size;
                this->_capacity = rhs._capacity;
                this->_alloc = rhs._alloc;
                return this*;
            }
            
            // template <class InputIterator>
            //     void                assign(InputIterator first, InputIterator last); //???
                
            void                    assign(size_type n, const value_type& val);

            allocator_type          get_allocator() const;

            // Element access
            reference               at(size_type pos);
            const_reference         at(size_type pos) const;
            reference               operator[](size_type pos);
            const_reference         operator[](size_type pos) const;
            reference               front();
            const_reference         front() const;
            reference               back();
            const_reference         back() const;
            T *                     data();
            const T *               data() const;

            // Iterators
            // iterator                begin();
            // const_iterator          begin() const;
            // iterator                end();
            // const_iterator          end() const;
            // reverse_iterator        rbegin();
            // const_reverse_iterator  rbegin() const;
            // reverse_iterator        rend();
            // const_reverse_iterator  rend() const;

            // Capacity
            bool                    empty() const;
            size_type               size() const;
            size_type               max_size() const;
            void                    reserve(size_type new_cap);
            size_type               capacity() const;
            void                    resize(size_type count);
            // void                 resize(size_type count, T value = T());

            // Modifiers
            void                    clear();
            iterator                insert(iterator pos, const T& value);
            void                    insert(iterator pos, size_type count, const T& value);

            // template< class InputIt >
            //     void                insert(iterator pos, InputIt first, InputIt last);
            iterator                erase(iterator pos);
            iterator                erase(iterator first, iterator last);
            void                    push_back(const T& value);
            void                    pop_back();
            void                    swap(vector& rhs);

            // NON-MEMBER FUNCTIONS
            friend bool operator==(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs) {return lhs == rhs;}
            friend bool operator!=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs) {return lhs != rhs;}
            friend bool operator<(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs) {return lhs < rhs;}
            friend bool operator<=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs) {return lhs <= rhs;}
            friend bool operator>(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs) {return lhs > rhs;}
            friend bool operator>=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs) {return lhs >= rhs;}


        private:
            T *             _arr;
            
            size_t          _size;
            size_t          _capacity;
            allocator_type  _alloc;
    };

    template <class T, class Alloc> 
    void swap(std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs) {lhs.swap(rhs);}
}

#endif