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

	bool testIfDraw(Player& thePlayer, Player& opponent)
	{
		countMove++;
		if (thePlayer.PMove || thePlayer.haveEat || opponent.PMove || opponent.haveEat) {
			countMove = 0;
			thePlayer.PMove = false;
			thePlayer.haveEat = false;
			opponent.PMove = false;
			opponent.haveEat = false;
		}
		/**�G�M*************************************************/
		bool ifCanNotMove = true;
		//king
		//if (thePlayer.king[0].canMovePos.size()==0)
		//�N��???
		
		//queen
		for (int i = 0; i < thePlayer.queen.size(); i++){
			if (thePlayer.queen[i].canMovePos.size() != 0){
				ifCanNotMove = false;
			}
		}

		//rook
		for (int i = 0; i < thePlayer.rook.size(); i++){
			if (thePlayer.rook[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//knight
		for (int i = 0; i < thePlayer.knight.size(); i++)	{
			if (thePlayer.knight[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//bishop
		for (int i = 0; i < thePlayer.bishop.size(); i++){
			if (thePlayer.bishop[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}

		//pawn
		for (int i = 0; i < thePlayer.pawn.size(); i++){
			if (thePlayer.pawn[i].canMovePos.size() != 0) {
				ifCanNotMove = false;
			}
		}
	
		if (ifCanNotMove) {
			return true;
		}
		/**75�B*************************************************/
		if (!thePlayer.PMove && !thePlayer.haveEat && countMove >=75) {
			return true;
		}
		/**���i��N��*******************************************/




		return false;
	}
};
