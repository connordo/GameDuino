#pragma once
#include "Entity.h"

class PhysicalEntity : public Entity{
protected:
  int mass;
  int x_acceleration;
  int y_acceleration;
  int x_velocity;
  int x_velocity_next;
  int y_velocity;
  int y_velocity_next;
  int x_pos_new;
  int y_pos_new;
  int x_force_total;
  int y_force_total;
  int x_cog; //X center of gravity
  int y_cog; //Y center of gravity
  double time;

public:
  PhysicalEntity();
  void applyPhysics();
}
