//
//  Player.cpp
//

#include "Player.hpp"


Player& Player::operator=(const Player& p) {
	playerName = p.playerName;
	position = p.position;
	die = p.die;
	return *this;
}

int Player::rollDieAndMove() {

	die.roll();
	position = position + die.getFaceValue();
	if (position < 0)
		throw range_error("index out of bounds");
	else if (position >= BOARD_SIZE)
		position = position - die.getFaceValue();

	return position;
}
