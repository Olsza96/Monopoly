#include "PrintFunctions.h"

void printMainMenu() {
	system("cls");
	std::cout
		<< "Witaj w MAGAZYNIE CZESCI SAMOCHODOWYCH!\n"
		<< "1.Kontynuuj jako kupujacy\n"
		<< "2.Zaloguj sie jako sprzedawca\n"
		<< "3.Zarejestruj konto sprzedawcy\n"
		<< "0.Zakoncz dzialanie\n";
}

void printMenuSellerChoiceOptions(){
	system("cls");
	std::cout << "-------------------------------------\nMENU SPRZEDAWCY\n-------------------------------------\n";
	std::cout 
		<< "1.Wprowadz dane elementu\n"
		<< "2.Wprowadz dane z pliku\n"
		<< "3.Wyswietl baze danych\n"
		<< "4.Wyszukaj element w bazie\n"
		<< "5.Wyczysc baze danych\n"
		<< "6.Utworz plik podsumowujacy stan bazy\n"
		<< "0.Powrot do menu glownego\n";
}

void printMenuCustomerChoiceOptions(){
	std::cout << "-------------------------------------\nMENU KUPUJACEGO\n-------------------------------------\n";
	std::cout
		<< "1.Wyswietl Baze\n"
		<< "2.Wyswietl zawartosc koszyka\n"
		<< "3.Wyszukaj element w bazie\n"
		<< "4.Utworz plik podsumowujacy zakupy\n"
		<< "0.Powrot do menu glownego\n";
}

void printMenuChoiceElements(std::string text) {
	system("cls");
	std::cout 
		<<	text << "\n"
		<< "1.Zderzak\n"
		<< "2.Lampa\n"
		<< "3.Akumulator\n"
		<< "4.Silnik\n"
		<< "5.Skrzynia biegow\n"
		<< "6.Deska rozdzielcza\n"
		<< "7.Fotel\n"
		<< "8.Kierownica\n"
		<< "0.Powrot do poprzednich opcji\n";
}

void PrintDataBase(std::list<std::shared_ptr<CarPart>> &database){

	if (!database.empty()) {
		while (true) {
			system("cls");

			for (auto it : database) {
				it->print();
			}

			std::cout << "\nSortuj:\n"
				<< "[1] Alfabetycznie\n"
				<< "[2] Wedlug ceny\n"
				<< "[3] Wedlug kategorii\n"
				<< "[0] Powrot\n";

			int switcher;
			readParam(switcher);

			switch (switcher) {
			case 1:
				database.sort(compareName);
				PrintDataBase(database);
				return;
			case 2:
				database.sort(compareCost);
				PrintDataBase(database);
				return;
			case 3:
				database.sort(compareCategory);
				PrintDataBase(database);
				return;
			default:
				return;
			}
		}
	}
	else {
		std::cout << "Brak zawartosci\n";
		system("pause");
		system("cls");
	}
}

void ClearDataBase(std::list<std::shared_ptr<CarPart>>& database){
	system("cls");

	database.clear();
	std::cout << "Wyczyszczono zawartosc bazy\n";
}

void EnterDataFromFile(FileManager manage, std::list<std::shared_ptr<CarPart>>& database){
	std::string fileName = EnterFileName();

	manage.loadFromOtherFile(fileName, database);
}

std::string EnterFileName(std::string text){
	std::cout << text << "\n";
	std::string fileName;
	std::cin >> fileName;

	return fileName;
}



