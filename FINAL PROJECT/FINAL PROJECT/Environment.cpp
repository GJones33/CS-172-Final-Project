#include "Environment.h"

Environment::Environment(int level) : Entity(0,0)
{
	Iam(environment);
	switch (level) {
	default:
		for (int i = 0; i < SCREEN_WIDTH; i++) {
			pixels.push_back(Pixel(i, 0, '*', *this));
			pixels.push_back(Pixel(i, SCREEN_HEIGHT - 1, '*', *this));
		}
		for (int i = 1; i < 19; i++) {
			pixels.push_back(Pixel(0, i, '*', *this));
			pixels.push_back(Pixel(SCREEN_WIDTH - 1, i, '*', *this));
		}
		break;
	case 0:
		for (int i = 0; i < SCREEN_WIDTH; i++) {
			pixels.push_back(Pixel(i, 0, '*', *this));
			pixels.push_back(Pixel(i, SCREEN_HEIGHT - 1, '*', *this));
		}
		for (int i = 1; i < 19; i++) {
			pixels.push_back(Pixel(0, i, '*', *this));
			pixels.push_back(Pixel(SCREEN_WIDTH - 1, i, '*', *this));
		}
		break;
	}
}