/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:36:52 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/25 00:59:56 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP
#include <iostream>
#include <memory>
#include <iterator>
#include <vector>
#include "type_traits.hpp"
#include "iterator_traits.hpp"


namespace ft {
    
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            //**********MEMMBER TYPES**********
            typedef T                                                   value_type;
            typedef Allocator                                           allocator_type;
            typedef             size_t                                  size_type;
            typedef             ptrdiff_t                               difference_type;
            
            typedef typename    allocator_type::reference               reference;
            typedef typename    allocator_type::const_reference         const_reference;
            typedef typename    allocator_type::pointer                 pointer;
            typedef typename    allocator_type::const_pointer           const_pointer;
            
            typedef pointer                                             iterator;
            // typedef const T                                             const_iterator; // TO DO
            // typedef             std::reverse_iterator<iterator>         reverse_iterator; // TO DO
            // typedef             std::reverse_iterator<const_iterator>   const_reverse_ieterator; // TO DO

            //**********MEMBER FUNCTIONS**********  
            explicit vector(const allocator_type & alloc = allocator_type()) 
                : _arr(NULL), _size(0), _capacity(0), _alloc(alloc) 
            {
                std::cout << "Default vector constructor" << std::endl;
            }
            
            explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()) 
                : _size(n), _capacity(n), _alloc(alloc)
            {
                std::cout << "Parameters constructor" << std::endl;
                _arr = _alloc.allocate(_capacity);
                if (!_arr)
                    throw::std::bad_alloc();
                for (size_t i = 0; i < _size; ++i)
                    _alloc.construct(&_arr[i], val);
            }
            
            // template < class InputIt>
                // vector (InputIt first, InputIt last, const allocator_type & alloc = alocator_type()) // TO DO plus tard
            //     {
            //         // ???
                    
            //     }
            
            vector (const vector & src)
                : _size(src._size), _capacity(src._capacity), _alloc(src._alloc)
            {
                std::cout << "Copy constructor" << std::endl;
         
                _arr = _alloc.allocate(_capacity);
                for (size_t i = 0; i < _size; ++i)
                    _alloc.construct(&_arr[i], src._arr[i]);
            }
           
            ~vector()
            {
                std::cout << "Destructor" << std::endl;
                for (size_t i = 0; i < _size; ++i)
                    _alloc.destroy(&_arr[i]);
                _alloc.deallocate(_arr, _capacity);
            }
            
            // vector & operator=(const vector & rhs) //? ; may throw exception? // TO DO
            // {
            //     for (size_t i = 0; i < _size; ++i)
            //         this->_arr[i] = rhs._arr[i];
            //     this->_size = rhs._size;
            //     this->_capacity = rhs._capacity;
            //     this->_alloc = rhs._alloc;
            //     return *this;
            // }

            
            // template <class InputIterator>
            //     void                assign(InputIterator first, InputIterator last); //??? TO DO plus tard
                
            void                    assign(size_type n, const value_type& val)
            {
                clear();
                if (n > _capacity)
                {
                    _alloc.deallocate(_arr, _capacity);
                    _arr = _alloc.allocate(n);
                    if (!_arr)
                        throw::std::bad_alloc();
                    _capacity = n;
                }
                for (size_t i = 0; i < n; ++i)
                    _alloc.construct(&_arr[i], val);
                _size = n;
            }

            allocator_type          get_allocator() const {return _alloc;}

            // **********Element access**********
            reference               at(size_type pos)
            {
                if (pos >= _size)
                    throw::std::out_of_range("Out of range");
                return (_arr[pos]);
            }
            
            const_reference         at(size_type pos) const
            {
                if (pos >= _size)
                    throw::std::out_of_range("Out of range");
                return (_arr[pos]);
            }
            
            reference               operator[](size_type pos) {return _arr[pos];}
            const_reference         operator[](size_type pos) const {return _arr[pos];}
            reference               front() {return _arr[0];}
            const_reference         front() const {return _arr[0];}
            reference               back() {return _arr[_size - 1];}
            const_reference         back() const {return _arr[_size - 1];}

            // **********Iterators**********
            iterator                begin() {return _arr;}
            iterator                end() {return _arr + _size;} 
            // const_iterator          begin() const {return _arr;}
            // const_iterator          end() const {return _arr + _size;} 
            // reverse_iterator        rbegin();
            // const_reverse_iterator  rbegin() const;
            // reverse_iterator        rend();
            // const_reverse_iterator  rend() const;

            // Capacity
            bool                    empty() const
            {
                if(_size != 0)
                    return false;
                return true;
            }
            
            size_type               size() const {return _size;}
            size_type               max_size() const {return _alloc.max_size();}
            
            void                    reserve(size_type new_cap)
            {
                if (new_cap < _capacity)
                    return ;
                if (new_cap > max_size())
                    throw::std::length_error("Length error");
                T * new_arr;
                new_arr = _alloc.allocate(new_cap);
                if (!new_arr)
                    throw::std::bad_alloc();
                size_t i;
                for (i = 0; i < _size; ++i)
                    _alloc.construct(&new_arr[i], _arr[i]);
                clear();
                _alloc.deallocate(_arr, _capacity);
                _arr = new_arr;
                _capacity = new_cap;
            }
            
            size_type               capacity() const {return _capacity;}
            
            void                    resize(size_type n, value_type val = value_type())
            {
                if (n > max_size())
                    throw::std::length_error("Length error");
                if (n < _size)
                {
                    for (size_t i = n; i > _size; --i)
                        pop_back();
                }
                if (n > _capacity)
                    reserve(n);
                for (size_t i = _size; i < n; ++i)
                    push_back(val);
            }

            // **********Modifiers**********
            void                    clear()
            {
                for (size_t i = 0; i < _size; ++i)
                 _alloc.destroy(&_arr[i]);
            }
            
            iterator                insert(iterator pos, const T& value)
            {
                difference_type index = pos - begin();

                insert(pos, 1, value);
                return iterator(&_arr[index]);     
            }
            
            void                    insert(iterator pos, size_type count, const T& value)
            {
                difference_type index = pos - begin();
                 
                if (_size + count > _capacity)
                    reserve(_size + count);
                size_t toMove = _size - index;
                for (pointer it = end() + count - 1; it >= end() + count - 1 - toMove; --it) 
                    _alloc.construct(it, *(it - count));
                pos = _arr + index;
                for (pointer it = pos; it < pos + count; ++it)
                    *it = value;   
                _size = _size + count;
            }

            // template< class InputIt >
            //     void                insert(iterator pos, InputIt first, InputIt last);
            
            iterator                erase(iterator pos)
            {
                return erase(pos, pos + 1);
            }
            
            iterator                erase(iterator first, iterator last)
            {
        
                difference_type toRemove = last - first;
            
                while (first != end())
                {
                    *first = *last;
                    first++;
                    last++;
                }
                for (pointer it = end(); it > end() - toRemove; --it)
                    _alloc.destroy(it);
                _size = _size - toRemove;
                return first;
            }
            
            void                    push_back(const T& value)
            {
                if (_capacity == _size)
                    reserve (2 * _size);
                _alloc.construct(&_arr[_size], value);
                ++_size;    
            }
            
            void                    pop_back()
            {
                _alloc.destroy(&_arr[_size]);
                 _size--;  
            }
            
            void                    swap(vector& rhs);

            //**********NON-MEMBER FUNCTIONS**********
            friend bool operator==(const vector& lhs, const vector& rhs) {return lhs == rhs;}
            friend bool operator!=(const vector& lhs, const vector& rhs) {return lhs != rhs;}
            friend bool operator<(const vector& lhs, const vector& rhs) {return lhs < rhs;}
            friend bool operator<=(const vector& lhs, const vector& rhs) {return lhs <= rhs;}
            friend bool operator>(const vector& lhs, const vector& rhs) {return lhs > rhs;}
            friend bool operator>=(const vector& lhs, const vector& rhs) {return lhs >= rhs;}


        private:
            T *             _arr;
            size_t          _size;
            size_t          _capacity;
            allocator_type  _alloc;
    };

    template <class T, class Alloc> 
    void swap(std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs) {lhs.swap(rhs);}
}


void    print(ft::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec.begin()[i] << ' ';
    std::cout << std::endl;
}

#endif