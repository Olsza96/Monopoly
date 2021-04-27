#pragma once
#include "CarPart.h"

const int _SERVICEPERIOD = 0;

class CarDrive :public CarPart {
protected:
	int servicePeriod = 0;

};