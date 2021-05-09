#include "Battery.h"
#include "LogicFunctions.h"

Battery::Battery(){
	_ID_++;
	this->category = _BATTERY;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->servicePeriod = _SERVICEPERIOD;
	this->capacity = _CAPACITY;
}

Battery::Battery(std::string name, double cost, int serviceperiod, int capacity){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, serviceperiod, capacity);
}

void Battery::set(std::string name, double cost, int serviceperiod, int capacity){
	this->category = _BATTERY;
	this->name = name;
	this->Cost = cost;
	this->servicePeriod = serviceperiod;
	this->capacity = capacity;
}

void Battery::fill(){
	std::string name;
	std::cout << "Wypelnij - ";

	std::cout << "\nnazwe: ";
	readParam(name);

	double cost;
	std::cout << "\ncene: ";
	readParam(cost);

	int periodAndcapacity[2];
	std::cout << "\nokres serwisowania: ";
	readParam(periodAndcapacity[0]);

	std::cout << "\npojemnosc akumulatora: ";
	readParam(periodAndcapacity[1]);

	set(name, cost, periodAndcapacity[0], periodAndcapacity[1]);
}

void Battery::print(){
	std::cout << "-----------------------------------\nAKUMULATOR\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nOkres serwisowania[LATA]: " << this->servicePeriod
		<< "\nPojemnosc[Ah]: " << this->capacity << std::endl;
}

void Battery::saveInFile(std::ostream& oStream){
	oStream << _BATTERY << "\n"
		<< this->name << "\n"
		<< this->ID << "\n"
		<< this->Cost << "\n"
		<< this->servicePeriod << "\n"
		<< this->capacity << "\n";
}

void Battery::loadFromFile(std::istream& iStream){
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
	this->capacity = std::stoi(textLine);
}
