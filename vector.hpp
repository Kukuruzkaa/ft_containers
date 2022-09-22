/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:36:52 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/22 18:02:43 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP
#include <memory>
#include <cstddef>
#include "type_traits.hpp"
#include "iterator_traits.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <algorithm> 

namespace ft {
	
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		private:
			typedef typename Allocator::template rebind< T >::other _T_alloc;
			
		public:
			//**********MEMMBER TYPES**********
			typedef T                                                   value_type;
			typedef Allocator                                           allocator_type;
			typedef             size_t                  				size_type;
			typedef            	ptrdiff_t                          		difference_type;
			
			typedef typename    _T_alloc::reference               		reference;
			typedef typename    _T_alloc::const_reference         		const_reference;
			typedef typename    _T_alloc::pointer                 		pointer;
			typedef typename    _T_alloc::const_pointer           		const_pointer;
			
			typedef pointer                                             iterator;
			typedef const_pointer                                       const_iterator;
			typedef             ft::reverse_iterator<iterator>         	reverse_iterator; 
			typedef             ft::reverse_iterator<const_iterator>   	const_reverse_iterator;


			//**********MEMBER FUNCTIONS**********  
			explicit vector(const allocator_type & alloc = allocator_type()) 
				: _alloc(alloc), _valloc(alloc), _arr(_valloc.allocate(0)), _size(0), _capacity(0)
			{
				// std::cout << "Default vector constructor" << std::endl;
			}
			
			explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()) 
				: _alloc(alloc), _valloc(alloc), _arr(_valloc.allocate(n)), _size(n), _capacity(n)
			{
				// std::cout << "Parameters constructor" << std::endl;
				for (size_t i = 0; i < _size; ++i)
					_valloc.construct(&_arr[i], val);
			}
			
			template < class InputIt> 
				vector (InputIt first, InputIt last, const allocator_type & alloc = allocator_type(), 
										typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = 0)
			   : _alloc(alloc), _valloc(alloc), _arr(_valloc.allocate(0)), _size(0), _capacity(0)
			{
				// std::cout << "Template constructor" << std::endl;
				this->insert(this->begin(), first, last);
			}
			
			vector (const vector & src)
				: _alloc(src._alloc), _valloc(src._valloc), _arr(_valloc.allocate(src._size)), _size(src._size), _capacity(src._size)
			{
				// std::cout << "Copy constructor" << std::endl;
		 
				for (size_t i = 0; i < _size; ++i)
					_valloc.construct(&_arr[i], src._arr[i]);
			}
		   
			~vector()
			{
				// std::cout << "Destructor" << std::endl;
					
				clear();
				_valloc.deallocate(_arr, _capacity);
			}
			
			vector & operator=(const vector & rhs) 
			{
				clear();
				this->insert(this->begin(), rhs.begin(), rhs.end());
				return *this;
			}

			
			template <class InputIt>
			void                	assign(InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = 0)
			{
				
				clear();
				insert(begin(), first, last);
			}
				
			void                    assign(size_type n, const value_type& val)
			{
				clear();
				if (n > _capacity)
				{
					_valloc.deallocate(_arr, _capacity);
					_arr = _valloc.allocate(n);
					if (!_arr)
						throw::std::bad_alloc();
					_capacity = n;
				}
				for (size_t i = 0; i < n; ++i)
					_valloc.construct(&_arr[i], val);
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
			iterator                begin() {return iterator(_arr);}
			iterator                end() {return iterator(_arr + _size);} 
			const_iterator          begin() const {return const_iterator(_arr);}
			const_iterator          end() const {return const_iterator(_arr + _size);} 
			reverse_iterator        rbegin() {return reverse_iterator(_arr +_size);}
			const_reverse_iterator  rbegin() const {return const_reverse_iterator(_arr +_size);}
			reverse_iterator        rend() {return reverse_iterator(_arr);}
			const_reverse_iterator  rend() const {return const_reverse_iterator(_arr);}

			// Capacity
			bool                    empty() const
			{
				if (_size != 0)
					return false;
				return true;
			}
			
			size_type               size() const {return _size;}
			size_type               max_size() const {return _alloc.max_size();}
			
			void                    reserve(size_type new_cap)
			{
				if (new_cap > max_size()) throw::std::length_error("vector::reserve");
				if (new_cap <= _capacity) return ;
				
				pointer new_arr = _valloc.allocate(new_cap);
				if (!new_arr)
					throw::std::bad_alloc();		
				for (size_t i = 0; i < _size; ++i)
				{
					_valloc.construct(new_arr + i, _arr[i]);
					_valloc.destroy(&_arr[i]);
				}
				_valloc.deallocate(_arr, _capacity);
				_arr = new_arr;
				_capacity = new_cap;
			}
			
			size_type               capacity() const {return _capacity;}
			
			
			void                    resize(size_type n, value_type val = value_type())
			{
				
				if (n < _size)
					erase(begin() + n, end());
				else if (n > _size)
					insert(end(), n - _size, val);
			}

			// **********Modifiers**********
			void                    clear()
			{
				for (pointer it = _arr, ite = _arr + _size; it < ite; ++it)
					_valloc.destroy(it);
				_size = 0;
			}
			
			iterator                insert(iterator pos, const T& value)
			{
				difference_type it = pos - begin();
				
				insert(pos, 1, value);
				return iterator(&_arr[it]);     
			}
			
			void                    insert(iterator pos, size_type count, const T& value)
			{
				difference_type i = pos - begin();
				_insert(count, i);
				pos = _arr + i;
				for (pointer it = pos; it < pos + count; ++it)
				{
					if (it >= _arr + _size)
						_valloc.construct(it, value);
					else
						*it = value;
				}
				_size = _size + count;
			}

			template< class InputIt >
			void                insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = 0)
			{
				difference_type i = pos - begin();
				if (&(*first) > &(*last))
					throw::std::length_error("vector::reserve");
				InputIt	tmp = first;
				size_t	count = 0;
				while (tmp != last)
				{
					tmp++;
					count++;
				}
				_insert(count, i);
				pos = _arr + i;
				for (pointer it = pos; it < pos + count; ++it, ++first)
				{
				
					if (it >= _arr + _size)
						_valloc.construct(it, *first);
					else
						*it = *first;
				}
				_size = _size + count;
			}
			
			iterator                erase(iterator pos)
			{
				return erase(pos, pos + 1);
			}
				
			iterator                erase(iterator first, iterator last)
			{
				difference_type toRemove = last - first;
				iterator tmp = first;
				while (tmp != end() && last != end())
				{
					*tmp = *last;
					tmp++;
					last++;
				}
				for (pointer it = end() - 1; it >= end() - toRemove; --it)
					_valloc.destroy(it);
				_size = _size - toRemove;
				return first;
			}
			
			void                    push_back(const T& value)
			{
				insert(end(), value);
			}
			
			void                    pop_back()
			{
				erase(end() - 1);
			}
			
			void                    swap(vector& rhs)
			{
				T *       arr = rhs._arr;;
				size_t    size = rhs._size;
				size_t    capacity = rhs._capacity;

				rhs._arr = _arr;
				rhs._size = _size;
				rhs._capacity = _capacity;
				
				_arr = arr;
				_size = size;
				_capacity = capacity;
			}

			//**********NON-MEMBER FUNCTIONS**********
			friend bool operator==(const vector& lhs, const vector& rhs)
			{
				if (lhs._size != rhs._size)
					return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}
			friend bool operator!=(const vector& lhs, const vector& rhs)
			{
				return (!(lhs == rhs));
			}
			friend bool operator<(const vector& lhs, const vector& rhs)
			{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
			friend bool operator<=(const vector& lhs, const vector& rhs) 
			{
				return (lhs < rhs || lhs == rhs);
			}
			friend bool operator>(const vector& lhs, const vector& rhs)
			{
				return (!(lhs <= rhs));
			}
			friend bool operator>=(const vector& lhs, const vector& rhs)
			{
				return (lhs > rhs || lhs == rhs);
				// return (!(lhs < rhs));
			}

		private:
			allocator_type  	_alloc;
			_T_alloc			_valloc;
			pointer             _arr; // Should be pointer ?
			size_t         	 	_size;
			size_t          	_capacity;

			template<typename _T>
			const _T	& max(_T const & x, _T const & y)
			{
				if (x < y)
					return y;
				return x;
			}

			void				_insert(size_t count, ptrdiff_t i)
			{
				if (size() + count > capacity()) 
					reserve(max<size_type>(count + size(), 2 * size()));
				size_t nbElem = _size - i;
				for (pointer it = end() + count - 1; it > end() + count - 1 - nbElem; --it)
				{
					if (it >= end())
						_valloc.construct(it, *(it - count));
					else
						*it = *(it - count);
				}
			}		
	};

	template <class T, class Alloc> 
	void swap(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs) {lhs.swap(rhs);}
}
#endif
