#include "Entity.h"

Pixel::Pixel(int x, int y, char pixel, Entity thing)
{
	this->pixel = pixel;
	x_offset = x;
	y_offset = y;
	x_pos = thing.get_x_position();
	y_pos = thing.get_y_position();
}

Entity::Entity(int x, int y)
{
	x_position = new int(x);
	y_position = new int(y);
	prev_x = *x_position; 
	prev_y = *y_position;
}


int * Entity::get_x_position()
{
	return x_position;
}

int * Entity::get_y_position()
{
	return y_position;
}

bool Entity::operator==(Entity & other)
{
	for (unsigned i = 0; i < pixels.size(); i++) { //Look through all the pixels of this
		for (unsigned j = 0; j < other.pixels.size(); j++) { //Look through all the pixels of other
			if (pixels.at(i).get_x() == other.pixels.at(j).get_x() &&
				pixels.at(i).get_y() == other.pixels.at(j).get_y()) {
				return true;
			}
		}

	}
	return false;
}
