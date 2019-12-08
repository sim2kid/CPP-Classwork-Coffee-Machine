#include "Heater.h"
#include <chrono>
#include <thread>
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
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // I wanted to raise this from 10 to 100 cus i thought it fit better this way.
	}
	return;
}

void Heater::coolDown() {
	while (75 < *temp) {
		*temp -= 10;
		if (*temp < 75) {
			*temp = 75;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return;
}

int Heater::getTemp() {
	return *temp;
}

Heater::~Heater() {
	delete temp;
}