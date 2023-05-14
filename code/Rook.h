#pragma once
#include "Position.h"
// ROOK // 城堡(橫、直走，不限制) // Castle (入堡) 

class Rook
{
private:
public:
	int color;
	char icon = 'R';
	Position pos;
	vector<Position> canMovePos;
	
	Rook() {
		this->pos.x = 0;
		this->pos.y = 0;
	}

	Rook(int index, int color) {
		if (index == 0) {
			this->pos.x = 0;
		}
		else if (index == 1) {
			this->pos.x = 7;
		}

		if (color == 1) {
			this->pos.y = 0;
		}
		else if (color == -1) {
			this->pos.y = 7;
		}

		this->color = color;
	}

	Rook(Position thePos) {
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

	/*bool move(Position to)
	{
		int dx = pos.x - to.x, dy = pos.y - to.y;

		if (dx == 0 && dy > 0) {
			return true;
		}
		if (dy == 0 && dx > 0) {
			return true;
		}
		cout << "failed to move\n";
		return false;
	}*/
};
