/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:16:40 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/01 17:17:16 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void  swap(T& a, T& b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T> T min(T& a, T& b)
{
  if (a < b)
    return (a);
  return (b);
}

template <typename T> T max(T& a, T& b)
{
  if (a > b)
    return (a);
  return (b);
}

#endif