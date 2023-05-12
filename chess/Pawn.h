#pragma once
#include "Player.h"
#include "Position.h"
#include <vector>

// PAWN // �L(�Y�L���L) //Promoting (�ɶ�)

class Pawn
{
private:
public:
	char icon = 'P';
	int color; //b.w
	Player* black, * white;
	Position pos;
	vector<Position> moveData;//�٨S�s

	/*Pawn(Position pPos)
	{
		this->pos = pPos;
	}*/

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

	//�i�H���ʪ���m
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
