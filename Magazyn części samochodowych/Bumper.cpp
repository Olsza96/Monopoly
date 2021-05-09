#include "Bumper.h"
#include "LogicFunctions.h"

Bumper::Bumper(){
	_ID_++;
	this->category = _BUMPER;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->color = _COLOR;
	this->bumpMaterial = _BUMPMATERIAL;
}

Bumper::Bumper(std::string name, double cost, std::string color, material bumpmaterial){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, color, bumpmaterial);
}

void Bumper::set(std::string name, double cost, std::string color, material bumpmaterial){
	this->category = _BUMPER;
	this->name = name;
	this->Cost = cost;
	this->color = color;
	this->bumpMaterial = bumpmaterial;
}

std::shared_ptr<std::string[]> Bumper::fillText() {
	std::shared_ptr<std::string[]> text(new std::string[2]);
	
	std::cout << "\nnazwe: ";
	readParam(text[0]);

	std::cout << "\nkolor: ";
	readParam(text[1]);

	return text;
}

double Bumper::fillCost() {
	double cost;
	std::cout << "\ncene: ";
	readParam(cost);

	return cost;
}

int Bumper::fillIterator() {
	int iterator;
	std::cout << "\nWybierz material: \n["
		<< material::ABS << ".ABS]\n["
		<< material::EPDM << ".EPDM]\n["
		<< material::EP << ".EP]\n";
	readParam(iterator);

	return iterator;
}

void Bumper::fill(){
	std::cout << "Wypelnij - ";
	std::shared_ptr<std::string[]> text = fillText();
	double cost = fillCost();
	int iterator = fillIterator();
	material mate;
	
	switch (iterator){
	case 1:
		mate = material::ABS;
		break;
	case 2:
		mate = material::EPDM;
		break;
	case 3:
		mate = material::EP;
		break;
	default:
		mate = material::NIEZNANY;
		break;
	}

	set(text[0], cost, text[1], mate);
}

void Bumper::print(){
	std::cout << "-----------------------------------\nZDERZAK\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nColor: " << this->color
		<< "\nRodzaj materialu: " << decrypt(this->bumpMaterial) << std::endl;
}

std::string Bumper::decrypt(material mater) {

	switch (mater){
	case ABS:
		return "ABS";
	case EPDM:
		return "EPDM";
	case EP:
		return "EP";
	default:
		return "NIEZNANY";
	}
}

void Bumper::saveInFile(std::ostream& oStream){
	oStream << _BUMPER			<< "\n"
		<< this->name			<< "\n"
		<< this->ID				<< "\n"
		<< this->Cost			<< "\n"
		<< this->color			<< "\n"
		<< this->bumpMaterial	<< "\n";
}

void Bumper::loadFromFile(std::istream& iStream){
	std::string textLine;

	std::getline(iStream, textLine);
	this->name = textLine;

	std::getline(iStream, textLine);
	//this->ID = ++_ID_;

	std::getline(iStream, textLine);
	this->Cost = std::stod(textLine);

	std::getline(iStream, textLine);
	this->color = textLine;

	std::getline(iStream, textLine);
	this->bumpMaterial = EvokeEnumMaterial(std::stoi(textLine));
}
