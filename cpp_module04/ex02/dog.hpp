#pragma once

#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog();

	virtual void makeSound() const;
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
};
