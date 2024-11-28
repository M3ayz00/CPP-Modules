/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:28 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/28 14:09:19 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"

ScalarConverter::ScalarConverter()
{
  
}

ScalarConverter::ScalarConverter(const ScalarConverter& S)
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter&  ScalarConverter::operator=(const ScalarConverter& S)
{

}

int ScalarConverter::isDigit(const std::string& arg)
{
  if (arg.empty())
    return (0);
  int i = 0;
  if (arg[i] == '-' || arg[i] == '+')
    i++;
  for (; i < arg.length(); i++)
  {
    if (!(isdigit(arg[i]) || arg[i] == '.' || arg[i] == 'f'))
      return (0);
  }
  return (1);
}

int ScalarConverter::hasDecimal(const std::string& arg, char c)
{
  if (!isDigit(arg))
    return (0);
  size_t pos = arg.find(".");
  if (pos != std::string::npos)
  {
    pos = arg.find(".", pos + 1);
    if (pos != std::string::npos) //invalid number (2 decimal points)
      return (0);
    if (c == 'f')
    {
      pos = arg.find("f");
      if (pos != arg.length() - 1)
        return (0); //invalid number (f must be at the end)
    }
  }
  return (1);
}

void  printChar(const std::string& literal)
{
  std::cout << "char: ";
  if (isprint(literal[0]))
    std::cout << static_cast<char>(std::stoi(literal));
  else
    std::cout << "Non displayable";
  std::cout << "\nint:  " << static_cast<int>(std::stoi(literal));
  std::cout << "\nfloat:  " << static_cast<float>(std::stof(literal));
  std::cout << "\ndouble:  " << static_cast<double>(std::stod(literal)) << '\n';
}

void  ScalarConverter::convert(const std::string &literal)
{
  if (literal.length() == 1)
    printChar(literal);
  else if (!isDigit(literal))
    ERR_PRINT();
  else
  {
    if ()
  }

}