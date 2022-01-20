// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TwoPlayers.hpp"
#include "AgainstAI.hpp"
using namespace std;


int main() {
	cout << "====== Welcome to Tic Tac Toe ======" << endl;
	cout << "Game Modes: \n1. Two Player\n2. Against Computer" << endl;
	int ch;
	cout << "> ";
	cin >> ch;

	if (ch == 1) {
		TwoPlayers twoPlayer;
		twoPlayer.execute();
	}
	else if (ch == 2) {
		AgainstAI againstAI;
		againstAI.execute();
	}
	else {
		cout << "Invalid Choice,Exiting!!" << endl;
	}

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
