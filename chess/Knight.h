#pragma once
#include "Player.h"
#include "Position.h"
// KNIGHT, // 騎士(左右(一格)上下(兩格)OR上下(一格)左右(兩格))


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
		//有沒有自己別的棋
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

		//超出版面
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
