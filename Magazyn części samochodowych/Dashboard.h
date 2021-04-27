#pragma once
#include "CarInterior.h"

const bool _ISAIRBAG = false;
const std::string _DASHBOARD = "DASHBOARD";

class Dashboard :public CarInterior{
	bool isAirbag;
	std::shared_ptr<std::string[]> fillText();
public:
	Dashboard();
	Dashboard(std::string name, double cost, std::string material, bool isairbag);
	void set(std::string name, double cost, std::string material, bool isairbag);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

