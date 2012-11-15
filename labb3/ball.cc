#include "ball.h"
//#include "console.h"

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

void Ball::collisionDetector(int width, int height, Paddle& paddle)
{
  if ( (x_pos == 1) || (x_pos == width - 2) )
  {
    x_direction = -x_direction;
  }
  if ( (y_pos == 1) || y_pos == height - 1)
  {
    y_direction = -y_direction;
  }
  if (y_pos == paddle.getPosY() - 1 && x_pos >= paddle.getPosX() &&
      x_pos <= paddle.getPosX() + paddle.getLength())
  {
    y_direction = -y_direction;
  }
}

bool Ball::isGameOver(int height)
{
  if ( y_pos == height -1 )
  {
    return true;
  }
  return false;
}

void Ball::move(Console& console, Paddle& paddle)
{
  console.setPos(x_pos, y_pos);
  console.put(' ');
  collisionDetector(console.getWidth(),console.getHeight(), paddle);
  x_pos += x_direction;
  y_pos += y_direction;
  console.setPos(x_pos, y_pos);
  console.put('\254');
}
