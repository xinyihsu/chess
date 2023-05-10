#pragma once
#include "Position.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h" //����
#include "Bishop.h" //�D��
#include "Knight.h" //�M�h
#include "Pawn.h" //�L
#include <vector>


//�޲z�Ѥl
class Player
{
private:
	int color; //1:�� -1:��
	King king;
	vector<Queen> queen;
	vector<Rook> rook;
	vector<Bishop> bishop;
	vector<Knight> knight;
	vector<Pawn> pawn;
public:
	char** playerBoard;
	//�w�F
	Player(int color) {
		//��l���a�ۤv�ѽL
		playerBoard = new char* [8];
		for (int i = 0; i < 8; i++) {
			playerBoard[i] = new char[8];
			for (int j = 0; j < 8; j++) {
				playerBoard[i][j] = ' ';
			}
		}

		//��l�h�L
		for (int i = 0; i < 8; i++) {
			Pawn temp;
			if (color == 1) {
				temp.pos.setPosition(i, 6);
			}
			else {
				temp.pos.setPosition(i, 1);
			}
			playerBoard[7 - temp.pos.y][temp.pos.x] = temp.icon;
			pawn.push_back(temp);
		}

		//��l����
		Rook tempR[2];
		if (color == 1) {
			tempR[0].pos.setPosition(0, 7);
			tempR[1].pos.setPosition(7, 7);
		}
		else {
			tempR[0].pos.setPosition(0, 0);
			tempR[1].pos.setPosition(7, 0);
		}
		playerBoard[7 - tempR[0].pos.y][tempR[0].pos.x] = tempR[0].icon;
		playerBoard[7 - tempR[1].pos.y][tempR[1].pos.x] = tempR[1].icon;
		rook.push_back(tempR[0]);
		rook.push_back(tempR[1]);

		//��l�M�h
		Knight tempK[2];
		if (color == 1) {
			tempK[0].pos.setPosition(1, 7);
			tempK[1].pos.setPosition(6, 7);
		}
		else {
			tempK[0].pos.setPosition(1, 0);
			tempK[1].pos.setPosition(6, 0);
		}
		playerBoard[7 - tempK[0].pos.y][tempK[0].pos.x] = tempK[0].icon;
		playerBoard[7 - tempK[1].pos.y][tempK[1].pos.x] = tempK[1].icon;
		knight.push_back(tempK[0]);
		knight.push_back(tempK[1]);

		//��l�D��
		Bishop tempB[2];
		if (color == 1) {
			tempB[0].pos.setPosition(2, 7);
			tempB[1].pos.setPosition(5, 7);
		}
		else {
			tempB[0].pos.setPosition(2, 0);
			tempB[1].pos.setPosition(5, 0);
		}
		playerBoard[7 - tempB[0].pos.y][tempB[0].pos.x] = tempB[0].icon;
		playerBoard[7 - tempB[1].pos.y][tempB[1].pos.x] = tempB[1].icon;
		bishop.push_back(tempB[0]);
		bishop.push_back(tempB[1]);

		//��l�ӦZ
		Queen tempQ;
		if (color == 1) {
			tempQ.pos.setPosition(3, 7);
		}
		else {
			tempQ.pos.setPosition(3, 0);
		}
		playerBoard[7 - tempQ.pos.y][tempQ.pos.x] = tempQ.icon;
		queen.push_back(tempQ);

		//��l���
		if (color == 1) {
			king.pos.setPosition(4, 7);
		}
		else {
			king.pos.setPosition(4, 0);
		}
		playerBoard[7 - king.pos.y][king.pos.x] = king.icon;
	}

	//�Ѥl�Q�Y
	void beEat(Position chessPos)
	{

	}
};