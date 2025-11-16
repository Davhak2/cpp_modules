#include "Zombie.hpp"

int main() {
	std::cout << "=== Heap zombie ===\n";
	Zombie* z1 = newZombie("HeapOne");
	z1->announce();

	std::cout << "\n=== Another heap zombie ===\n";
	Zombie* z2 = newZombie("HeapTwo");
	z2->announce();

	std::cout << "\nDeleting HeapOne manually...\n";
	delete z1;

	std::cout << "\n=== Stack zombie via randomChump ===\n";
	randomChump("StackOne");

	std::cout << "\n=== Creating a block with stack zombies ===\n";
	Zombie a("BlockZombieA");
	Zombie b("BlockZombieB");
	a.announce();
	b.announce();
	std::cout << "Block ending... stack zombies will auto-destroy.\n";

	std::cout << "\n=== Creating multiple heap zombies ===\n";
	Zombie* list[3];
	list[0] = newZombie("HeapA");
	list[1] = newZombie("HeapB");
	list[2] = newZombie("HeapC");

	for (int i = 0; i < 3; i++)
		list[i]->announce();

	std::cout << "\nCleaning up heap zombies manually...\n";
	for (int i = 0; i < 3; i++)
		delete list[i];

	return 0;
}
