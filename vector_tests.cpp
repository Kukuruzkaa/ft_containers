/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:40:53 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/17 21:46:09 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define PRINT(a)	std::cout	<< #a << " == " << a << std::endl;

template<typename T>
void    vec_print(T & vec)
{
    for (typename T::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

int     main(void)
{
    std::cout << std::endl;
    std::cout << "******* FT::VECTOR::CONSTRUCTORS::ITERATORS*******" << std::endl;
    std::cout << std::endl;

    NAMESPACE::vector<int> first; // default constructor
    vec_print(first);                             
    NAMESPACE::vector<int> second (4,100); // with parameters 
    vec_print(second);                         
    NAMESPACE::vector<int> third (second.begin(),second.end()); // constructor with the range of elements 
    vec_print(third);  
    NAMESPACE::vector<int> fourth (third); // copy constrcutor 
    vec_print(fourth);
    std::cout << std::endl;                      

    NAMESPACE::vector<int> foo (3,7);
    std::cout << "original foo with the size of: " << foo.size() << std::endl;
    vec_print(foo); 
    NAMESPACE::vector<int> bar (5,8);
    std::cout << "original bar with the size of: " << bar.size() << std::endl;
    vec_print(bar); 
    std::cout << std::endl;
    
    bar = foo; // operator =
    std::cout << "bar = foo with the size of: " << bar.size() << std::endl;
    vec_print(bar);
    foo = NAMESPACE::vector<int>();
    std::cout << "foo = new empty vector with the size of: " << foo.size() << std::endl;
    vec_print(foo);

    NAMESPACE::vector<int> myvector;
    for (int i = 1; i <= 10; i++) 
        myvector.push_back(i);

    NAMESPACE::vector<int>::iterator it = myvector.begin();
    NAMESPACE::vector<int>::const_iterator cit = it;
    NAMESPACE::vector<int>::const_iterator cite = myvector.end();
    
    std::cout << "myvector contains:";
    for (; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    ++cit;
    std::cout << "myvector cit value:";
    for (; cit != cite; ++cit)
        std::cout << ' ' << *cit;
    std::cout << std::endl;
    std::cout << std::endl;
    
    NAMESPACE::vector<char> my_char_vector;
    for (int i = 'a'; i <= 'g'; i++) 
        my_char_vector.push_back(i);
    std::cout << "original my_char_vector contains:";
    vec_print(my_char_vector);
        
    NAMESPACE::vector<char>::reverse_iterator char_rit = my_char_vector.rbegin();
    NAMESPACE::vector<char>::const_reverse_iterator char_crit = char_rit;
    NAMESPACE::vector<char>::const_reverse_iterator char_crite = my_char_vector.rend();

    std::cout << "my_char_vector contains:";
    for (; char_rit != my_char_vector.rend(); ++char_rit)
        std::cout << ' ' << *char_rit;
    std::cout << std::endl;

    ++char_crit;
    --char_crite;
    std::cout << "my_char_vector char_cit value:";
    for (; char_crit != char_crite; ++char_crit)
        std::cout << ' ' << *char_crit;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "******* FT::VECTOR::CAPACITY*******" << std::endl;
    std::cout << std::endl;

    PRINT(myvector.size());
    PRINT(my_char_vector.size());
    for (size_t i = 0; i <= 20; ++i)
        myvector.push_back(i);
    PRINT(myvector.size());
    PRINT(myvector.capacity());
    PRINT(myvector.max_size());
    std::cout << std::endl;
    
    std::cout << "before resize myvector contains:";
    vec_print(myvector);
    std::cout << "after first resize:";
    myvector.resize(20);
    vec_print(myvector);
    PRINT(myvector.size());
    myvector.resize(45);
    std::cout << "after second resize:";
    vec_print(myvector);
    PRINT(myvector.size());
    
    if (foo.empty())
        std::cout << "foo is empty, because it's size is " << foo.size() << std::endl;
    std::cout << std::endl;
    
    std::cout << "bar => capacity before reserve: " << bar.capacity() << std::endl;
    size_t size = bar.capacity();
    bar.reserve(100);  
    std::cout << "making bar grow:\n";
    for (int i = 0; i < 100; ++i) 
    {
        bar.push_back(i);
        if (size != bar.capacity()) 
        {
            size = bar.capacity();
            std::cout << "capacity changed: " << size << '\n';
        }
    }
    std::cout << std::endl;
    
    std::cout << "******* FT::VECTOR::ELEMENT ACCESS *******" << std::endl;
    std::cout << std::endl;
    
    NAMESPACE::vector<int> int_vec(10);
    for (size_t i = 0; i < int_vec.size(); i++)
        int_vec[i] = i;
    vec_print(int_vec);
    
    return 0;
}