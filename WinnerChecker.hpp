#ifndef WINNERCHECKER_HPP
#define WINNERCHECKER_HPP
#include <iostream>
using namespace std;

class WinnerChecker
{
	string board[3][3];
	void initBoard(string board[3][3]);
	bool checkCols(string);
	bool checkRows(string);
	bool checkDiagonals(string);
	
public:
	WinnerChecker();
	bool test(string targetBoard[3][3],string );
	~WinnerChecker();

};

#endif // WINNERCHECKER_HPP
