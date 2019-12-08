#pragma once
#ifndef COFFEE_H
#define COFFEE_H
#include <string>

class Coffee {
private:
	int* strength;
	int* liquid;
	int* quality;
public:
	Coffee(int s, int l, int q);
	std::string toString();
	~Coffee();
};

#endif