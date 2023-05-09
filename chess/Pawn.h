#pragma once
#include <vector>
// PAWN // 兵(吃過路兵) //Promoting (升階)

class Pawn
{
private:
public:
	char icon = 'P';
	//char color; //b.w
	Position pos;

	/*Pawn(Position pPos)
	{
		this->pos = pPos;
	}*/

	bool ifMoveValid(Position temp)
	{
		//有沒有自己別的棋 call set 
		//超出版面
		if (this->pos.x > 'h' || this->pos.x < 'a') {
			return false;
		}
		if (this->pos.y > '8' || this->pos.y < '1') {
			return false;
		}

		return true;
	}

	//可以移動的位置
	vector<Position> canMove() {
		Position temp;
		vector<Position> answer;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				temp.x = this->pos.x + i;
				temp.y = this->pos.y + i;
				if (ifMoveValid(temp)) {
					answer.push_back(temp);
				}
			}
		}
	}

	char getIcon() {
		return this->icon;
	}
};
