#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int idx = 0; idx < 4; ++idx)
		templates[idx] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int idx = 0; idx < 4; ++idx)
		templates[idx] = 0;
	copyTemplates(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		clearTemplates();
		copyTemplates(other);
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	clearTemplates();
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int idx = 0; idx < 4; ++idx)
	{
		if (!templates[idx])
		{
			templates[idx] = m->clone();
			delete m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int idx = 0; idx < 4; ++idx)
	{
		if (templates[idx] && templates[idx]->getType() == type)
			return templates[idx]->clone();
	}
	return 0;
}

void MateriaSource::clearTemplates()
{
	for (int idx = 0; idx < 4; ++idx)
	{
		if (templates[idx])
		{
			delete templates[idx];
			templates[idx] = 0;
		}
	}
}

void MateriaSource::copyTemplates(const MateriaSource& other)
{
	for (int idx = 0; idx < 4; ++idx)
	{
		if (other.templates[idx])
			templates[idx] = other.templates[idx]->clone();
		else
			templates[idx] = 0;
	}
}
