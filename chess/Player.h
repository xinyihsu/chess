#pragma once
#include "Position.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h" //城堡
#include "Bishop.h" //主教
#include "Knight.h" //騎士
#include "Pawn.h" //兵
#include <vector>


//管理棋子
class Player
{
private:
	int color; //1:黑 -1:白
	King king;
	vector<Queen> queen;
	vector<Rook> rook;
	vector<Bishop> bishop;
	vector<Knight> knight;
	vector<Pawn> pawn;
public:
	char** playerBoard;
	//硬幹
	Player(int color) {
		//初始玩家自己棋盤
		playerBoard = new char* [8];
		for (int i = 0; i < 8; i++) {
			playerBoard[i] = new char[8];
			for (int j = 0; j < 8; j++) {
				playerBoard[i][j] = ' ';
			}
		}

		//初始士兵
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
		playerBoard[7 - tempR[0].pos.y][tempR[0].pos.x] = tempR[0].icon;
		playerBoard[7 - tempR[1].pos.y][tempR[1].pos.x] = tempR[1].icon;
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
		playerBoard[7 - tempK[0].pos.y][tempK[0].pos.x] = tempK[0].icon;
		playerBoard[7 - tempK[1].pos.y][tempK[1].pos.x] = tempK[1].icon;
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
		playerBoard[7 - tempB[0].pos.y][tempB[0].pos.x] = tempB[0].icon;
		playerBoard[7 - tempB[1].pos.y][tempB[1].pos.x] = tempB[1].icon;
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
		playerBoard[7 - tempQ.pos.y][tempQ.pos.x] = tempQ.icon;
		queen.push_back(tempQ);

		//初始國王
		if (color == 1) {
			king.pos.setPosition(4, 7);
		}
		else {
			king.pos.setPosition(4, 0);
		}
		playerBoard[7 - king.pos.y][king.pos.x] = king.icon;
	}

	//棋子被吃
	void beEat(Position chessPos)
	{

	}
};