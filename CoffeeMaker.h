#pragma once
#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "Hopper.h"
#include "Reservoir.h"
#include "Heater.h"
#include "Coffee.h"
#include <string>

class CoffeeMaker {
private:
	Heater* heater;
	Reservoir* tank;
	Hopper* hopper;
	int brewingTemp;
public:
	CoffeeMaker();
	void addWater(int oz);
	void addBeans(int beans);
	Coffee brew();
	void setHeatingTemp(int tempF);
	std::string toString();
	~CoffeeMaker();
};

#endif