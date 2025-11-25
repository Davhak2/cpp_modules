#include "FragTrap.hpp"

int main()
{
	FragTrap ft1;
	FragTrap ft2("RoboBob");
	ft2.highFivesGuys();
	FragTrap ft3(ft2);
	ft1 = ft3;
	return 0;
}
