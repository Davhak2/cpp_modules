#include "ClapTrap.hpp"
#include <sstream>

std::string intToString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

void printSeparator(const std::string &title)
{
	std::cout << "\n"
			  << std::string(50, '=') << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

int main()
{
	printSeparator("CONSTRUCTOR TESTS");

	std::cout << "\n1. Default Constructor:" << std::endl;
	ClapTrap defaultBot;

	std::cout << "\n2. Name Constructor:" << std::endl;
	ClapTrap warrior("Warrior");
	ClapTrap guardian("Guardian");

	std::cout << "\n3. Copy Constructor:" << std::endl;
	ClapTrap copiedWarrior(warrior);

	printSeparator("BASIC FUNCTIONALITY TESTS");

	std::cout << "\n1. Normal Attack (should work):" << std::endl;
	warrior.attack("Training Dummy");

	std::cout << "\n2. Multiple Attacks to test energy consumption:" << std::endl;
	for (int i = 1; i <= 5; i++)
	{
		std::cout << "Attack " << i << ": ";
		warrior.attack("Enemy " + intToString(i));
	}

	std::cout << "\n3. Normal Repair (should work):" << std::endl;
	guardian.beRepaired(5);

	std::cout << "\n4. Normal Damage:" << std::endl;
	guardian.takeDamage(3);

	printSeparator("EDGE CASE TESTS - ENERGY DEPLETION");

	std::cout << "\nExhausting energy through attacks and repairs:" << std::endl;
	ClapTrap energyTest("EnergyTest");

	// Use up all 10 energy points
	for (int i = 1; i <= 6; i++)
	{
		std::cout << "Energy action " << i << ": ";
		if (i % 2 == 0)
		{
			energyTest.beRepaired(1);
		}
		else
		{
			energyTest.attack("Target");
		}
	}

	std::cout << "\nTrying to act with no energy (should fail):" << std::endl;
	energyTest.attack("Should Fail");
	energyTest.beRepaired(1);

	printSeparator("EDGE CASE TESTS - ZERO/NEGATIVE HP");

	ClapTrap victim("Victim");

	std::cout << "\n1. Normal damage:" << std::endl;
	victim.takeDamage(5);

	std::cout << "\n2. Lethal damage (exactly to 0 HP):" << std::endl;
	victim.takeDamage(5);

	std::cout << "\n3. Overkill damage (negative HP):" << std::endl;
	victim.takeDamage(10);

	std::cout << "\n4. Trying to act when destroyed (should fail):" << std::endl;
	victim.attack("Ghost Target");
	victim.beRepaired(5);

	printSeparator("ASSIGNMENT OPERATOR TESTS");

	std::cout << "\n1. Assignment operator:" << std::endl;
	ClapTrap assignee("Assignee");
	assignee = warrior; // warrior has used some energy

	std::cout << "\n2. Self-assignment test:" << std::endl;
	assignee = assignee;

	std::cout << "\n3. Chain assignment:" << std::endl;
	ClapTrap chain1("Chain1"), chain2("Chain2"), chain3("Chain3");
	chain1 = chain2 = chain3;

	printSeparator("STRESS TESTS");

	std::cout << "\n1. Extreme values test:" << std::endl;
	ClapTrap extremeTest("Extreme");
	extremeTest.takeDamage(1000);
	extremeTest.beRepaired(1000);

	std::cout << "\n2. Repair while low on energy:" << std::endl;
	ClapTrap repairTest("RepairTest");
	for (int i = 0; i < 9; i++)
	{
		repairTest.attack("Target");
	}
	repairTest.beRepaired(5);
	repairTest.attack("Should Fail");

	printSeparator("COPY BEHAVIOR VERIFICATION");

	std::cout << "\nModifying original after copy:" << std::endl;
	std::cout << "Original warrior attacks:" << std::endl;
	warrior.attack("Final Target");

	std::cout << "Copied warrior (should have different state):" << std::endl;
	copiedWarrior.attack("Copy Target");

	printSeparator("DESTRUCTOR TESTS");

	std::cout << "\nCreating temporary objects:" << std::endl;
	{
		ClapTrap temp1("Temp1");
		ClapTrap temp2("Temp2");
		std::cout << "Temporary objects created, leaving scope..." << std::endl;
	}
	std::cout << "Temporary objects destroyed" << std::endl;

	printSeparator("END OF TESTS - CLEANUP");
	std::cout << "\nAll remaining objects will be destroyed now..." << std::endl;

	return 0;
}
