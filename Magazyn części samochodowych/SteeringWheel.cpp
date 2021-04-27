#include "SteeringWheel.h"
#include "LogicFunctions.h"

SteeringWheel::SteeringWheel(){
	_ID_++;
	this->category = _STEERINGWHEEL;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->material = _MATERIAL;
	this->brachial = _BRACHIAL;
}

SteeringWheel::SteeringWheel(std::string name, double cost, std::string material, int brachial){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, material, brachial);
}

void SteeringWheel::set(std::string name, double cost, std::string material, int brachial){
	this->category = _STEERINGWHEEL;
	this->name = name;
	this->Cost = cost;
	this->material = material;
	this->brachial = brachial;
}

std::shared_ptr<std::string[]> SteeringWheel::fillText() {
	std::shared_ptr<std::string[]> text(new std::string[2]);
	std::cout << "Podaj nazwe, a nastepnie rodzaj materialu: \n";
	std::cin.clear();
	std::cin >> text[0] >> text[1];

	return text;
}

void SteeringWheel::fill(){
	std::shared_ptr<std::string[]> text = fillText();
	double cost;
	std::cout << "Podaj cene: \n";
	std::cin.clear();
	readParam(cost);

	unsigned int brachial;
	std::cout << "Podaj liczbe ramion: \n";
	std::cin.clear();
	readParam(brachial);

	set(text[0], cost, text[1], (int)brachial);
}

void SteeringWheel::print(){
	std::cout << "-----------------------------------\nKIEROWNICA\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nTyp materialu: " << this->material
		<< "\nLiczba ramion: " << this->brachial << std::endl;
}

void SteeringWheel::saveInFile(std::ostream& oStream){
	oStream << _STEERINGWHEEL << "\n"
		<< this->name << "\n"
		<< this->ID << "\n"
		<< this->Cost << "\n"
		<< this->material << "\n"
		<< this->brachial << "\n";
}

void SteeringWheel::loadFromFile(std::istream& iStream){
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
	this->brachial = std::stoi(textLine);
}
