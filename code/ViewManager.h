#pragma once

class ViewManager
{
private:
public:
	Player* black, * white;
	/*char** gBoard;
	ViewManager() {
		gBoard = new char* [8];
		for (int i = 0; i < 8; i++) {
			gBoard[i] = new char[8];
		}
	}*/

	void printBoard()
	{
		system("cls");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((i % 2 == 0 && j % 2 == 0) || ((i % 2 == 1 && j % 2 == 1))) {
					cout << "\033[43m"; //¶À©³
				}
				else {
					cout << "\033[46m"; //ÂÅ©³
				}

				if (white->playerBoard[i][j] != ' ') {
					cout << white->playerBoard[i][j];
				}
				else if (black->playerBoard[i][j] != ' ') {
					cout << "\033[30m"  << black->playerBoard[i][j]; //¶Â¦r
				}
				else {
					cout << " ";
				}
				cout << "\033[0m"; //­«»s
			}
			cout << endl;
		}
	}

	void printCanMove(char chess)
	{

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (black->playerBoard[i][j] != ' ') {
					cout << black->playerBoard[i][j];
				}
				else if (white->playerBoard[i][j] != ' ') {
					cout << "\033[30m" << "\033[47m" << black->playerBoard[i][j] << "\033[0m";
				}
				else {
					cout << " ";
				}
				cout << " ";
			}
			cout << endl;
		}
	}
};
