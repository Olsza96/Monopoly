#include "AutoPartsDealer.h"

AutoPartsDealer::AutoPartsDealer(){

}

AutoPartsDealer::AutoPartsDealer(std::string n, std::string p){
	this->nick = n;
	this->password = p;
}

void AutoPartsDealer::setNick(std::string nick){
	this->nick = nick;
}

void AutoPartsDealer::setPassword(std::string password){
	this->password = password;
}

void AutoPartsDealer::loadFromFile(std::istream &iStream){
	std::string textLine;
	
	std::getline(iStream, textLine);
	this->nick = textLine;
	
	std::getline(iStream, textLine);
	this->password = textLine;
}

void AutoPartsDealer::saveInFile(std::ostream &oStream){
	oStream
		<< this->nick
		<< "\n"
		<< this->password
		<< "\n";
}
