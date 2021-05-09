#include "Lamp.h"
#include "LogicFunctions.h"

Lamp::Lamp(){
	_ID_++;
	this->category = _LAMP;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->color = _COLOR;
	this->power = _POWER;
}

Lamp::Lamp(std::string name, double cost, std::string color, int power){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, color, power);
}

void Lamp::set(std::string name, double cost, std::string color, int power){
	this->category = _LAMP;
	this->name = name;
	this->Cost = cost;
	this->color = color;
	this->power = power;
}

std::shared_ptr<std::string[]> Lamp::fillText() {
	std::shared_ptr<std::string[]> text(new std::string[2]);

	std::cout << "\nnazwe: ";
	readParam(text[0]);

	std::cout << "\nkolor: ";
	readParam(text[1]);

	return text;
}

double Lamp::fillCost() {
	double cost;
	std::cout << "cene: ";
	readParam(cost);

	return cost;
}
void Lamp::fill(){
	std::cout << "Wypelnij - ";
	std::shared_ptr<std::string[]> text = fillText();
	double cost = fillCost();
	int power;
	std::cout << "\nmoc: ";
	readParam(power);

	set(text[0], cost, text[1], power);
}

void Lamp::print(){
	std::cout << "-----------------------------------\nLAMPA\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nColor: " << this->color
		<< "\nMoc[W]: " << this->power << std::endl;
}

void Lamp::saveInFile(std::ostream& oStream){
	oStream << _LAMP << "\n"
		<< this->name << "\n"
		<< this->ID << "\n"
		<< this->Cost << "\n"
		<< this->color << "\n"
		<< this->power << "\n";
}

void Lamp::loadFromFile(std::istream& iStream){
	std::string textLine;

	std::getline(iStream, textLine);
	this->name = textLine;

	std::getline(iStream, textLine);
	this->ID = ++_ID_;

	std::getline(iStream, textLine);
	this->Cost = std::stod(textLine);

	std::getline(iStream, textLine);
	this->color = textLine;

	std::getline(iStream, textLine);
	this->power = std::stoi(textLine);
}
