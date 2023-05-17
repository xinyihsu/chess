#pragma once
#include <vector>
#include "Player.h"
using namespace std;

enum EndStatus {
	CHECKMATE, //將死
	TIME_UP, //時間到
	DRAW, //和局(無子可動，但沒被將軍)
	SURRENDER, //認輸
};

//處理遊戲狀態
class GameManager
{
private:
public:
	int turns = -1; //輪到誰
	int checkKing;
	int countMove = 0;

	void menu() {
		int input = 0;
		cout << "Choose the game style: (1) normal (white first), (2) black first\n";
		while (input != 1 || input != 2) {
			cin >> input;
			if (input == 1) {
				turns = -1;
				break;
			}
			else if (input == 2) {
				turns = 1;
				break;
			}
			else {
				cout << "invalid input\n";
			}
		}

		system("cls");
		return;
	}

	bool testIfDraw(Player& my, Player& opponent)
	{
		countMove++;
		if (my.PMove || my.haveEat || opponent.PMove || opponent.haveEat) {
			countMove = 0;
			my.PMove = false;
			my.haveEat = false;
			opponent.PMove = false;
			opponent.haveEat = false;
		}
		/**逼和*************************************************/
		bool ifCanNotMove = true;
		//king
		//if (thePlayer.king[0].canMovePos.size()==0)
		//將死???
		
		//queen
		for (int i = 0; i < my.queen.size(); i++){//white?????
			if (my.queen[i].canMovePos.size() != 0){
				ifCanNotMove = false;
			}
		}

		//rook
		for (int i = 0; i < my.rook.size(); i++){
			if (my.rook[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//knight
		for (int i = 0; i < my.knight.size(); i++)	{
			if (my.knight[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//bishop
		for (int i = 0; i < my.bishop.size(); i++){
			if (my.bishop[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//pawn
		for (int i = 0; i < my.pawn.size(); i++){
			if (my.pawn[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}
	
		if (ifCanNotMove) {
			return true;
		}
		/**50步*************************************************/
		if (!my.PMove && !my.haveEat && countMove >=50) {
			return true;
		}
		/**不可能將死*******************************************/
		bool ifCanCheckMate = false;
		if (my.pawn.size() == 0 && my.queen.size() == 0 && my.rook.size() == 0 && opponent.pawn.size() == 0 && opponent.queen.size() == 0 && opponent.rook.size() == 0) {
			//king&bishop vs king&bishop (bishops are in the same color)
			if (my.knight.size() == 0 && opponent.knight.size() == 0 && my.bishop.size() == 1 && opponent.bishop.size() == 1) {
				Position myB = my.bishop[0].pos;
				Position opponentB = opponent.bishop[0].pos;
				bool blackBColor = (myB.x % 2 == 0 && myB.y % 2 == 0) || ((myB.x % 2 == 1 && myB.y % 2 == 1));
				bool whteBColor = (opponentB.x % 2 == 0 && opponentB.y % 2 == 0) || ((opponentB.x % 2 == 1 && opponentB.y % 2 == 1));
				if (blackBColor == whteBColor) return true;
			}
			//king vs king and knight
			if (my.bishop.size() == 0 && opponent.bishop.size() == 0) {
				if ((my.knight.size() == 1 && opponent.knight.size() == 0) || (opponent.knight.size() == 1 && my.knight.size() == 0)) {
					return true;
				}
			}
			//king vs king
			if (my.knight.size() == 0 && opponent.knight.size() == 0 && my.bishop.size() == 0 && opponent.bishop.size() == 0) {
				return true;
			}
		}

		return false;
	}
};
