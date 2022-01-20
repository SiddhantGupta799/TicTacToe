#ifndef AI_HPP
#define AI_HPP
#include <iostream>
using namespace std;

struct Move {
	int row, col;
};

class AI {
		string newBoard[3][3];
		void initBoard ( string newBoard[3][3] );
		int checkWinning(string newBoard[3][3]);
		bool isMovesLeft ( string newBoard[3][3] );
		Move findBestMove();
		int minimax ( string newBoard[3][3] ,int ,bool);

	public:
		AI();
		Move execute ( string newBoard[3][3] );
		~AI();
};

#endif // AI_HPP
