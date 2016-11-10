//
//  ChutesAndLaddersGame.hpp
//

#pragma once

#include <stdio.h>
#include <string>
#include "ArrayQueue.h"
#include "Player.hpp"
#include "GameBoard.hpp"
using namespace std;

const int MIN_NUMBER_OF_PLAYERS = 2;

class ChutesAndLaddersGame {
public:

	ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);
	~ChutesAndLaddersGame();
	int getNumberOfPlayers() {return MIN_NUMBER_OF_PLAYERS;}
	string getWinner() {return winner;}
	void resetGame();
	void playGame();
private:
	const int WINNING_POSITION = 100;
	string winner;							 
	GameBoard gameBoard;					 
	ArrayQueue<Player> queue;				 
};
