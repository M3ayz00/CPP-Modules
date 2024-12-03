/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:36:51 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/03 10:38:50 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
  {
    Array<int> arr(5);
    try
    {
      std::cout << arr[2] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  {
    Array<std::string>arr(3);
    arr[0] = "pixou";
    arr[1] = "appah";
    arr[2] = "okdaaa";
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    Array<std::string>arr2(arr);
    arr2[0] = "pixou2";
    arr2[1] = "appah2";
    arr2[2] = "okdaaa2";
    std::cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << "\n";
  }
}