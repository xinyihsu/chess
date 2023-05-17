#pragma once
#include <vector>
#include "Player.h"

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
	int turns; //輪到誰
	int checkKing;
	int countMove = 0;

	bool testIfDraw(Player& black, Player& white)
	{
		countMove++;
		if (black.PMove || black.haveEat || white.PMove || white.haveEat) {
			countMove = 0;
			black.PMove = false;
			black.haveEat = false;
			white.PMove = false;
			white.haveEat = false;
		}
		/**逼和*************************************************/
		bool ifCanNotMove = true;
		//king
		//if (thePlayer.king[0].canMovePos.size()==0)
		//將死???
		
		//queen
		for (int i = 0; i < black.queen.size(); i++){//white?????
			if (black.queen[i].canMovePos.size() != 0){
				ifCanNotMove = false;
			}
		}

		//rook
		for (int i = 0; i < black.rook.size(); i++){
			if (black.rook[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//knight
		for (int i = 0; i < black.knight.size(); i++)	{
			if (black.knight[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//bishop
		for (int i = 0; i < black.bishop.size(); i++){
			if (black.bishop[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//pawn
		for (int i = 0; i < black.pawn.size(); i++){
			if (black.pawn[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}
	
		if (ifCanNotMove) {
			return true;
		}
		/**50步*************************************************/
		if (!black.PMove && !black.haveEat && countMove >=50) {
			return true;
		}
		/**不可能將死*******************************************/
		bool ifCanCheckMate = false;
		if (black.pawn.size() == 0 && black.queen.size() == 0 && black.rook.size() == 0 && white.pawn.size() == 0 && white.queen.size() == 0 && white.rook.size() == 0) {
			//king&bishop vs king&bishop (bishops are in the same color)
			if (black.knight.size() == 0 && white.knight.size() == 0 && black.bishop.size() == 1 && white.bishop.size() == 1) {
				Position blackB = black.bishop[0].pos;
				Position whiteB = white.bishop[0].pos;
				bool blackBColor = (blackB.x % 2 == 0 && blackB.y % 2 == 0) || ((blackB.x % 2 == 1 && blackB.y % 2 == 1));
				bool whteBColor = (whiteB.x % 2 == 0 && whiteB.y % 2 == 0) || ((whiteB.x % 2 == 1 && whiteB.y % 2 == 1));
				if (blackBColor == whteBColor) return true;
			}
			//king vs king and knight
			if (black.bishop.size() == 0 && white.bishop.size() == 0) {
				if ((black.knight.size() == 1 && white.knight.size() == 0) || (white.knight.size() == 1 && black.knight.size() == 0)) {
					return true;
				}
			}
			//king vs king
			if (black.knight.size() == 0 && white.knight.size() == 0 && black.bishop.size() == 0 && white.bishop.size() == 0) {
				return true;
			}
		}

		return false;
	}
};
