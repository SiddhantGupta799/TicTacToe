#include "AI.hpp"
#include "WinnerChecker.hpp"

AI::AI() {
}

Move AI::execute ( string origBoard[3][3] ) {
	initBoard ( origBoard );
	return findBestMove();
}

void AI::initBoard ( string origboard[3][3] ) {
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			newBoard[i][j] = origboard[i][j];
		}
	}
}

Move AI::findBestMove() {
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			// Check if cell is empty
			if ( newBoard[i][j] == " - " ) {
				// Make the move
				newBoard[i][j] = " X ";

				// compute evaluation function for this
				// move.
				int moveVal = minimax ( newBoard, 0, false );

				// Undo the move
				newBoard[i][j] = " - ";

				// If the value of the current move is
				// more than the best value, then update
				// best/
				if ( moveVal > bestVal ) {
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	cout << "The value of the best Move is : " << bestVal << endl;

	return bestMove;
}

int AI::minimax ( string board[3][3], int depth, bool isMax ) {
	int score = checkWinning ( board );

	// If Maximizer has won the game return his/her
	// evaluated score
	if ( score > 0 )
		return score - depth;

	// If Minimizer has won the game return his/her
	// evaluated score
	if ( score < 0 )
		return score + depth;

	// If there are no more moves and no winner then
	// it is a tie
	if ( isMovesLeft ( board ) == false )
		return 0;

	// If this maximizer's move
	if ( isMax ) {
		int best = -1000;

		// Traverse all cells
		for ( int i = 0; i < 3; i++ ) {
			for ( int j = 0; j < 3; j++ ) {
				// Check if cell is empty
				if ( board[i][j] == " - " ) {
					// Make the move
					board[i][j] = " X ";

					// Call minimax recursively and choose
					// the maximum value
					best = max ( best,
					             minimax ( board, depth + 1, !isMax ) );

					// Undo the move
					board[i][j] = " - ";
				}
			}
		}

		return best;
	}

	// If this minimizer's move
	else {
		int best = 1000;

		// Traverse all cells
		for ( int i = 0; i < 3; i++ ) {
			for ( int j = 0; j < 3; j++ ) {
				// Check if cell is empty
				if ( board[i][j] == " - " ) {
					// Make the move
					board[i][j] = " O ";

					// Call minimax recursively and choose
					// the minimum value
					best = min ( best,
					             minimax ( board, depth + 1, !isMax ) );

					// Undo the move
					board[i][j] = " - ";
				}
			}
		}

		return best;
	}
}

int AI::checkWinning ( string board[3][3] ) {
	WinnerChecker won;

	if ( won.test ( board, " X " ) ) {
		return 10;
	} else if ( won.test ( board, " O " ) ) {
		return -10;
	} else {
		return 0;
	}
}

bool AI::isMovesLeft ( string board[3][3] ) {
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			if ( board[i][j] == " - " ) {
				return true;
			}
		}
	} return false;
}

AI::~AI() {
}
