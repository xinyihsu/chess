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
#include <windows.h>
#include <mmsystem.h>
#pragma comment (lib,"Winmm.lib")
using namespace std;

bool moveChess(const char&, const Position&, Position);
int checkMate(int, Player&, Player&);

Player black(1), white(-1); //�դ�, �¤�
ViewManager myChess;
GameManager myGame;

int main()
{
	PlaySound(TEXT("./music/backround_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	myChess.black = &black;
	myChess.white = &white;
	//myGame.turns = -1; //�ե� //�i�A�h�[���a�M�w�֥�
	myGame.menu();
	black.update();
	white.update();
	black.updateCanMovePos(white);
	white.updateCanMovePos(black);

	Player tmpB(1);
	Player tmpW(1);

	while (1) {
		myGame.checkKing = checkMate(myGame.turns, black, white);
		//test if checkMate
		if (myGame.checkKing == 0) {
			if (myGame.turns == 1) {
				cout << "black dead" << endl;
			}
			else {
				cout << "white dead" << endl;
			}
			break;
		}
		else if (myGame.checkKing == 1) {
			cout << "King gonna dead!!Save him!!" << endl;
			cout << "Only move King!" << endl; //���b
		}

		//test if draw
		if (myGame.turns == 1) {
			if (myGame.testIfDraw(black, white)) {//�����չL
				cout << "Draw" << endl;
				break;
			}
		}
		else {
			if (myGame.testIfDraw(white, black)) {//�����չL
				cout << "Draw" << endl;
				break;
			}
		}

		myChess.printBoard();

		if (myGame.turns == 1) cout << "It's black turn." << endl;
		else cout << "It's white turn." << endl;

		char chess;
		string input;
		cout << "input x y (from):";
		cin >> input;

		if (input == "FEN") {
			getline(cin, input);
			int i = myChess.readFEN(input);
			if (i != 0) myGame.turns = i;
			system("cls");
			cout << "FEN success" << endl;
			continue;
		}
		//restart
		if (input == "restart")
		{
			black.reset();
			white.reset();

			black.update();
			white.update();

			black.updateCanMovePos(white);
			white.updateCanMovePos(black);

			myGame.turns = -1; //�ե� //�i�A�h�[���a�M�w�֥�

			system("cls");
			cout << "restart successful" << endl;
			continue;
		}
		if (input == "undo") {
			if (myGame.turns == 1) {
				myGame.turns = -1;
				white = tmpW;
				black = tmpB;
			}
			else {
				myGame.turns = 1;
				white = tmpW;
				black = tmpB;
			}
			black.update();
			white.update();
			black.updateCanMovePos(white);
			white.updateCanMovePos(black);
			system("cls");
			cout << "undo success" << endl;
			continue;
		}

		else if (input.size() != 2 || !isalpha(input[0]) || !isdigit(input[1])) {
			system("cls");
			cout << "invalid input" << endl;
			continue;
		}

		Position fromPos;
		fromPos.x = input[0] - 'a';
		fromPos.y = 7 - (input[1] - '1');

		if (fromPos.x > 7 || fromPos.x < 0 || fromPos.y > 7 || fromPos.y < 0) {
			system("cls");
			cout << "invalid position(out of board)" << endl;
			continue;
		}

		//test if input valid
		if (myGame.turns == 1) {
			chess = black.playerBoard[fromPos.y][fromPos.x];
			if (chess == ' ') {
				system("cls");
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
				system("cls");
				if (black.playerBoard[fromPos.y][fromPos.x] != ' ') {
					cout << "invalid position(it's white turn)" << endl;
				}
				else {
					cout << "invalid position(does not have chess)" << endl;
				}
				continue;
			}
		}

		if (myGame.checkKing == 1 && chess != 'K') {
			system("cls");
			cout << "you can only move king." << endl;
			return false;
		}

		//print can move pos
		vector<Position> print;
		if (myGame.turns == 1) print = black.returnCanMovePos(chess, fromPos);
		else print = white.returnCanMovePos(chess, fromPos);
		system("cls");
		myChess.printCanMove(print);
		cout << "You are going to move " << chess << endl; //���ե�

		cout << "input x y (to):";
		cin >> input;

		if (input == "no") {
			system("cls");
			cout << "again" << endl;
			continue;
		}
		else if (input.size() != 2 || !isalpha(input[0]) || !isdigit(input[1])) {
			system("cls");
			cout << "invalid input" << endl;
			continue;
		}

		Position toPos;
		toPos.x = input[0] - 'a';
		toPos.y = 7 - (input[1] - '1');

		if (toPos.x > 7 || toPos.x < 0 || toPos.y > 7 || toPos.y < 0) {
			system("cls");
			cout << "invalid toPos(out of board)" << endl;
			continue;
		}

		if (fromPos == toPos) {
			system("cls");
			cout << "invalid position(����)" << endl;
			continue;
		}

		//�s��
		tmpB = black;
		tmpW = white;

		if (!moveChess(chess, fromPos, toPos)) {
			system("cls");
			cout << "move invalid" << endl;
			continue;
		}

		if (myGame.turns == -1) {
			if (toPos.y == 0 && chess == 'P') {
				white.promoting(toPos);
			}
		}
		else {
			if (toPos.y == 7 && chess == 'P') {
				black.promoting(toPos);
			}
		}
		//cout << "OK1";
		black.update();
		white.update();
		//cout << "OK2";
		black.updateCanMovePos(white);
		white.updateCanMovePos(black);
		//cout << "OK3";

		//���H
		if (myGame.turns == 1) myGame.turns = -1;
		else myGame.turns = 1;

	}
	PlaySound(NULL, NULL, SND_ASYNC | SND_PURGE);
}

bool moveChess(const char& chess, const Position& fromPos, Position toPos)
{
	//move or eat //!!!!canmovepos==0
	if (myGame.turns == 1) {
		if (black.playerBoard[toPos.y][toPos.x] != ' ') {
			system("cls");
			cout << "invalid position (��m�W�w�g���Ѥl)" << endl;
			return false;
		}
		else {
			//move
			if (black.move(chess, fromPos, toPos)) {
				//system("cls");
				cout << "success!" << endl;
			}
			else {
				system("cls");
				cout << "invalid move way" << endl;
				return false;
			}

			for (int i = 0; i < white.pawn.size(); i++) {
				white.pawn[i].enpassant = false;
			}

			//eat
			if (white.playerBoard[toPos.y][toPos.x] != ' ') {
				//��մѧR��
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
			system("cls");
			cout << "invalid position (��m�W�w�g���Ѥl)" << endl;
			return false;
		}
		else {
			//move
			if (white.move(chess, fromPos, toPos)) {
				//system("cls");
				cout << "success" << endl;
			}
			else {
				system("cls");
				cout << "invalid move way" << endl;
				return false;
			}

			for (int i = 0; i < black.pawn.size(); i++) {
				black.pawn[i].enpassant = false;
			}

			//eat
			if (black.playerBoard[toPos.y][toPos.x] != ' ') {
				//��´ѧR��
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
	return true;
}

int checkMate(int index, Player& black, Player& white) {
	//�T�{���L�Q�¯�
	int checkKing = 0;
	int checCheck = 0;
	//�ˬd���C�ӴѤl��_�Y��L
	//�P�_��� 1�� -1��
	if (index == 1) {
		//����i�H���ʽd��
		for (int i = 0; i < black.king[0].canMovePos.size(); i++) {
			checkKing = 0;
			//Q
			for (int j = 0; j < white.queen.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < white.queen[j].canMovePos.size(); k++) {
					if (black.king[0].canMovePos[i] == white.queen[j].canMovePos[k]) {
						auto item = black.king[0].canMovePos.erase(black.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}

			//R
			for (int j = 0; j < white.rook.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < white.rook[j].canMovePos.size(); k++) {
					if (black.king[0].canMovePos[i] == white.rook[j].canMovePos[k]) {
						auto item = black.king[0].canMovePos.erase(black.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}

			//N
			for (int j = 0; j < white.knight.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < white.knight[j].canMovePos.size(); k++) {
					if (black.king[0].canMovePos[i] == white.knight[j].canMovePos[k]) {
						auto item = black.king[0].canMovePos.erase(black.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}


			//B
			for (int j = 0; j < white.bishop.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < white.bishop[j].canMovePos.size(); k++) {
					if (black.king[0].canMovePos[i] == white.bishop[j].canMovePos[k]) {
						//auto item = black.king[0].canMovePos.erase(black.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}

			//P
			for (int j = 0; j < white.pawn.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < white.pawn[j].canMovePos.size(); k++) {
					if (black.king[0].canMovePos[i] == white.pawn[j].canMovePos[k]) {
						auto item = black.king[0].canMovePos.erase(black.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}
		}
	}
	else if (index == -1) {
		//�̥~�����i�H���ʽd��
		for (int i = 0; i < white.king[0].canMovePos.size(); i++) {
			checkKing = 0;
			//Q
			for (int j = 0; j < black.queen.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < black.queen[j].canMovePos.size(); k++) {
					if (white.king[0].canMovePos[i] == black.queen[j].canMovePos[k]) {
						auto item = white.king[0].canMovePos.erase(white.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}

			//R
			for (int j = 0; j < black.rook.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < black.rook[j].canMovePos.size(); k++) {
					if (white.king[0].canMovePos[i] == black.rook[j].canMovePos[k]) {
						auto item = white.king[0].canMovePos.erase(white.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}

			//N
			for (int j = 0; j < black.knight.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < black.knight[j].canMovePos.size(); k++) {
					if (white.king[0].canMovePos[i] == black.knight[j].canMovePos[k]) {
						auto item = white.king[0].canMovePos.erase(white.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}

			//B
			for (int j = 0; j < black.bishop.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < black.bishop[j].canMovePos.size(); k++) {
					if (white.king[0].canMovePos[i] == black.bishop[j].canMovePos[k]) {
						auto item = white.king[0].canMovePos.erase(white.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}

			//P
			for (int j = 0; j < black.pawn.size(); j++) {
				if (checkKing == 1) { break; }
				for (int k = 0; k < black.pawn[j].canMovePos.size(); k++) {
					if (white.king[0].canMovePos[i] == black.pawn[j].canMovePos[k]) {
						auto item = white.king[0].canMovePos.erase(white.king[0].canMovePos.begin() + i);
						checkKing = 1;
						checCheck = 1;
						break;
					}
				}
			}
		}
	}

	if (index == 1) {
		if (black.king[0].canMovePos.size() == 0 && checCheck == 1) {
			return 0; //�N���C������
		}
		else if (checCheck == 1) {
			return 1; //�L�N���Q�¯�
		}
		else {
			return 2; //�L�N���L�Q�¯�
		}
	}
	else if (index == -1) {
		if (white.king[0].canMovePos.size() == 0 && checCheck == 1) {
			return 0; //�N���C������
		}
		else if (checCheck == 1) {
			return 1; //�L�N���Q�¯�
		}
		else {
			return 2; //�L�N���L�Q�¯�
		}
	}
}