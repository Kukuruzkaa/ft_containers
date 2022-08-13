/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:36:52 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/13 18:26:30 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP
#include <iostream>
#include <vector>

namespace ft {
    
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
        //MEMMBER TYPES  
        typedef T                                                   value_type;
        typedef Allocator                                           allocator_type;
        typedef             std::size_t                             size_type;
        typedef             std::ptrdiff_t                          difference_type;
        typedef typename    Allocator::reference                    reference;
        typedef typename    Allocator::const_reference              const_reference;
        typedef typename    Allocator::pointer                      pointer;
        typedef typename    Allocator::const_pointer                const_pointer;
        typedef T                                                   iterator;
        typedef const T                                             const_iterator;
        typedef             std::reverse_iterator<iterator>         reverse_iterator;
        typedef             std::reverse_iterator<const_iterator>   const_reverse_ieterator;

        // MEMBER FUNCTIONS  
        explicit vector(const Allocator & alloc);
        explicit vector (size_type count, const T & value = T(), const Allocator & alloc = Allocator());
        
        template < class InputIt>
        vector (InputIt first, InputIt last, class cnst Allocator & alloc = Allocator());
        vector (const vector & src);
        ~vector();
        
        vector & operator=(const vector & rhs);
        
        template <class InputIterator>
            void                assign(InputIterator first, InputIterator last);
        void                    assign(size_type count, const T& value);

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

        template< class InputIt >
            void                insert(iterator pos, InputIt first, InputIt last);
        iterator                erase(iterator pos);
        iterator                erase(iterator first, iterator last);
        void                    push_back(const T& value);
        void                    pop_back();
        void                    swap(vector& rhs);

        // NON-MEMBER FUNCTIONS
        bool operator==(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
        bool operator!=(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
        bool operator<(const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
        bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs);
        bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
        bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

        template< class T, class Alloc > void swap(std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs);
    }
};

#endif