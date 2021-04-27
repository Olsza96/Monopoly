#include "Seat.h"
#include "LogicFunctions.h"

Seat::Seat(){
	_ID_++;
	this->category = _SEAT;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->material = _MATERIAL;
	this->isWarmUp = _ISWARMUP;
}

Seat::Seat(std::string name, double cost, std::string material, bool iswarmup){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, material, iswarmup);
}

void Seat::set(std::string name, double cost, std::string material, bool iswarmup){
	this->category = _SEAT;
	this->name = name;
	this->Cost = cost;
	this->material = material;
	this->isWarmUp = iswarmup;
}

std::shared_ptr<std::string[]> Seat::fillText() {
	std::shared_ptr<std::string[]> text(new std::string[2]);
	std::cout << "Podaj nazwe, a nastepnie rodzaj materialu: \n";
	std::cin.clear();
	std::cin >> text[0] >> text[1];

	return text;
}

void Seat::fill(){
	std::shared_ptr<std::string[]> text = fillText();
	double cost;
	std::cout << "Podaj cene: \n";
	std::cin.clear();
	readParam(cost);

	char c;
	std::cout << "Czy fotel jest podgrzewany?[T/N]\n";
	std::cin.clear();
	readParam(c, "Podano za wiele znakow, sprobuj ponownie\n");

	bool iswarpup;
	if (c == 'T') {
		iswarpup = true;
	}
	else {
		iswarpup = false;
	}

	set(text[0], cost, text[1], iswarpup);
}

void Seat::print(){
	std::cout << "-----------------------------------\nFOTEL\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nTyp materialu: " << this->material
		<< "\nPodgrzewanie: ";
	if (this->isWarmUp) {
		std::cout << "POSIADANE\n";
	}
	else {
		std::cout << "BRAK\n";
	}
}

void Seat::saveInFile(std::ostream& oStream){
	oStream << _SEAT << "\n"
		<< this->name << "\n"
		<< this->ID << "\n"
		<< this->Cost << "\n"
		<< this->material << "\n"
		<< this->isWarmUp << "\n";
}

void Seat::loadFromFile(std::istream& iStream){
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
	this->isWarmUp = std::stoi(textLine);
}
