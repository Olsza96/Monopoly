#pragma once
#include "LogicFunctions.h"

void printMainMenu();
void printMenuChoiceElements(std::string text);
void printMenuSellerChoiceOptions();
void printMenuCustomerChoiceOptions();
void PrintDataBase(std::list<std::shared_ptr<CarPart>> database);
void printOptionsSort(std::list<std::shared_ptr<CarPart>> &database);
void ClearDataBase(std::list<std::shared_ptr<CarPart>>& database);
void EnterDataFromFile(FileManager manage, std::list<std::shared_ptr<CarPart>>& database);
std::string EnterFileName(std::string text = "Podaj nazwe pliku:");