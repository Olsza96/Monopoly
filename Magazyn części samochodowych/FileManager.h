#pragma once
#include <list>
#include "AutoPartsDealer.h"

#include "Bumper.h"
#include "Lamp.h"
#include "Battery.h"
#include "Engine.h"
#include "Gearbox.h"
#include "Dashboard.h"
#include "Seat.h"
#include "SteeringWheel.h"

const std::string _DATABASENAME = "DATABASE.txt";
const std::string _REGISTER = "REGISTER.txt";

class FileManager{
public:
	void saveDataBase(std::list<std::shared_ptr<CarPart>> database);
	void loadDataBase(std::list<std::shared_ptr<CarPart>>& database, std::fstream& File);
	void loadFromOtherFile(const std::string& fileName, std::list<std::shared_ptr<CarPart>>& database);
	std::fstream OpenSummaryFile(const std::string fileName);
	void loadDataUsers(std::list<std::shared_ptr<AutoPartsDealer>>& usr, const std::string& fileName = _REGISTER);
	void saveDataUsers(std::list<std::shared_ptr<AutoPartsDealer>>& usr, const std::string& fileName = _REGISTER);
};

