/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:08 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/25 15:23:54 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	/* PROPER VIRTUAL TEST */

	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();  // will output cat sound
	dog->makeSound();  // will output dog sound
	meta->makeSound(); // will output animal sound

	delete meta;
	delete dog;
	delete cat;

	/* WRONG TEST */

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();	// will output WrongAnimal sound
	wrongMeta->makeSound(); // will output WrongAnimal sound

	delete wrongMeta;
	delete wrongCat;

	return 0;
}