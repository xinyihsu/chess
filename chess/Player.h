#pragma once
#include "King.h"
#include "Queen.h"
#include "Rook.h" //����
#include "Bishop.h" //�D��
#include "Knight.h" //�M�h
#include "Pawn.h" //�L
#include <vector>

//�޲z�Ѥl
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
		vector<Pawn*> pawn(8); //�s������?
	}
};