#include "Actor.h"

Actor::Actor(int init_x_pos, int init_y_pos, int init_width, int init_height){
  x_pos = init_x_pos;
  y_pos = init_y_pos;
  width = init_width;
  height = init_height;
  componentArrayLength = 0;
}

void Actor::set_position(int new_x_pos, int new_y_pos){
  x_pos = new_x_pos;
  y_pos = new_y_pos;
}

int Actor::get_x_pos(){
  return x_pos;
}

int Actor::get_y_pos(){
  return y_pos;
}

int Actor::get_width(){
  return width;
}

int Actor::get_height(){
  return height;
}

void Actor::add_component(Component *new_component){
  componentArray[componentArrayLength] = new_component;
  componentArrayLength++;
}

void Actor::update(){
  for(int i = 0; i < componentArrayLength; i++){
    componentArray[i]->update();
  }
}
