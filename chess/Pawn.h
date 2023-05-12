#pragma once
#include "Player.h"
#include "Position.h"
#include <vector>

// PAWN // 兵(吃過路兵) //Promoting (升階)

class Pawn
{
private:
public:
	char icon = 'P';
	int color; //b.w
	Player* black, * white;
	Position pos;
	vector<Position> moveData;//還沒存

	/*Pawn(Position pPos)
	{
		this->pos = pPos;
	}*/

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

	//可以移動的位置
	std::vector<Position> canMove() {
		Position temp;

		temp.x = this->pos.x;
		std::vector<Position> answer;
		if (color == 1) {
			if (moveData.size() == 1) {
				temp.y = this->pos.y + 2;
				if (ifMoveValid(temp) && white->playerBoard[temp.y][temp.x] == ' ') {
					answer.push_back(temp);
				}
			}
			temp.y = this->pos.y + 1;
			if (ifMoveValid(temp)) {
				answer.push_back(temp);
			}
		}
		else {
			if (moveData.size() == 1) {
				temp.y = this->pos.y - 2;
				if (ifMoveValid(temp) && black->playerBoard[temp.y][temp.x] == ' ') {
					answer.push_back(temp);
				}
			}
			temp.y = this->pos.y - 1;
			if (ifMoveValid(temp)) {
				answer.push_back(temp);
			}
		}

		return answer;
	}

	char getIcon() {
		return this->icon;
	}
};
