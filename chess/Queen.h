#pragma once
// QUEEN, // �ӦZ(��B���B�ר��A������)
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
		for (int i = 0; i < canMovePos.size(); i++) {
			if (to == canMovePos[i]) {
				return true;
			}
		}
		cout << "failed to move\n";
		return false;
	}
};