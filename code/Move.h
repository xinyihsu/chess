#include <iostream>
#include <vector>
using namespace std;

class ChessMove
{
public:
	vector<Position> canMovePos;

	bool move(Position to)
	{
		for (int i = 0; i < canMovePos.size(); i++) {
			if (to == canMovePos[i]) {
				return true;
			}
		}

		cout << "failed to move\n";
		return false;
	}
};
