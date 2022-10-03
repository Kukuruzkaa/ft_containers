/* ************************************************************************** */
/*                                                                            */
/*                                                        ::      ::::::::   */
/*   tests_vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:31:34 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/08 18:26:17 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RBTree.hpp"
#include "map.hpp"
#include "vector.hpp"

#define PRINT(a)	std::cout	<< #a << " == " << a << std::endl;

using namespace ft;
typedef ft::vector<int>::reverse_iterator	vectrit;
typedef ft::vector<int>::const_reverse_iterator	vectcrit;
int main() 
{
	// ft::vector<int>	v(10, 10);
	// __attribute__ ((unused))vectrit	rit1 = v.rbegin();
	// __attribute__ ((unused))vectrit	rit2;
	// __attribute__ ((unused))vectcrit	rit3(rit1);
	// __attribute__ ((unused))vectrit	rit4(rit2);
	// // ft::map<char,int> first;

	// first['a']=10;
	// first['b']=30;
	// first['c']=50;
	// first['d']=70

	// return (0);

	// ft::map<int, int> bst;
	// for (int i = 1; i < 10000000; ++i)
	// {
	// 	bst.insert(make_pair(i, i));
	// }

	ft::map<int, int> bst;
	ft::map<int, int>::iterator	it = bst.begin();
	for (int i = 1; i < 10; ++i)
	{
		it = bst.insert(it, make_pair(i, i));
		// bst.print();
	}
	it = bst.begin();
	++it;
	bst.print();

	while (it != bst.end())
	{
		std::cout	<< *it
					<< std::endl;
		++it;
	}
	ft::map<int, int> bst2;
	bst2.insert(++(++(++(++(++(++(++bst.begin())))))), bst.end());	
	bst2.print();

	while (it != bst.begin())
	{
		std::cout	<< *it
					<< std::endl;
		--it;
	}
	
	// bst.insertNode(8);
	// bst.insertNode(18);
	// bst.insertNode(5);6
	// bst.insertNode(15);
	// bst.insertNode(17);
	// bst.insertNode(25);
	// bst.insertNode(40);
	// bst.insertNode(80);
	// bst.insertNode(90);
	// bst.insertNode(101);
	// bst.insertNode(3);
	// bst.insertNode(0);
	// bst.insertNode(74);
	// bst.insertNode(1111);
	// bst.insertNode(2147483647);
	// bst.insertNode(-4);
	
	// // bst.treePrint();
	// bst.print();
	// std::cout << "avant delete" << std::endl;

	// bst.deleteNode(80);
	// bst.deleteNode(25);
	// bst.deleteNode(8);
	// bst.deleteNode(40);
	// bst.deleteNode(15);
	// bst.deleteNode(18);
	// bst.deleteNode(5);
	// bst.deleteNode(17);
	// bst.deleteNode(17);
	// bst.deleteNode(81);
	// bst.print();

	// map<int, int>::iterator	it = bst.begin();
	// map<int, int>::const_iterator cit = bst.begin();
	// map<int, int>::iterator ite = bst.end();
	// map<int, int>::const_iterator cite = bst.end();

	// map<int, int>::reverse_iterator	rit = bst.rbegin();
	// map<int, int>::const_reverse_iterator rcit = bst.rbegin();
	// map<int, int>::reverse_iterator rite = bst.rend();
	// map<int, int>::const_reverse_iterator rcite = bst.rend();

	
	// // (*it).second = 4;
	// PRINT((*it).second);
	// PRINT((*cit).first);
	// PRINT((*ite).second);
	// PRINT((*cite).first);
	// PRINT((*rit).second);
	// PRINT((*rcit).first);
	// PRINT((*rite).second);
	// PRINT((*rcite).first);

	// std::cout	<< __LINE__
	// 			<< std::endl
	// 			<< __FILE__
	// 			<< std::endl
	// 			<< __FUNCTION__
	// 			<< std::endl;


	return 0;
}
