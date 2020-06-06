#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <list>
#include "Architect.hpp";

using namespace std;

Architect readArchitect(string filename) {
	string name = "";
	string id = "";
	int permission_number = 0;
	string diploma_number = "";
	string specialty = "";

	ifstream file(filename);

	if (file.is_open()) {
		string line;

		getline(file, line);
		name = line;

		getline(file, line);
		id = line;

		getline(file, line);

		stringstream ss(line);
		ss >> permission_number;

		getline(file, line);
		diploma_number = line;

		getline(file, line);
		specialty = line;

		file.close();
	}

	Architect architect = Architect(name, id, permission_number, diploma_number, specialty);
	return architect;
}

int main()
{
	list<Architect> listOfArchitects;

	while (true) {
		// 1 - Add new archiect
		// 2 - Update or delete architect
		// 3 - Print architects by specialty
		// 4 - Print diploma by specialty ordered by name

		cout << "1 - Add new archiect" << endl;
		cout << "2 - Update or delete architect" << endl;
		cout << "3 - Print architects by specialty"<< endl;
		cout << "4 - Print diploma by specialty ordered by name" << endl;

		int userInput;
		cin >> userInput;

		string filename;
		string specialityInput;
		Architect architect;
		list<Architect>::iterator architectsIterator;
		bool is_input_fine = true;

		switch (userInput) {
		case 1:
			cin >> filename;
			architect = readArchitect(filename);

			for (architectsIterator = listOfArchitects.begin(); architectsIterator != listOfArchitects.end(); architectsIterator++) {
				if (architectsIterator->getId() == architect.getId()) {
					cout << "The id is already taken by another architect in the list..." << endl;
					is_input_fine = false;
					break;
				}
			}
			if (!is_input_fine) {
				break;
			}

			listOfArchitects.push_back(architect);
			break;
		case 2:
			cout << "1 - Update" << endl;
			cout << "2 - Delete" << endl;

			cin >> userInput;
			if (userInput == 1) {
				cin >> filename;
				architect = readArchitect(filename);

				for (architectsIterator = listOfArchitects.begin(); architectsIterator != listOfArchitects.end(); architectsIterator++) {
					if (architectsIterator->getId() == architect.getId()) {
						architectsIterator->setName(architect.getName());
						architectsIterator->setDiplomaNumber(architect.getDiplomaNumber());
						architectsIterator->setPermissionNumber(architect.getPermissionNumber());
						architectsIterator->setSpecialty(architect.getSpecialty());

						break;
					}
				}
			}
			else if (userInput == 2) {
				cin >> filename;
				architect = readArchitect(filename);

				for (architectsIterator = listOfArchitects.begin(); architectsIterator != listOfArchitects.end(); architectsIterator++) {
					if (architectsIterator->getId() == architect.getId()) {
						listOfArchitects.erase(architectsIterator);
						break;
					}
				}
			}
		case 3:
			cin >> specialityInput;

			for (architectsIterator = listOfArchitects.begin(); architectsIterator != listOfArchitects.end(); architectsIterator++) {
				if (architectsIterator->getSpecialty() == specialityInput) {
					architectsIterator->print_architect();
				}
			}
		case 4:
			cin >> specialityInput;

			auto listCopy = listOfArchitects;
			listCopy.sort();

			for (architectsIterator = listCopy.begin(); architectsIterator != listCopy.end(); architectsIterator++) {
				if (architectsIterator->getSpecialty() == specialityInput) {
					architectsIterator->print_architect();
				}
			}
		}
	}
}