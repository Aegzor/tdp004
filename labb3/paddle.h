#ifndef PADDLE_H
#define PADDLE_H

#include <string>
#include "console.h"

class Paddle
{
 public:
  Paddle(int paddle_length, int y);
  ~Paddle();

  int getLength();

  void setPosX(int x);
  int getPosX();

  int getPosY();

  void print(Console& console);
  
  /* moves the paddle */
  void move(Console& console, char direction);
  bool canMoveLeft();
  bool canMoveRight(int width);

 private:
  
  int length;
  int x_pos, y_pos;
  std::string paddle_string;
  
};

#endif //BALL_H
