/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:31:34 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/27 18:41:14 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

void    print(NAMESPACE::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec.begin()[i] << ' ';
	std::cout << std::endl;
}

void    print_data  (std::vector<int> tmp)
{
	std::cout   << "size     = "
				<< tmp.size()
				<< std::endl
				<< "capacity = "
				<< tmp.capacity()
				<< std::endl;
}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main () 
{
	// ft::vector<int> t;
	// t.pop_back();
	// std::cout   << "t1\n";

	ft::vector<int>    t;

	// t.push_back(1);
	// t.push_back(2);
	// t.push_back(3);
	// t.push_back(4);
	// t.push_back(5);
	// t.push_back(6);
	// t.push_back(7);
	// t.push_back(8);

	for (int i = 0; i < 8; i++) {
		t.insert(t.end(), i);
	}

	print(t);

	ft::vector<int>::iterator it = t.begin() + 2;
	t.erase(it, it + 2);
	
	print(t);
//   char foo[]="Apple";
//   char bar[]="apartment";

//   std::cout << std::boolalpha;

//   std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

//   std::cout << "Using default comparison (operator<): ";
//   std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
//   std::cout << '\n';

//   std::cout << "Using mycomp as comparison object: ";
//   std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
//   std::cout << '\n';

  return 0;
}
// int main    (void)
// {

//     NAMESPACE::vector<int>            v1; //empty
//     NAMESPACE::vector<int>            v2(5,5);
//     NAMESPACE::vector<int>            v3(3,3);
//     NAMESPACE::vector<int>            v4, v5;
	
	

//     // std::cout << "v1.empty(): " << std::boolalpha << v1.empty() << std::endl;
	
//     // std::cout << "v1 :" << std::endl;
//     // print(v1);
//     std::cout << "v2 :" << std::endl;
//     print(v2);
//     // std::cout << "v3 :" << std::endl;
//     // print(v3);
	
   
   
//     v2.insert(v2.begin() + 2, 3, 7);
//     print(v2);
//     v2.insert(v2.begin() + 3, 8);
//     print(v2);

//     v2.insert(v2.begin() + 4, v3.begin(), v3.end());
//     print(v2);
	
//     v2.erase(v2.begin() + 1, v2.begin() + 4);
//     print(v2);

//     v4 = v3;
//     std::cout << "V4 :" << std::endl;
//     print(v4);
//     // v4 = v2;
//     std::cout << "V4 = V2:" << std::endl;
//     print(v4);
//     // v4 = v3;
//     // std::cout << "V4 :" << std::endl;
//     // print(v4);   
//     v5.insert(v5.begin(), 2, 4);
//     std::cout   << v4.size()
//                 << std::endl
//                 << v4.capacity()
//                 << std::endl;
//     print(v5);

//     NAMESPACE::vector<int>            v7(v4.begin(), v4.end());
//     std::cout << "V7 :" << std::endl;
//     print(v7);

//     std::cout << "V7 assign:" << std::endl;
//     std::cout << "capacity : " << v7.capacity() << std::endl;
//     v7.assign(v2.begin(), v2.end());
//     std::cout << "capacity : " << v7.capacity() << std::endl;
//      print(v7);

	 
//     std::vector<int>    t,
//                         s;

//     for (int i = 0; i < 10; i++)
//         t.push_back(i);
	
//     std::cout   << t.capacity()
//                 << std::endl;
//     t.clear();
//     std::cout   << t.size()
//                 << std::endl;

//     std::cout << "before swap :" << std::endl;
//     print(v7);
//     print(v5);

//     v7.swap(v5);
//     std::cout << "after swap :" << std::endl;
//     print(v7);
//     print(v5);
	
	
	// s = t;
	// s.assign(t.begin(), t.end());
	// s.pop_back();
	// t.assign(s.begin(), s.end());
	// // s = t;
	// std::cout   << t.size()
	//             << std::endl
	//             << s.size()
	//             << std::endl
	//             << t.capacity()
	//             << std::endl;

	// for (ft::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
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
// }


// int main()
// {
//   std::cout << std::boolalpha;
//   std::cout << "is_integral:" << std::endl;
//   std::cout << "char: " << ft::is_integral<char>::value << std::endl;
//   std::cout << "int: " << ft::is_integral<int>::value << std::endl;
//   std::cout << "float: " << ft::is_integral<float>::value << std::endl;
//   return 0;
// }