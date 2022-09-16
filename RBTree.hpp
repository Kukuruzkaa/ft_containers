/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:33:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/16 19:10:53 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_CLASS_HPP
# define RBTREE_CLASS_HPP
# define RED   1
# define BLACK 0
#include <cstdlib>
#include <memory>
#include <iostream>
    
namespace ft {

    template<typename T>
    class Node {
        
        public:
            typedef T       value_type;
             
            Node() : 
                _key(), _p(NULL), _left(NULL), _right(NULL), _color(BLACK) {}
            Node (const value_type & key, const Node * p, const Node * left, 
                    const Node * right, bool)
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

    
    template<typename T, class Compare, class Allocator>
    
    class RBTree {

        public:
            typedef T                   value_type;
            typedef Allocator           allocator_type;
            typedef Compare             key_compare;
            typedef Node<T>   const &   _node_ref;
            typedef Node<T>             _node;
      
            
            RBTree(const allocator_type & alloc = allocator_type(), const key_compare & key_comp = key_compare())
                : _alloc(alloc), _key_comp(key_comp), _sentinel(_alloc.allocate(_sentinel)), _root(_alloc.allocate(_sentinel))
            {
                std::cout << "RBTree constructor" << std::endl;
                _alloc.construct(_sentinel);
            }
            ~RBTree()
            {
                std::cout << "RBTree destructor" << std::endl;
                _alloc.destroy(_sentinel);
                _alloc.deallocate(_sentinel);
            }

            // void    right_rotation(_node lhs, _node rhs)
            // {
            //     if (lhs->_p != _sentinel)
            //     {
            //         if (lhs->_p->_left == lhs)
            //             lhs->_p->_left = rhs;
            //         else   
            //             lhs->_p->_right = rhs;
            //     }
            //     rhs->_p = lhs->_p;
            //     lhs->_p = rhs;
            //     lhs->_left = rhs->_right;
            //     rhs->_right = lhs;
            // }

            // void    left_rotation(_node lhs, _node rhs)
            // {
            //     if (rhs->_p != _sentinel)
            //     {
            //         if (rhs->_p->_left == rhs)
            //             rhs->_p->_left = lhs;
            //         else   
            //             rhs->_p->_right = lhs;
            //     }
            //     lhs->_p = rhs->_p;
            //     rhs->_p = lhs;
            //     rhs->_right = lhs->_left;
            //     lhs->_left = rhs;
            // }

            void    leftRotation(_node_ref x)
            {
                _node y = x->_right;
                x->_right = y->_left;
                if (y->_left != _sentinel)
                    y->_left->_p = x;
                y->_p = x->_p;
                if (x->_p == _sentinel)
                    _root = y;
                else if (x == x->_p->_left)
                    x->_p->_left = y;
                else
                    x->_p->_right = y;
                y->_left = x;
                x->_p = y;                
            }
            
            void    rightRotation(_node_ref x)
            {
                _node y = x->_left;
                x->_left = y->_right;
                if (y->_right != _sentinel)
                    y->_right->_p = x;
                y->_p = x->_p;
                if (x->_p == _sentinel)
                    _root = y;
                else if (x == x->_p->_right)
                    x->_p->_right = y;
                else
                    x->_p_left = y;
                y->_right = x;
                x->_p = y;
            }

            void    InorderTreeWalk(_node_ref node)
            {
                if (node == _sentinel)
                    return ;
                InorderTreeWalk(node->_left);
                std::cout << node->_key << std::endl;
                InorderTreeWalk(node->_right);
            }

            _node    TreeSearch(_node_ref node, value_type key)
            {
                if (node == _sentinel || key == node->_key)
                    return node;
                if (key < node->_key)
                    return TreeSearch(node->_left, key);
                return TreeSearch(node->_right, key);
            }

            _node    IterTreeSearch(_node_ref node, value_type key)
            {
                while (node != _sentinel && key != node->_key)
                {
                    if (key < node->_key)
                        node = node->_left;
                    node = node->_right;
                }
                return node;
            }

            _node   TreeMin(_node_ref node)
            {
                while (node->_left != _sentinel)
                {
                    node = node->_left;
                }
                return node;
            }

            _node   TreeMax(_node_ref node)
            {
                while (node->_right != _sentinel)
                {
                    node = node->_right;
                }
                return node;
            }

            _node   successor(_node_ref x)
            {
                if (x->_right != _sentinel)
                    return TreeMin(x->_right);
                _node y = x->_p;
                while (y != _sentinel && x == y->_right)
                {
                    x = y;
                    y = y->_p;
                }
                return y;
            }

            _node   predecessor(_node_ref x)
            {
                if (x->_left != _sentinel)
                    return TreeMax(x->_left);
                _node y = x->_p;
                 while (y != _sentinel && x == y->_left)
                {
                    x = y;
                    y = y->_p;
                }
                return y;
            }

            void    transplant(_node_ref u, _node_ref v)
            {
                if (u->_p == _sentinel)
                    _root = v;
                else if (u == u->_p->_left)
                    u->_p->_left = v;
                else
                    u->_p->_right = v;
                v->_p = u->_p;
            }

            void    insertNode(_node_ref z)
            {
                _node y = _sentinel;
                _node x = _root;
                
                while(x != _sentinel)
                {
                    y = x;
                    if (z->_key < x->_key)
                        x = x->_left;
                    else
                        x = x->_right;
                }
                z->_p = y;
                if (y == _sentinel)
                    _root = z;
                else if (z->_key < y->_key)
                    y->_left = z;
                else  
                    y->_right = z;
                z->_left = _sentinel;
                z->_right = _sentinel;
                z->_color = RED;
                insertFixUp(z);
            }

            void    deleteNode(_node_ref z)
            {
                _node_ref y = z;
                _node x;
                bool y_color = y->_color;
                if (z->_left == _sentinel)
                {
                    x = z->_right;
                    transplant(z, z->_right);
                }
                else if (z->_right == _sentinel)
                {
                    x = z->_left;
                    transplant(z, z->_left);      
                }
                else
                {
                    y = TreeMin(z->_right);
                    y_color = y->_color;
                    x = y->_right;
                    if (y->_p == z)
                        x->_p = y;
                    else
                    {
                        transplant(y, y->_right);
                        y->_right = z->_right;
                        y->_right->_p = y;

                    }
                    transplant(z, y);
                    y->_left = z->_left;
                    y->_left->_p = y;
                    y->_color = z->_color; 
                }
                if (y_color == BLACK)
                    deleteFixUp(x);
            }


        private:
            allocator_type      _alloc;
            key_compare         _key_comp;
            Node<T> *           _sentinel;
            Node<T> *           _root;  
            
            void    insertFixUp(_node_ref z)
            {
                while(z->_p->_color == RED)
                {
                    if (z->_p == z->_p->_p->_left)
                    {
                       _node y = z->_p->_p->_right;
                        if (y->_color == RED)
                        {
                            z->_p->_color = BLACK;
                            y->_color = BLACK;
                            z->_p->_p->_color = RED;
                            z = z->_p;
                        }
                        else
                        {
                            if (z == z->_p->_right)
                            {
                                z = z->_p;
                                leftRotate(z);
                            }
                            z->_p->_color = BLACK;
                            z->_p->_p->_color = RED;
                            rightRotate(z->_p->_p);
                        }
                    }
                }
                _root->color = BLACK;  
            }
            
            void    deleteFixUp(_node_ref x)
            {
                _node y;
                
                while (x != _sentinel && x->_color == BLACK)
                {
                    if (x == x->_p->_left)
                    {
                        y = x->_p->_right;
                        if (y->_clor == RED)
                        {
                            y->_color == BLACK;
                            x->_p->_color = RED;
                            leftRotation(x->_p);
                            y = x->_p->_right;
                        }
                        if (y->_left->_color == BLACK && y->_right->_color == BLACK)
                        {
                            y->_color = RED;
                            x = x->_p;
                        }
                        else if (y->_right->_color == BLACK)
                        {
                            y->_left->_color = BLACK;
                            y->_color = RED;
                            rightRotation(y);
                            y = x->_p->_right;
                        }
                        y->_color = x->_p->_color;
                        x->_p->_color = BLACK;
                        y->_right->_color = BLACK;
                        leftRotation(x->_p);
                        x = _root;
                    }   
                }
                x->_color = BLACK; 
            }      
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

