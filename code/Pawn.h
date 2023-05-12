#pragma once
#include "Player.h"
#include "Position.h"
#include <vector>

// PAWN // 兵(吃過路兵) //Promoting (升階)

class Pawn
{
private:
public:
	char icon = 'P';
	int color; //b.w
	int moveTimes = 0;
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
			this->pos.y = 0;
		}
		else if (color == -1) {
			this->pos.y = 7;
		}

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
		int dx = pos.x - to.x, dy = pos.y - to.y;
		if (dx!= 0) {
			cout << "failed to move\n";
			return false;
		}
		if (color == 1) {
			if (moveTimes == 0 && (dy == -2 || dy == -1)) {
				return true;
			}
			else if (dy == -1) {
				
				return false;
			}
		}
		else {
			if (moveTimes == 0 && (dy == 2 || dy == 1)) {
				return true;
			}
			else if (dy == 1) {

				return false;
			}
		}
		cout << "failed to move\n";
		return false;
	}
};
