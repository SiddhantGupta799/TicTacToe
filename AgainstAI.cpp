#include "AgainstAI.hpp"
#include "WinnerChecker.hpp"

int AIWinDetector = 0;
int level = 0;

AgainstAI::AgainstAI() {}

void AgainstAI::execute() {
	char ch = ' ' ;
	levelSelect();
	Play();

	while ( true ) {
		if ( AIWinDetector < 0 ) {
			cout << "Seems Like You have Won by Luck!! I challenge You Once again!!" << endl;
			cout << "Common Press Y and Fight!! Unless you want to Leave Like a Coward press N" << endl;
			cout << "> ";
			cin >> ch;
			ch = tolower ( ch );

			if ( ch == 'y' ) {
				Play();
			} else {
				break;
			}
		} else if ( AIWinDetector > 0 ) {
			cout << "You Lost XD!! Try Me Once Again!!" << endl;
			cout << "Giving Up? No Man! Press Y and Fight back!!" << endl;
			cout << "> ";
			cin >> ch;
			ch = tolower ( ch );

			if ( ch == 'y' ) {
				Play();
			} else {
				break;
			}
		} else {
			cout << " Draw. " << endl;
			cout << "Gave You Tough Competition Right! Hit Y to Play Again" << endl;
			cout << "> ";
			cin >> ch;
			ch = tolower ( ch );

			if ( ch == 'y' ) {
				Play();
			} else {
				break;
			}
		}
	}
}

void AgainstAI:: levelSelect() {
	cout << "Level Select: " << endl;
	cout << "1. Easy\n2. Hard" << endl;
	cout << "> ";
	cin >> level;

	if ( level == 1 ) {
		cout << "Easy Level Selected" << endl;
	} else if ( level == 2 ) {
		cout << "Hard Level Selected" << endl;
	} else {
		cout << "Default Level Selected" << endl;
	}
}

void AgainstAI::WashBoard() {
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3 ; j++ ) {
			BOARD[i][j] = " - ";
		}
	}
}

void AgainstAI:: Play() {
	WashBoard();
	WinnerChecker won;
	int flag = 0;

	for ( int i = 0; i < 9; i++ ) {
		if ( i % 2 == 0 ) {
			cout << "Your Turn: " << endl;
			Place ( symX );

			if ( won.test ( BOARD, symX ) ) {
				cout << "You Won!!" << endl;
				AIWinDetector = -12;
				flag = 1;
				break;
			}
		} else {
			cout << "Computer's Turn: " << endl;

			PlaceRandom ();

			if ( won.test ( BOARD, symO ) ) {
				cout << "Computer Won!!" << endl;
				AIWinDetector = 12;
				flag = 1;
				break;
			} else {
				cout << "Turn Completed" << endl;
			}
		}
	}

	if ( flag == 0 ) {
		AIWinDetector = 0;
	}

	ShowBoard();
}

void AgainstAI::PlaceRandom() {
	if ( level == 1 ) {
		AI ai;
		Move move = ai.execute ( BOARD );
		BOARD[move.row][move.col] = symO;
	} else {
	}
}

AgainstAI::~AgainstAI() {
}
