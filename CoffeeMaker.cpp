#include "CoffeeMaker.h"
#include "Hopper.h"
#include "Reservoir.h"
#include "Heater.h"
#include "Coffee.h"
#include <string>

std::string CoffeeMaker::toString() {
	std::string re = "Coffee Maker Stats:\nBrewing Temp: ";
	re += brewingTemp + " Degrees F.\nTank's Amount: ";
	re += tank->waterLeft() + " Oz.\nHopper's Amount: ";
	re += hopper->beansLeft() + " Beans.\n";
	return re;
}

CoffeeMaker::CoffeeMaker() {
	heater = new Heater();
	tank = new Reservoir();
	hopper = new Hopper();
	brewingTemp = 185;
}

void CoffeeMaker::addWater(int oz) {
	tank->fillWater(oz);
}

void CoffeeMaker::addBeans(int beans) {
	hopper->fillHopper(beans);
}

Coffee CoffeeMaker::brew() {
	int strength = 0;
	int liquid = 0;
	int quality = 0;
	heater->heatUp(brewingTemp);
	quality = 185 - heater->getTemp();
	liquid = 10 - tank->useWater(10);
	strength = 45 - hopper->useBeans(45);
	heater->coolDown();

	return Coffee(strength, liquid, quality);
}

void CoffeeMaker::setHeatingTemp(int tempF) {
	brewingTemp = tempF;
}

CoffeeMaker::~CoffeeMaker() {
	delete heater;
	delete tank;
	delete hopper;
}