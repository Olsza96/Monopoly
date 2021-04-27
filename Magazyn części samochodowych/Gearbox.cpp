#include "Gearbox.h"
#include "LogicFunctions.h"

Gearbox::Gearbox(){
	_ID_++;
	this->category = _GEARBOX;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->servicePeriod = _SERVICEPERIOD;
	this->type = _TYPE;
}

Gearbox::Gearbox(std::string name, double cost, int serviceperiod, Kind type){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, serviceperiod, type);
}

void Gearbox::set(std::string name, double cost, int serviceperiod, Kind type){
	this->category = _GEARBOX;
	this->name = name;
	this->Cost = cost;
	this->servicePeriod = serviceperiod;
	this->type = type;
}

int Gearbox::fillIterator() {
	int iterator;
	std::cout << "Wybierz material: \n["
		<< Kind::manual << ".Manual]\n["
		<< Kind::automatic << ".Automatic]\n["
		<< Kind::sequential << ".Sequential]\n";
	std::cin.clear();
	readParam(iterator);

	return iterator;
}

void Gearbox::fill(){
	std::string name;
	std::cout << "Podaj nazwe: \n";
	std::cin.clear();
	std::cin >> name;

	double cost;
	std::cout << "Podaj cene: \n";
	std::cin.clear();
	readParam(cost);

	int period;
	std::cout << "Podaj okres serwisowania: \n";
	std::cin.clear();
	readParam(period);

	int iterator = fillIterator();
	Kind type;

	switch (iterator) {
	case 1:
		type = Kind::manual;
		break;
	case 2:
		type = Kind::automatic;
		break;
	case 3:
		type = Kind::sequential;
		break;
	default:
		type = Kind::BRAK;
		break;
	}

	set(name, cost, period, type);
}

void Gearbox::print(){
	std::cout << "-----------------------------------\nSKRZYNIA BIEGOW\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nOkres serwisowania[LATA]: " << this->servicePeriod
		<< "\nRodzaj: " << decrypt(this->type) << std::endl;
}

std::string Gearbox::decrypt(Kind kin) {
	switch (kin){
	case manual:
		return "MANUAL";
	case automatic:
		return "AUTOMATYK";
	case sequential:
		return "SEKWENTYK";
	default:
		return "BRAK";
	}
}

void Gearbox::saveInFile(std::ostream& oStream){
	oStream << _GEARBOX << "\n"
		<< this->name << "\n"
		<< this->ID << "\n"
		<< this->Cost << "\n"
		<< this->servicePeriod << "\n"
		<< this->type << "\n";
}

void Gearbox::loadFromFile(std::istream& iStream){
	std::string textLine;

	std::getline(iStream, textLine);
	this->name = textLine;

	std::getline(iStream, textLine);
	this->ID = ++_ID_;

	std::getline(iStream, textLine);
	this->Cost = std::stod(textLine);

	std::getline(iStream, textLine);
	this->servicePeriod = std::stoi(textLine);

	std::getline(iStream, textLine);
	this->type = EvokeEnumKind(std::stoi(textLine));
}
