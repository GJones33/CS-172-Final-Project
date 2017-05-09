//Project: Make a working videogame
//File: Define the Display class that keeps track of all the things that are to be displayed on the screen, as well as having the functionality of displaying everything
//Last Updated on: 04/16/2017
//             by: Cameron Rutherford

////////////////////////////////
//            NOTE            //
////////////////////////////////
//The screen is displayed in a conventional coordinate system with (0,0) being the bottom left corner
//		0		1		2		3		4		5		6		7		....
//
//...
//
//6
//
//5
//
//4
//
//3
//
//2
//
//1
//
//0

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Entity.h"

using namespace std;

class Display {
private:
	vector<vector<char>> pixels;  //used to keep track of the pixels on the screen/when printing the screen itself
	void _delete(); //Removes all the pixels in the screen
	void space_screen(); //Fills the screen with the default character
	char default_char = ' ';
	void populate_screen(); //Runs through all the entities stored in the Display and stores the assosciated pixels in the pixel array
public:
	Display(); //uses the space screen as the default constructor
	void print(); //prints the screen
	vector<Entity *> Entities; //stores all of the entities to be printed to the screen
	bool PlayerEnvironmentCollision();
	bool EnemyEnvironmentCollision();
	void PlayerKillEnemies();
};

#endif