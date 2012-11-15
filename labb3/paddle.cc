#include "paddle.h"

using namespace std;

Paddle::Paddle(int paddle_length, int y)
{
  length = paddle_length;
  y_pos = y;
  paddle_string=""; 
  for (int i = 0; i < length; ++i)
  {
    paddle_string += '\254';
    /*
    if(i == 0 || i == length - 1)
    {
      paddle_string += "Ö";
    }
    else
    {
      paddle_string += "ö";
    }*/
  }
}

Paddle::~Paddle(){}

int Paddle::getLength()
{
  return length;
}

void Paddle::setPosX(int x)
{
  x_pos = x;
}

int Paddle::getPosX()
{
  return x_pos;
}

int Paddle::getPosY()
{
  return y_pos;
}

void Paddle::print(Console& console)
{
  console.setPos(x_pos, y_pos);
  console.put(paddle_string);
}

void Paddle::move(Console& console, char direction)
{

  if( direction == 'a' && canMoveLeft())
  {
    console.setPos(x_pos+length-1, y_pos);
    console.put(' ');
    x_pos -= 1;
    print(console);
  }
  else if( direction == 's' && canMoveRight(console.getWidth()))
  {
    console.setPos(x_pos, y_pos);
    console.put(' ');
    x_pos += 1;
    print(console);
  }
}

bool Paddle::canMoveLeft()
{
  if ( x_pos == 1 )
  {
    return false;
  }
  return true;
}

bool Paddle::canMoveRight(int width)
{
  if( x_pos + length - 1 == width - 2 )
  {
    return false;
  }
  return true;
}
