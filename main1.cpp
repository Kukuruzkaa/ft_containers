/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:31:34 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/25 01:00:04 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
// #include <vector>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif



int main    (void)
{

    // NAMESPACE::vector<int>            v1; //empty
    NAMESPACE::vector<int>            v2(5,5);
    // NAMESPACE::vector<int>            v3(v2);

    // std::cout << "v1.empty(): " << std::boolalpha << v1.empty() << std::endl;
    
    // std::cout << "v1 :" << std::endl;
    // print(v1);
    std::cout << "v2 :" << std::endl;
    print(v2);
    // std::cout << "v3 :" << std::endl;
    // print(v3);
    
    ft::vector<int>::iterator it;

    it = v2.begin();
    v2.insert(it + 2, 3, 7);
    print(v2);
    it = v2.begin();
    v2.insert(it + 3, 8);
    print(v2);
    v2.erase(v2.begin() + 1);
    print(v2);

    
    // for (ft::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
    //     std::cout << *it << std::endl;

    // v2.assign (7,100); 
    // for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
    //     std::cout << *it << std::endl;

    // v1.assign (7,100); 
    // for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << *it << std::endl;

    // v1.reserve(50);

    // for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << *it << std::endl;

    // std::cout << "v1.empty(): " << std::boolalpha << v1.empty() << std::endl;
    // std::cout << "v1 size(): " << v1.size() << std::endl;

    // v1.resize(12, 15);
    // for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << *it << std::endl;
    // std::cout << "v1 size(): " << v1.size() << std::endl;   
    // v1 = v2;

    // std::vector<int>            v1; //empty
    // std::vector<int>            v2(3,5);
    // std::vector<int>            v3(v2);

    // for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
    //     std::cout << *it << std::endl;

    // for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
    //     std::cout << *it << std::endl;

    // // v2.assign (7,100); 
    // // for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
    // //     std::cout << *it << std::endl;

    // v1.assign (7,100); 
    // for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    //     std::cout << *it << std::endl;
}


// int main()
// {
//   std::cout << std::boolalpha;
//   std::cout << "is_integral:" << std::endl;
//   std::cout << "char: " << ft::is_integral<char>::value << std::endl;
//   std::cout << "int: " << ft::is_integral<int>::value << std::endl;
//   std::cout << "float: " << ft::is_integral<float>::value << std::endl;
//   return 0;
// }