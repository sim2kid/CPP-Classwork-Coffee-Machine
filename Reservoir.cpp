#include "Reservoir.h"
//#include "pch.h"


Reservoir::Reservoir() {
	waterOz = new int;
	*waterOz = 0;
}

void Reservoir::fillWater(int oz) {
	*waterOz += oz;
	return;
}

int Reservoir::useWater(int oz) {
	if (*waterOz < oz) {
		oz = *waterOz;
	}
	*waterOz -= oz;
	return oz;
}

int Reservoir::waterLeft() {
	return *waterOz;
}

Reservoir::~Reservoir() {
	delete waterOz;
}