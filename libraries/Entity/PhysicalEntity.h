#pragma once
#include "Entity.h"

class PhysicalEntity : public Entity{
protected:
  int x_acceleration;
  int y_acceleration;
  int x_force;
  int y_force;
  int x_cog; //X center of gravity
  int y_cog; //Y center of gravity

}
