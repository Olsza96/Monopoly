#include "PrintFunctions.h"

void MainMenu() {
	std::list<std::shared_ptr<CarPart>> DATABASE;

	int i;
	while (true) {
		printMainMenu();
		readParam(i);

		switch (i) {
		case 1:
			MenuCustomer(DATABASE);
			break;
		case 2:

			if (LogInToSeller()) {
				MenuSeller(DATABASE);
			}
			else {
				std::cout << "Nieprawidlowe haslo lub nazwa uzytkownika\n";
				system("pause");
			}

			break;
		case 3:
			RegisterUser();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}

bool LogInToSeller(){
	std::list<std::shared_ptr<AutoPartsDealer>> Users;
	FileManager manage;
	std::string password;
	std::string nick;

	manage.loadDataUsers(Users);
	std::cout << "------------------------------\nLOGOWANIE\n------------------------------\n";
	std::cout << "Podaj nazwe:\n";
	readParam(nick);
	std::cout << "Podaj haslo:\n";
	readParam(password);

	std::shared_ptr<AutoPartsDealer> user = std::make_shared<AutoPartsDealer>(nick, password);
	

	for (std::list<std::shared_ptr<AutoPartsDealer>>::iterator it = Users.begin(); it != Users.end(); ++it) {
		
		if(it->get()->getNick() == user->getNick()) {

			while (it->get()->getPassword() != user->getPassword()) {
				++it;

				if (it->get() == nullptr) {
					return false;
				}
			}

			if (it->get()->getPassword() == user->getPassword()) {
				return true;
			}
			else {
				return false;
			}

		}
	}

	return false;
}

void RegisterUser() {
	FileManager manage;
	std::string nick;
	std::string password;

	std::cout << "------------------------------\nREJESTRACJA\n------------------------------\n";
	std::cout << "Podaj nazwe:\n";
	readParam(nick);
	std::cout << "Podaj haslo:\n";
	readParam(password);

	std::shared_ptr<AutoPartsDealer> user = std::make_shared<AutoPartsDealer>(nick, password);
	std::list<std::shared_ptr<AutoPartsDealer>> users;
	
	manage.loadDataUsers(users);
	users.push_back(user);

	manage.saveDataUsers(users);

}

void MenuSeller(std::list<std::shared_ptr<CarPart>>& database) {
	int switcher = 0;

	FileManager manageFiles;

	std::fstream File(_DATABASENAME, std::ios::in);
	manageFiles.loadDataBase(database, File);

	while (true) {
		printMenuSellerChoiceOptions();

		readParam(switcher);

		switch (switcher) {
		case 1:
			AddElement(database);
			break;
		case 2:
			EnterDataFromFile(manageFiles, database);
			break;
		case 3:
			PrintDataBase(database);
			break;
		case 4:
			SearchElement(database);
			break;
		case 5:
			ClearDataBase(database);
			break;
		case 6:
			CreateSummaryFile(database, manageFiles);
			break;
		case 0:
			manageFiles.saveDataBase(database);
			database.clear();
			return;
		default:
			std::cout << "Brak takiego wyboru, sprobuj ponownie\n";
			system("pause");
			break;
		}
	}
}

void MenuCustomer(std::list<std::shared_ptr<CarPart>>& database){
	int switcher = 0;

	FileManager manageFiles;

	std::fstream File(_DATABASENAME, std::ios::in);
	manageFiles.loadDataBase(database, File);
	std::list<std::shared_ptr<CarPart>> purchases;

	while (true) {

		printMenuCustomerChoiceOptions();
		readParam(switcher);

		switch (switcher){
		case 1:
			PrintDataBase(database);
			break;
		case 2:
			PrintDataBase(purchases);
			break;
		case 3:
			PickElement(database, purchases);
			break;
		case 4:
			CreateShoppingList(purchases, manageFiles);
			break;
		case 0:
			manageFiles.saveDataBase(database);
			database.clear();
			return;
		default:
			std::cout << "Brak takiego wyboru, sprobuj ponownie\n";
			system("pause");
			break;
		}
	}
}

void PickElement(std::list<std::shared_ptr<CarPart>>& database, std::list<std::shared_ptr<CarPart>> &purchases){
	std::shared_ptr<CarPart> element = FindElement(database);

	if (element) {
		system("cls");
		element->print();
	}
	else {
		std::cout << "Brak takiego produktu\n";
		return;
	}

	std::cout
		<< "[1]Dodaj do koszyka\n"
		<< "[0]Powrot\n";
	
	size_t i;
	readParam(i);

	switch (i){
	case 1:
		database.remove(element);
		purchases.push_back(element);
		std::cout << "Dodano element do koszyka\n";
		system("pause");
		return;
	case 0:
		return;
	default:
		break;
	}

}

void printOptionsFiltres(std::list<std::shared_ptr<CarPart>> DATABASE, std::list<std::shared_ptr<CarPart>>& database) {
	database.clear();

	std::cout << "Filtruj:\n"
		<< "[1] Kategorie\n"
		<< "[2] Cene\n"
		<< "[0] Powrot\n";
	
	int switcher = -1;
	int min, max;
	readParam(switcher);

	switch (switcher){
	case 1:
		printMenuChoiceElements("Wybierz kategorie, ktorej szukasz\n");
		readParam(switcher);

		for (auto it : DATABASE) {

			if (it->getCategory() == _BUMPER && switcher == 1) {
				database.push_back(it);
			}
			else if (it->getCategory() == _LAMP && switcher == 2) {
				database.push_back(it);
			}
			else if (it->getCategory() == _BATTERY && switcher == 3) {
				database.push_back(it);
			}
			else if (it->getCategory() == _ENGINE && switcher == 4) {
				database.push_back(it);
			}
			else if (it->getCategory() == _GEARBOX && switcher == 5) {
				database.push_back(it);
			}
			else if (it->getCategory() == _DASHBOARD && switcher == 6) {
				database.push_back(it);
			}
			else if (it->getCategory() == _SEAT && switcher == 7) {
				database.push_back(it);
			}
			else if (it->getCategory() == _STEERINGWHEEL && switcher == 8) {
				database.push_back(it);
			}
			else if (switcher == 0) {
				break;
			}
		}

		break;
	case 2:
		std::cout << "Podaj zakres cen\n"
			<< "[1] minimalna wartosc\n"
			<< "[2] maksymalna wartosc\n"
			<< "[12] MinMax\n";
		readParam(switcher);

		if (switcher == 1) {
			std::cout << "\nMin = ";
			readParam(min);
			
			for (auto it : DATABASE) {

				if (it->getCost() >= min) {
					database.push_back(it);
				}

			}
		}
		else if (switcher == 2) {
			std::cout << "\nMax = ";
			readParam(max);

			for (auto it : DATABASE) {

				if (it->getCost() <= max) {
					database.push_back(it);
				}

			}
		}
		else if (switcher == 12) {
			std::cout << "\nMin = ";
			readParam(min);

			std::cout << "\nMax = ";
			readParam(max);

			for (auto it : DATABASE) {

				if (it->getCost() >= min && it->getCost() <= max) {
					database.push_back(it);
				}

			}
		}

		break;
	default:
		return;
	}
}

void CreateShoppingList(std::list<std::shared_ptr<CarPart>> purchases, FileManager manage){
	std::string fileName = "KOSZYK";
	std::fstream file = manage.OpenSummaryFile(fileName);

	size_t amountOfElements[8] = { 0 };
	double amountDue = 0;

	for (auto it : purchases) {

		if (it->getCategory() == _BUMPER) {
			amountOfElements[0]++;
			amountDue += it->getCost();
		}
		else if (it->getCategory() == _LAMP) {
			amountOfElements[1]++;
			amountDue += it->getCost();
		}
		else if (it->getCategory() == _BATTERY) {
			amountOfElements[2]++;
			amountDue += it->getCost();
		}
		else if (it->getCategory() == _ENGINE) {
			amountOfElements[3]++;
			amountDue += it->getCost();
		}
		else if (it->getCategory() == _GEARBOX) {
			amountOfElements[4]++;
			amountDue += it->getCost();
		}
		else if (it->getCategory() == _DASHBOARD) {
			amountOfElements[5]++;
			amountDue += it->getCost();
		}
		else if (it->getCategory() == _SEAT) {
			amountOfElements[6]++;
			amountDue += it->getCost();
		}
		else if (it->getCategory() == _STEERINGWHEEL) {
			amountOfElements[7]++;
			amountDue += it->getCost();
		}
	}

	file << "PODSUMOWANIE ZAKUPOW\nZAKUPIONO:";

	if (amountOfElements[0] > 0) {
		file << "\nZDERZAKI: " << amountOfElements[0];
	}
	if (amountOfElements[1] > 0) {
		file << "\nLAMPY: " << amountOfElements[1];
	}
	if (amountOfElements[2] > 0) {
		file << "\nAKUMULATORY: " << amountOfElements[2];
	}
	if (amountOfElements[3] > 0) {
		file << "\nSILNIKI: " << amountOfElements[3];
	}
	if (amountOfElements[4] > 0) {
		file << "\nSKRZYNIE BIEGÓW: " << amountOfElements[4];
	}
	if (amountOfElements[5] > 0) {
		file << "\nFOTELE: " << amountOfElements[6];
	}
	if (amountOfElements[6] > 0) {
		file << "\nKIEROWNICE: " << amountOfElements[7];
	}

	file << "\nWYDANO: " << amountDue;

	file.close();

	system("cls");
}

void AddElement(std::list<std::shared_ptr<CarPart>>& database) {
	while (true) {
		printMenuChoiceElements("Wybierz element do dodania:");

		int whichItem = 0;
		readParam(whichItem);

		if (whichItem == 1) {
			std::shared_ptr<Bumper> Bump = std::make_shared<Bumper>();
			Bump->fill();
			database.push_back(Bump);
		}
		else if (whichItem == 2) {
			std::shared_ptr<Lamp> L = std::make_shared<Lamp>();
			L->fill();
			database.push_back(L);
		}
		else if (whichItem == 3) {
			std::shared_ptr<Battery> Batt = std::make_shared<Battery>();
			Batt->fill();
			database.push_back(Batt);
		}
		else if (whichItem == 4) {
			std::shared_ptr<Engine> E = std::make_shared<Engine>();
			E->fill();
			database.push_back(E);
		}
		else if (whichItem == 5) {
			std::shared_ptr<Gearbox> G = std::make_shared<Gearbox>();
			G->fill();
			database.push_back(G);
		}
		else if (whichItem == 6) {
			std::shared_ptr<Dashboard> D = std::make_shared<Dashboard>();
			D->fill();
			database.push_back(D);
		}
		else if (whichItem == 7) {
			std::shared_ptr<Seat> S = std::make_shared<Seat>();
			S->fill();
			database.push_back(S);
		}
		else if (whichItem == 8) {
			std::shared_ptr<SteeringWheel> W = std::make_shared<SteeringWheel>();
			W->fill();
			database.push_back(W);
		}
		else if (whichItem == 0) {
			break;
		}
		else {
			std::cout << "Nie ma takiego wyboru, sprobuj ponownie\n";
			system("pause");
		}

	}
}

std::shared_ptr<CarPart> FindElement(std::list<std::shared_ptr<CarPart>>& database){
	int i;
	size_t id;

	do {
		printMenuChoiceElements("Jakiej czesci szukasz?");
		readParam(i);
	} while (i < 0 || i > 8);
	
	if (i == 0) {
		return nullptr;
	}

	std::string category = getNameOfCarPart(i);
	std::cout << "Podaj klucz ID: \n";
	readParam(id);

	for (auto it : database) {
		
		if (it->getCategory() == category) {

			if (it->getID() == id) {
				return it;
			}
		}
	}

	return nullptr;
}

void SearchElement(std::list<std::shared_ptr<CarPart>>& database){

	std::shared_ptr<CarPart> element = FindElement(database);
	if (element) {
		system("cls");
		element->print();
	}
	else {
		std::cout << "Brak takiego produktu\n";
		system("pause");
		return;
	}

	std::cout
		<< "\n[1] Edytuj element\n"
		<< "[2] Usun element\n"
		<< "[0] Powrot\n";
	int i;
	readParam(i);

	switch (i){
	case 1:
		element->fill();
		break;
	case 2:
		database.remove(element);
		break;
	case 0:
		return;
	default:
		break;
	}
}

void CreateSummaryFile(std::list<std::shared_ptr<CarPart>>& database, FileManager manage){
	std::string fileName = EnterFileName("Nazwij swoj plik podsumowujacy:");
	std::fstream file = manage.OpenSummaryFile(fileName);
	size_t amountOfElements[8] = { 0 };

	for (auto it : database) {

		if (it->getCategory() == _BUMPER) {
			amountOfElements[0]++;
		}
		else if (it->getCategory() == _LAMP) {
			amountOfElements[1]++;
		}
		else if (it->getCategory() == _BATTERY) {
			amountOfElements[2]++;
		}
		else if (it->getCategory() == _ENGINE) {
			amountOfElements[3]++;
		}
		else if (it->getCategory() == _GEARBOX) {
			amountOfElements[4]++;
		}
		else if (it->getCategory() == _DASHBOARD) {
			amountOfElements[5]++;
		}
		else if (it->getCategory() == _SEAT) {
			amountOfElements[6]++;
		}
		else if (it->getCategory() == _STEERINGWHEEL) {
			amountOfElements[7]++;
		}
	}

	file
		<< "PODSUMOWANIE ZAWARTOSCI MAGAZYNU\n"
		<< "\nZDERZAKI: " << amountOfElements[0]
		<< "\nLAMPY: " << amountOfElements[1]
		<< "\nAKUMULATORY: " << amountOfElements[2]
		<< "\nSILNIKI: " << amountOfElements[3]
		<< "\nSKRZYNIE BIEGÓW: " << amountOfElements[4]
		<< "\nDESKI ROZDZIELCZE: " << amountOfElements[5]
		<< "\nFOTELE: " << amountOfElements[6]
		<< "\nKIEROWNICE: " << amountOfElements[7];

	file.close();
}

std::string toUpperString(std::string str){
	int i = 0;
	char* cstr = new char[str.length() + 1];

	while (str.c_str()[i]) {
		cstr[i] = str.c_str()[i];
		i++;
	}

	cstr[str.length()] = 0;

	char c;
	std::string reStr = "";
	i = 0;
	while (cstr[i]){
		c = cstr[i];
		reStr += (toupper(c));
		i++;
	}

	delete[] cstr;

	return reStr;
}

bool compareName(const std::shared_ptr<CarPart>& D1, const std::shared_ptr<CarPart>& D2){

	std::string str1 = toUpperString(D1->getName());
	std::string str2 = toUpperString(D2->getName());

	if (str1 == str2) {
		return D1 < D2;
	}

	return str1 < str2;
}



bool compareCost(const std::shared_ptr<CarPart>& D1, const std::shared_ptr<CarPart>& D2) {

	if (D1->getCost() == D2->getCost()) {
		return D1 > D2;
	}

	return D1->getCost() > D2->getCost();
}

bool compareCategory(const std::shared_ptr<CarPart>& D1, const std::shared_ptr<CarPart>& D2){
	std::string str1 = toUpperString(D1->getCategory());
	std::string str2 = toUpperString(D2->getCategory());

	if (str1 == str2) {
		return D1 < D2;
	}

	return str1 < str2;
}

std::string getNameOfCarPart(int i){
	std::string name;

	if (i == 1) {
		name = _BUMPER;
	}
	else if (i == 2) {
		name = _LAMP;
	}
	else if (i == 3) {
		name = _BATTERY;
	}
	else if (i == 4) {
		name = _ENGINE;
	}
	else if (i == 5) {
		name = _GEARBOX;
	}
	else if (i == 6) {
		name = _DASHBOARD;
	}
	else if (i == 7) {
		name = _SEAT;
	}
	else if (i == 8) {
		name = _STEERINGWHEEL;
	}
	else {
		name = "\0";
	}

	return name;
}

material EvokeEnumMaterial(int changer) {
	switch (changer) {
	case 1:
		return material::ABS;
	case 2:
		return material::EPDM;
	case 3:
		return material::EP;
	default:
		return material::NIEZNANY;
	}
}

Kind EvokeEnumKind(int changer) {
	switch (changer) {
	case 1:
		return Kind::manual;
	case 2:
		return Kind::automatic;
	case 3:
		return Kind::sequential;
	default:
		return Kind::BRAK;
	}
}

