#pragma once
// QUEEN, // 皇后(橫、直、斜走，不限制)
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

	//void move(int desX, int desY) {
	//	cout << x << ' ' << y << '\n';
	//	int dx = desX - x;
	//	int dy = desY - y;
	//	//if(valid(desX, desY)){} //判斷有沒有超過
	//	if (dx == 0) {
	//		if (dy < 0) {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (y > toY) {
	//				if (setW.count({ x, y - 1 })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					y--;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}

	//		else {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (y < toY) {
	//				if (setW.count({ x, y + 1 })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					y++;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}
	//	}

	//	else if (dy == 0) {
	//		if (dx < 0) {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (x > toX) {
	//				if (setW.count({ x - 1, y })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					x--;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}

	//		else {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (x < toX) {
	//				if (setW.count({ x + 1, y })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					x++;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}
	//	}

	//	else if (dx / dy == -1) {
	//		if (dx < 0) {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (x > toX) {
	//				if (setW.count({ x - 1, y + 1 })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					x--;
	//					y++;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}

	//		else {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (x < toX) {
	//				if (setW.count({ x + 1, y - 1 })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					x++;
	//					y--;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}
	//	}

	//	else if (dx / dy == 1) {
	//		if (dx < 0) {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (x > toX) {
	//				if (setW.count({ x - 1, y - 1 })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					x--;
	//					y--;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}

	//		else {
	//			int fromX = x, fromY = y;
	//			int toX = x + dx, toY = y + dy;
	//			while (x < toX) {
	//				if (setW.count({ x + 1, y + 1 })) {
	//					cout << "failed to move" << '\n';
	//					return;
	//				}
	//				else {
	//					x++;
	//					y++;
	//				}
	//				cout << x << ' ' << y << '\n';
	//			}
	//			setW.insert({ toX, toY });
	//			setW.erase({ fromX, fromY });
	//		}
	//	}

	//	else {
	//		cout << "failed to move" << '\n';
	//		return;
	//	}
	//}
};