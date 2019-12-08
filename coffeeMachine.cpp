// coffeeMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>
#include "CoffeeMaker.h"
#include <string>

void clear();
int askForInt(std::string question);
int intToString(std::string s);
void delay(int i);

int main()
{
	clear();
	std::cout << "Welcome To The Coffee Machine!" << std::endl;

	CoffeeMaker* cm = new CoffeeMaker();
	int brewing = 1;

	while (brewing != 0) {
		std::cout << cm->toString() << std::endl;
		cm->addWater(askForInt("How much water would you like to add to the tank? (10 oz)"));
		clear();

		std::cout << cm->toString() << std::endl;
		cm->addBeans(askForInt("How many beans would you like to add to the hopper? (45 beans)"));
		clear();

		std::cout << cm->toString() << std::endl;
		cm->setHeatingTemp(askForInt("What should the heating temp be? (185 F)"));
		clear();
		
		std::cout << cm->toString() << std::endl;

		std::cout << "Heating Water..." << std::endl;
		Coffee c = cm->brew();

		std::cout << "Now Brewing";
		delay(1000);
		std::cout << ".";
		delay(1000);
		std::cout << ".";
		delay(1000);
		std::cout << "." << std::endl;
		delay(1000);
		clear();

		std::cout << cm->toString() << std::endl;
		std::cout << "Coffee Is Done!\n" << std::endl;

		std::cout << c.toString() << std::endl;

		brewing = askForInt("\nWant to make another Cup of Coffee?\n0) No\n1) Yes");
		clear();
	}
	std::cout << "Goodbye!" << std::endl;
	delete cm;
}

void delay(int i) {
	std::this_thread::sleep_for(std::chrono::milliseconds(i));
}

void clear() {
	for (int i = 0; i < 30; i++) {
		std::cout << std::endl;
	}
}

int askForInt(std::string question) {
	int asking = 1;
	int i = -1;
	while (asking == 1) {
		std::cout << question << std::endl;
		std::string s;
		std::cin >> s;

		i = intToString(s);

		if (i == -1) {
			std::cout << "Please Re-Enter Your Answer:\n" << std::endl;
		}
		else if (i < 0) {
			std::cout << "Please Enter a Non-Negative Number:\n" << std::endl;
		}
		else {
			asking = 0;
		}
	}
	return i;
}

int intToString(std::string s) {
	try
	{
		int i = std::stoi(s);
		return i;
	}
	catch (std::invalid_argument const& e) {
		std::cout << "Please Enter a Number!" << std::endl;
	}
	catch (std::out_of_range const& e) {
		std::cout << "Integer Out Of Range! Please use something closer to Zero." << std::endl;
	}
	return -1;
}