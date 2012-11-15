#ifndef BALL_H
#define BALL_H

#include "console.h"
#include "paddle.h"

class Ball
{
public:
  Ball();
  ~Ball();

  /* set/get position of ball */
  void setPosX(int x);
  void setPosY(int y);
  int getPosX();
  int getPosY();

  /* set/get direction of ball */
  void setDirectionX(int x);
  void setDirectionY(int y); // -1 = left/up; 1 = right/down
  int getDirectionX();
  int getDirectionY();

  /* set/get speed of the ball (speed is given in x/10 seconds) */
  void setSpeed(int speed);
  int getSpeed();

  /* other game mechanics */
  void collisionDetector(int width, int height, Paddle& paddle);
  bool isGameOver(int height);

  /* moves the ball */
  void move(Console& console, Paddle& paddle);

private:
  
  int x_pos, y_pos;
  int x_direction, y_direction;
  int speed;

};

#endif //BALL_H
