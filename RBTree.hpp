/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:33:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/11 17:09:24 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_CLASS_HPP
# define RBTREE_CLASS_HPP
# define RED   1
# define BLACK 0
#include <cstdlib>
#include <memory>
    
namespace ft {

    template<typename T>
    class Node {
        
        public:
            typedef T       value_type;
             
            Node() : 
                _key(), _p(NULL), _left(NULL), _right(NULL), _color(BLACK) {}
            Node (const value_type & key, const Node * p, const Node * left, 
                    const Node * right, bool color)
                    : _key(key), _p(p), _left(left), _right(right), _color(RED) {}
            Node(Node & src) : 
                _key(src._key), _left(src._left), _right(src._right), _color(src._color) {}
            Node & operator=(Node & rhs)
            {
                _key = rhs._key;
                _p = rhs._p;
                _left = rhs._left;
                _right = rhs._right;
                _color = rhs._color;
                return *this;
            }
            ~Node() {}
            
            value_type       _key;
            Node *           _p; 
            Node *           _left; 
            Node *           _right; 
            bool             _color; 
    };

    typedef struct s_pair
    {
        int x;
        int y;
    }       t_pair;

    
    template<typename T, class Compare, class Allocator>
    
    class RBTree {

        public:
            typedef Allocator   allocator_type;
            typedef Compare     key_compare;
            
            RBTree(const allocator_type & alloc = allocator_type(), const key_compare & key_comp = key_compare())
                : _alloc(alloc), _key_comp(key_comp), _sentinel(_alloc.allocate(_sentinel)), _root(_alloc.allocate(_sentinel))
            {
                _alloc.construct(_sentinel);
            }
            ~RBTree()
            {
                _alloc.destroy(_sentinel);
                _alloc.deallocate(_sentinel);
            }

            void    right_rotation(Node <T> & lhs, Node <T> & rhs)
            {
                if (lhs->_p != _sentinel)
                {
                    if (lhs->_p->_left == lhs)
                        lhs->_p->_left = rhs;
                    else   
                        lhs->_p->_right = rhs;
                }
                rhs->_p = lhs->_p;
                lhs->_p = rhs;
                lhs->_left = rhs->_right;
                rhs->_right = lhs;
            }

            void    left_rotation(Node <T> & lhs, Node<T> & rhs)
            {
                if (rhs->_p != _sentinel)
                {
                    if (rhs->_p->_left == rhs)
                        rhs->_p->_left = lhs;
                    else   
                        rhs->_p->_right = lhs;
                }
                lhs->_p = rhs->_p;
                rhs->_p = lhs;
                rhs->_right = lhs->_left;
                lhs->_left = rhs;
            }  

        private:
            allocator_type      _alloc;
            key_compare         _key_comp;
            Node<T> *           _sentinel;
            Node<T> *           _root;         
    }; 
}

#endif

// // right rotation
// root = B
// B->parent = NIL
// B->left = A
// B->right= y
// A->parent = B
// A->left = a
// A->right= b

// if (B->parent != NIL)
// {
//     if (B->parent->left == B)
//         B->parent->left = A;
//     else   
//         B->parent->right = A;
// }
// A->parent = B->parent;
// B->parent = A;
// B->left = A->right;
// A->right = B;


// B->parent = A
// B->left = b
// B->right = y
// A->parent = NIL
// A->left = a
// A->right = B


// //left rotation

// root = A
// A->parent = NIL
// A->left = a
// A->right= B
// B->parent = A
// B->left = b
// B->right= y

// if (A->parent != NIL)
// {
//     if (A->parent->left == A)
//         A->parent->left = B;
//     else   
//         A->parent->right = B;
// }
// B->parent = A->parent
// A->parent = B
// A->right = B->left
// B->left = A

// B->parent = NIL
// B->left = A
// B->right = y
// A->parent = B
// A->left = a
// A->right = b

// typedef true RIGHT;
// typedef false LEFT;

