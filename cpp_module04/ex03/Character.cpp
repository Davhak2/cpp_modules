#include "Character.hpp"

Character::Character(std::string const& name) : name(name)
{
	for (int idx = 0; idx < 4; ++idx)
		inventory[idx] = 0;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int idx = 0; idx < 4; ++idx)
		inventory[idx] = 0;
	copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;
		clearInventory();
		copyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int idx = 0; idx < 4; ++idx)
	{
		if (!inventory[idx])
		{
			inventory[idx] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (inventory[idx])
		inventory[idx]->use(target);
}

void Character::clearInventory()
{
	for (int idx = 0; idx < 4; ++idx)
	{
		if (inventory[idx])
		{
			delete inventory[idx];
			inventory[idx] = 0;
		}
	}
}

void Character::copyInventory(const Character& other)
{
	for (int idx = 0; idx < 4; ++idx)
	{
		if (other.inventory[idx])
			inventory[idx] = other.inventory[idx]->clone();
		else
			inventory[idx] = 0;
	}
}
