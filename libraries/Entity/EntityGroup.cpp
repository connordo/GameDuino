#include "EntityGroup.h"

int EntityGroup::get_x_pos()
{
	return x_pos;
}

int EntityGroup::get_y_pos()
{
	return y_pos;
}

int EntityGroup::get_width()
{
	return width;
}

int EntityGroup::get_height()
{
	return width;
}

int EntityGroup::get_arr_length()
{
	return array_length;
}

Entity ** EntityGroup::getEntities()
{
	return entities;
}

EntityGroup::EntityGroup()
{

}



EntityGroup::~EntityGroup()
{
	
}
