#include "Dashboard.h"
#include "LogicFunctions.h"

Dashboard::Dashboard(){
	_ID_++;
	this->category = _DASHBOARD;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->material = _MATERIAL;
	this->isAirbag = _ISAIRBAG;
}

Dashboard::Dashboard(std::string name, double cost, std::string material, bool isairbag){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, material, isairbag);
}

void Dashboard::set(std::string name, double cost, std::string material, bool isairbag){
	this->category = _DASHBOARD;
	this->name = name;
	this->Cost = cost;
	this->material = material;
	this->isAirbag = isairbag;
}

std::shared_ptr<std::string[]> Dashboard::fillText() {
	std::shared_ptr<std::string[]> text(new std::string[2]);
	std::cout << "Podaj nazwe, a nastepnie rodzaj materialu: \n";
	std::cin.clear();
	std::cin >> text[0] >> text[1];

	return text;
}

void Dashboard::fill(){
	std::shared_ptr<std::string[]> text = fillText();

	double cost;
	std::cout << "Podaj cene: \n";
	std::cin.clear();
	readParam(cost);
	
	char c;
	std::cout << "Czy zawiera sie poduszka powietrzna?[T/N]\n";
	std::cin.clear();
	readParam(c, "Podano za wiele znakow, sprobuj ponownie\n");

	bool isairbag;
	if (c == 'T') {
		isairbag = true;
	}
	else {
		isairbag = false;
	}

	set(text[0], cost, text[1], isairbag);
}

void Dashboard::print(){
	std::cout << "-----------------------------------\nDESKA ROZDZIELCZA\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nTyp materialu: " << this->material
		<< "\nPoduszka powietrzna: ";
	if (this->isAirbag) {
		std::cout << "POSIADANA\n";
	}
	else {
		std::cout << "BRAK\n";
	}
}

void Dashboard::saveInFile(std::ostream& oStream){
	oStream << _DASHBOARD << "\n"
		<< this->name << "\n"
		<< this->ID << "\n"
		<< this->Cost << "\n"
		<< this->material << "\n"
		<< this->isAirbag << "\n";
}

void Dashboard::loadFromFile(std::istream& iStream){
	std::string textLine;

	std::getline(iStream, textLine);
	this->name = textLine;

	std::getline(iStream, textLine);
	this->ID = ++_ID_;

	std::getline(iStream, textLine);
	this->Cost = std::stod(textLine);

	std::getline(iStream, textLine);
	this->material = EvokeEnumMaterial(std::stoi(textLine));

	std::getline(iStream, textLine);
	this->isAirbag = std::stoi(textLine);
}
