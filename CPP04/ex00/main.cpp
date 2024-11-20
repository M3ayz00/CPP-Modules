/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:58:36 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/18 18:51:22 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    {
        const WrongAnimal* meta = new WrongAnimal();
        WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        i->setType("nullptr");
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound();
        delete meta;
        delete i;
    }
    {
        WrongAnimal meta = WrongAnimal();
        Animal A = Cat();
        std::cout << meta.getType() << " " << std::endl;
        meta.makeSound();
        std::cout << A.getType() << " " << std::endl;
        A.makeSound();
        meta.setType("PIXOU");
        std::cout << meta.getType() << " " << std::endl;
        meta.makeSound();
    }
}