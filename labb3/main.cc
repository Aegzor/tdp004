#include <iostream>
#include "console.h"
#include "ball.h"
#include "paddle.h"

using namespace std;



void print_board(Console& console)
{
  for (int i = 0; i < console.getWidth(); ++i)
  {
    console.put('\254');
  }
  for (int i = 0; i < console.getHeight()-1; ++i)
  {
    console.put('\254');
    for (int j = 0; j < console.getWidth()-2; ++j)
    {
      console.put(' ');
    }
    console.put('\254');
  }
  /*for (int i = 0; i < console.getWidth(); ++i)
  {
    console.put(' ');
    }*/
}

int main()
{
  Console console;
  char command;
  Ball ball;
  Paddle paddle(console.getWidth()/10, console.getHeight() - 5 );
  bool game_over = false;
  console.setBackgroundColor(COLOR_BLACK);
  console.setForegroundColor(COLOR_GREEN);
  console.get();
  print_board(console);
  paddle.print(console);

  while( !game_over )
  {
    if( console.get(command) )
    {
      //TODO: process input (paddle, quit)
      if (command == 'q')
      {
	return 0;
      }
      else if (command == 'a' || command == 's')
      {
	paddle.move(console, command);
      }
    }
    ball.move(console, paddle);
    game_over = ball.isGameOver(console.getHeight());
    
  }
  cin.get();

  return 0;
}
