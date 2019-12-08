#pragma once
#ifndef HEATER_H
#define HEATER_H

class Heater {
private:
	int* temp;
public:
	Heater();
	void heatUp(int tempF);
	int getTemp();
	void coolDown();
	~Heater();
};

#endif