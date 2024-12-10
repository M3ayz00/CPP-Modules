/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:16:40 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/02 19:58:51 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void  swap(T& a, T& b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T min(T& a, T& b)
{
  return (a < b ? a : b);
}

template <typename T>
T max(T& a, T& b)
{
  return (a > b ? a : b);
}

#endif