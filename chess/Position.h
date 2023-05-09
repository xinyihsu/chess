#pragma once


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
};
