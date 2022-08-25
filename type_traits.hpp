/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:49:19 by ddiakova          #+#    #+#             */
/*   Updated: 2022/08/25 22:12:39 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {
  template <bool, typename T = void>
  struct enable_if {};

  template <typename T>
  struct enable_if<true, T> 
  {
    typedef T type;
  };

  template <class T, T v>
  struct integral_constant 
  {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T,v> type;
    operator T() {return v;}
  };
  
  template <class T> 
  struct is_integral : public integral_constant<bool, false>
  {
    static const bool value = false;
  };

  template<>
  struct is_integral<char> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<unsigned char> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<wchar_t> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<int> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<short int> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<long int> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<long long int> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<unsigned short int> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };

  template<>
  struct is_integral<unsigned long int> : public integral_constant<bool, true> 
  {
    static const bool value = true;
  };
}

#endif