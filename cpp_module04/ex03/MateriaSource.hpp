#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* templates[4];

	void clearTemplates();
	void copyTemplates(const MateriaSource& other);

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	virtual ~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const& type);
};
