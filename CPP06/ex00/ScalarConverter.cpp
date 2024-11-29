/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:28 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/29 15:20:16 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"
#include <cmath>
#include <limits.h>
#include <cstdlib>

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


int ScalarConverter::isDigit(const std::string& literal)
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

int ScalarConverter::isSpecialDouble(const std::string& literal)
{
  return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

int ScalarConverter::isSpecialFloat(const std::string& literal)
{
  return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isInt(const std::string& literal)
{
  char *end;
  std::strtol(literal.c_str(), &end, 10);
  return ((*end == '\0'));
}

bool ScalarConverter::isChar(const std::string& literal)
{
  return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isFloat(const std::string& literal)
{
  char *end;
  std::strtof(literal.c_str(), &end);
  size_t  pos = literal.find("f");
  if (pos == std::string::npos || pos != literal.length() - 1) return (0);
  return (*end == 'f' && std::isdigit(*(end - 1)));
}

bool ScalarConverter::isDouble(const std::string& literal)
{
  char *end;
  std::strtod(literal.c_str(), &end);
  return ((*end == '\0'));
}

void  ScalarConveter::printChar(double value)
{
  std::cout << "char: ";
  if (isnanl(value) || isinfl(value) || value > CHAR_MAX || value < 0)  
    std::cout << "impossible\n";
  else if (!std::isprint(static_cast<char>(value)))
    std::cout << "non displayable\n";
  else
    std::cout << "\'" << static_cast<char>(value) << "\'\n";
}

void  ScalarConverter::printInt(double value)
{
  std::cout << "int: ";
  if (isnanl(value) || isinfl(value) || value > INT_MAX || value < INT_MIN)  
    std::cout << "impossible\n";
  else
    std::cout << static_cast<int>(value) << "\n";
}

void  ScalarConverter::printDouble(double value)
{
  std::cout << "double: ";
  if (isnanl(value))  
    std::cout << "nan\n";
  else if (isinfl(value))
    std::cout << (std::signbit(value) ? "-inf\n" : "+inf\n"); 
  else
    std::cout << value << ((value == static_cast<int>(value)) ? ".0\n" : "\n");
}

void  ScalarConverter::printFloat(double value)
{
  std::cout << "float: ";
  if (isnanf(value))  
    std::cout << "nanf\n";
  else if (isinff(value))
    std::cout << (std::signbit(value) ? "-inff\n" : "+inff\n"); 
  else
    std::cout << static_cast<float>(value) << ((static_cast<float>(value) == static_cast<int>(value)) ? ".0f\n" : "f\n");
}

void  ScalarConverter::convert(const std::string& literal)
{
  double  value = 0.0;

  if (isChar(literal))
    value = static_cast<double>(literal[0]);
  else if (isInt(literal))
    value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
  else if (isFloat(literal) || isSpecialFloat(literal))
    value = static_cast<double>(std::strtof(literal.c_str(), NULL));
  else if (isDouble(literal) || isSpecialDouble(literal))
    value = static_cast<double>(std::strtod(literal.c_str(), NULL));
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