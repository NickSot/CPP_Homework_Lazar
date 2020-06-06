#ifndef ARCHITECT_H
#define ARCHITECT_H

#include <string>

class Architect {
private:
	std::string name;
	std::string id;
	unsigned int permission_number;
	std::string diploma_number;
	std::string specialty;
public:
	Architect(std::string name, std::string id, unsigned int permission_number, std::string diploma_number,
		std::string specialty);
	Architect();

	bool operator==(Architect & other);
	bool operator<(const Architect & other);
	bool operator>(const Architect& other);
	
	void print_architect();
	std::string getId();
	std::string getName();
	int getPermissionNumber();
	std::string getDiplomaNumber();
	std::string getSpecialty();

	void setName(std::string name);
	void setId(std::string id);
	void setPermissionNumber(int permission_number);
	void setDiplomaNumber(std::string diploma_number);
	void setSpecialty(std::string specialty);
};
#endif