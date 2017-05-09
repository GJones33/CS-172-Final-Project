#include "Player.h"

void Player::movementAlgorithm(char direction)
{
	switch (algorithmChar) {
	default:
		switch (direction) {
		case 'u':
			(*y_position) += 1;
			break;
		case 'd':
			(*y_position) -= 1;
			break;
		case 'r':
			(*x_position) += 1;
			break;
		case 'l':
			(*x_position) -= 1;
			break;
		}
		break;
	}
}

Player::Player(int x, int y) : Entity(x,y) //use the origin of the players x and y position int the constructor
{
	Iam(player);
	pixels.push_back(Pixel(0, 0, '\\', *this));
	pixels.push_back(Pixel(1, 0, '_', *this));
	pixels.push_back(Pixel(2, 0, '/', *this));
	pixels.push_back(Pixel(0, 1, '<', *this));
	pixels.push_back(Pixel(2, 1, '>', *this));
	pixels.push_back(Pixel(0, 2, '/', *this));
	pixels.push_back(Pixel(1, 3, '_', *this));
	pixels.push_back(Pixel(2, 2, '\\', *this));
}

