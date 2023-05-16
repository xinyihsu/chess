#pragma once
#include "Position.h"
// KNIGHT, // �M�h(���k(�@��)�W�U(���)OR�W�U(�@��)���k(���))


class Knight
{
private:
public:
	int color;
	char icon = 'N';
	Position pos;
	vector<Position> canMovePos;

	pair<int, int> step[8] = {
		{1, 2},
		{2, 1},
		{2, -1},
		{1, -2},
		{-1, -2},
		{-2, -1},
		{-2, 1},
		{-1, 2},
	};

	Knight() {
		this->pos.x = 0;
		this->pos.y = 0;
	}

	Knight(int index, int color) {
		if (index == 0) {
			this->pos.x = 1;
		}
		else if (index == 1) {
			this->pos.x = 6;
		}

		if (color == 1) {
			this->pos.y = 0;
		}
		else if (color == -1) {
			this->pos.y = 7;
		}

		this->color = color;
	}

	Knight(Position thePos) {
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
