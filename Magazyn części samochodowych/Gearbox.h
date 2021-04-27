#pragma once
#include "CarDrive.h"

enum Kind{BRAK = 0, manual, automatic, sequential };
const Kind _TYPE = BRAK;
const std::string _GEARBOX = "GEARBOX";

class Gearbox :public CarDrive{
	Kind type;
	std::string decrypt(Kind kin);
	int fillIterator();
public:
	Gearbox();
	Gearbox(std::string name, double cost, int serviceperiod, Kind type);
	void set(std::string name, double cost, int serviceperiod, Kind type);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

