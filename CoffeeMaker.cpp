#include "CoffeeMaker.h"
#include "Hopper.h"
#include "Reservoir.h"
#include "Heater.h"
#include "Coffee.h"
#include <string>

std::string CoffeeMaker::toString() {
	std::string re = "Coffee Maker Stats:\n\nTank's Amount: ";
	re += std::to_string(tank->waterLeft()) + " Oz F.\nHopper's Amount: ";
	re += std::to_string(hopper->beansLeft()) + " Beans.\nBrewing Temp: ";
	re += std::to_string(brewingTemp) + " Degrees F.\n";
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
	quality = heater->getTemp() - 185;
	liquid = tank->useWater(999) - 10;
	strength = hopper->useBeans(999) - 45;
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