#include <vector>
#include <iostream>

#include "Display.h"
#include "Player.h"
#include "GettingInput.h"
#include "Environment.h"
#include "Enemies.h"
#include "GeneratingDirection.h"

using namespace std;

int main() {
	system("CLS");
	Display Screen;
	Environment level(0);
	Player p1(1,1);
	Enemies Enemies;
	Enemies.addCompass(CompassEnemy(40,10));
	for (int i = 0; i < Enemies.getsize(); i++) {
		Screen.Entities.push_back(Enemies.getEnt(i));
	}
	Screen.Entities.push_back(p1.getEnt());
	Screen.Entities.push_back(level.getEnt());
	Screen.print();
	int c = 0;
	ShowConsoleCursor(false);
	while (1)
	{
		c = 0;
		bool successful = false;
		while (!successful) {
			switch ((c = getch())) {
			case KEY_UP:
				p1.up(); //key up
				successful = true;
				break;
			case KEY_DOWN:
				p1.down(); // key down
				successful = true;
				break;
			case KEY_LEFT:
				p1.left(); // key left
				successful = true;
				break;
			case KEY_RIGHT:
				p1.right(); // key right
				successful = true;
				break;
			default:
				break;
			}
		}
		system("CLS");
		if (Screen.PlayerEnvironmentCollision()) {
			cout << "Player environment collision detected." << endl;
			p1.revert();
		}
		else {
			p1.update();
		}
		Screen.PlayerKillEnemies();

		int enemy_index = 0;
		while (enemy_index < Enemies.getsize()) {
			int count = 1;
			Enemies.moveEnemy(enemy_index, GetDirection(true));
			while (Screen.EnemyEnvironmentCollision() && count < 4) {
				cout << "Enemy environment collision detected" << endl;
				Enemies.revertEnemy(enemy_index);
				Enemies.moveEnemy(enemy_index, GetDirection(false));
				count++;
			}
			Enemies.updateEnemy(enemy_index);
			enemy_index++;
		}
		Screen.print();
	}

	return 0;
}