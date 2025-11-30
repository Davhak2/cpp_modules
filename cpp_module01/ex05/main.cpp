#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string level;

	while (!0)
	{
		std::cout << "Level for Harl: ";
		if (!std::getline(std::cin, level))
		{
			std::cout << std::endl;
			break;
		}

		if (level.empty())
			break;

		harl.complain(level);
	}

	return 0;
}
