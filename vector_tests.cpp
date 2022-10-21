/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:40:53 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/21 22:27:05 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define PRINT(a)	std::cout	<< std::boolalpha << #a << " == " << a << std::endl;
#define PRINT_CMD(cmd)  std::cout   << #cmd << std::endl; \
                        cmd;

template<typename T>
void    vec_print(T & vec)
{
    for (typename T::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

void    vectorTest(void)
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
    
    std::cout << "access to the vector element via operator []: " << std::endl;
    NAMESPACE::vector<int> int_vec(10);
    for (size_t i = 0; i < int_vec.size(); i++)
        int_vec[i] = i;
    vec_print(int_vec);

    PRINT(my_char_vector[0]);
    std::cout << std::endl;
    std::cout << "access to the vector element using AT: " << std::endl;
    for (size_t i = 0; i < int_vec.size(); i++)
        PRINT(myvector.at(i));
    std::cout << std::endl;
    
    std::cout << "access to the vector element using FRONT: " << std::endl;
    PRINT(foo.front());
    std::cout << std::endl;
    
    std::cout << "access to the vector element using BACK: " << std::endl;
    PRINT(bar.back());
    PRINT(bar.back() - 1);
    std::cout << std::endl;

    std::cout << "******* FT::VECTOR::MODIFIERS *******" << std::endl;
    std::cout << std::endl;

    std::cout << "-- ASSIGN function -- : " << std::endl;
    std::cout << std::endl;
    
    first.assign(7, 55);
    std::cout << "assigning first with parameteres: " << std::endl;
    vec_print(first);
    std::cout << std::endl;

    second.assign(bar.begin(), bar.begin() + 50);
    std::cout << "assigning second with the iterator and the bar: " << std::endl;
    vec_print(second);
    std::cout << std::endl;
    
    int myints[] = {999, 7, 8};
    third.assign(myints,myints+3);
    std::cout << "assigning third from array: " << std::endl;
    vec_print(third);
    std::cout << std::endl;

    std::cout << "-- PUSH_BACK function -- : " << std::endl;
    std::cout << std::endl;
    
    NAMESPACE::vector<std::string> string_vec;

    string_vec.push_back("Creating");
    string_vec.push_back(" new");
    string_vec.push_back(" string_vec with");
    string_vec.push_back(" push_back.");
    vec_print(string_vec);
    std::cout << std::endl;

    std::cout << "-- POP_BACK function -- : " << std::endl;
    std::cout << std::endl;

    while (!string_vec.empty())
    {
        vec_print(string_vec);
        string_vec.pop_back(); 
    }
    vec_print(string_vec);
    
    std::cout << "-- INSERT function -- : " << std::endl;
    std::cout << std::endl;
    
    NAMESPACE::vector<std::string> abc_vec;
    NAMESPACE::vector<std::string>::iterator str_it = abc_vec.begin();
    abc_vec.insert(str_it, "a b c");
    str_it = abc_vec.end();
    abc_vec.insert(str_it, "d e f");
    abc_vec.insert(abc_vec.end(), "g h i");
    std::cout << "printing abc_vec after 1 insert: " << std::endl;
    vec_print(abc_vec);
    std::cout << std::endl;
    
    str_it = abc_vec.begin() + 1;
    abc_vec.insert(str_it, 2, " x x ");
    std::cout << "printing abc_vec after 2 insert: " << std::endl;
    vec_print(abc_vec);
    std::cout << std::endl;

    string_vec.insert(string_vec.begin(), abc_vec.begin() + 1, abc_vec.end() - 2);
    std::cout << "printing string_vec after 3 insert by pos + range of the abc_vec: " << std::endl;
    vec_print(string_vec);
    std::cout << std::endl;

    std::cout << "-- ERASE function -- : " << std::endl;
    std::cout << std::endl;
    
    string_vec.push_back(" o o ");
    std::cout << "printing string_vec before erase: " << std::endl;
    vec_print(string_vec);
    string_vec.erase(string_vec.end() - 1);
    std::cout << "printing string_vec after erase: " << std::endl;
    vec_print(string_vec);
    std::cout << std::endl;
    
    std::cout << "printing abc_vec before erase: " << std::endl;
    vec_print(abc_vec);
    abc_vec.erase(abc_vec.begin(), abc_vec.end() - 2);
    std::cout << "printing abc_vec after erase: " << std::endl;
    vec_print(abc_vec);
    std::cout << std::endl;

    std::cout << "-- SWAP function -- : " << std::endl;
    std::cout << std::endl;

    abc_vec.swap(string_vec);
    std::cout << "printing abc_vec after swap: " << std::endl;
    vec_print(abc_vec);
    std::cout << "printing string_vec after swap: " << std::endl;
    vec_print(string_vec);
  
    std::cout << std::endl;

    std::cout << "-- CLEAR function -- : " << std::endl;
    std::cout << std::endl;

    PRINT_CMD(abc_vec.clear());
    PRINT(abc_vec.size());
   
    PRINT_CMD(string_vec.clear());
    PRINT(string_vec.size());
    std::cout << std::endl;
    
    std::cout << "-- OPERATORS -- : " << std::endl;
    std::cout << std::endl;

    NAMESPACE::vector<int> fo_o (3,100); 
    NAMESPACE::vector<int> ba_r (2,200);   

    PRINT((fo_o == ba_r));
    PRINT((fo_o != ba_r));
    PRINT((fo_o < ba_r));
    PRINT((fo_o > ba_r));
    PRINT((fo_o <= ba_r));
    PRINT((fo_o >= ba_r));
}