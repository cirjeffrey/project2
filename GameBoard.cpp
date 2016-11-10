//
//  GameBoard.cpp
//

#include "GameBoard.hpp"

void GameBoard::buildBoard(){
		for (int i = 0; i < 100; i++)
			vector.insert(i, i + 1);		
}
