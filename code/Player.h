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
		int index=0;
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
				if (color == 1) {
					for (int i = 0; i < 8; i++) {
						for (int j = 0; j < 8; j++) {
							//if ()
						}
					}
				}
				
				king[index].pos.setPosition(toPos);
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
				pawn[index].pos.setPosition(toPos);
				pawn[index].moveTimes++;
				this->PMove = true;
				return true;
			}
			break;
		}

		return false;
	}

	void updateCanMovePos(char chess, Position fromPos, const Player& opponent)
	{
		int index = findTheChess(chess, fromPos);
		Position temp;
		switch (chess) {
		case 'K':
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					temp.x = king[index].pos.x + i;
					temp.y = king[index].pos.y + j;
					if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
						king[index].canMovePos.push_back(temp);
					}
					else {
						break;
					}
				}
			}
			break;
		case 'Q':
			//to left up
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x - i;
				temp.y = queen[index].pos.y - i;
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

			//to right down
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x + i;
				temp.y = queen[index].pos.y + i;
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

			//to left down
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x - i;
				temp.y = queen[index].pos.y + i;
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

			//to right up
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x + i;
				temp.y = queen[index].pos.y - i;
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

			//go up
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x;
				temp.y = queen[index].pos.y - i;
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

			//go down
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x;
				temp.y = queen[index].pos.y + i;
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

			//go left
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x - i;
				temp.y = queen[index].pos.y;
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
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
				temp.x = queen[index].pos.x + i;
				temp.y = queen[index].pos.y;
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
					rook[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}

			break;
		case 'R':
			//go up
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x;
				temp.y = queen[index].pos.y - i;
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

			//go down
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x;
				temp.y = queen[index].pos.y + i;
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

			//go left
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x - i;
				temp.y = queen[index].pos.y;
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

			//go right
			for (int i = 1; i < 8; i++) {
				temp.x = queen[index].pos.x + i;
				temp.y = queen[index].pos.y;
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
		
			break;
		case 'N':
			for (int i = 0; i < 8; i++) {
				temp.x = knight[index].pos.x + knight[index].step[i].first;
				temp.y = knight[index].pos.y + knight[index].step[i].second;
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
					knight[index].canMovePos.push_back(temp);
				}
			}
			break;
		case 'B':
			//to left up
			for (int i = 1; i < 8; i++) {
				temp.x = bishop[index].pos.x - i;
				temp.y = bishop[index].pos.y - i;
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
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
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
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
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
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
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
					bishop[index].canMovePos.push_back(temp);
					if (opponent.playerBoard[temp.y][temp.x] != ' ') {
						break;
					}
				}
				else {
					break;
				}
			}
			
			break;
		case 'P':
			temp.x = pawn[index].pos.x;
			if (color == 1) {
				if (pawn[index].moveTimes == 1) {
					temp.y = pawn[index].pos.y + 2;
					if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
						pawn[index].canMovePos.push_back(temp);
					}
				}
				temp.y = pawn[index].pos.y + 1;
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
					pawn[index].canMovePos.push_back(temp);
				}
			}
			else {
				if (pawn[index].moveTimes == 1) {
					temp.y = pawn[index].pos.y - 2;
					if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
						pawn[index].canMovePos.push_back(temp);
					}
				}
				temp.y = pawn[index].pos.y - 1;
				if (playerBoard[temp.y][temp.x] == ' ' && temp.x <= 7 && temp.x >= 0 && temp.y <= 7 && temp.y >= 0) {
					pawn[index].canMovePos.push_back(temp);
				}
			}
			break;
		}
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
};

