/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:08 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 20:11:31 by vvagapov         ###   ########.fr       */
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
	cat->makeSound(); // will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	/* WRONG TEST */

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound(); // will output the WrongAnimal sound!
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	return 0;
}