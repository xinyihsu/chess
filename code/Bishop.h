#pragma once
#include "Position.h"
// BISHOP, // �D��(�ר��A������)

class Bishop// : public ChessMove
{
private:
public:
	int color;
	char icon = 'B';
	Position pos;
	vector<Position> canMovePos;

	Bishop() 
	{
		this->pos.x = 0;
		this->pos.y = 0;
	}

	Bishop(int index, int color) 
	{
		if (index == 0) {
			this->pos.x = 2;
		}
		else if (index == 1) {
			this->pos.x = 5;
		}

		if (color == 1) {
			this->pos.y = 0;
		}
		else if (color == -1) {
			this->pos.y = 7;
		}

		this->color = color;
	}

	Bishop(Position thePos) 
	{
		this->pos = thePos;
	}

	bool move(Position to)
	{
		for (int i = 0; i < canMovePos.size(); i++) {
			if (to == canMovePos[i]) {
				return true;
			}
		}

		cout << "failed to move\n";
		return false;
	}
};
