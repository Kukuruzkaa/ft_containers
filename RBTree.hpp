/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:33:18 by ddiakova          #+#    #+#             */
/*   Updated: 2022/10/04 20:20:40 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_CLASS_H
# define RBTREE_CLASS_H
# define RED   1
# define BLACK 0

# define RESET "\033[0m"
# define BLACK_TEXT "\033[30m"
# define RED_TEXT "\033[31m"
# define WHITE_BACK "\033[47m"

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
            typedef T                   value_type;
            typedef Allocator           allocator_type;
            typedef Compare             key_compare;
            typedef Node<T>             _node;
            typedef map_iterator<_node>     iterator;
            typedef map_citerator<_node>    const_iterator;
      
            
            RBTree(const allocator_type & alloc = allocator_type(), const key_compare & key_comp = key_compare())
                : _alloc(alloc), _nalloc(alloc), _key_comp(key_comp)
            {
                _sentinel = _nalloc.allocate(1);
                _node   tmp(value_type(), _sentinel, _sentinel, _sentinel, BLACK);
                tmp._color = BLACK;
                std::cout << "RBTree constructor" << std::endl;
                _nalloc.construct(_sentinel, tmp);
                _root = _sentinel;
            }
            ~RBTree()
            {
                std::cout << "RBTree destructor" << std::endl;
                _nalloc.destroy(_sentinel);
                _nalloc.deallocate(_sentinel, 1);
                _destroy(_root);
            }
            
            void    _destroy    (_node * node)
            {
                if (node == _sentinel)
                    return ;
                _destroy(node->_left);
                _destroy(node->_right);
                _nalloc.destroy(node);
                _nalloc.deallocate(node, 1);
            }

            _node * getMin() {return _root->TreeMin();}

            _node * getMax() {return _root->TreeMax();}

            _node * getRoot() {return _root;}

            _node * getSentinel() {return _sentinel;}
            
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
            }
            
            void printHelper(_node * root, std::string indent, bool last) 
            {
                if (root != _sentinel) 
                {
                    std::cout<<indent;
                    if (last) 
                    {
                        std::cout<<"R----";
                        indent += "     ";
                    }
                    else 
                    {
                        std::cout<<"L----";
                        indent += "|    ";
                    }
                }
                std::string color = root->_color?"RED":"BLACK";
		        std::cout<<root->_key<<"("<<color<<")"<<std::endl;
		        printHelper(root->_left, indent, false);
                printHelper(root->_right, indent, true);
		    }

            void treePrint() 
            {
                if (_root != _sentinel) 
                    printHelper(_root, "", true);
	        }

            void	print	(void)
            {
                size_t	height = _height(_root);
                std::vector<std::string>	tree;

                tree.resize(height);
                for (size_t i = 0; i < height; ++i)
                    tree[i] += WHITE_BACK BLACK_TEXT;
                _print(_root, tree, 0);
                tree[height - 1] += RESET;
                std::cout   << WHITE_BACK  
                            << std::endl;
                for (size_t i = 0; i < height; ++i)
                    std::cout	<< tree[i]
                                << std::endl;
                // std::cout	<< RESET
                //             << std::endl;
            }
    
            void	_print	(_node * & node,
                            std::vector<std::string> & tree,
                            size_t depth,
                            size_t pos = 0,
                            size_t * left = NULL,
                            size_t * right = NULL)
            {
                for (size_t i = _strsize(tree[depth]); i < pos; ++i)
                    tree[depth] += " ";
                if (node == _sentinel)
                {
                    if (node->_color == RED)
                        tree[depth] += WHITE_BACK RED_TEXT "NIL" BLACK_TEXT;
                    else
                        tree[depth] += "NIL";
                    if (left != NULL && right != NULL)
                    {
                        *left += 2;
                        *right += 1;
                    }
                    return ;
                }

                std::stringstream	ss;
                ss	<< node->_key;
                size_t	cur_size = ss.str().size();

                size_t	ll = 0, lr = 0;
                _print(node->_left, tree, depth + 1, pos, &ll, &lr);
                size_t	rl = 0, rr = 0;
                _print(node->_right, tree, depth + 1, pos + ll + lr + 2 + cur_size, &rl, &rr);

                for (size_t i = 0; i <= ll + lr; ++i)
                {
                    if (i == ll - 1)
                        tree[depth] += "┌";
                    else if (i >= ll)
                        tree[depth] += "─";
                    else
                        tree[depth] += " ";
                }
                if (node->_color == RED)
                    tree[depth] += WHITE_BACK RED_TEXT;
                else
                    tree[depth] += WHITE_BACK BLACK_TEXT;
                tree[depth] += ss.str();
                tree[depth] += BLACK_TEXT;
                for (size_t i = 0; i <= rl; ++i)
                {
                    if (i == rl)
                        tree[depth] += "┐";
                    else
                        tree[depth] += "─";
                }
                if (left != NULL && right != NULL)
                {
                    *left = ll + lr + ((cur_size + 1) / 2) + 1;
                    *right = rl + rr + (cur_size / 2) + 1;
                }
            }

            size_t	_height	(_node * & node)
            {
                if (node == _sentinel)
                    return (1);
                return (1 + std::max(_height(node->_left), _height(node->_right)));
            }

            size_t	_strsize	(std::string & str)
            {
                size_t	count = 0;

                for (size_t i = 0; i < str.size(); ++i)
                {
                    std::string special = str.substr(i, 3);
                    std::string	color = str.substr(i, 5);
                    std::string	reset = str.substr(i, 4);
                    if (special == "─" || special == "┌" || special == "┐")
                        i += 2;
                    else if (color == RED_TEXT || color == BLACK_TEXT || color == WHITE_BACK)
                    {
                        i += 4;
                        --count;
                    }
                    ++count;
                }
                return (count);
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
