#include "ball.h"

Ball::Ball()
{
  x_pos = 5;
  y_pos = 5;
  x_direction = 1;
  y_direction = 1;
  speed = 5;
}

Ball::~Ball(){}

void Ball::setPosX(int x)
{
  x_pos = x;
}

void Ball::setPosY(int y)
{
  y_pos = y;
}

int Ball::getPosX()
{
  return x_pos;
}

int Ball::getPosY()
{
  return y_pos;
}

void Ball::setDirectionX(int x)
{
  x_direction = x;
}

void Ball::setDirectionY(int y)
{
  y_direction = y;
}

int Ball::getDirectionX()
{
  return x_direction;
}

int Ball::getDirectionY()
{
  return y_direction;
}

void Ball::setSpeed(int speed)
{
  speed = speed;
}

int Ball::getSpeed()
{
  return speed;
}
