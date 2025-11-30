#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl was created" << std::endl;
	std::cout << "Available levels for Harl are: DEBUG, INFO, WARNING, ERROR" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl was destroyed" << std::endl;
}

void Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Harl::complain(std::string level) const
{
	int i;
	void (Harl::*methodPtrs[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (level.empty())
		return;
	for (i = 0; i < 4; i++)
		if (level == levels[i])
			break;
	if (i > 3)
	{
		std::cout << "Harl doesnt have such level!" << std::endl;
		return;
	}
	(this->*methodPtrs[i])();
}
