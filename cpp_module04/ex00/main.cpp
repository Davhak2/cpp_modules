#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wronganimal.hpp"
#include "wrongcat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCatAsAnimal = new WrongCat();
	const WrongCat* realWrongCat = new WrongCat();

	std::cout << wrongCatAsAnimal->getType() << std::endl;
	wrongMeta->makeSound();
	wrongCatAsAnimal->makeSound();
	realWrongCat->makeSound();

	delete wrongMeta;
	delete wrongCatAsAnimal;
	delete realWrongCat;

	return 0;
}
