#pragma once
#include "Player.h"
#include "Position.h"
// BISHOP, // 主教(斜走，不限制)

class Bishop
{
private:
public:
	int color;
	char icon = 'B';
	Player* black, * white;
	Position pos;

	//void move(int desX, int desY) {
	//	int dx = x - desX, dy = y - desY;
	//	if (abs(dx) != abs(dy)) {
	//		cout << "failed to move\n";
	//	}

	//	while (x != desX && y != desY) {
	//		if (x < desX) {
	//			x++;
	//		}
	//		else if (x > desX) {
	//			x--;
	//		}
	//		if (y < desY) {
	//			y++;
	//		}
	//		else if (y > desY) {
	//			y--;
	//		}
	//		moves.insert(make_pair(x, y)); // 歷史紀錄Undo/Redo?
	//	}
	//	moves.insert(make_pair(desX, desY));
	//}
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
		if (temp.x > 7 || temp.x < 0) {
			return false;
		}
		if (temp.y > 7 || temp.y < 0) {
			return false;
		}

		return true;
	}

	vector<Position> canMove() {
		vector<Position> answer;
		Position temp;

		//to left up
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x - i;
			temp.y = this->pos.y - i;
			if (ifMoveValid(temp)) {
				answer.push_back(temp);
				if (color == 1) {
					if (white->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					if (black->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
			}
			else {
				break;
			}
		}

		//to right down
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x + i;
			temp.y = this->pos.y + i;
			if (ifMoveValid(temp)) {
				answer.push_back(temp);
				if (color == 1) {
					if (white->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					if (black->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
			}
			else {
				break;
			}
		}

		//to left down
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x - i;
			temp.y = this->pos.y + i;
			if (ifMoveValid(temp)) {
				answer.push_back(temp);
				if (color == 1) {
					if (white->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					if (black->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
			}
			else {
				break;
			}
		}

		//to right up
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x + i;
			temp.y = this->pos.y - i;
			if (ifMoveValid(temp)) {
				answer.push_back(temp);
				if (color == 1) {
					if (white->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					if (black->playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
			}
			else {
				break;
			}
		}

		return answer;
	}
};
