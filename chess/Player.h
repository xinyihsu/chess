#pragma once
#include "Position.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h" //城堡
#include "Bishop.h" //主教
#include "Knight.h" //騎士
#include "Pawn.h" //兵
#include <vector>

struct findChess
{
	int index;
	int color;
	vector<Position> canMovePos;
};


//管理棋子
class Player
{
private:
	int color = 1; // 1:黑 -1:白
	King king;
	vector<Queen> queen;
	vector<Rook> rook;
	vector<Bishop> bishop;
	vector<Knight> knight;
	vector<Pawn> pawn;

public:
	char** playerBoard;
	//硬幹
	Player(int turn)
	{
		//初始玩家自己棋盤
		color = turn;
		playerBoard = new char* [8];
		for (int i = 0; i < 8; i++)
		{
			playerBoard[i] = new char[8];
			for (int j = 0; j < 8; j++)
			{
				playerBoard[i][j] = ' ';
			}
		}

		//初始士兵
		for (int i = 0; i < 8; i++)
		{
			Pawn temp;
			if (turn == 1)
			{
				temp.pos.setPosition(i, 1);
			}
			else
			{
				temp.pos.setPosition(i, 6);
			}
			playerBoard[temp.pos.y][temp.pos.x] = temp.icon;
			temp.color = turn;
			temp.black = &black;
			temp.white = &white;
			pawn.push_back(temp);
		}

		//初始城堡
		Rook tempR[2];
		if (turn == 1)
		{
			tempR[0].pos.setPosition(0, 0);
			tempR[1].pos.setPosition(7, 0);
		}
		else
		{
			tempR[0].pos.setPosition(0, 7);
			tempR[1].pos.setPosition(7, 7);
		}
		playerBoard[tempR[0].pos.y][tempR[0].pos.x] = tempR[0].icon;
		playerBoard[tempR[1].pos.y][tempR[1].pos.x] = tempR[1].icon;
		tempR[0].color = turn;
		tempR[1].color = turn;
		tempR[0].black = &black;
		tempR[0].white = &white;
		tempR[1].black = &black;
		tempR[1].white = &white;
		rook.push_back(tempR[0]);
		rook.push_back(tempR[1]);

		//初始騎士
		Knight tempK[2];
		if (turn == 1)
		{
			tempK[0].pos.setPosition(1, 0);
			tempK[1].pos.setPosition(6, 0);
		}
		else
		{
			tempK[0].pos.setPosition(1, 7);
			tempK[1].pos.setPosition(6, 7);
		}
		playerBoard[tempK[0].pos.y][tempK[0].pos.x] = tempK[0].icon;
		playerBoard[tempK[1].pos.y][tempK[1].pos.x] = tempK[1].icon;
		tempK[0].color = turn;
		tempK[1].color = turn;
		tempK[0].black = &black;
		tempK[0].white = &white;
		tempK[1].black = &black;
		tempK[1].white = &white;
		knight.push_back(tempK[0]);
		knight.push_back(tempK[1]);

		//初始主教
		Bishop tempB[2];
		if (turn == 1)
		{
			tempB[0].pos.setPosition(2, 0);
			tempB[1].pos.setPosition(5, 0);
		}
		else
		{
			tempB[0].pos.setPosition(2, 7);
			tempB[1].pos.setPosition(5, 7);
		}
		playerBoard[tempB[0].pos.y][tempB[0].pos.x] = tempB[0].icon;
		playerBoard[tempB[1].pos.y][tempB[1].pos.x] = tempB[1].icon;
		tempB[0].color = turn;
		tempB[1].color = turn;
		tempB[0].black = &black;
		tempB[0].white = &white;
		tempB[1].black = &black;
		tempB[1].white = &white;
		bishop.push_back(tempB[0]);
		bishop.push_back(tempB[1]);

		//初始皇后
		Queen tempQ;
		if (turn == 1)
		{
			tempQ.pos.setPosition(3, 0);
		}
		else
		{
			tempQ.pos.setPosition(3, 7);
		}
		playerBoard[tempQ.pos.y][tempQ.pos.x] = tempQ.icon;
		tempQ.color = turn;
		tempQ.black = &black;
		tempQ.white = &white;
		queen.push_back(tempQ);

		//初始國王
		if (turn == 1)
		{
			king.pos.setPosition(4, 0);
		}
		else
		{
			king.pos.setPosition(4, 7);
		}
		playerBoard[king.pos.y][king.pos.x] = king.icon;
		king.color = turn;
		king.black = &black;
		king.white = &white;
	}

	findChess findTheChess(char chess, Position fromPos)
	{
		findChess theChessFind;

		//find the chess
		switch (chess)
		{
		case 'K':
			theChessFind.canMovePos = king.chessCanMove;
			break;
		case 'Q':
			for (int i = 0; i < queen.size(); i++)
			{
				if (queen[i].pos == fromPos)
				{
					theChessFind.index = i;
					break;
				}
			}
			theChessFind.canMovePos = queen[theChessFind.index].canMove();
			break;
		case 'R':
			for (int i = 0; i < rook.size(); i++)
			{
				if (rook[i].pos == fromPos)
				{
					theChessFind.index = i;
					break;
				}
			}
			theChessFind.canMovePos = rook[theChessFind.index].canMove();
			break;
		case 'N':
			for (int i = 0; i < knight.size(); i++)
			{
				if (knight[i].pos == fromPos)
				{
					theChessFind.index = i;
					break;
				}
			}
			theChessFind.canMovePos = knight[theChessFind.index].canMove();
			break;
		case 'B':
			for (int i = 0; i < bishop.size(); i++)
			{
				if (bishop[i].pos == fromPos)
				{
					theChessFind.index = i;
					break;
				}
			}
			theChessFind.canMovePos = bishop[theChessFind.index].canMove();
			break;
		case 'P':
			for (int i = 0; i < pawn.size(); i++)
			{
				if (pawn[i].pos == fromPos)
				{
					theChessFind.index = i;
					break;
				}
			}
			theChessFind.canMovePos = pawn[theChessFind.index].canMove();
			break;
		}

		theChessFind.color = color;
		return theChessFind;
	}

	bool move(char chess, Position fromPos, Position toPos)
	{
		vector<Position> canMovePos = findTheChess(chess, fromPos).canMovePos;
		int index = findTheChess(chess, fromPos).index;

		for (int i = 0; i < canMovePos.size(); i++) {
			if (canMovePos[i] == toPos) {
				switch (chess) {
				case 'K':
					king.pos.setPosition(toPos);
					break;
				case 'Q':
					queen[index].pos.setPosition(toPos);
					break;
				case 'R':
					rook[index].pos.setPosition(toPos);
					break;
				case 'N':
					knight[index].pos.setPosition(toPos);
					break;
				case 'B':
					bishop[index].pos.setPosition(toPos);
					break;
				case 'P':
					pawn[index].pos.setPosition(toPos);
					break;
				}
				return true;
			}
		}

		return false;
	}

	//棋子被吃
	void beEat(Position chessPos)
	{
		char theChess = playerBoard[chessPos.y][chessPos.x];
		//find the chess
		int i;
		switch (theChess)
		{
		case 'K':
			//delete king
			//lose？！！！
			break;
		case 'Q':
			for (i = 0; i < queen.size(); i++)
			{
				if (queen[i].pos == chessPos)
				{
					break;
				}
			}
			queen.erase(queen.begin() + i);
			break;
		case 'R':
			for (i = 0; i < rook.size(); i++)
			{
				if (rook[i].pos == chessPos)
				{
					break;
				}
			}
			rook.erase(rook.begin() + i);
			break;
		case 'N':
			for (i = 0; i < knight.size(); i++)
			{
				if (knight[i].pos == chessPos)
				{
					break;
				}
			}
			knight.erase(knight.begin() + i);
			break;
		case 'B':
			for (i = 0; i < bishop.size(); i++)
			{
				if (bishop[i].pos == chessPos)
				{
					break;
				}
			}
			bishop.erase(bishop.begin() + i);
			break;
		case 'P':
			for (i = 0; i < pawn.size(); i++)
			{
				if (pawn[i].pos == chessPos)
				{
					break;
				}
			}
			pawn.erase(pawn.begin() + i);
			break;
		}
	}

	//update playboard
	void update() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				playerBoard[i][j] = ' ';
			}
		}

		//update king
		playerBoard[king.pos.y][king.pos.x] = king.icon;

		//update queen
		for (int i = 0; i < queen.size(); i++) {
			playerBoard[queen[i].pos.y][queen[i].pos.x] = queen[i].icon;
		}

		//update bishop
		for (int i = 0; i < bishop.size(); i++) {
			playerBoard[bishop[i].pos.y][bishop[i].pos.x] = bishop[i].icon;
		}

		//update knight
		for (int i = 0; i < knight.size(); i++) {
			playerBoard[knight[i].pos.y][knight[i].pos.x] = knight[i].icon;
		}

		//update pawn
		for (int i = 0; i < pawn.size(); i++) {
			playerBoard[pawn[i].pos.y][pawn[i].pos.x] = pawn[i].icon;
		}

		//update rook
		for (int i = 0; i < rook.size(); i++) {
			playerBoard[rook[i].pos.y][rook[i].pos.x] = rook[i].icon;
		}

	}
};

