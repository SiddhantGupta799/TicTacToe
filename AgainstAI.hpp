#ifndef AGAINSTAI_HPP
#define AGAINSTAI_HPP
#include "GameInterfaceProvider.hpp"
#include "AI.hpp"
#include <iostream>
using namespace std;

class AgainstAI : public GameInterfaceProvider
{
	void Play();
	void PlaceRandom();
	void WashBoard();
	void levelSelect();
public:
	AgainstAI();
	void execute();
	~AgainstAI();

};

#endif // AGAINSTAI_HPP
