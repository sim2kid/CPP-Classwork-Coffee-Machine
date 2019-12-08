#include "Hopper.h"
//#include "pch.h"


Hopper::Hopper() {
	beanz = new int;
	*beanz = 0;
}

void Hopper::fillHopper(int beans) {
	*beanz += beans;
	return;
}

int Hopper::beansLeft() {
	return *beanz;
}

int Hopper::useBeans(int beans) {
	if (*beanz < beans) {
		beans = *beanz;
	}
	*beanz -= beans;
	return beans;
}

Hopper::~Hopper() {
	delete beanz;
}