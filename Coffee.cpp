#include "Coffee.h"
#include <string>

Coffee::Coffee(int s, int l, int q) {
	strength = new int;
	liquid = new int;
	quality = new int;

	*strength = s;
	*liquid = l;
	*quality = q;
}

std::string Coffee::toString() {
	std::string back = "The Coffee's Strength is ";

	if (*strength < 0) {
		if(*strength < -20) {
			back += "Very Weak. (Way Too Little Beans).";
		}
		else {
			back += "Weak. (Too Little Beans).";
		}
	}
	else if (*strength > 0) {
		if (*strength > 20) {
			back += "Very Strong. (Way Too Many Beans).";
		}
		else {
			back += "Strong. (Too Many Beans).";
		}
	}
	else {
		back += "Perfect!";
	}

	back += "\nThe Coffee's Amount is ";

	if (*liquid < 0) {
		if (*liquid < -6) {
			back += "Very Low. (Way Too Little Water).";
		}
		else {
			back += "Low. (Too Little Water).";
		}
	}
	else if(*liquid > 0)
	{
		if (*liquid > 6) {
			back += "Overflowing. (Way Too Much Water).";
		}
		else {
			back += "Too High. (Too Much Water).";
		}
	}
	else {
		back += "Perfect!";
	}

	back += "\nThe Coffee's Brew is ";

	if (*quality < 0) {
		back += "Undercooked. (Raise the Brew Heat).";
	}
	else if (*quality > 0) {
		back += "Overcooked. (Lower the Brew Heat).";
	}
	else {
		back += "Perfect!";
	}

	return back;
}

Coffee::~Coffee() {
	delete strength;
	delete liquid;
	delete quality;
}