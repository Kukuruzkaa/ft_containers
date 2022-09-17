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
#include "RBTree.h"

using namespace ft;

int main() 
{
	RBTree<int> bst;

	// std::cout   << "_sentinel   == "
	// 			<< bst._sentinel
	// 			<< std::endl
	// 			<< "root == "
	// 			<< bst._root
	// 			<< std::endl
	// 			<< std::endl;
	bst.insertNode(8);
	// std::cout   << "_sentinel   == "
    //         << bst._sentinel
    //         << std::endl
    //         << "root == "
    //         << bst._root
    //         << std::endl
    //         << std::endl;
	bst.insertNode(18);
	bst.insertNode(5);
	bst.insertNode(15);
	bst.insertNode(17);
	bst.insertNode(25);
	bst.insertNode(40);
	bst.insertNode(80);
	// bst.deleteNode(25);
	// bst.treePrint();
	bst.print();

	return 0;
}