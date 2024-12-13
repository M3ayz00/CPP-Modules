/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:12:25 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/03 14:12:26 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T, typename Iterator = typename T::const_iterator>
int easyfind(const T& container, int toFind)
{
  Iterator it = std::find(container.begin(), container.end(), toFind);
  if (it != container.end())
    return (std::distance(container.begin(), it));
  else
    throw (std::runtime_error("Element not found."));
}

#endif