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
public:
	int color = 1; // 1:黑 -1:白
	vector<King> king;
	vector<Queen> queen;
	vector<Rook> rook;
	vector<Bishop> bishop;
	vector<Knight> knight;
	vector<Pawn> pawn;
	char** playerBoard;
	bool PMove = false;
	bool haveEat = false;

	
	//init chess
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
		for (int i = 0; i < 8; i++)	{
			Pawn temp(i, turn);
			playerBoard[temp.pos.y][temp.pos.x] = temp.icon;
			pawn.push_back(temp);
		}

		//初始城堡
		for (int i = 0; i < 2; i++) {
			Rook temp(i,turn);
			playerBoard[temp.pos.y][temp.pos.x] = temp.icon;
			rook.push_back(temp);
		}

		//初始騎士
		for (int i = 0; i < 2; i++) {
			Knight temp(i, turn);
			playerBoard[temp.pos.y][temp.pos.x] = temp.icon;
			knight.push_back(temp);
		}

		//初始主教
		for (int i = 0; i < 2; i++) {
			Bishop temp(i, turn);
			playerBoard[temp.pos.y][temp.pos.x] = temp.icon;
			bishop.push_back(temp);
		}

		//初始皇后
		Queen tempQ(0, turn);
		playerBoard[tempQ.pos.y][tempQ.pos.x] = tempQ.icon;
		queen.push_back(tempQ);

		//初始國王
		King tempK(0, turn);
		playerBoard[tempK.pos.y][tempK.pos.x] = tempK.icon;
		king.push_back(tempK);
	}

	int findTheChess(char chess, Position fromPos)
	{
		int index = 0;
		//find the chess
		switch (chess)
		{
		case 'K':
			index = 0;
			break;
		case 'Q':
			for (int i = 0; i < queen.size(); i++)
			{
				if (queen[i].pos == fromPos)
				{
					index = i;
					break;
				}
			}
			break;
		case 'R':
			for (int i = 0; i < rook.size(); i++)
			{
				if (rook[i].pos == fromPos)
				{
					index = i;
					break;
				}
			}
			break;
		case 'N':
			for (int i = 0; i < knight.size(); i++)
			{
				if (knight[i].pos == fromPos)
				{
					index = i;
					break;
				}
			}
			break;
		case 'B':
			for (int i = 0; i < bishop.size(); i++)
			{
				if (bishop[i].pos == fromPos)
				{
					index = i;
					break;
				}
			}
			break;
		case 'P':
			for (int i = 0; i < pawn.size(); i++)
			{
				if (pawn[i].pos == fromPos)
				{
					index = i;
					break;
				}
			}
			break;
		}

		return index;
	}

	bool move(char chess, Position fromPos, Position toPos)
	{
		int index = findTheChess(chess, fromPos);

		switch (chess) {
		case 'K':
			if (king[index].move(toPos)) {
				//不能自殺
				int dx = toPos.x - king[index].pos.x;
				int dy = toPos.y - king[index].pos.y;
				king[index].pos.setPosition(toPos);
				if (dy == 0) {
					//路中無棋子(updateCanMove)
					if (dx == 2) {
						rook[1].pos.setPosition(toPos.x - 1, toPos.y);
						rook[1].isMove = true;
					}
					else if(dx == -2){
						rook[0].pos.setPosition(toPos.x + 1, toPos.y);
						rook[0].isMove = true;
					}
				}
				king[0].isMove = true;
				return true;
			}
			break;
		case 'Q':
			if (queen[index].move(toPos)) {
				queen[index].pos.setPosition(toPos);
				return true;
			}
			break;
		case 'R':
			if (rook[index].move(toPos)) {
				rook[index].pos.setPosition(toPos);
				rook[index].isMove = true;
				return true;
			}
			break;
		case 'N':
			if (knight[index].move(toPos)) {
				knight[index].pos.setPosition(toPos);
				return true;
			}
			break;
		case 'B':
			if (bishop[index].move(toPos)) {
				bishop[index].pos.setPosition(toPos);
				return true;
			}
			break;
		case 'P':
			if (pawn[index].move(toPos)) {
				int dy = toPos.y - fromPos.y;
				pawn[index].pos.setPosition(toPos);
				pawn[index].moveTimes++;
				this->PMove = true;

				if (abs(dy) == 2) {
					pawn[index].enpassant = true;
				}
				return true;
			}
			break;
		}

		return false;
	}

	void updateCanMovePos(Player& opponent)
	{
		Position temp;
		// K
		king[0].canMovePos.clear();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				temp.x = king[0].pos.x + i;
				temp.y = king[0].pos.y + j;
				if (temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
					if (playerBoard[temp.y][temp.x] == ' ') {
						king[0].canMovePos.push_back(temp);
					}
				}
			}
		}
		//castle
		if (!king[0].isMove && !king[0].isCheckMate) {
			temp.x = king[0].pos.x + 2;
			temp.y = king[0].pos.y;
			for (int i = king[0].pos.x + 1; i < 7; i++) {
				if (this->playerBoard[king[0].pos.y][i] == ' ' && opponent.playerBoard[king[0].pos.y][i] == ' ') {
					king[0].canMovePos.push_back(temp);
				}
			}
			temp.x = king[0].pos.x - 2;
			for (int i = king[0].pos.x - 1; i >= 1; i--) {
				if (this->playerBoard[king[0].pos.y][i] == ' ' && opponent.playerBoard[king[0].pos.y][i] == ' ') {
					king[0].canMovePos.push_back(temp);
				}
			}
		}
		
		//Q
		for (int index = 0; index < queen.size(); index++) {
			queen[index].canMovePos.clear();
			//to left up
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x - i;
				temp.y = queen[index].pos.y - i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					queen[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//to right down
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x + i;
				temp.y = queen[index].pos.y + i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					queen[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//to left down
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x - i;
				temp.y = queen[index].pos.y + i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					queen[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//to right up
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x + i;
				temp.y = queen[index].pos.y - i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					queen[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//go up
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x;
				temp.y = queen[index].pos.y - i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					queen[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//go down
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x;
				temp.y = queen[index].pos.y + i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					queen[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//go left
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x - i;
				temp.y = queen[index].pos.y;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					queen[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//go right
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x + i;
				temp.y = queen[index].pos.y;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
						queen[index].canMovePos.push_back(temp);
						if (opponent.playerBoard[temp.y][temp.x] != ' ') {
							break;
						}
					}
					else {
						break;
					}
				}
			}
		}

		//R
		for (int index = 0; index < rook.size(); index++) {
			rook[index].canMovePos.clear();
			//go up
			for (int i = 1; i < 8; i++) {
				temp.x = rook[index].pos.x;
				temp.y = rook[index].pos.y - i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					rook[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//go down
			for (int i = 1; i < 8; i++) {
				temp.x = rook[index].pos.x;
				temp.y = rook[index].pos.y + i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					rook[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//go left
			for (int i = 1; i < 8; i++) {
				temp.x = rook[index].pos.x - i;
				temp.y = rook[index].pos.y;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					rook[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//go right
			for (int i = 1; i < 8; i++) {
				temp.x = rook[index].pos.x + i;
				temp.y = rook[index].pos.y;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					rook[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}
		}
		
		//N
		for (int index = 0; index < knight.size(); index++) {
			knight[index].canMovePos.clear();
			for (int i = 0; i < 8; i++) {
				temp.x = knight[index].pos.x + knight[index].step[i].first;
				temp.y = knight[index].pos.y + knight[index].step[i].second;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) continue;
				if (playerBoard[temp.y][temp.x] == ' ') {
					knight[index].canMovePos.push_back(temp);
				}
			}
		}
		
		//B
		for (int index = 0; index < bishop.size(); index++) {
			bishop[index].canMovePos.clear();
			//to left up
			for (int i = 1; i < 8; i++) {
				temp.x = bishop[index].pos.x - i;
				temp.y = bishop[index].pos.y - i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					bishop[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//to right down
			for (int i = 1; i < 8; i++) {
				temp.x = bishop[index].pos.x + i;
				temp.y = bishop[index].pos.y + i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					bishop[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//to left down
			for (int i = 1; i < 8; i++) {
				temp.x = bishop[index].pos.x - i;
				temp.y = bishop[index].pos.y + i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					bishop[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			//to right up
			for (int i = 1; i < 8; i++) {
				temp.x = bishop[index].pos.x + i;
				temp.y = bishop[index].pos.y - i;
				if (temp.x > 7 || temp.x < 0 || temp.y > 7 || temp.y < 0) break;
				if (playerBoard[temp.y][temp.x] == ' ') {
					bishop[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}
		}
		
		//P
		for (int index = 0; index < pawn.size(); index++){
			pawn[index].canMovePos.clear();
			temp.x = pawn[index].pos.x;
			temp.y = color == 1 ? pawn[index].pos.y + 1 : pawn[index].pos.y - 1;

			if (temp.y > 7 || temp.y < 0) continue;//恩 升階??
			if (playerBoard[temp.y][temp.x] == ' ' && opponent.playerBoard[temp.y][temp.x] == ' ') {
				pawn[index].canMovePos.push_back(temp);

				//first time can move two units
				if (pawn[index].moveTimes == 0) {
					temp.y = color == 1 ? pawn[index].pos.y + 2 : pawn[index].pos.y - 2;
					if (temp.y <= 7 && temp.y >= 0) {
						if (playerBoard[temp.y][temp.x] == ' ' && opponent.playerBoard[temp.y][temp.x] == ' ') {
							pawn[index].canMovePos.push_back(temp);
						}
					}
				}
			}

			//吃棋 & Enpassant
			temp.y = color == 1 ? pawn[index].pos.y + 1 : pawn[index].pos.y - 1;
			temp.x = pawn[index].pos.x + 1;
			if (temp.x <= 7) {
				if (opponent.playerBoard[pawn[index].pos.y][temp.x] == 'P' && opponent.pawn[index + 1].enpassant) {
					pawn[index].canMovePos.push_back(temp);
				}
				else if (opponent.playerBoard[temp.y][temp.x] != ' ') {
					pawn[index].canMovePos.push_back(temp);
				}
			}

			temp.x = pawn[index].pos.x - 1;
			if (temp.x >= 0) {
				if (opponent.playerBoard[pawn[index].pos.y][temp.x] == 'P' && opponent.pawn[index - 1].enpassant) {
					pawn[index].canMovePos.push_back(temp);
				}
				else if (opponent.playerBoard[temp.y][temp.x] != ' ') {
					pawn[index].canMovePos.push_back(temp);
				}
			}
		}
	}

	vector<Position> returnCanMovePos(char chess, const Position& fromPos)
	{
		int index = findTheChess(chess, fromPos);
		vector<Position> answer;

		switch (chess) {
		case 'K':
			answer = king[index].canMovePos;
			break;
		case 'Q':
			answer = queen[index].canMovePos;
			break;
		case 'R':
			answer = rook[index].canMovePos;
			break;
		case 'N':
			answer = knight[index].canMovePos;
			break;
		case 'B':
			answer = bishop[index].canMovePos;
			break;
		case 'P':
			answer = pawn[index].canMovePos;
			break;
		}

		return answer;
	}

	//棋子被吃
	void beEat(Position chessPos)
	{
		this->haveEat = true;
		char theChess = playerBoard[chessPos.y][chessPos.x];
		//find the chess
		int i;
		switch (theChess)
		{
		case 'K':
			cout << "you lose" << endl;
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
		playerBoard[king[0].pos.y][king[0].pos.x] = king[0].icon;

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

	//redo
	void reset()//升階後???
	{
		//初始士兵
		pawn.clear();
		for (int i = 0; i < 8; i++) {
			Pawn temp(i, color);
			pawn.push_back(temp);
		}

		//初始城堡
		rook.clear();
		for (int i = 0; i < 2; i++) {
			Rook temp(i, color);
			rook.push_back(temp);
		}

		//初始騎士
		knight.clear();
		for (int i = 0; i < 2; i++) {
			Knight temp(i, color);
			knight.push_back(temp);
		}

		//初始主教
		bishop.clear();
		for (int i = 0; i < 2; i++) {
			Bishop temp(i, color);
			bishop.push_back(temp);
		}

		//初始皇后
		queen.clear();
		Queen tempQ(0, color);
		queen.push_back(tempQ);

		//初始國王
		king.clear();
		King tempK(0, color);
		king.push_back(tempK);

		PMove = false;
		haveEat = false;
	}
};

