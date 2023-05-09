#pragma once
#include "King.h"
#include "Queen.h"
#include "Rook.h" //城堡
#include "Bishop.h" //主教
#include "Knight.h" //騎士
#include "Pawn.h" //兵
#include "Position.h"
#include <vector>

//struct Position
//{
//	char x, y;
//};

//管理棋子
class Player
{
private:
	int color; //1:黑 -1:白
	char** playerBoard;
	King king;
	vector<Queen> queen;
	vector<Rook> rook;
	vector<Bishop> bishop;
	vector<Knight> knight;
	vector<Pawn> pawn;
public:
	//硬幹
	Player(int color) {
		//初始士兵
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

		//初始城堡
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

		//初始騎士
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

		//初始主教
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

		//初始皇后
		Queen tempQ;
		if (color == 1) {
			tempQ.pos.setPosition(3, 7);
		}
		else {
			tempQ.pos.setPosition(3, 0);
		}
		queen.push_back(tempQ);

		//初始國王
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