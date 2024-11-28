/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m3ayz00 <m3ayz00@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:04:30 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/28 22:12:55 by m3ayz00          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"
#include <cmath>
#include <limits>
#include <cstdlib>

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

int isSpecialDouble(const std::string& literal)
{
  return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

int isSpecialFloat(const std::string& literal)
{
  return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool isInt(const std::string& literal)
{
  char *end;
  std::strtol(literal.c_str(), &end, 10);
  return ((*end == '\0'));
}

bool  isChar(const std::string& literal)
{
  return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool isFloat(const std::string& literal)
{
  char *end;
  std::strtof(literal.c_str(), &end);
  return ((std::string(end).back() == 'f'));
}

bool isDouble(const std::string& literal)
{
  char *end;
  std::strtod(literal.c_str(), &end);
  return ((*end == '\0'));
}
  // size_t pos = literal.find(".");
  // if (pos == std::string::npos || pos == 0 || pos == literal.length() - 1)  return (0);
  // if (!isdigit(literal[pos - 1]) || !isdigit(literal[pos + 1])) return (0);
  // pos = literal.find(".", pos + 1);
  // if (pos != std::string::npos) return (0);
  // pos = literal.find("f");
  // if (pos != std::string::npos)
  // {
  //   if (pos != literal.length() - 1) return (0);
  //   pos = literal.find("f", pos + 1);
  //   if (pos != std::string::npos)
  //     return (0);
  // }
  // else
  //   return (2); // 2 for double
  // return (1); // 1 for float

void  printChar(double value)
{
  std::cout << "char: ";
  if (isnanl(value) || isinfl(value) || value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())  
    std::cout << "impossible\n";
  else if (!std::isprint(static_cast<char>(value)))
    std::cout << "non displayable\n";
  else
    std::cout << "\'" << static_cast<char>(value) << "\'\n";
}

void  printInt(double value)
{
  std::cout << "int: ";
  if (isnanl(value) || isinfl(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())  
    std::cout << "impossible\n";
  else
    std::cout << static_cast<int>(value) << "\n";
}

void  printDouble(double value)
{
  std::cout << "double: ";
  if (isnanl(value))  
    std::cout << "nan\n";
  else if (isinfl(value))
    std::cout << (std::signbit(value) ? "-inf\n" : "+inf\n"); 
  else
    std::cout << value << ((value == static_cast<int>(value)) ? ".0\n" : "\n");
}

void  printFloat(double value)
{
  std::cout << "float: ";
  if (isnanf(value))  
    std::cout << "nanf\n";
  else if (isinff(value))
    std::cout << (std::signbit(value) ? "-inff\n" : "+inff\n"); 
  else
    std::cout << static_cast<float>(value) << ((value == static_cast<int>(value)) ? ".0f\n" : "f\n");
}

void  convert(const std::string& literal)
{
  double  value = 0.0;

  if (isChar(literal))
    value = static_cast<double>(literal[0]);
  else if (isInt(literal))
    value = std::strtol(literal.c_str(), NULL, 10);
  else if (isFloat(literal) || isSpecialFloat(literal))
    value = std::strtof(literal.c_str(), NULL);
  else if (isDouble(literal) || isSpecialDouble(literal))
    value = std::strtod(literal.c_str(), NULL);
  else
  {
    std::cout << "Invalid literal\n";
    return ; 
  }
  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}

int main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cerr << "Usage : ./convert [parameter]\n";
    return (1);
  }
  convert(std::string(av[1]));
}