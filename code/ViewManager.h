#pragma once
#define RESET   "\033[0m"
#define BLACK_C     "\033[30m"
#define BLUE_B    "\033[46m"
#define YELLOW_B  "\033[43m"
#define RED_B     "\033[41m"

//#define GREEN   "\033[32m"
//#define DARKBLUE    "\033[34m"
//#define PURPLE "\033[35m"
//#define WHITE   "\033[37m"

class ViewManager
{
private:
public:
	Player* black, * white;

	void printBoard()
	{
		system("cls");
		for (int i = 0; i < 8; i++) {
			cout << 8 - i;
			for (int j = 0; j < 8; j++) {
				if ((i % 2 == 0 && j % 2 == 0) || ((i % 2 == 1 && j % 2 == 1))) {
					cout << YELLOW_B; //¶À©³
				}
				else {
					cout << BLUE_B; //ÂÅ©³
				}

				if (white->playerBoard[i][j] != ' ') {
					cout << white->playerBoard[i][j];
				}
				else if (black->playerBoard[i][j] != ' ') {
					cout << BLACK_C << black->playerBoard[i][j]; //¶Â¦r
				}
				else {
					cout << " ";
				}
				cout << RESET; //­«»s
			}
			cout << endl;
		}

		cout << " abcdefgh" << endl;
		
	}

	void printCanMove(vector<Position> print)
	{
		system("cls");
		for (int i = 0; i < 8; i++) {
			cout << 8 - i;
			for (int j = 0; j < 8; j++) {

				if ((i % 2 == 0 && j % 2 == 0) || ((i % 2 == 1 && j % 2 == 1))) {
					cout << YELLOW_B; //¶À©³
				}
				else {
					cout << BLUE_B; //ÂÅ©³
				}

				for (int k = 0; k < print.size(); k++) {
					Position locate(j, i);
					if (locate == print[k]) {
						cout << RESET;
						cout << RED_B;
						print.erase(print.begin() + k);
						break;
					}
				}

				if (white->playerBoard[i][j] != ' ') {
					cout << white->playerBoard[i][j];
				}
				else if (black->playerBoard[i][j] != ' ') {
					cout << BLACK_C << black->playerBoard[i][j]; //¶Â¦r
				}
				else {
					cout << " ";
				}
				cout << RESET; //­«»s
			}
			cout << endl;
		}

		cout << " abcdefgh" << endl;
	}
};
