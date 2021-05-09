#include "Engine.h"
#include "LogicFunctions.h"

Engine::Engine(){
	_ID_++;
	this->category = _ENGINE;
	this->name = _NAME;
	this->ID = _ID_;
	this->Cost = _COST;
	this->servicePeriod = _SERVICEPERIOD;
	this->horsePower = _HORSEPOWER;
}

Engine::Engine(std::string name, double cost, int serviceperiod, int power){
	_ID_++;
	this->ID = _ID_;
	set(name, cost, serviceperiod, power);
}

void Engine::set(std::string name, double cost, int serviceperiod, int power){
	this->category = _ENGINE;
	this->name = name;
	this->Cost = cost;
	this->servicePeriod = serviceperiod;
	this->horsePower = power;
}

void Engine::fill(){
	std::string name;
	std::cout << "Wypelnij - ";
	std::cout << "\nnazwe: ";
	readParam(name);

	double cost;
	std::cout << "\ncene: ";
	readParam(cost);

	int periodAndHorsePower[2];
	std::cout << "\nokres serwisowania: ";
	readParam(periodAndHorsePower[0]);
	
	std::cout << "\nmoc silnika[KM]: ";
	readParam(periodAndHorsePower[1]);

	set(name, cost, periodAndHorsePower[0], periodAndHorsePower[1]);
}

void Engine::print(){
	std::cout << "-----------------------------------\nSILNIK\n-----------------------------------\nNazwa: " << this->name
		<< "\nNumer identyfikacyjny[ID]: " << this->ID
		<< "\nCena[PLN]: " << this->Cost
		<< "\nOkres serwisowania[LATA]: " << this->servicePeriod
		<< "\nKonie mechaniczne[KM]: " << this->horsePower << std::endl;
}

void Engine::saveInFile(std::ostream& oStream){
	oStream << _ENGINE << "\n"
		<< this->name << "\n"
		<< this->ID << "\n"
		<< this->Cost << "\n"
		<< this->servicePeriod << "\n"
		<< this->horsePower << "\n";
}

void Engine::loadFromFile(std::istream& iStream){
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
	this->horsePower = std::stoi(textLine);
}
