#include "FileManager.h"

void FileManager::saveDataBase(std::list<std::shared_ptr<CarPart>> database){
	std::fstream File(_DATABASENAME, std::ios::out);

	if (File.is_open()) {

		for (auto it : database) {
			it->saveInFile(File);
		}

		File.close();
	}
	else {
		std::cout << "Brak pliku do zapisu danych w bazie\nTworze plik\n";
		saveDataBase(database);
		system("pause");
	}
}

void FileManager::loadDataBase(std::list<std::shared_ptr<CarPart>>& database, std::fstream &File){
	std::string category;

	if (File.is_open()) {

		while (std::getline(File, category)) {

			if (category == _BUMPER) {
				std::shared_ptr<Bumper> Bump = std::make_shared<Bumper>();
				Bump->loadFromFile(File);
				database.push_back(Bump);
			}
			else if (category == _LAMP) {
				std::shared_ptr<Lamp> L = std::make_shared<Lamp>();
				L->loadFromFile(File);
				database.push_back(L);
			}
			else if (category == _BATTERY) {
				std::shared_ptr<Battery> Batt = std::make_shared<Battery>();
				Batt->loadFromFile(File);
				database.push_back(Batt);
			}
			else if (category == _ENGINE) {
				std::shared_ptr<Engine> E = std::make_shared<Engine>();
				E->loadFromFile(File);
				database.push_back(E);
			}
			else if (category == _GEARBOX) {
				std::shared_ptr<Gearbox> G = std::make_shared<Gearbox>();
				G->loadFromFile(File);
				database.push_back(G);
			}
			else if (category == _DASHBOARD) {
				std::shared_ptr<Dashboard> D = std::make_shared<Dashboard>();
				D->loadFromFile(File);
				database.push_back(D);
			}
			else if (category == _SEAT) {
				std::shared_ptr<Seat> S = std::make_shared<Seat>();
				S->loadFromFile(File);
				database.push_back(S);
			}
			else if (category == _STEERINGWHEEL) {
				std::shared_ptr<SteeringWheel> W = std::make_shared<SteeringWheel>();
				W->loadFromFile(File);
				database.push_back(W);
			}
			else {
				std::cout << "-----------------------------------\nNieznany obiekt\n";
			}
		}
		File.close();
	}
	else {
		std::cout << "Nie udalo sie zaladowac bazy danych\n";
		system("pause");
	}
}

void FileManager::loadFromOtherFile(const std::string &fileName, std::list<std::shared_ptr<CarPart>>& database){
	std::fstream file;
	std::string text;

	size_t countLetters = fileName.length();
	std::string isTypeOfTxt;

	if (countLetters > 4) {
		isTypeOfTxt = fileName.substr(countLetters - 4, 4);
	}
	else {
		isTypeOfTxt = "\0";
	}

	if (!(isTypeOfTxt == ".txt")) {
		const std::string nameWithOutTxt = fileName + ".txt";
		file.open(nameWithOutTxt, std::ios::in);
	}
	else {
		file.open(fileName, std::ios::in);
	}

	if (!file.is_open()) {
		std::cout << "Brak takiego pliku do odczytu\n";
		system("pause");
		return;
	}

	loadDataBase(database, file);
}

std::fstream FileManager::OpenSummaryFile(const std::string fileName){
	std::fstream file;
	std::string text;

	size_t countLetters = fileName.length();
	std::string isTypeOfTxt;

	if (countLetters > 4) {
		isTypeOfTxt = fileName.substr(countLetters - 4, 4);
	}
	else {
		isTypeOfTxt = "\0";
	}

	if (!(isTypeOfTxt == ".txt")) {
		const std::string nameWithOutTxt = fileName + ".txt";
		file.open(nameWithOutTxt, std::ios::out);
	}
	else {
		file.open(fileName, std::ios::out);
	}

	if (!file.is_open()) {
		file = OpenSummaryFile(fileName);
	}

	return file;
}

void FileManager::loadDataUsers(std::list<std::shared_ptr<AutoPartsDealer>> &usrs, const std::string &fileName){
	std::fstream file(fileName, std::ios::in);
	std::string text;

	if (file.is_open()) {
		int size = 0;
		std::string text;
		
		std::getline(file, text);
		size = stoi(text);

		for (int i = 0; i < size; i++) {
			std::shared_ptr<AutoPartsDealer> user = std::make_shared<AutoPartsDealer>();
			user->loadFromFile(file);
			usrs.push_back(user);
		}

		file.close();
	}
	else {

	}
	
}

void FileManager::saveDataUsers(std::list<std::shared_ptr<AutoPartsDealer>>& usrs, const std::string& fileName){
	std::fstream file(fileName, std::ios::out);

	if (file.is_open()) {
		file << usrs.size();
		file << "\n";
		for (auto it : usrs) {
			it->saveInFile(file);
		}
		file.close();
	}
	else {
		saveDataUsers(usrs, fileName);
	}

}
