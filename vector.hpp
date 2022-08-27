/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:36:52 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/27 23:28:39 by ddiakova         ###   ########.fr       */
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


namespace ft {
	
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			//**********MEMMBER TYPES**********
			typedef T                                                   		value_type;
			typedef Allocator                                           		allocator_type;
			typedef             	size_t                  					size_type;
			typedef            		ptrdiff_t                          		difference_type;
			
			typedef typename    allocator_type::reference               reference;
			typedef typename    allocator_type::const_reference         const_reference;
			typedef typename    allocator_type::pointer                 pointer;
			typedef typename    allocator_type::const_pointer           const_pointer;
			
			typedef pointer                                             iterator;
			typedef const_pointer                                       const_iterator;
			typedef             std::reverse_iterator<iterator>         reverse_iterator; 
			typedef             std::reverse_iterator<const_iterator>   const_reverse_iterator; 

			//**********MEMBER FUNCTIONS**********  
			explicit vector(const allocator_type & alloc = allocator_type()) 
				: _arr(NULL), _size(0), _capacity(0), _alloc(alloc) 
			{
				// std::cout << "Default vector constructor" << std::endl;
			}
			
			explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()) 
				: _size(n), _capacity(n), _alloc(alloc)
			{
				// std::cout << "Parameters constructor" << std::endl;
				_arr = _alloc.allocate(_capacity);
				if (!_arr)
					throw::std::bad_alloc();
				for (size_t i = 0; i < _size; ++i)
					_alloc.construct(&_arr[i], val);
			}
			
			template < class InputIt> 
				vector (InputIt first, InputIt last, const allocator_type & alloc = allocator_type(), 
										typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = 0)
			   : _arr(NULL), _size(0), _capacity(0), _alloc(alloc) 
			{
				// std::cout << "Template constructor" << std::endl;
				this->insert(this->begin(), first, last);
			}
			
			vector (const vector & src)
				: _size(src._size), _capacity(src._capacity), _alloc(src._alloc)
			{
				// std::cout << "Copy constructor" << std::endl;
		 
				_arr = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; ++i)
					_alloc.construct(&_arr[i], src._arr[i]);
			}
		   
			~vector()
			{
				// std::cout << "Destructor" << std::endl;
				if (!empty())
				{
					for (size_t i = 0; i < _size; ++i)
						_alloc.destroy(&_arr[i]);
					clear();
				}
				if (_capacity)
					_alloc.deallocate(_arr, _capacity);
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
			const_iterator          begin() const {return _arr;}
			const_iterator          end() const {return _arr + _size;} 
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
				if (new_cap < _capacity)
					return ;
				if (new_cap > max_size())
					throw::std::length_error("vector::reserve");
				// ft::vector<T>	tmp(*this);
				T * new_arr;
				new_arr = _alloc.allocate(new_cap);
				if (!new_arr)
					throw::std::bad_alloc();
				size_t i;
				for (i = 0; i < _size; ++i)
					_alloc.construct(&new_arr[i], _arr[i]);
				size_t	size_tmp = _size;
				clear();
				_size = size_tmp;
				if (_capacity)
					_alloc.deallocate(_arr, _capacity);
				// *this = tmp;
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
					for (size_t i = _size; i > n; --i)
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
				
				if (_size + count > _capacity)
					reserve(std::max((_size + count), (_size * 2)));
				size_t nbElem = _size - i;
				for (pointer it = end() + count - 1; it > end() + count - 1 - nbElem; --it)  
					_alloc.construct(it, *(it - count));
				pos = _arr + i;
				for (pointer it = pos; it < pos + count; ++it)
					*it = value;   
				_size = _size + count;
			}

			template< class InputIt >
			void                insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = 0)
			{
				difference_type i = pos - begin();
				
				InputIt	tmp = first;
				size_t	range = 0;
				while (tmp != last)
				{
					tmp++;
					range++;
				} 
				if (_size + range > _capacity)
					reserve(std::max((_size + range), (_size * 2)));
				size_t nbElem = _size - i;
				for (pointer it = end() + range - 1; it > end() + range - 1 - nbElem; --it) 
					_alloc.construct(it, *(it - range));
				pos = _arr + i;
				for (pointer it = pos; it < pos + range; ++it, ++first)
					*it = *first;   
				_size = _size + range;
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
				for (pointer it = end() - 1; it > end() - toRemove; --it)
					_alloc.destroy(it);
				_size = _size - toRemove;
				return first;
			}
			
			void                    push_back(const T& value)
			{
				if (_capacity == 0)
					reserve (1);
				else if (_capacity == _size)
					reserve (2 * _size);
				_alloc.construct(&_arr[_size], value);
				_size++;    
			}
			
			void                    pop_back()
			{
				if (_size)
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
			T *             _arr;
			size_t          _size;
			size_t          _capacity;
			allocator_type  _alloc;
	};

	template <class T, class Alloc> 
	void swap(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs) {lhs.swap(rhs);}
}
#endif