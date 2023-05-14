#pragma once
#include "Position.h"
// KING, // ���(��B���B�ר��A�@��)

class King
{
public:
	int color = 1; //1:�� -1:��
	char icon = 'K';
	Position pos;
	vector<Position> canMovePos;

	King() {
		this->pos.x = 0;
		this->pos.y = 0;
	}

	King(int index, int color) {
		this->pos.x = 4;
		if (color == 1) {
			this->pos.y = 0;
		}
		else if (color == -1) {
			this->pos.y = 7;
		}

		this->color = color;
	}

	King(Position thePos) {
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
		if (dx > 1 || dx < -1 || dy > 1 || dy < -1) {
			std::cout << "failed to move\n";
			return false;
		}

		return true;
	}*/
};