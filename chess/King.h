#pragma once
#include "Player.h"
#include "Position.h"
// KING, // 國王(橫、直、斜走，一格)

class King
{
public:
	int color = 1; //1:黑 -1:白
	char icon = 'K';
	Player* black, * white;
	Position pos;
	vector<Position> chessCanMove;

	bool ifMoveValid(Position temp)
	{
		//送死

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

	//可以移動的位置
	void canMove(void) {
		Position temp;
		vector<Position> answer;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				temp.x = this->pos.x + i;
				temp.y = this->pos.y + j;
				if (ifMoveValid(temp)) {
					chessCanMove.push_back(temp);
				}
			}
		}
	}
};