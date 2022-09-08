/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:17:23 by ddiakova          #+#    #+#             */
/*   Updated: 2022/09/08 20:27:37 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {
    template <class Iterator>
    class reverse_iterator : public
        std::iterator<typename iterator_traits<Iterator>::iterator_category,
                    typename iterator_traits<Iterator>::value_type,
                    typename iterator_traits<Iterator>::difference_type,
                    typename iterator_traits<Iterator>::pointer,
                    typename iterator_traits<Iterator>::reference> {
    protected:
        Iterator current;
    public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::reference           reference;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
    
           
    reverse_iterator()
        :current()
    {}
    explicit reverse_iterator(Iterator x)
        :current(x)
    {}
    template <class U> reverse_iterator(const reverse_iterator<U>& u)
        :current(u.base())
    {}
    
    Iterator base() const {return current;} // explicit
    
    reference operator*() const
    {
        Iterator tmp = current;
        return *--tmp;
    }
    pointer operator->() const {return &(operator*());}
   
    reverse_iterator& operator++()
    {
        --current;
        return *this;
    }
    reverse_iterator operator++(int)
    {
        reverse_iterator tmp = *this;
        --current;
        return tmp;
    }
    reverse_iterator& operator--()
    {
        ++current;
        return *this;
    }
    reverse_iterator operator--(int)
    {
        reverse_iterator tmp = *this;
        ++current;
        return tmp;
    }
    
    reverse_iterator operator+ (difference_type n) const
    {
       return reverse_iterator(current - n);
    }
    reverse_iterator& operator+=(difference_type n)
    {
        current -= n;
        return *this;
    }
    reverse_iterator operator- (difference_type n) const
    {
        return reverse_iterator(current + n);
    }
    reverse_iterator& operator-=(difference_type n)
    {
        current += n;
        return *this;
    }const reverse_iterator<Iterator1> & lhs,
            const reverse_iterator<Iterator2> & rhs)

    template <class Iterator1, class Iterator2>
        bool    operator==(
            const reverse_iterator<Iterator1> & lhs,
            const reverse_iterator<Iterator2> & rhs)
        {
            return (lhs.base() == rhs.base());
        }
            
    template <class Iterator1, class Iterator2>
        bool operator<(
            const reverse_iterator<Iterator1>& lhs,
            const reverse_iterator<Iterator2>& rhs)
        {
            return lhs.base() > rhs.base();
        }
            
    template <class Iterator1, class Iterator2>
        bool operator!=(
            const reverse_iterator<Iterator1>& lhs,
            const reverse_iterator<Iterator2>& rhs)
        {
            return lhs.base() != rhs.base();
        }
            
    template <class Iterator1, class Iterator2>
        bool operator>(
            const reverse_iterator<Iterator1>& lhs,
            const reverse_iterator<Iterator2>& rhs)
        {
            return lhs.base() < rhs.base();
        }

    template <class Iterator1, class Iterator2>
        bool operator>=(
            const reverse_iterator<Iterator1>& lhs,
            const reverse_iterator<Iterator2>& rhs)
        {
            return lhs.base() <= rhs.base();
        }
            
    template <class Iterator1, class Iterator2>
        bool operator<=(
            const reverse_iterator<Iterator1>& lhs,
            const reverse_iterator<Iterator2>& rhs)
        {
            return lhs.base() >= rhs.base();
        }
            
    template <class Iterator1, class Iterator2>
        typename reverse_iterator<Iterator1>::difference_type operator-(
            const reverse_iterator<Iterator1>& lhs,
            const reverse_iterator<Iterator2>& rhs)
        {
            return rhs.base() - lhs.base();
        }
            
    template <class Iterator>
        reverse_iterator<Iterator> operator+(
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& lhs)
        {
           return reverse_iterator<Iterator> (lhs.base() - n);
        }
}
#endif