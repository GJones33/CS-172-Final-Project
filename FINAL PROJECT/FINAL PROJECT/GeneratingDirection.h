#ifndef GENERATING_DIRECTION_H_
#define GENERATING_DIRECTION_H_

#include <ctime>
#include <iostream>
using namespace std;

char GetDirection(bool reset); //generates a direction randomly, without spitting
							   //out the same direction uless reset == true

char GetDirection(bool reset)
{
	static bool up = false;
	static bool down = false;
	static bool left = false;
	static bool right = false;
	if (reset == true) {
		up = false;
		down = false;
		left = false;
		right = false;
	}
	srand(time(NULL));

	for (;;) {
		int x = rand() % 5;
		switch (x) {
		case 0:
			if (!down) {
				down = true;
				return 'd';
			}
			break;
		case 1:
			if (!up) {
				up = true;
				return 'u';
			}
			break;
		case 3:
			if (!left) {
				left = true;
				return 'l';
			}
			break;
		case 4:
			if (!right) {
				right = true;
				return 'r';
			}
			break;
		}
	}
}

#endif