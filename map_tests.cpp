/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:49:07 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/13 21:59:06 by ddiakova         ###   ########.fr       */
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

    PRINT(my_map.at('c'));
    // PRINT(my_map.at('e'));
    std::cout << std::endl;


    std::cout << "******* FT::MAP::MODIFIERS *******" << std::endl;
    std::cout << std::endl;

    // first insert function version - inserting pair:
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

    // second insert function version - inserting with iterator position:
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

    // third insert function version (range insertion):
    NAMESPACE::map<char,int> new_map;
    new_map.insert(mymap.begin(),mymap.find('q'));
    std::cout << "Printing new_map: " << std::endl;
    for (NAMESPACE::map<char, int>:: iterator it = new_map.begin(); it != new_map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << std::endl;

    return 0;
}


