#include "GameManager.h"
#include "Player.h"
#include "ViewManager.h"
#include "Position.h"
#include <iostream>

using namespace std;

Player black, white; //�դ�, �¤�
char** gBoard;


int main()
{
	while (1) {
		string from, to;
		cin >> from >> to;

		Position fromPos, toPos;
		fromPos.x = from[0] - 'a';
		fromPos.y = from[1] - '0';
		toPos.x = to[0] - 'a';
		toPos.y = to[0] - '0';

		//�����O���@�ӴѤl

	}
}