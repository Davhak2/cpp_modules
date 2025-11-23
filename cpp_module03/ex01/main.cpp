#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n=== Test 1: Default ScavTrap ===" << std::endl;
	ScavTrap defaultScav;
	defaultScav.attack("TargetDummy");

	std::cout << "\n=== Test 2: Energy Management ===" << std::endl;
	ScavTrap bob("Bob");
	bob.attack("Enemy1");
	for (int i = 0; i < 49; ++i)
		bob.attack("Enemy1");
	bob.attack("Enemy1");

	std::cout << "\n=== Test 3: Guarding the Gate ===" << std::endl;
	bob.guardGate();
	bob.guardGate();

	std::cout << "\n=== Test 4: Copy Constructor ===" << std::endl;
	ScavTrap copyBob(bob);
	copyBob.attack("Enemy2");
	copyBob.guardGate();

	std::cout << "\n=== Test 5: Assignment Operator ===" << std::endl;
	ScavTrap assignBob("AssignBob");
	assignBob = bob;
	assignBob.attack("Enemy3");
	assignBob.guardGate();

	std::cout << "\n=== Test 6: Health Check ===" << std::endl;
	ScavTrap weak("Weakling");
	weak.takeDamage(100);
	weak.attack("Enemy4");
	weak.guardGate();

	std::cout << "\n=== Test 7: Guard State Copy ===" << std::endl;
	ScavTrap guardCopy(copyBob);
	guardCopy.guardGate();

	return 0;
}
