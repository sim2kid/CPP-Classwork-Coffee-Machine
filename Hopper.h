#pragma once
#ifndef HOPPER_H
#define HOPPER_H

class Hopper {
private:
	int* beanz;
public:
	Hopper();
	void fillHopper(int beans);
	int beansLeft();
	int useBeans(int beans);
	~Hopper();
};

#endif