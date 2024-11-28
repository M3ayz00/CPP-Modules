/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:04:30 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/28 18:56:04 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"

int isDigit(const std::string& literal)
{
  if (literal.empty())  return (0);
  size_t i = 0;
  if (literal[i] == '-' || literal[i] == '+') i++;
  for (; i < literal.length(); i++)
  {
    if (!isdigit(literal[i]))
    {
      if (literal[i] != '.')
      {
        if (literal[i] != 'f') return (0);
        else if (literal[i] == 'f' && i != literal.length() - 1) return (0); 
      }
    }
  }
  return (1);
}

int isSpecial(const std::string& literal)
{
  return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

int isSpecialF(const std::string& literal)
{
  return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

int isInt(const std::string& literal)
{
  size_t i = 0;
  if (literal[i] == '-' || literal[i] == '+') i++;
  for(; i < literal.length(); i++)
    if (!isdigit(literal[i])) return (0);
  return (1);
}

int isFloatOrDouble(const std::string& literal)
{
  size_t pos = literal.find(".");
  if (pos == std::string::npos || pos == 0 || pos == literal.length() - 1)  return (0);
  if (!isdigit(literal[pos - 1]) || !isdigit(literal[pos + 1])) return (0);
  pos = literal.find(".", pos + 1);
  if (pos != std::string::npos) return (0);
  pos = literal.find("f");
  if (pos != std::string::npos)
  {
    pos = literal.find("f", pos + 1);
    if (pos != std::string::npos)
      return (0);
  }
  else
    return (2); // 2 for double
  return (1); // 1 for float
}

void  printChar(const std::string& literal)
{
  std::cout << "char: ";
  if (isprint(literal[0]))
    std::cout << "\'" << literal[0] << "\'";
  else
    std::cout << "Non displayable";
  std::cout << "\nint: " << static_cast<int>(literal[0]);
  std::cout << "\nfloat: " << static_cast<float>(literal[0]);
  std::cout << ".0f\ndouble: " << static_cast<double>(literal[0]) << ".0\n";
}

void  printDigit(const std::string& literal)
{
  std::cout << "char: ";
  if (isprint(std::stoi(literal)))
    std::cout << "\'" << static_cast<char>(std::stoi(literal)) << "\'";
  else
    std::cout << "Non displayable";
  std::cout << "\nint: " << static_cast<int>(std::stoi(literal));
  std::cout << "\nfloat: " << static_cast<float>(std::stof(literal));
  if (!isFloatOrDouble(literal) || std::stoi(literal) == 0)
    std::cout << ".0f\ndouble: " << static_cast<double>(std::stod(literal)) << ".0\n";
  else
    std::cout << "f\ndouble: " << static_cast<double>(std::stod(literal)) << "\n";
}

int main(int ac, char **av)
{
  // if (ac != 2)
  // {
  //   ScalarConverter S;
  //   S.convert(std::string(av[1]));
  //   return (0);
  // }
  // else
  //   std::cerr << "Usage : ./convert [parameter]\n";
  // return (1);
  printDigit("1.17549e-38");
}