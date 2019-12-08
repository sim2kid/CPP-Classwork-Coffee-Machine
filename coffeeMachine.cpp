// coffeeMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <synchapi.h>
#include "CoffeeMaker.h"

int main()
{
	std::cout << "Welcome To The Coffee Machine!" << std::endl;

	CoffeeMaker* cm = new CoffeeMaker();
	int brewing = 1;

	while (brewing != 0) {
		cm->toString();
		cm->addWater(askForInt("How much water would you like to add to the tank? (10 oz)"));
		clear();

		cm->toString();
		cm->addBeans(askForInt("How many beans would you like to add to the hopper? (45 beans)"));
		clear();

		cm->toString();
		cm->setHeatingTemp(askForInt("What should the heating temp be? (185 F)"));
		clear();

		cm->toString();
		std::cout << "Now Brewing";
		Sleep(1000);
		std::cout << ".";
		Sleep(1000);
		std::cout << ".";
		Sleep(1000);
		std::cout << "." << std::endl;
		Sleep(1000);
		clear();

		cm->toString();
		std::cout << "Coffe Is Done!\n" << std::endl;

		std::cout << cm->brew().toString() << std::endl;

		brewing = askForInt("Want to make another Cup of Coffee?\n0) No\n1) Yes");
		clear();
	}
	std::cout << "Goodbye!" << std::endl;
}

void clear() {
	for (int i = 0; i < 20; i++) {
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
			std::cout << "Please Re-Enter." << std::endl;
		}
		else if (i < 0) {
			std::cout << "Please Enter a Non-Negative Number." << std::endl;
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
	catch (std::invalid_argument const &e){
		std::cout << "Please Enter a Number!" << std::endl;
	}
	catch (std::out_of_range const &e) {
		std::cout << "Integer Out Of Range! Please use something closer to Zero." << std::endl;
	}
	return -1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
