#pragma once

#include <iostream>
#include <string>
#include <fstream>

const std::string _NAME = "BRAK NAZWY";
const double _COST = 0;
static int _ID_;

class CarPart {
protected:
	std::string name;
	std::string category;
	size_t ID = 0;
	double Cost = 0;
public:
	virtual void fill() = 0;
	virtual void print() = 0;
	virtual void saveInFile(std::ostream &oStream) = 0;
	virtual void loadFromFile(std::istream &iStream) = 0;
	std::string getName() { return this->name; }
	std::string getCategory() { return this->category; }
	double getCost() { return this->Cost; }
	size_t getID() { return this->ID; }
	virtual ~CarPart(){}
};
