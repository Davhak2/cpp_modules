#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n=== Test 1: Default DiamondTrap ===" << std::endl;
	DiamondTrap defaultDiamond;
	defaultDiamond.whoAmI();
	defaultDiamond.attack("Target1");
	defaultDiamond.takeDamage(30);
	defaultDiamond.beRepaired(15);

	std::cout << "\n=== Test 2: Named DiamondTrap ===" << std::endl;
	DiamondTrap shiny("Shiny");
	shiny.whoAmI();

	for (int i = 0; i < 55; i++) {
		std::cout << "Attack #" << i + 1 << ": ";
		shiny.attack("Target2");
	}

	DiamondTrap copyShiny(shiny);
	copyShiny.whoAmI();
	copyShiny.attack("Target3");
	copyShiny.beRepaired(10);

	std::cout << "\n=== Test 4: Assignment Operator ===" << std::endl;
	DiamondTrap assigned;
	assigned = shiny;
	assigned.whoAmI();
	assigned.attack("Target4");

	std::cout << "\n=== Test 5: Health Management ===" << std::endl;
	DiamondTrap tough("Tough");
	tough.takeDamage(99);
	tough.whoAmI();
	tough.beRepaired(50);
	tough.takeDamage(100);
	tough.attack("Target5");
	tough.whoAmI();

	std::cout << "\n=== Test 6: Multiple Inheritance Check ===" << std::endl;
	DiamondTrap multi("Multi");
	multi.whoAmI();
	multi.attack("Target6");
	multi.highFivesGuys();
	multi.guardGate();

	return 0;
}
