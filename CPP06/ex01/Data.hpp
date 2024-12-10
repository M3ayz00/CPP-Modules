/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:18:52 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/01 15:33:36 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
private:
  std::string type;
  size_t      size;
public:
  Data();
  Data(const std::string& _type, size_t _size);
  Data(const Data& D);
  Data& operator=(const Data& D);
  ~Data();

  void          setType(const std::string& _type);
  std::string   getType( void ) const;
  void          setSize(size_t _size);
  size_t        getSize( void ) const;
};


#endif