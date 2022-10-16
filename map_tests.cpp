/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:49:07 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/16 19:15:23 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "map.hpp"
#include <map>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define PRINT(a)	std::cout	<< #a << " == " << a << std::endl;

int     main(void)
{
    std::cout << std::endl;
    std::cout << "******* FT::MAP::CONSTRUCTORS::ITERATORS*******" << std::endl;
    std::cout << std::endl;

    NAMESPACE::map<char, int>           first;

    first['a'] = 10;
    first['b'] = 30;
    first['c'] = 50;
    first['d'] = 70;

    NAMESPACE::map<char, int>::iterator it = first.begin();
    NAMESPACE::map<char, int>::iterator ite = first.end();

    for (; it != ite; ++it)
    {
        PRINT(it->first);
        PRINT(it->second);
        std::cout << std::endl;
    }   

    NAMESPACE::map<char, int> second (first.begin(),first.end());
    NAMESPACE::map<char, int>::const_iterator cit = first.begin();
    NAMESPACE::map<char, int>::const_iterator cite = ite;
    for (; cit != cite; ++cit)
    {
        PRINT(cit->first);
        PRINT(cit->second);
        std::cout << std::endl;
    }  
    NAMESPACE::map<char, int> third (second);
    NAMESPACE::map<char, int>::const_reverse_iterator crit = third.rbegin();
    NAMESPACE::map<char, int>::const_reverse_iterator crite = third.rend();
    for (; crit != crite; ++crit)
    {
        PRINT(crit->first);
        PRINT(crit->second);
        std::cout << std::endl;
    }
      
    NAMESPACE::map<char, int> forth = first;
    for (NAMESPACE::map<char, int>::reverse_iterator rit = forth.rbegin(); rit != forth.rend(); ++rit)
    {
        PRINT(rit->first);
        PRINT(rit->second);
        std::cout << std::endl;
    }


    std::cout << "******* FT::MAP::CAPCITY *******" << std::endl;
    std::cout << std::endl;

    NAMESPACE::map<char, int>   mymap;

    mymap['a'] = 00;
    mymap['b'] = 11;
    mymap['c'] = 22;
    mymap['d'] = 33;
    mymap['e'] = 44;
    mymap['f'] = 55;
    mymap['g'] = 66;
    mymap['h'] = 77;
    mymap['i'] = 88;
    mymap['j'] = 99;
    size_t map_size = mymap.size();
    PRINT(map_size);
    
    while (!mymap.empty())
    {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
    }
    if (mymap.empty())
        std::cout << "mymap is empty :)" << std::endl;
    map_size = mymap.size();
    PRINT(map_size);
    std::cout << std::endl;


    std::cout << "******* FT::MAP::ELEMENT ACCESS *******" << std::endl;
    std::cout << std::endl;

    NAMESPACE::map<char, std::string> my_map;
    
    my_map['a'] = "the first element";
    my_map['b'] = "the second element";
    my_map['c'] = my_map['b'];

    PRINT(my_map['a']);
    PRINT(my_map['b']);
    PRINT(my_map['c']);
    PRINT(my_map['d']);
    std::string & ref_to_d_element = my_map['d'];
    PRINT(ref_to_d_element);

    PRINT(my_map.at('c'));
    // PRINT(my_map.at('e'));
    std::cout << std::endl;


    std::cout << "******* FT::MAP::MODIFIERS *******" << std::endl;
    std::cout << std::endl;

    std::cout << "1. -- First INSERT function version - inserting pair: --" << std::endl;
    my_map['d'] = "ex-empty string";
    my_map.insert(NAMESPACE::pair<char, std::string>('e', "new element"));
    my_map.insert(NAMESPACE::pair<char, std::string>('f', "another element"));

    NAMESPACE::pair<NAMESPACE::map<char, std::string>::iterator,bool> ret;
    ret = my_map.insert(NAMESPACE::pair<char, std::string>('b', "test") );
    if (ret.second == false) {
        std::cout << "element 'b' already existed";
        std::cout << " with a value of " << ret.first->second << std::endl;
    }

    std::cout << "Printing my_map: " << std::endl;
    for (NAMESPACE::map<char, std::string>:: iterator it = my_map.begin(); it != my_map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "2. -- Second INSERT function version - inserting with iterator position: --" << std::endl;
    it = mymap.begin();
    mymap.insert (it, NAMESPACE::pair<char,int>('z',777));  
    mymap.insert (it, NAMESPACE::pair<char,int>('q',999));
    mymap.insert (it, NAMESPACE::pair<char,int>('c',888));
    
    std::cout << "Printing mymap: " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = mymap.begin(); it != mymap.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << std::endl;
    ++it;

    std::cout << "3. -- Third INSERT function version (range insertion): --" << std::endl;
    NAMESPACE::map<char,int> new_map;
    new_map.insert(mymap.begin(),mymap.find('q'));
    std::cout << "Printing new_map: " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = new_map.begin(); it != new_map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "1. -- First ERASE function version - erasing by iterator: --" << std::endl;
    
    NAMESPACE::map<int, int> erase_map;
	NAMESPACE::map<int, int>::iterator	it_erase = erase_map.begin();
	for (int i = 1; i < 10; ++i)
    {
		it_erase = erase_map.insert(it_erase, NAMESPACE::pair<int, int>(i, i));
        std::cout << it_erase->first << " : " << it_erase->second << std::endl;
    }

	it_erase = erase_map.find(2);
    erase_map.erase(it_erase);
    it_erase = erase_map.begin();
    std::cout << std::endl;
    std::cout << "after erase: " << std::endl; 
    for (; it_erase != erase_map.end(); ++it_erase)
        std::cout << it_erase->first << " : " << it_erase->second << std::endl;
    std::cout << std::endl;

    std::cout << "2. -- Second ERASE function version - erasing by key: --" << std::endl;
	erase_map.erase(5);
    it_erase = erase_map.begin();
    for (; it_erase != erase_map.end(); ++it_erase)
        std::cout << it_erase->first << " : " << it_erase->second << std::endl;
    std::cout << std::endl;

    std::cout << "3. -- Third ERASE function version - erasing by range: --" << std::endl;
    it_erase = erase_map.find(4);
    erase_map.erase(it_erase, erase_map.end());
    it_erase = erase_map.begin();
    for (; it_erase != erase_map.end(); ++it_erase)
        std::cout << it_erase->first << " : " << it_erase->second << std::endl;
    std::cout << std::endl;

    std::cout << "-- SWAP function -- : " << std::endl;
    std::cout << std::endl;
    std::cout << "Printing mymap before swap : " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " : " << it->second << std::endl;
        
    std::cout << "Printing first before swap : " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = first.begin(); it != first.end(); ++it)
        std::cout << it->first << " : " << it->second << std::endl;
        
    mymap.swap(first);
    std::cout << "Printing mymap after swap : " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " : " << it->second << std::endl;

    std::cout << "Printing first after swap : " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = first.begin(); it != first.end(); ++it)
        std::cout << it->first << " : " << it->second << std::endl;
    std::cout << std::endl;
    
    std::cout << "-- CLEAR function -- : " << std::endl;
    first.clear();
    std::cout << "Printing first after clear : " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = first.begin(); it != first.end(); ++it)
        std::cout << it->first << " : " << it->second << std::endl;

    std::cout << "******* FT::MAP::OBSERVERS *******" << std::endl;
    std::cout << std::endl;

    std::cout << "-- KEY_COMP function -- : " << std::endl;

    NAMESPACE::map<char,int> foo;

    NAMESPACE::map<char,int>::key_compare mycomp = foo.key_comp();

    foo['a']=100;
    foo['b']=200;
    foo['c']=300;

    std::cout << "foo contains: " << std::endl;

    char highest = foo.rbegin()->first;  

    NAMESPACE::map<char,int>::iterator it_foo = foo.begin();
    do {
        std::cout << it_foo->first << " : " << it_foo->second << std::endl;
    } while (mycomp((*it_foo++).first, highest));
    std::cout << std::endl;

    std::cout << "-- VALUE_COMP function -- : " << std::endl;
    NAMESPACE::map<char,int> bar;

    bar['x']=1001;
    bar['y']=2002;
    bar['z']=3003;

    std::cout << "bar contains: " << std::endl;

    NAMESPACE::pair<char, int> _highest = *bar.rbegin();          // last element

    NAMESPACE::map<char, int>::iterator it_bar = bar.begin();
    do {
        std::cout << it_bar->first << " : " << it_bar->second << std::endl;
    } while (bar.value_comp()(*it_bar++, _highest));
    std::cout << std::endl;

    std::cout << "******* FT::MAP::OPERATORS *******" << std::endl;
    std::cout << std::endl;

    std::cout << "-- LOWER AN UPPER BOUNDS functions -- : " << std::endl;
    
    NAMESPACE::map<char,int>::iterator itlow,itup;
    itlow = mymap.lower_bound ('b'); 
    itup = mymap.upper_bound ('c');   
    PRINT((*itlow).first);
    PRINT((*itlow).second);
    PRINT((*itup).first);
    PRINT((*itup).second);

    std::cout << "-- EQUAL_RANGE -- : " << std::endl;
    
    NAMESPACE::pair<NAMESPACE::map<char,int>::const_iterator, NAMESPACE::map<char,int>::const_iterator> eq_ret;
    eq_ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << eq_ret.first->first << " => " << eq_ret.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << eq_ret.second->first << " => " << eq_ret.second->second << std::endl;

    std::cout << "-- COUNT -- : " << std::endl;
    PRINT(mymap.count('a'));
    PRINT(mymap.count('m'));
    
    return 0;
}


