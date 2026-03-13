#pragma once

#include "animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat();

	virtual void makeSound() const;
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
};
