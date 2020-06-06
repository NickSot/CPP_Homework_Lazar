#include "Architect.hpp";

#include <iostream>
using namespace std;

Architect::Architect(string name, string id, unsigned int permission_number, string diploma_number, string specialty)
{
	Architect::name = name;
	Architect::id = id;
	Architect::permission_number = permission_number;
	Architect::diploma_number = diploma_number;
	Architect::specialty = specialty;
}

Architect::Architect() {}

bool Architect::operator==(Architect& other)
{
	return this->getId() == other.getId() && this->getName() == other.getName()
		&& this->getDiplomaNumber() == other.getDiplomaNumber()
		&& this->getPermissionNumber() == other.getPermissionNumber()
		&& this->getSpecialty() == other.getSpecialty();
}

bool Architect::operator<(const Architect& other)
{
	return this->name < other.name;
}

bool Architect::operator>(const Architect& other)
{
	return this->name > other.name;
}

void Architect::print_architect()
{
	cout << Architect::name << endl;
	cout << Architect::id << endl;
	cout << Architect::permission_number << endl;
	cout << Architect::diploma_number << endl;
	cout << Architect::specialty << endl;
}

std::string Architect::getId()
{
	return Architect::id;
}

std::string Architect::getName()
{
	return Architect::name;
}

int Architect::getPermissionNumber()
{
	return Architect::permission_number;
}

std::string Architect::getDiplomaNumber()
{
	return Architect::diploma_number;
}

std::string Architect::getSpecialty()
{
	return Architect::specialty;
}

void Architect::setName(std::string name)
{
	Architect::name = name;
}

void Architect::setId(std::string id)
{
	Architect::id = id;
}

void Architect::setPermissionNumber(int permission_number)
{
	Architect::permission_number = permission_number;
}

void Architect::setDiplomaNumber(std::string diploma_number)
{
	Architect::diploma_number = diploma_number;
}

void Architect::setSpecialty(std::string specialty)
{
	Architect::specialty = specialty;
}


