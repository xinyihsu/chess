#pragma once
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
	Player() {
		King king;
		Queen queen;
		vector<Rook*> rook(2);
		vector<Bishop*> bishop(2);
		vector<Knight*> knight(2);
		vector<Pawn*> pawn(8); //存成指標?
	}
};