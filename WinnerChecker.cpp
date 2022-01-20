#include "WinnerChecker.hpp"
#include <iostream>
using namespace std;

WinnerChecker::WinnerChecker() {
}

bool WinnerChecker::test(string nBoard[3][3],string sym){
	initBoard(nBoard);
	return checkCols(sym)  or checkRows(sym) or checkDiagonals(sym);
}

void WinnerChecker::initBoard(string newBoard[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			board[i][j] = newBoard[i][j];
		}
	}
}

bool WinnerChecker:: checkCols(string s){
	int count = 0;

	for ( int i = 0; i < 3; i++ ) {
		count = 0;

		for ( int j = 0; j < 3; j++ ) {
			if ( board[j][i] == s ) {
				++count;

				if ( count == 3 ) {
					return true;
				}
			}
		}
	}

	return false;
}

bool WinnerChecker:: checkRows(string s){
	int count = 0;

	for ( int i = 0; i < 3; i++ ) {
		count = 0;

		for ( int j = 0; j < 3; j++ ) {
			if ( board[i][j] == s ) {
				++count;

				if ( count == 3 ) {
					return true;
				}
			}
		}
	}

	return false;
}

bool WinnerChecker::checkDiagonals ( string s ) {
	if (board[0][2] == s and board[1][1] == s and board[2][0] == s ) {
		return true;
	} else if ( board[0][0] == s and board[1][1] == s and board[2][2] == s ) {
		return true;
	}

	return false;
}

WinnerChecker::~WinnerChecker() {
}
