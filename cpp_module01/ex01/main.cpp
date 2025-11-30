#include "Zombie.hpp"

int main()
{
	std::cout << "Creating horde of 5 zombies...\n";

	Zombie *horde1 = zombieHorde(5, "Zomb1");

	if (!horde1)
	{
		std::cout << "Failed to create horde\n";
		return 1;
	}

	std::cout << "\nAnnouncing horde:\n";
	for (int i = 0; i < 5; i++)
		horde1[i].announce();

	std::cout << "\nDeleting horde...\n";
	delete[] horde1;

	std::cout << "\nCreating horde of 1 zombie...\n";
	Zombie *horde2 = zombieHorde(1, "Zomb2");
	horde2[0].announce();
	delete[] horde2;

	std::cout << "\nTesting zero or negative count (should do nothing)...\n";
	Zombie *horde3 = zombieHorde(0, "Zomb3");
	if (!horde3)
		std::cout << "Correct: returned NULL.\n";

	return 0;
}
