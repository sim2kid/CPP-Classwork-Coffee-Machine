#include "Heater.h"
#include <synchapi.h>
//#include "pch.h"


Heater::Heater() {
	temp = new int;
	*temp = 75; //room temp;
}

void Heater::heatUp(int tempF) {
	while (tempF > *temp) {
		*temp += 10;
		if (*temp > tempF) {
			*temp = tempF;
		}
		Sleep(10);
	}
	return;
}

void Heater::coolDown() {
	while (75 < *temp) {
		*temp -= 10;
		if (*temp < 75) {
			*temp = 75;
		}
		Sleep(10);
	}
	return;
}

int Heater::getTemp() {
	return *temp;
}

Heater::~Heater() {
	delete temp;
}