/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:33:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/10 22:35:44 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_CLASS_HPP
# define RBTREE_CLASS_HPP
# define RED   1
# define BLACK 0
#include <cstdlib>
    
namespace ft {

    template<typename T>
   
    class Node {
        
        public:
            typedef T       value_type;
             
            Node() : 
                _val(), _p(NULL), _left(NULL), _right(NULL), _color(RED) {}
            Node(Node & src) : 
                _val(src._val), _left(src._left), _right(src._right), _color(src._color) {}
            Node & operator=(Node & rhs)
            {
                _val = rhs._val;
                _left = rhs._left;
                _right = rhs._right;
                _color = rhs._color;
                return *this;
            }
            ~Node() {}
            
            value_type       _val;
            Node *           _p; 
            Node *           _left; 
            Node *           _right; 
            bool             _color; 
    };

    class RBTree {

        public:
            



        private:
            Node *  _root;
            Node *  _sentinel;
    };


    
}
#endif