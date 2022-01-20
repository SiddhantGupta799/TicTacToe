#ifndef GAMEINTERFACEPROVIDER_HPP
#define GAMEINTERFACEPROVIDER_HPP
#include <iostream>
using namespace std;

class GameInterfaceProvider {
	protected:
		string BOARD[3][3] = {{" - ", " - ", " - "}, {" - ", " - ", " - "}, {" - ", " - ", " - "}};
		const string symX = " X ";
		const string symO = " O ";
		void Play();
		void Place(string);
		void ShowBoard();
		bool isValid ( int );
		GameInterfaceProvider();
		~GameInterfaceProvider();

};

#endif // GAMEINTERFACEPROVIDER_HPP
