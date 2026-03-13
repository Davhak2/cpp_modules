#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	int		n = 10;
	Animal	*data[n];

	for (size_t i = 0; i < n; i++)
	{
		if (i % 2)
			data[i] = new Dog();
		else
			data[i] = new Cat();
	}
	for (size_t i = 0; i < n; i++)
		delete data[i];

	Dog *d1 = new Dog();
	Dog *d2 = new Dog();
	Dog *d3 = new Dog(*d2);
	*d1 = *d2;
	delete d1;
	delete d2;
	delete d3;

	return 0;
}
