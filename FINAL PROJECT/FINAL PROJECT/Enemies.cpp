#include "Enemies.h"

Enemy::Enemy(int x, int y) : Entity(x, y)
{
	Iam(enemy);
}

CompassEnemy::CompassEnemy(int x, int y) : Enemy(x,y)
{
	pixels.push_back(Pixel(-1, 0, '<', *this));
	pixels.push_back(Pixel(1, 0, '>', *this));
	pixels.push_back(Pixel(0, 1, '^', *this));
	pixels.push_back(Pixel(0, -1, 'v', *this));

}

void CompassEnemy::move(char direction)
{
	switch (direction) {
	case 'u':
		(*y_position)++;
		break;
	case 'd':
		(*y_position)--;
		break;
	case 'r':
		(*x_position)++;
		break;
	case 'l':
		(*x_position)--;
		break;
	
	}
}

Entity * Enemies::getEnt(int index)
{
	if (index < CompassEnemies.size()) {
		return CompassEnemies[index].getEnt();
	}
	else {

	}
}

void Enemies::addCompass(CompassEnemy thing)
{
	enemy_count++;
	CompassEnemies.push_back(thing);
}

void Enemies::moveEnemy(int index, char direction)
{
	if (index < CompassEnemies.size()) {
		CompassEnemies[index].move(direction);
	}
	else {

	}
}

void Enemies::revertEnemy(int index)
{
	if (index < CompassEnemies.size()) {
		CompassEnemies[index].revert();
	}
	else {

	}
}

void Enemies::updateEnemy(int index)
{
	if (index < CompassEnemies.size()) {
		CompassEnemies[index].update();
	}
	else {

	}
}
