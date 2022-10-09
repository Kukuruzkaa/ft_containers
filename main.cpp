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
// int main() 
// {
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

	// ft::map<int, int> bst;
	// ft::map<int, int>::iterator	it = bst.begin(),
	// 							it2 = it;
	// // ft::map<int, int>::const_iterator cit = bst.begin();
	// for (int i = 1; i < 10; ++i)
	// {
	// 	it = bst.insert(it, make_pair(i, i));
	// 	// bst.print();
	// }
	// it = bst.begin();
	// it2 = it;
	// ++it;
	// bst.print();

	// while (it != bst.end())
	// {
	// 	std::cout	<< *it
	// 				<< std::endl;
	// 	it2 = it;
	// 	++it;
	// }
	// ft::map<int, int> bst2;
	// bst2.insert(bst.begin(), bst.find(4));	
	// bst2.print();

// 	ft::map<char, int, std::less<char>, std::allocator<char> > mymap;

//   // first insert function version (single parameter):
	
// 	for (char c = 'v'; c != 'a'; --c)
// 	{
// 		mymap.insert(make_pair(c, (int)(c - 'a')));
// 	}

// 	ft::map<char, int, std::less<char>, std::allocator<char> >::iterator	it = mymap.begin();

//   	// mymap.insert ( pair<char,int>('a',100) );
//   	// mymap.insert ( pair<char,int>('z',200) );

// 	// mymap.print();

//   	// ft::map<char,int>::iterator it = mymap.begin();
// 	// mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
//   	// mymap.print();
// 	// mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

// 	mymap.print();
// 	// std::cout << "***************************************" << std::endl;
// 	// ft::map<char, int> copy(mymap);

// 	// copy.print();

// 	// ft::map<char, int>copy2;
// 	// copy2 = copy;
// 	// std::cout << "***************************************" << std::endl;
// 	// copy.print();


// //   	ft::pair<map<char,int>::iterator,bool> ret;
// //   	ret = mymap.insert ( pair<char,int>('z',500) );
// //   	if (ret.second==false)
// // 	{
// //     	std::cout << "element 'z' already exists";
// //     	std::cout << " with a value of " << ret.first->second << '\n';
// //   	}

// //   // second insert function version (with hint position):
// //   	ft::map<char,int>::iterator it = mymap.begin();
// // 	mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
// //   	mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

// //   // third insert function version (range insertion):
// //   	ft::map<char,int> anothermap;
// //   	anothermap.insert(mymap.begin(),mymap.find('c'));

// //   // showing contents:
// //   	std::cout << "mymap contains:\n";
// //   	for (it=mymap.begin(); it!=mymap.end(); ++it)
// //     	std::cout << it->first << " => " << it->second << '\n';

// //   // cout  << "map size == "
// //   //       << anothermap.size()
// //   //       << std::endl;
// //   	for (it = mymap.begin(); it != mymap.find('c'); ++it)
// //       	std::cout  << "(" << it->first << ":" << it->second << ")" << std::endl;
// //   	std::cout << "anothermap contains:\n";
// // 	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
// //     	std::cout << it->first << " => " << it->second << '\n';

// // 	mymap.print();

// 	// while (it2 != bst.begin())
// 	// {
// 	// 	std::cout	<< *it2
// 	// 				<< std::endl;
// 	// 	--it2;
// 	// }

// 	// it = bst2.find(1);
// 	// PRINT(it->first);

// 	// bst2.test();

// 	// __attribute__((unused)) size_t	size = bst.count(17);
// 	// PRINT(bst.find(4)->first);

	

// 	// bst2.erase(it);
// 	// bst2.print();
// 	// bst2.clear();
// 	// bst2.print();

	
// 	// bst.insertNode(8);
// 	// bst.insertNode(18);
// 	// bst.insertNode(5);6
// 	// bst.insertNode(15);
// 	// bst.insertNode(17);
// 	// bst.insertNode(25);
// 	// bst.insertNode(40);
// 	// bst.insertNode(80);
// 	// bst.insertNode(90);
// 	// bst.insertNode(101);
// 	// bst.insertNode(3);
// 	// bst.insertNode(0);
// 	// bst.insertNode(74);
// 	// bst.insertNode(1111);
// 	// bst.insertNode(2147483647);
// 	// bst.insertNode(-4);
	
// 	// // bst.treePrint();
// 	// bst.print();
// 	// std::cout << "avant delete" << std::endl;

// 	// bst.deleteNode(80);
// 	// bst.deleteNode(25);
// 	// bst.deleteNode(8);
// 	// bst.deleteNode(40);
// 	// bst.deleteNode(15);
// 	// bst.deleteNode(18);
// 	// bst.deleteNode(5);
// 	// bst.deleteNode(17);
// 	// bst.deleteNode(17);
// 	// bst.deleteNode(81);
// 	// bst.print();

// 	// map<int, int>::iterator	it = bst.begin();
// 	// map<int, int>::const_iterator cit = bst.begin();
// 	// map<int, int>::iterator ite = bst.end();
// 	// map<int, int>::const_iterator cite = bst.end();

// 	// map<int, int>::reverse_iterator	rit = bst.rbegin();
// 	// map<int, int>::const_reverse_iterator rcit = bst.rbegin();
// 	// map<int, int>::reverse_iterator rite = bst.rend();
// 	// map<int, int>::const_reverse_iterator rcite = bst.rend();

	
// 	// // (*it).second = 4;
// 	// PRINT((*it).second);
// 	// PRINT((*cit).first);
// 	// PRINT((*ite).second);
// 	// PRINT((*cite).first);
// 	// PRINT((*rit).second);
// 	// PRINT((*rcit).first);
// 	// PRINT((*rite).second);
// 	// PRINT((*rcite).first);

// 	// std::cout	<< __LINE__
// 	// 			<< std::endl
// 	// 			<< __FILE__
// 	// 			<< std::endl
// 	// 			<< __FUNCTION__
// 	// 			<< std::endl;


// 	return 0;
// }


// // int main ()
// // {
// //   ft::map<char,int> mymap;
// // 	ft::map<char,int>::iterator itlow, itup;

// //   mymap['a']=20;
// //   mymap['b']=40;
// //   mymap['c']=60;
// //   mymap['d']=80;
// //   mymap['e']=100;

// //   itlow=mymap.lower_bound ('b');  // itlow points to b
// //   itup=mymap.upper_bound ('d');   // itup points to e (not d!)
// //   PRINT((*itlow).first);
// //   PRINT((*itlow).second);
// //   PRINT((*itup).first);
// //   PRINT((*itup).second);

  

// //   mymap.erase(itlow,itup);        // erases [itlow,itup)

// //   // print content:
// //   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// //     std::cout << it->first << " => " << it->second << '\n';

// //   return 0;
// // }

// // int main ()
// // {
// //   ft::map<char,int> mymap;

// //   mymap['a']=10;
// //   mymap['b']=20;
// //   mymap['c']=30;

// //   ft::pair<ft::map<char,int>::const_iterator,ft::map<char,int>::const_iterator> ret;
// //   ret = mymap.equal_range('b');

// //   std::cout << "lower bound points to: ";
// //   std::cout << ret.first->first << " => " << ret.first->second << '\n';

// //   std::cout << "upper bound points to: ";
//   std::cout << ret.second->first << " => " << ret.second->second << '\n';

//   return 0;
// }

int main ()
{
  ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}