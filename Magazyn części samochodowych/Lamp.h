#pragma once
#include "CarBody.h"

const int _POWER = 0;
const std::string _LAMP = "LAMP";

class Lamp :public CarBody{
	int power;
	std::shared_ptr<std::string[]> fillText();
	double fillCost();
public:
	Lamp();
	Lamp(std::string name, double cost, std::string color, int power);
	void set(std::string name, double cost, std::string color, int power);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

