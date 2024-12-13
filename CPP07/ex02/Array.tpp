/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:20:35 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/03 10:36:58 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : arrSize(0)
{
  ptr = new T[arrSize];
}

template<typename T>
Array<T>::Array(unsigned int _size) : arrSize(_size)
{
  ptr = new T[arrSize];
  for (unsigned int i = 0; i < arrSize; i++)
    ptr[i] = T();
}

template<typename T>
Array<T>::Array(const Array& arr) : arrSize(arr.size())
{
  ptr = new T[arrSize];
  for (unsigned int i = 0; i < arrSize; i++)
    ptr[i] = arr.ptr[i];
}

template<typename T>
Array<T>::~Array()
{
  delete[] ptr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& arr)
{
  if (this != &arr)
  {
    delete[] ptr;
    arrSize = arr.size();
    ptr = new T[arrSize];
    for (unsigned int i = 0; i < arrSize; i++)
      ptr[i] = arr.ptr[i];
  }
  return (*this);
}

template<typename T>
size_t  Array<T>::size( void ) const
{
  return (arrSize);
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
  if (index < 0 || index >= arrSize)
    throw(std::out_of_range("Error: index out of bounds"));
  return (ptr[index]);
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
  if (index < 0 || index >= arrSize)
    throw(std::out_of_range("Error: index out of bounds"));
  return (ptr[index]);
}
