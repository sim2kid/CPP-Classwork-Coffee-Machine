#pragma once
#ifndef RESERVOIR_H
#define RESERVOIR_H

class Reservoir {
private:
	int* waterOz;
public:
	Reservoir();
	void fillWater(int oz);
	int useWater(int oz);
	int waterLeft();
	~Reservoir();
};

#endif