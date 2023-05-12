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

Player black(1), white(-1); //�դ�, �¤�
char** gBoard;
ViewManager myChess;
GameManager myGame;

int main()
{
	myChess.black = &black;
	myChess.white = &white;
	myChess.printBoard();

	myGame.turns = -1; //�ե� //�i�A�h�[���a�M�w�֥�

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

		//�����O���@�ӴѤl
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
		cout << "You are going to move " << chess << endl; //���ե�
		//myChess.printCanMove(chess);

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
			cout << "invalid position(����)" << endl;
			continue;
		}

		//move or eat
		if (myGame.turns == 1) {
			if (black.playerBoard[toPos.y][toPos.x] != ' ') {
				cout << "invalid position (��m�W�w�g���Ѥl)" << endl;
			}
			else {
				//move
				if (black.move(chess, fromPos, toPos)) {
					cout << "���\" << endl;
				}
				else {
					cout << "invalid move way" << endl;
					continue;
				}

				//eat
				if (white.playerBoard[toPos.y][toPos.x] != ' ') {
					//��մѧR��
					white.beEat(toPos);
				}
			}
				myGame.turns == -1;
		}
		else if (myGame.turns == -1) {
			if (white.playerBoard[toPos.y][toPos.x] != ' ') {
				cout << "invalid position (��m�W�w�g���Ѥl)" << endl;
				continue;
			}
			else {
				//move
				if (white.move(chess, fromPos, toPos)) {
					cout << "���\" << endl;
				}
				else {
					cout << "invalid move way" << endl;
					continue;
				}

				//eat
				if (black.playerBoard[toPos.y][toPos.x] != ' ') {
					//��´ѧR��
					black.beEat(toPos);
				}
			}
			myGame.turns == 1;
		}

		if (myGame.turns == 1) {
			myGame.turns == -1;
		}
		else {
			myGame.turns == 1;
		}
		black.update();
		black.updateCanMovePos(chess, fromPos, white);
		white.update();
		white.updateCanMovePos(chess, fromPos, black);
		myChess.printBoard();
		if (myGame.turns == 1) {
			cout << "It's black turn." << endl;
		}
		else {
			cout << "It's white turn." << endl;
		}

	}
}