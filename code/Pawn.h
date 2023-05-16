#pragma once
#include "Position.h"
#include <vector>

// PAWN // 兵(吃過路兵) //Promoting (升階)

class Pawn
{
private:
public:
	char icon = 'P';
	int color; //b.w
	int moveTimes = 0; //to judge if first move
	bool enpassant = false;
	Position pos;
	vector<Position> canMovePos;
	//vector<Position> moveData;//還沒存 要存嗎?

	Pawn() {
		this->pos.x = 0;
		this->pos.y = 0;
	}

	Pawn(int index,int color) {
		this->pos.x = index;

		if (color == 1) {
			this->pos.y = 1;
		}
		else if (color == -1) {
			this->pos.y = 6;
		}

		this->color = color;
	}

	Pawn(Position thePos) {
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
