//#include "Position.h"
//#include "Player.h"
//#include "GameManager.h"
//#include "ViewManager.h"

#include <iostream>
#include <vector>
#include "Position.h"
#include "Player.h"
#include "GameManager.h"
#include "ViewManager.h"

using namespace std;


int main()
{
	Player black(1), white(-1); //白方, 黑方
	ViewManager myChess;
	GameManager myGame;
	myChess.black = &black;
	myChess.white = &white;
	myGame.turns = -1; //白先 //可再多加玩家決定誰先

	while (1) {
		black.update();
		white.update();
		black.updateCanMovePos(white);
		white.updateCanMovePos(black);

		if (myGame.testIfDraw(black, white)) {
			cout << "Draw" << endl;
			break;
		}

		myChess.printBoard();

		if (myGame.turns == 1) {
			cout << "It's black turn." << endl;
		}
		else {
			cout << "It's white turn." << endl;
		}

		char chess;
		string input;
		cout << "input x y (from):";
		cin >> input;

		//redo
		if (input == "redo")
		{
			black.reset();
			white.reset();

			black.update();
			white.update();
			
			black.updateCanMovePos(white);
			white.updateCanMovePos(black);

			myGame.turns = -1; //白先 //可再多加玩家決定誰先

			cout << "redo successful" << endl;
			continue;
		}

		if (input.size() != 2 || !isalpha(input[0]) || !isdigit(input[1])) {
			cout << "invalid input" << endl;
			continue;
		}

		Position fromPos;
		fromPos.x = input[0] - 'a';
		fromPos.y = 7 - (input[1] - '1');

		if (fromPos.x > 7 || fromPos.x < 0 || fromPos.y > 7 || fromPos.y < 0) {
			cout << "invalid position(out of board)" << endl;
			continue;
		}

		//test if input valid
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
		}
		cout << "You are going to move " << chess << endl; //測試用

		//print can move pos
		vector<Position> print;
		if (myGame.turns == 1) print = black.returnCanMovePos(chess, fromPos);
		else print = white.returnCanMovePos(chess, fromPos);
		myChess.printCanMove(print);

		Position toPos;
		cout << "input x y (to):";
		cin >> input;
		toPos.x = input[0] - 'a';
		toPos.y = 7 - (input[1] - '1');

		if (toPos.x > 7 || toPos.x < 0 || toPos.y > 7 || toPos.y < 0) {
			cout << "invalid position(out of board)" << endl;
			continue;
		}

		if (fromPos == toPos) {
			cout << "invalid position(重複)" << endl;
			continue;
		}

		//move or eat //!!!!canmovepos==0
		if (myGame.turns == 1) {
			if (black.playerBoard[toPos.y][toPos.x] != ' ') {
				cout << "invalid position (位置上已經有棋子)" << endl;
				continue;
			}
			else {
				//move
				if (black.move(chess, fromPos, toPos)) {
					cout << "成功" << endl;
				}
				else {
					cout << "invalid move way" << endl;
					continue;
				}

				for (int i = 0; i < white.pawn.size(); i++) {
					white.pawn[i].enpassant = false;
				}

				//eat
				if (white.playerBoard[toPos.y][toPos.x] != ' ') {
					//把白棋刪除
					white.beEat(toPos);
				}
				//eat enpassant
				else  if (chess == 'P') {
					int dx = toPos.x - fromPos.x;
					int dy = toPos.y - fromPos.y;
					if (abs(dx) == 1 && abs(dy) == 1) {
						toPos.y -= 1;
						white.beEat(toPos);
					}
				}
			}
		}
		else if (myGame.turns == -1) {
			if (white.playerBoard[toPos.y][toPos.x] != ' ') {
				cout << "invalid position (位置上已經有棋子)" << endl;
				continue;
			}
			else {
				//move
				if (white.move(chess, fromPos, toPos)) {
					cout << "成功" << endl;
				}
				else {
					cout << "invalid move way" << endl;
					continue;
				}

				for (int i = 0; i < black.pawn.size(); i++) {
					black.pawn[i].enpassant = false;
				}

				//eat
				if (black.playerBoard[toPos.y][toPos.x] != ' ') {
					//把黑棋刪除
					black.beEat(toPos);
				}
				//eat enpassant
				else  if (chess == 'P') {
					int dx = toPos.x - fromPos.x;
					int dy = toPos.y - fromPos.y;
					if (abs(dx) == 1 && abs(dy) == 1) {
						toPos.y += 1;
						black.beEat(toPos);
					}
				}
			}
		}

		if (myGame.turns == 1) {
			myGame.turns = -1;
		}
		else {
			myGame.turns = 1;
		}
	}
}