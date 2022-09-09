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

// #include <iostream>
// #include "vector.hpp"
// #include <vector>
// # include <string>
// # include <sstream>

// // # ifndef TO_STRING
// // #  define TO_STRING
// 	std::string	to_string(size_t n)
// 	{
// 		std::stringstream tmp;

// 		tmp << n;

// 		return tmp.str();
// 	}
// // # endif

// using namespace ft;

//#include "test_utils.hpp"
#include "vector.hpp"
#include <vector>


#define PRINT_EXECUTE(cmd)	std::cout	<< #cmd \
										<< " == " \
										<< cmd \
										<< std::endl;

#ifndef NAMESPACE
# define NAMESPACE std
# define NAME "std"
#else
# define NAME "ft"
#endif

#include <typeinfo>

#define SIZE 20

using namespace NAMESPACE;

int main()
{
	NAMESPACE::vector<int>	v;

	v.reserve(SIZE);
	for (int i = 0; i < SIZE; i++)
		v[i] = i;
	
	ft::vector<int>::reverse_iterator		rit;


//	NAMESPACE::vector<int>::const_reverse_iterator	rit, rite;

//	for (rit = v.rbegin(), rite = v.rend();
//		 rit != rite;
//		 ++rit)
//	{
//		std::cout	<< *rit
//					<< std::endl;
//	}
//	std::cout	<< typeid (NAMESPACE::vector<int>::reverse_iterator).name()
//				<< std::endl;

//	NAMESPACE::vector<int>	v;
//
//	PRINT_EXECUTE(v.size());
//
//	v.pop_back();
//
//	PRINT_EXECUTE(v.size());
// 	vector<int>			test(3, 3);

// 	cout << "self assignation test\n";
// 	vector<vector<int> >	self_assign;
// 	vector<vector<int> >	*ptr = &self_assign;
// 	vector<vector<int> >	*ptr2 = &self_assign;

// 	self_assign.assign(4, test);
// 	*ptr = *ptr2;

// 	cout << std::boolalpha << (*ptr == *ptr2) << '\n';
// //	self_assign = self_assign; //compiler doesn't like it!



// 	vector<vector<int> > JOHN;
// 	vector<vector<int> > BOB(5, test);
// 	cout << "BOB(5, test(test, 5)) : \n";
// 	for (size_t i = 0; i < BOB.size(); i++)
// 	{
// 		for (size_t j = 0; j < BOB[i].size(); j++)
// 			cout << BOB[i][j] << ' ';
// 		cout << '\n';
// 	}
// 	vector<vector<int> > MIKE(BOB);

// 	// / CTORs
// 	cout << "\nCTORS\n";
// 	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
// 	cout << "BOB is empty? " << BOB.empty() << '\n';

// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	cout << "Size of BOB " << BOB.size() << std::endl;
// 	cout << "Size of MIKE " << MIKE.size() << std::endl;

// 	// RESIZE
// 	size_t	bob_resize = 2;
// 	cout << "\nRESIZE\n";
// 	BOB.resize(bob_resize);
// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
// 	cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
// 	cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

// 	size_t	mike_resize = 9;
// 	bob_resize = 0;
	
// 	BOB.resize(bob_resize);
// 	cout << "BOB is empty now ? " << BOB.empty() << '\n';
// 	MIKE.resize(mike_resize, test);
// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
// 	cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
// 	cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_resize)
// 		cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 		{
// 			cout << MIKE[i][j] << ' ';
// 		}
// 	cout << std::endl;
// 	}
// 	// RESERVE
// 	cout << "\nRESERVE\n";

// 	size_t	john_reserve = 0;
// 	size_t	bob_reserve = 3;
// 	size_t	mike_reserve = 4;

// 	JOHN.reserve(john_reserve);
// 	BOB.reserve(bob_reserve);
// 	MIKE.reserve(mike_reserve);
// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= john_reserve)
// 		cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
// 	cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_reserve)
// 		cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
// 	cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_reserve)
// 		cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			cout << MIKE[i][j] << ' ';
// 	cout << std::endl;
// 	}


// 	//ASSIGN
// 	cout << "\nASSIGN\n";
// 	test.assign(3, 17);
// 	BOB.assign(3, test);

// 	//ASSIGN RANGE
// 	cout << "\nASSIGN RANGE\n";
// 	vector<vector<int> >	assign_range;
// 	assign_range.assign(8, test);
// 	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

// 	//EMPTY
// 	cout << "\nEMPTY\n";
// 	cout << "BOB is empty ? " << BOB.empty() << '\n';
// 	cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

// 	//PUSH/POP_BACK
// 	cout << "\nPUSH/POP_BACK\n";
// 	test.assign(2, 42);
// 	BOB.push_back(test);
// 	cout << "last elem of BOB : " << BOB.back().back() << '\n';
// 	BOB.pop_back();
// 	cout << "last elem of BOB : " << BOB.back().back() << '\n';

// 	//ERASE
// 	cout << "\nERASE\n";
// 	vector<vector<int> >	erase_in_me;
// 	for (int i = 0; i < 15; i++)
// 	{
// 		vector<int>	j(1, i);
// 		erase_in_me.push_back(j);
// 	}
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		cout << erase_in_me.at(i).front() << ' ';
// 	cout << '\n';

// 	erase_in_me.erase(erase_in_me.begin() + 7);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		cout << erase_in_me.at(i).front() << ' ';
// 	cout << '\n';
// 	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		cout << erase_in_me.at(i).front() << ' ';
// 	cout << '\n';

	return (0);
}
