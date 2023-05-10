#pragma once
// QUEEN, // �ӦZ(��B���B�ר��A������)
#include <iostream>
#include <set>
using namespace std;
set<pair<int, int>> setW;

class Queen
{
private:
	int x = 5, y = 4;
public:
	char icon = 'Q';
	Position pos;
	void move(int dx, int dy) {
		if (dx / dy == 1) {
			if (dx < 0) {
				int fromX = x, fromY = y;
				int toX = x + dx, toY = y + dy;
				while (x > toX) {
					if (setW.count({ x - 1, y - 1 })) {
						cout << "failed to move" << '\n';
						return;
					}
					else {
						x--;
						y--;
					}
					cout << x << ' ' << y << '\n';
				}
				setW.insert({ toX, toY });
				setW.erase({ fromX, fromY });
			}

			else {
				int fromX = x, fromY = y;
				int toX = x + dx, toY = y + dy;
				while (x < toX) {
					if (setW.count({ x + 1, y + 1 })) {
						cout << "failed to move" << '\n';
						return;
					}
					else {
						x++;
						y++;
					}
					cout << x << ' ' << y << '\n';
				}
				setW.insert({ toX, toY });
				setW.erase({ fromX, fromY });
			}
		}


	}
};