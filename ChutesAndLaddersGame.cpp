//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
	
		Player Cirjeffrey;
		Player Jerel;
		Cirjeffrey.setName("Cirjeffrey");
		Jerel.setName("Jerel");			
		queue.enqueue(Jerel);
		Jerel.setPosition(0);
		queue.enqueue(Cirjeffrey);
		Cirjeffrey.setPosition(0);
}

ChutesAndLaddersGame::~ChutesAndLaddersGame() {
	while (!queue.empty())
		queue.dequeue();
}

void ChutesAndLaddersGame::resetGame() {
	ChutesAndLaddersGame(MIN_NUMBER_OF_PLAYERS);
}

void ChutesAndLaddersGame::playGame() {
	
	while (winner == "no winner"){
		Player temp = queue.front();
			queue.dequeue();

		int value = temp.rollDieAndMove();
		int newValue = gameBoard.checkChutesLadders(value);
		temp.setPosition(newValue);

		if (newValue == WINNING_POSITION){
			winner = temp.getName();
			cout << "Winner is " << winner << endl;
			temp.setPosition(0);
		}
			queue.enqueue(temp);	
	} 
winner = "no winner";
resetGame();
}
