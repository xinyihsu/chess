#pragma once
#include "Player.h"
#include "Position.h"
// KING, // ���(��B���B�ר��A�@��)

class King
{
public:
	int color = 1; //1:�� -1:��
	char icon = 'K';
	Player* black, * white;
	Position pos;
	vector<Position> chessCanMove;

	bool ifMoveValid(Position temp)
	{
		//�e��

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

	//�i�H���ʪ���m
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