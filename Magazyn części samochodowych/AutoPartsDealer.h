#pragma once
#include <iostream>
#include <string>

class AutoPartsDealer{
	std::string nick;
	std::string password;
public:
	AutoPartsDealer();
	AutoPartsDealer(std::string n, std::string p);
	void setNick(std::string n);
	std::string getNick() { return this->nick; }
	std::string getPassword() { return this->password; }
	void setPassword(std::string password);
	void loadFromFile(std::istream &iStream);
	void saveInFile(std::ostream &oStream);
};

