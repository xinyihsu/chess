#pragma once
#include <vector>
using namespace std;

class  Position
{
public:
	int x, y;

	Position() {

	}

	Position(int inputX, int inputY) {
		x = inputX;
		y = inputY;
	}

	void setPosition(int inputX, int inputY) {
		x = inputX;
		y = inputY;
	}

	void setPosition(Position input) {
		x = input.x;
		y = input.y;
	}

	void operator= (const Position& equal) {
		this->x = equal.x;
		this->y = equal.y;
	}

	bool operator== (const Position& compare) {
		if (this->x != compare.x) {
			return false;
		}
		if (this->y != compare.y) {
			return false;
		}
		return true;
	}
};
