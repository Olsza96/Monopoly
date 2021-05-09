#include "FileManager.h"
#include "AutoPartsDealer.h"

void MainMenu();
bool LogInToSeller();
void RegisterUser();
void MenuCustomer(std::list<std::shared_ptr<CarPart>>& database);
void PickElement(std::list<std::shared_ptr<CarPart>>& database, std::list<std::shared_ptr<CarPart>> &purchases);
void CreateShoppingList(std::list<std::shared_ptr<CarPart>> purchases, FileManager manage);
void MenuSeller(std::list<std::shared_ptr<CarPart>> &database);
void AddElement(std::list<std::shared_ptr<CarPart>> &database);
std::shared_ptr<CarPart> FindElement(std::list<std::shared_ptr<CarPart>>& database);
void SearchElement(std::list<std::shared_ptr<CarPart>>& database);
void CreateSummaryFile(std::list<std::shared_ptr<CarPart>>& database, FileManager manage);
void printOptionsFiltres(std::list<std::shared_ptr<CarPart>> DATABASE, std::list<std::shared_ptr<CarPart>>& database);

std::string toUpperString(std::string str);
bool compareName(const std::shared_ptr<CarPart>& D1, const std::shared_ptr<CarPart>& D2);
bool compareCost(const std::shared_ptr<CarPart>& D1, const std::shared_ptr<CarPart>& D2);
bool compareCategory(const std::shared_ptr<CarPart>& D1, const std::shared_ptr<CarPart>& D2);
std::string getNameOfCarPart(int i);
material EvokeEnumMaterial(int changer);
Kind EvokeEnumKind(int changer);

template<class T> void readParam(T& param, std::string errorText = "Podano bledne dane, sproboj ponownie\n") {

	while (!(std::cin >> param)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		std::cout << errorText;
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
}