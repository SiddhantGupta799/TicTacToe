#ifndef TWOPLAYERS_HPP
#define TWOPLAYERS_HPP
#include <iostream>
#include "GameInterfaceProvider.hpp"
using namespace std;

class TwoPlayers : public GameInterfaceProvider {
	public:
		TwoPlayers();
		void execute();
		~TwoPlayers();

};

#endif // TWOPLAYERS_HPP
