#include "GameInterfaceProvider.hpp"
#include "WinnerChecker.hpp"
#include <iostream>
using namespace std;

GameInterfaceProvider::GameInterfaceProvider() {
}

void GameInterfaceProvider::ShowBoard() {
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			cout << BOARD[i][j] << " ";
		} cout << endl;
	}
}

void GameInterfaceProvider:: Play() {
	WinnerChecker won;

	for ( int i = 0; i < 9; i++ ) {
		if ( i % 2 == 0 ) {
			cout << "Player 1's Turn, Your Symbol is:" << symX << endl;

			Place ( symX );

			if ( won.test ( BOARD, symX ) ) {
				cout << "Congrats Player1, You Won" << endl;
				break;
			}
		} else {
			cout << "Player 2's Turn, Your Symbol is:" << symO << endl;
			Place ( symO );

			if ( won.test ( BOARD, symO ) ) {
				cout << "Congrats Player2, You Won" << endl;
				break;
			}
		}
	}

	ShowBoard();
}

void GameInterfaceProvider::Place ( string sym ) {
	ShowBoard();
	int row, col;

	while ( true ) {
		cout << "Enter the Row no.: ";
		cin >> row;
		cout << "Enter the Coloumn no.: ";
		cin >> col;

		if ( isValid ( row ) and isValid ( col ) and BOARD[row - 1][col - 1] == " - " ) {
			BOARD[row - 1][col - 1] = sym;
			break;
		} else {
			cout << "Invalid Values!! Enter again." << endl;
		}
	}
}

bool GameInterfaceProvider::isValid ( int n ) {
	if ( n > 0 and n < 4 ) {
		return true;
	} return false;
}

GameInterfaceProvider::~GameInterfaceProvider() {
}
