//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// TODO: implement the constructor with all your team members
// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
	
		Player Cirjeffrey;
		Player Jerel;
		Cirjeffrey.setName("Cirjeffrey");
		Jerel.setName("Jerel");


		queue.enqueue(Cirjeffrey);
		queue.enqueue(Jerel);

}

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
	
	while (!queue.empty())
		queue.dequeue();

}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {

	queue.enqueue(Cirjeffrey);
	Cirjeffrey.setPosition(0);
	queue.enqueue(Jerel);
	Jerel.setPosition(0);
}

// TO DO: implement this function properly
// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {

	bool winnerfound = false;
	Player *p = new Player("temp");
	*p = queue.front();


	while (winnerfound == false){
		int value = p->rollDieAndMove();
		int newValue = gameBoard.checkChutesLadders(value);
		queue.dequeue();

		if (newValue == WINNING_POSITION){
			winner = p->getName();
			cout << "Winner is " << winner << endl;
			winnerfound = true;
		}
		else{	
			queue.enqueue(p->getName());
			
		//	cout <<"newValue= " <<  newValue << endl;
		//	winner = p->getName();
		}
	} 
// TODO: implement this function properly	
// function not changing players;
}
