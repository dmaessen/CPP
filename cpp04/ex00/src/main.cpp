/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:04 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/06 14:52:47 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete(meta);
    delete(j);
    delete(i);

    std::cout << "\n\n"; 
    const WrongAnimal* w = new WrongAnimal();
    const WrongAnimal* wcat = new WrongCat();
    std::cout << w->getType() << " " << std::endl;
    std::cout << wcat->getType() << " " << std::endl;
    w->makeSound();
    wcat->makeSound();

    delete(w);
    delete(wcat);
    
    return 0;
}
