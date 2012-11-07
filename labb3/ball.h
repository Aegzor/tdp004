#ifndef BALL_H
#define BALL_H

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

private:
  
  int x_pos, y_pos;
  int x_direction, y_direction;
  int speed;

};

#endif //BALL_H
