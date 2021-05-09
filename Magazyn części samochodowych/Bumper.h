#pragma once
#include "CarBody.h"

enum material {NIEZNANY = 0, ABS, EPDM, EP = 3 };
const material _BUMPMATERIAL = NIEZNANY;
const std::string _BUMPER = "BUMPER";

class Bumper :public CarBody{
private:
	material bumpMaterial; 

	std::string decrypt(material mater);
	std::shared_ptr<std::string[]> fillText();
	double fillCost();
	int fillIterator();
public:
	Bumper();
	Bumper(std::string name, double cost, std::string color, material bumpmaterial);
	void set(std::string name, double cost, std::string color, material bumpmaterial);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

