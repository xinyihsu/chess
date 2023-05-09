#pragma once
#include "King.h"
#include "Queen.h"
#include "Rook.h" //����
#include "Bishop.h" //�D��
#include "Knight.h" //�M�h
#include "Pawn.h" //�L
#include "Position.h"
#include <vector>

//struct Position
//{
//	char x, y;
//};

//�޲z�Ѥl
class Player
{
private:
	int color; //1:�� -1:��
	char** playerBoard;
	King king;
	vector<Queen> queen;
	vector<Rook> rook;
	vector<Bishop> bishop;
	vector<Knight> knight;
	vector<Pawn> pawn;
public:
	//�w�F
	Player(int color) {
		//��l�h�L
		for (int i = 0; i < 8; i++) {
			Pawn temp;
			if (color == 1) {
				temp.pos.setPosition(i, 6);
			}
			else {
				temp.pos.setPosition(i, 1);
			}
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
		queen.push_back(tempQ);

		//��l���
		King tempK;
		if (color == 1) {
			tempK.pos.setPosition(3, 7);
		}
		else {
			tempK.pos.setPosition(3, 0);
		}
		king.push_back(tempK);
	}
};