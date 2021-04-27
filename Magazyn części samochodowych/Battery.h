#pragma once
#include "CarDrive.h"

const int _CAPACITY = 0;
const std::string _BATTERY = "BATTERY";

class Battery :public CarDrive{
	int capacity;

public:
	Battery();
	Battery(std::string name, double cost, int serviceperiod, int capacity);
	void set(std::string name, double cost, int serviceperiod, int capacity);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

