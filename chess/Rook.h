#pragma once
#include "Player.h"
#include "Position.h"
// ROOK // 城堡(橫、直走，不限制) // Castle (入堡) 

class Rook
{
private:
public:
	int color;
	char icon = 'R';
	Player* black, * white;
	Position pos;
	/*void move(int desX, int desY) {
		int dx = desX - pos.x;
		int dy = desY - pos.y;

		if (dx == 0) {
			if (dy < 0) {
				int fromX = pos.x, fromY = pos.y;
				int toX = pos.x + dx, toY = pos.y + dy;
				while (pos.y > toY) {
					if (setW.count({ pos.x, pos.y - 1 })) {
						cout << "failed to move" << '\n';
						return;
					}
					else {
						pos.y--;
					}
					cout << pos.x << ' ' << pos.y << '\n';
				}
				setW.insert({ toX, toY });
				setW.erase({ fromX, fromY });
			}

			else {
				int fromX = pos.x, fromY = pos.y;
				int toX = pos.x + dx, toY = pos.y + dy;
				while (pos.y < toY) {
					if (setW.count({ pos.x, pos.y + 1 })) {
						cout << "failed to move" << '\n';
						return;
					}
					else {
						pos.y++;
					}
					cout << pos.x << ' ' << pos.y << '\n';
				}
				setW.insert({ toX, toY });
				setW.erase({ fromX, fromY });
			}
		}

		else if (dy == 0) {
			if (dx < 0) {
				int fromX = pos.x, fromY = pos.y;
				int toX = pos.x + dx, toY = pos.y + dy;
				while (pos.x > toX) {
					if (setW.count({ pos.x - 1, pos.y })) {
						cout << "failed to move" << '\n';
						return;
					}
					else {
						pos.x--;
					}
					cout << pos.x << ' ' << pos.y << '\n';
				}
				setW.insert({ toX, toY });
				setW.erase({ fromX, fromY });
			}

			else {
				int fromX = pos.x, fromY = pos.y;
				int toX = pos.x + dx, toY = pos.y + dy;
				while (pos.x < toX) {
					if (setW.count({ pos.x + 1, pos.y })) {
						cout << "failed to move" << '\n';
						return;
					}
					else {
						pos.x++;
					}
					cout << pos.x << ' ' << pos.y << '\n';
				}
				setW.insert({ toX, toY });
				setW.erase({ fromX, fromY });
			}
		}

		else {
			cout << "failed to move" << '\n';
			return;
		}
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

	vector<Position> canMove() {
		vector<Position> answer;
		Position temp;
		//go up
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x;
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

		//go down
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x;
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

		//go left
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x - i;
			temp.y = this->pos.y;
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

		//go right
		for (int i = 1; i < 8; i++) {
			temp.x = this->pos.x + i;
			temp.y = this->pos.y;
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
