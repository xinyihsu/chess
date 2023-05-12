#pragma once
// QUEEN, // 皇后(橫、直、斜走，不限制)
#include "Position.h"
#include <iostream>
#include <set>

using namespace std;
set<pair<int, int>> setW;

class Queen
{
private:
public:
	int color;
	char icon = 'Q';
	Position pos;
	vector<Position> canMovePos;

	Queen() {
		this->pos.x = 0;
		this->pos.y = 0;
	}

	Queen(int index, int color) {
		this->pos.x = 3;
		if (color == 1) {
			this->pos.y = 0;
		}
		else if (color == -1) {
			this->pos.y = 7;
		}

		this->color = color;
	}

	Queen(Position thePos) {
		this->pos = thePos;
	}

	bool move(Position to)
	{
		int dx = pos.x - to.x, dy = pos.y - to.y;
		if (abs(dx) == abs(dy)) {
			return true;
		}
		if (dx == 0 && dy > 0) {
			return true;
		}
		if (dy == 0 && dx > 0) {
			return true;
		}
		cout << "failed to move\n";
		return false;
	}
};