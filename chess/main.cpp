#include "Position.h"
#include "GameManager.h"
#include "Player.h"
#include "ViewManager.h"
#include <iostream>

using namespace std;

Player black(1), white(-1); //白方, 黑方
char** gBoard;
ViewManager chess;
GameManager myGame;

int main()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (black.playerBoard[i][j] != ' ')
				cout << "\033[30m" << "\033[47m" << black.playerBoard[i][j] << "\033[0m";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (white.playerBoard[i][j] != ' ')
				cout << white.playerBoard[i][j];
		}
		cout << endl;
	}
	myGame.turns = -1; //白先 //可再多加玩家決定誰先

	while (1) {
		char chess;
		string input;
		cout << "input x y (from):";
		cin >> input;

		Position fromPos;
		fromPos.x = input[0] - 'a';
		fromPos.y = 7 - (input[1] - '1');

		if (fromPos.x > 7 || fromPos.x < 0 || fromPos.y > 7 || fromPos.y < 0) {
			cout << "invalid position(out of board)" << endl;
			continue;
		}

		//偵測是哪一個棋子
		if (myGame.turns == 1) {
			chess = black.playerBoard[fromPos.y][fromPos.x];
			if (chess == ' ') {
				if (white.playerBoard[fromPos.y][fromPos.x] != ' ') {
					cout << "invalid position(it's black turn)" << endl;
				}
				else {
					cout << "invalid position(does not have chess)" << endl;
				}
				continue;
			}
			else {
				//move
			}
		}
		else if (myGame.turns == -1) {
			chess = white.playerBoard[fromPos.y][fromPos.x];
			if (chess == ' ') {
				if (black.playerBoard[fromPos.y][fromPos.x] != ' ') {
					cout << "invalid position(it's white turn)" << endl;
				}
				else {
					cout << "invalid position(does not have chess)" << endl;
				}
				continue;
			}
			else {
				//move

			}
		}

		Position toPos;
		cout << "input x y (to):";
		cin >> input;
		toPos.x = input[0] - 'a';
		toPos.y = 7 - (input[1] - '1');

		if (toPos.x > 7 || toPos.x < 0 || toPos.y > 7 || toPos.y < 0) {
			cout << "invalid position(out of board)" << endl;
			continue;
		}

	}
}