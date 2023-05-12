#pragma once
#include "Player.h"
#include "Position.h"
// BISHOP, // 主教(斜走，不限制)

class Bishop
{
private:
public:
	int color;
	char icon = 'B';
	Position pos;
	vector<Position> canMovePos;

	Bishop() {
		this->pos.x = 0;
		this->pos.y = 0;
	}

	Bishop(int index, int color) {
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

	Bishop(Position thePos) {
		this->pos = thePos;
	}

	bool move(Position to) 
	{
		int dx = pos.x - to.x, dy = pos.y - to.y;
		if (abs(dx) != abs(dy)) {
			cout << "failed to move\n";
			return false;
		}

		return true;
		//moves.insert(make_pair(x, y)); // 歷史紀錄Undo/Redo?
		//moves.insert(make_pair(desX, desY));
	}
};
