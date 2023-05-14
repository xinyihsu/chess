#pragma once
#include <vector>
#include "Player.h"

enum EndStatus {
	CHECKMATE, //�N��
	TIME_UP, //�ɶ���
	DRAW, //�M��(�L�l�i�ʡA���S�Q�N�x)
	SURRENDER, //�{��
};

//�B�z�C�����A
class GameManager
{
private:
public:
	int turns; //�����
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
		/**�G�M*************************************************/
		bool ifCanNotMove = true;
		//king
		//if (thePlayer.king[0].canMovePos.size()==0)
		//�N��???
		
		//queen
		for (int i = 0; i < black.queen.size(); i++){
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
		/**75�B*************************************************/
		if (!black.PMove && !black.haveEat && countMove >=75) {
			return true;
		}
		/**���i��N��*******************************************/




		return false;
	}
};
