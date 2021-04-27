#pragma once
#include "CarInterior.h"

const bool _ISWARMUP = false;
const std::string _SEAT = "SEAT";

class Seat :public CarInterior{
	bool isWarmUp;
	std::shared_ptr<std::string[]> fillText();
public:
	Seat();
	Seat(std::string name, double cost, std::string material, bool iswarmup);
	void set(std::string name, double cost, std::string material, bool iswarmup);
	virtual void fill();
	virtual void print();
	virtual void saveInFile(std::ostream& oStream);
	virtual void loadFromFile(std::istream& iStream);
};

