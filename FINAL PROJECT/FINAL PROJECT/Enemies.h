#ifndef ENEMIES_H_
#define ENEMIES_H_

#include "Entity.h"

using namespace std;

class Enemy : public Entity {
private:
public:
	Enemy(int x, int y);
};

class CompassEnemy : public Enemy {
private:
public:
	CompassEnemy(int x, int y);
	void move(char direction);
};

class Enemies {
private:
	int enemy_count = 0;
	vector<CompassEnemy> CompassEnemies;
public:
	Entity * getEnt(int index);
	int getsize() { return enemy_count; }
	void addCompass(CompassEnemy);
	void moveEnemy(int index, char direction);
	void revertEnemy(int index);
	void updateEnemy(int index);
};

#endif