/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:58:36 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 15:52:56 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // *abstract class (not instantiable)*
    // const Animal* animal = new Animal();
    // animal->makeSound();
    const Animal* meta[100];
    for(int i = 0; i < 100; i++)
    {
        if (i < 50)
            meta[i] = new Cat();
        else
            meta[i] = new Dog();
    }

    for (int i = 0; i < 100; i++)
        delete meta[i];
}