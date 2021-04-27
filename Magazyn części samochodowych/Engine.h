#pragma once

#include "CarDrive.h"
const int _HORSEPOWER = 0;
const std::string _ENGINE = "ENGINE";

class Engine :public CarDrive{
	int horsePower;

public:
	Engine();
	Engine(std::string name, double cost, int serviceperiod, int power);
	void set(std::string name, double cost, int serviceperiod, int power);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

