#include <iostream>
#include "console.h"
#include "ball.h"

using namespace std;

void print_board(Console console)
{
  for (int i = 0; i < console.getWidth(); ++i)
  {
    console.put('#');
  }
  for (int i = 0; i < console.getHeight()-2; ++i)
  {
    console.put('#');
    for (int j = 0; j < console.getWidth()-2; ++j)
    {
      console.put(' ');
    }
    console.put('#');
  }
  for (int i = 0; i < console.getWidth(); ++i)
  {
    console.put('#');
  }
}

int main()
{
  Console console;
  char command;
  Ball ball;
  bool game_over = false;
  console.setBackgroundColor(COLOR_MAGENTA);
  console.setForegroundColor(COLOR_BLACK);
  console.get();
  print_board(console);
  console.setPos(ball.getPosX(),ball.getPosY());
  console.put('o');
  while( != game_over )
  {
    if( console.get(command);
    {
      //TODO: process input (paddle, quit)
    }
    else
    {
      //TODO: move ball here
    }
  }

  return 0;
}
