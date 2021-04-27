#pragma once
#include "CarInterior.h"

const int _BRACHIAL = 0;
const std::string _STEERINGWHEEL = "STEERINGWHEEL";

class SteeringWheel :public CarInterior {
	int brachial;
	std::shared_ptr<std::string[]> fillText();
public:
	SteeringWheel();
	SteeringWheel(std::string name, double cost, std::string material, int brachial);
	void set(std::string name, double cost, std::string material, int brachial);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

