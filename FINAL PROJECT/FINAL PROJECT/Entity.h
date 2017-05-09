//Project: Make a working videogame
//File: Define the entity and pixel class that are used when displaying the things in the videogame to the screen
//Last Updated on: 04/16/2017
//by: Cameron Rutherford

#ifndef ENTITY_
#define ENTITY_

#include <vector>
#include <iostream>
#include <string>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

using namespace std;

const string enemy = "Enemy";
const string player = "Player";
const string environment = "Environment";

using namespace std;

class Entity;
class Pixel;

class Pixel {
private:
	int * x_pos;
	int * y_pos;
	int x_offset; //x offset of the pixel
	int y_offset; //y offset of the pixel
	char pixel; //character of the pixel to be printed
public:
	Pixel(int, int, char, Entity); //Default constructor for pixel that takes the x and y coord to be printed
	int get_x() { return *x_pos + x_offset; }; //Getters and setters for the private variables
	int get_y() { return *y_pos + y_offset; };
	char get_char() { return pixel; };
	void set_x_offset(int x) { x_offset = x; }
	void set_y_offset(int y) { y_offset = y; }
	void set_char(char c) { pixel = c; }
};

class Entity {
private:
	string WhatAmI;
public:
	string whatAmI() { return WhatAmI; }
	int * x_position; //this will be the x coord of the bottom left of the entity
	int * y_position; //this will be the y coord of the bottom left of the entity
	int width, height; //stores the width and the height of the entity
	int prev_x; //used to keep track of the previos position of the entity in case you cannot move in a certain direction
	int prev_y;
	Entity(int, int);
	vector<Pixel> pixels;
	int * get_x_position(); 
	int * get_y_position();
	Entity * getEnt() { return this; }
	void update() { prev_x = *x_position; prev_y = *y_position; } //either updates the previous position if the move was "allowed"
	void revert() { *x_position = prev_x; *y_position = prev_y; } //or reverts the move as it was deemed "illegal"
	bool operator==(Entity &other); //overloading the == operator to check for intersection	
protected:
	void Iam(string WhatAmI) { this->WhatAmI = WhatAmI; } //is used in all the things that are Entities to identify what they are
														  //I tried to use polymorphism here but it broke too many other things
};

#endif