#pragma once

class ViewManager
{
private:

public:
	char** gBoard;
	ViewManager() {
		gBoard = new char* [8];
		for (int i = 0; i < 8; i++) {
			gBoard[i] = new char[8];
		}
	}

	void printBoard(int color) {
		/*for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << "\033[30m" << "\033[47m" << black.playerBoard[i][j] << " ";
			}
			cout << "\033[0m" << endl;
		}*/
	}
};
