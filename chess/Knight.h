#pragma once
#include "Player.h"
#include "Position.h"
// KNIGHT, // �M�h(���k(�@��)�W�U(���)OR�W�U(�@��)���k(���))


class Knight
{
private:
public:
	int color;
	char icon = 'N';
	Player* black, * white;
	Position pos;

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

	Knight(Position thePos) {
		this->pos = thePos;
	}

	bool ifMoveValid(Position temp)
	{
		//���S���ۤv�O����
		if (color == 1) {
			if (black->playerBoard[temp.y][temp.x] != ' ') {
				return false;
			}
		}
		else if (color == -1) {
			if (white->playerBoard[temp.y][temp.x] != ' ') {
				return false;
			}
		}

		//�W�X����
		if (this->pos.x > 7 || this->pos.x < 0) {
			return false;
		}
		if (this->pos.y > 7 || this->pos.y < 0) {
			return false;
		}

		return true;
	}

	std::vector<Position> canMove() {
		std::vector<Position> answer;
		Position temp;
		for (int i = 0; i < 8; i++) {
			temp.x = this->pos.x + step[i].first;
			temp.y = this->pos.y + step[i].second;
			if (ifMoveValid(temp)) {
				answer.push_back(temp);
			}
		}
		return answer;
	}

};
