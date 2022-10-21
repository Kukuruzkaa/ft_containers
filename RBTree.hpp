/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:33:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/21 22:39:03 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_CLASS_H
# define RBTREE_CLASS_H
# define RED   1
# define BLACK 0

#include <cstdlib>
#include <memory>
#include <iostream>
#include <vector>
#include <sstream>
#include "map_iterator.hpp"
    
namespace ft {

    template<typename T>
    class Node {
        
        public:
            typedef T       value_type;
             
            Node() : 
                _key(), _p(NULL), _left(NULL), _right(NULL), _color(BLACK) {}
            Node (const value_type & key, Node * p, Node * left, Node * right, bool)
                    : _key(key), _p(p), _left(left), _right(right), _color(RED) {}
            Node(Node const & src) : 
                _key(src._key), _p(src._p), _left(src._left), _right(src._right), _color(src._color) {}
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


            Node  * successor(void)
            {
                Node * parent = this->_p;
                Node * node = this;
                
                if (node == node->_left)
                    return parent->TreeMax();

                if (node->_right != node->_right->_right)
                    return node->_right->TreeMin();
                while (parent != parent->_left && node == parent->_right)
                {
                    node = parent;
                    parent = parent->_p;
                }
                return parent;
            }

            Node const  * successor(void) const
            {
                Node const * parent = this->_p;
                Node const * node = this;
                
                if (node == node->_left)
                    return parent->TreeMax();

                if (node->_right != node->_right->_right)
                    return node->_right->TreeMin();
                while (parent != parent->_left && node == parent->_right)
                {
                    node = parent;
                    parent = parent->_p;
                }
                return parent;
            }

            Node  *  predecessor(void)
            {
                Node * parent = this->_p;
                Node * node = this;
                
                if (node == node->_left)
                    return parent->TreeMax();
                    
                if (node->_left != node->_left->_left)
                    return node->_left->TreeMax();
                while (parent != parent->_left && node == parent->_left)
                {
                    node = parent;
                    parent = parent->_p;
                }
                return parent;
            }

            Node const *  predecessor(void) const
            {
                Node const * parent = this->_p;
                Node const * node = this;
                
                if (node == node->_left)
                    return parent->TreeMax();
                    
                if (node->_left != node->_left->_left)
                    return node->_left->TreeMax();
                while (parent != parent->_left && node == parent->_left)
                {
                    node = parent;
                    parent = parent->_p;
                }
                return parent;
            }

            Node * TreeMin(void)
            {
                Node * parent = this;
                Node * kid = parent->_left;
                
                while (kid != kid->_left)
                {
                    parent = kid;
                    kid = kid->_left;
                }
                return parent;
            }

            Node * TreeMax(void)
            {
                Node * parent = this;
                Node * kid = parent->_right;
                
                while (kid != kid->_right)
                {
                    parent = kid;
                    kid = kid->_right;
                }
                return parent;
            }

            Node const * TreeMax(void) const
            {
                Node const * parent = this;
                Node const * kid = parent->_right;
                
                while (kid != kid->_right)
                {
                    parent = kid;
                    kid = kid->_right;
                }
                return parent;
            }
    };

    
    template
    <
        typename T,
        class Compare = std::less<T>,
        class Allocator = std::allocator<Node<T> >
    >
    
    class RBTree {


        private:
            typedef typename Allocator::template rebind<Node<T> >::other    _Node_alloc;
            
        public:
            typedef T                       value_type;
            typedef Allocator               allocator_type;
            typedef Compare                 key_compare;
            typedef Node<T>                 _node;
            typedef map_iterator<_node>     iterator;
            typedef map_citerator<_node>    const_iterator;
            
            RBTree(const allocator_type & alloc = allocator_type(), const key_compare & key_comp = key_compare())
                : _alloc(alloc), _nalloc(alloc), _key_comp(key_comp)
            {
                _sentinel = _nalloc.allocate(1);
                _node   tmp(value_type(), _sentinel, _sentinel, _sentinel, BLACK);
                tmp._color = BLACK;
                #ifdef __DEBUG__
                std::cout << "RBTree constructor" << std::endl;
                #endif
                _nalloc.construct(_sentinel, tmp);
                _root = _sentinel;
            }

            RBTree(const RBTree & src)
                :_alloc(src._alloc), _nalloc(src._nalloc), _key_comp(src._key_comp)
            {
                iterator it = src.getMin();
                iterator ite = src._sentinel;
                
                _sentinel = _nalloc.allocate(1);
                _node   tmp(value_type(), _sentinel, _sentinel, _sentinel, BLACK);
                tmp._color = BLACK;
                _nalloc.construct(_sentinel, tmp);
                _root = _sentinel;
                
                while (it != ite)
                {
                    insertNode(*it);
                    ++it;
                }
            }


            RBTree & operator=(const RBTree & rhs)
            {
                _destroy(_root);
                
                iterator it = rhs.getMin();
                iterator ite = rhs._sentinel;
                for (;it != ite; ++it)
                    insertNode(*it);
                return *this;
            }           

            void    swap    (RBTree & rhs)
            {
                Node<T> *   tmp = _sentinel;
                _sentinel = rhs._sentinel;
                rhs._sentinel = tmp;

                tmp = _root;
                _root = rhs._root;
                rhs._root = tmp;
            } 
            
            ~RBTree()
            {
                #ifdef __DEBUG__
                std::cout << "RBTree destructor" << std::endl;
                #endif
                _nalloc.destroy(_sentinel);
                _nalloc.deallocate(_sentinel, 1);
                _destroy(_root);
            }
            
            size_t  max_size    (void) const
            {   return (_nalloc.max_size());}
            
            void    _destroy    (_node * node)
            {
                if (node == _sentinel)
                    return ;
                _destroy(node->_left);
                _destroy(node->_right);
                if (node == _root)
                    _root = _sentinel;
                _nalloc.destroy(node);
                _nalloc.deallocate(node, 1);
            }

            void    test    (void) const
            {
                std::cout   << _sentinel
                            << std::endl
                            << _sentinel->_p
                            << std::endl;
            }
            
            _node * getMin() {return _root->TreeMin();}

            _node * getMin() const {return _root->TreeMin();}

            _node * getMax() {return _root->TreeMax();}

            _node * getMax() const {return _root->TreeMax();}

            _node * getRoot() {return _root;}

            _node * getRoot() const {return _root;}

            _node * getSentinel() {return _sentinel;}
            
            _node * getSentinel() const {return _sentinel;}
            
            void    leftRotation(_node * x)
            {
                _node * y = x->_right;
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
            
            void    rightRotation(_node * x)
            {
                _node* y = x->_left;
                x->_left = y->_right;
                if (y->_right != _sentinel)
                    y->_right->_p = x;
                y->_p = x->_p;
                if (x->_p == _sentinel)
                    _root = y;
                else if (x == x->_p->_right)
                    x->_p->_right = y;
                else
                    x->_p->_left = y;
                y->_right = x;
                x->_p = y;
            }

            void    InorderTreeWalk(_node * node)
            {
                if (node == _sentinel)
                    return ;
                InorderTreeWalk(node->_left);
                std::cout << node->_key << std::endl;
                InorderTreeWalk(node->_right);
            }

            
            _node * &   TreeSearch(value_type val)
            {
                _node * parent = _sentinel;
                return (TreeSearch(val, parent));
            }

            _node * &   TreeSearch(value_type val, _node * & parent)
            {
                _node **    node = &_root;
                if (parent != _sentinel)
                {
                    node = &parent;
                    while (*node != _root &&
                            (((*node)->_p->_left == *node && _key_comp((*node)->_p->_key.first, val.first)) ||
                            ((*node)->_p->_right == *node && _key_comp(val.first, (*node)->_p->_key.first))))
                    {
                        node = &(*node)->_p;
                    }
                    if (! _key_comp((*node)->_p->_key.first, val.first) && ! _key_comp(val.first, (*node)->_p->_key.first))
                        return ((*node)->_p);
                }
                while(*node != _sentinel)
                {
                    parent = *node;
                    if (_key_comp(val.first, (*node)->_key.first)) // if val < node
                        node = &(*node)->_left;
                    else if (_key_comp((*node)->_key.first, val.first)) // if val > node
                        node = &(*node)->_right;
                    else // val == tmp
                        return *node;
                }
                return (*node);
            }

            _node const *   TreeSearch(value_type val) const
            {
                _node * parent = _sentinel;
                return (TreeSearch(val, parent));
            }

            _node const *   TreeSearch(value_type val, _node * & parent) const
            {
                _node * const *    node = &_root;
                if (parent != _sentinel)
                {
                    node = &parent;
                    _node ** tmp = &(*node)->_p;
                    while (*tmp != _sentinel &&
                            (((*node)->_p->_left == *node && _key_comp((*tmp)->_key.first, val.first)) ||
                            ((*node)->_p->_right == *node && _key_comp(val.first, (*tmp)->_key.first))))
                    {
                        node = tmp;
                        tmp = &(*node)->_p;
                    }
                }
                if (parent != _sentinel)
                    node = &parent;
                while(*node != _sentinel)
                {
                    parent = *node;
                    if (_key_comp(val.first, (*node)->_key.first)) // if val < node
                        node = &(*node)->_left;
                    else if (_key_comp((*node)->_key.first, val.first)) // if val > node
                        node = &(*node)->_right;
                    else // val == tmp
                        return *node;
                }
                return (*node);
            }

            void    transplant(_node * u, _node * v)
            {
                if (u->_p == _sentinel)
                    _root = v;
                else if (u == u->_p->_left)
                    u->_p->_left = v;
                else
                    u->_p->_right = v;
                v->_p = u->_p;
            }

            bool    insertNode(value_type z)
            {
                return (insertNode(z, _sentinel));
            }

            bool    insertNode(value_type z, iterator pos)
            {
                _node * parent = pos._node_ptr;
                _node * & node = TreeSearch(z, parent);

                return (insertNode(z, node, parent));
            }

            bool    insertNode(value_type z, _node * & node, _node * parent)
            {
                if (node != _sentinel)
                    return false;
                _node   temp(z, parent, _sentinel, _sentinel, 1);
                node = _nalloc.allocate(1);
                _nalloc.construct(node, temp);
                insertFixUp(node);
                _sentinel->_p = _root;
                return true;
            }

            void    deleteNode(value_type val)
            {
                _node * z = TreeSearch(val);
                _node * y, * x;
                if (z == _sentinel)
                    return ;
                y = z;                
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
                    y = z->_right->TreeMin();
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
                _nalloc.destroy(z);
                _nalloc.deallocate(z, 1);
                _sentinel->_p = _root;
            }
            

            private:
            allocator_type      _alloc;
            _Node_alloc         _nalloc;
            key_compare         _key_comp;
            Node<T> *           _sentinel;
            Node<T> *           _root;  
            
            void    insertFixUp(_node * node)
            {
                while(node->_p->_color == RED)
                {
                    if (node->_p == node->_p->_p->_left)
                    {
                       _node * y = node->_p->_p->_right;
                        if (y->_color == RED)
                        {
                            node->_p->_color = BLACK;
                            y->_color = BLACK;
                            node->_p->_p->_color = RED;
                            node = node->_p->_p;
                        }
                        else
                        {
                             if (node == node->_p->_right)
                            {
                                node = node->_p;
                                leftRotation(node);
                            }
                            node->_p->_color = BLACK;
                            node->_p->_p->_color = RED;
                            rightRotation(node->_p->_p);
                        }
                    }
                    else
                    {
                        _node * y = node->_p->_p->_left;
                        if (y->_color == RED)
                        {
                            node->_p->_color = BLACK;
                            y->_color = BLACK;
                            node->_p->_p->_color = RED;
                            node = node->_p->_p;
                        }
                        else 
                        {
                            if (node == node->_p->_left)
                            {
                                node = node->_p;
                                rightRotation(node);
                            }
                            node->_p->_color = BLACK;
                            node->_p->_p->_color = RED;
                            leftRotation(node->_p->_p);
                        }
                    }
                }
                _root->_color = BLACK;  
            }
            
            void    deleteFixUp(_node * x)
            {
                _node * y;
                while (x != _root && x->_color == BLACK)
                {
                    if (x == x->_p->_left)
                    {
                        y = x->_p->_right;
                        if (y->_color == RED)
                        {
                            y->_color = BLACK;
                            x->_p->_color = RED;
                            leftRotation(x->_p);
                            y = x->_p->_right;
                        }
                        if (y->_left->_color == BLACK && y->_right->_color == BLACK)
                        {
                            y->_color = RED;
                            x = x->_p;
                        }
                        else 
                        {
                            if (y->_right->_color == BLACK)
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
                    else
                    {
                        y = x->_p->_left;
                        if (y->_color == RED)
                        {
                            y->_color = BLACK;
                            x->_p->_color = RED;
                            rightRotation(x->_p);
                            y = x->_p->_left;
                        }
                        if (y->_left->_color == BLACK && y->_right->_color == BLACK)
                        {
                            y->_color = RED;
                            x = x->_p;
                        }
                        else 
                        {
                            if (y->_left->_color == BLACK)
                            {
                                y->_right->_color = BLACK;
                                y->_color = RED;
                                leftRotation(y);
                                y = x->_p->_left;
                            }
                            y->_color = x->_p->_color;
                            x->_p->_color = BLACK;
                            y->_left->_color = BLACK;
                            rightRotation(x->_p);
                            x = _root;
                        }
                    }
                }      
                x->_color = BLACK; 
            }     
    };  
}

#endif
