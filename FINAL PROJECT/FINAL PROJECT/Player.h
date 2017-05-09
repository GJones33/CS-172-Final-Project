#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

class Player: public Entity {
private:
	char algorithmChar = ' '; //this character determines which direction the player will move when an input is given
	void movementAlgorithm(char direction);
	//Any gameplay elements like health, weapon, status, items etc...
public:
	Player(int x, int y); //use the correct x and y starting coords here
	void up() { movementAlgorithm('u'); }
	void down() { movementAlgorithm('d'); }
	void right() { movementAlgorithm('r'); }
	void left() { movementAlgorithm('l'); }
};

#endif