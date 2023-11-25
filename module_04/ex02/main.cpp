/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:08 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/25 15:07:29 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// const Animal *forbiddenAnimal = new Animal();

	const Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}

	/* TESTING deep brain copy */

	// Creating original cat and dog and putting ideas in their brains
	Cat *cat = new Cat();
	Dog *dog = new Dog();

	cat->addIdea("cat idea one", 0);
	dog->addIdea("dog idea one", 0);
	cat->printIdeas();
	dog->printIdeas();

	// Creating copies of cat and dog
	Cat *copyCat = new Cat(*cat);
	Dog *copyDog = new Dog();
	*copyDog = *dog;

	// Adding more ideas to original cat and dog
	cat->addIdea("cat idea two", 1);
	dog->addIdea("dog idea two", 1);
	cat->printIdeas();
	dog->printIdeas();

	// Making sure that copies didn't get those new ideas
	copyCat->printIdeas();
	copyDog->printIdeas();

	delete cat;
	delete dog;
	delete copyCat;
	delete copyDog;

	return 0;
}