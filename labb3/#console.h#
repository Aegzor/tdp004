#ifndef CONSOLE_H
#define CONSOLE_H

#include <exception>
#include <string>
#include <ncursesw/ncurses.h>

using namespace std;

/**
 * This is the color constants you can use where a color is expected:
 *
 * COLOR_BLACK
 * COLOR_RED
 * COLOR_GREEN
 * COLOR_YELLOW
 * COLOR_BLUE
 * COLOR_MAGENTA
 * COLOR_CYAN
 * COLOR_WHITE
 */
typedef short color;


/**
 * Provide "C++" access to elementary ncurses functions.
 *
 * ** Not meant to be efficient, but simple to grasp fast
 *
 * version 0.1
 */
class Console
{
public:
  Console();
  ~Console();
  
  /* get input from keyboard */
  int  get(); // returns ERR after 1/10 second
  bool get(char& c); // returns false if a character was not
                     // available within 1/10 second
  
  /* write character(s) at current position */
  void put(char c);     // put the character for ascii code c
  void put(int i);      // put the integer i
  void put(string str); // put a string
  
  /* set/get position where next character will end up */
  void setPos(int x, int y);
  void getPos(int& x, int& y);
  
  /* get the size of the screen */
  int getWidth();
  int getHeight();

  /* set/get the current color for characters and background */
  void setForegroundColor(color c);
  void setBackgroundColor(color c);
  color getForegroundColor();
  color getBackgroundColor();
      
private:

  bool _has_colors;
  color _fg_color, _bg_color;

  static bool instantiated;
};

/**
 * Thrown when something goes amiss
 */
class ConsoleError : public exception
{
   public:
      ConsoleError(string const& msg) : exception(), _what(msg) {}
      ~ConsoleError() throw() {}

      const char* what() const throw() { return _what.c_str(); }
      
   private:
      string _what;
};

#endif
