/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:12:44 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/03 15:58:57 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include "easyfind.hpp"


int main()
{
  try
  {
    std::vector<int> vec{9, 1, 87,456,321,654,159,48,26,31,1489,9874,651,984513,1};
    std::cout << easyfind(vec, 1) << std::endl;
    vec.at(1) = 10;
    std::cout << easyfind(vec, 1) << std::endl;
    /////////////////////////////////////////////////////////////////////////////////
    const std::vector<int> vec1{0, 1, 2, 12, 32, 45, 26, 94, 48};
    std::cout << easyfind(vec1, 48) << std::endl;
    vec.at(8) = 14;
    std::cout << easyfind(vec1, 14) << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}