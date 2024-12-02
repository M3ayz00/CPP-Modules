/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:32:42 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/01 16:11:46 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
  Data *data = new Data("some data type", 20);
  uintptr_t uptr = Serializer::serialize(data);
  std::cout << uptr << std::endl;
  Data* ptr = Serializer::deserialize(uptr);
  std::cout << ptr->getType() << std::endl << ptr->getSize() << std::endl;
  delete data;
  
}