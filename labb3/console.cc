#include <sstream>
#include "console.h"

/**
 * Please look in the header file to get an overview of the functions
 * and how to use them. The gory details here should not be needed.
 */

using namespace std;

bool Console::instantiated = false;

Console::Console()
{
  if (instantiated)
    throw ConsoleError("only one Console instance allowed");
  
  instantiated = true;
  
  initscr();
  cbreak();
  //raw();
  keypad(stdscr, TRUE);
  
  halfdelay(1);
  
  _fg_color = COLOR_WHITE;
  _bg_color = COLOR_BLACK;
  
  if (has_colors() == TRUE)
  {
    start_color();
    _has_colors = true;
    pair_content(0, &_fg_color, &_bg_color);
    attron(COLOR_PAIR(0));
  }
  else
  {
    _has_colors = false;
  }

  //  echo();
  noecho();
  curs_set(0);
  //  curs_set(1);
}

Console::~Console()
{
  endwin();
  instantiated = false;
}


/* get input */
int  Console::get()
{
  return getch();
}

/* get input */
bool  Console::get(char& c)
{
  int ch = getch();
  
  if (ch == ERR)
    return false;
  
  c = char(ch);
  
  return true;
}

/* write character at current position, and advance position */
void Console::put(char c)
{
  addch(c);
}

void Console::put(int i)
{
  ostringstream os;
  os << i;
  put(os.str());
}

void Console::put(string str)
{
  for (unsigned i = 0; i < str.length(); ++i)
    addch(str[i]);
}

/* set/get current write position */
void Console::setPos(int x, int y)
{
  move(y, x);
}

void Console::getPos(int& x, int& y)
{
  getyx(stdscr, y, x);
}

int Console::getWidth()
{
  int top, left, bottom __attribute__((unused)), right;
  
  /* those are macro definitions, no pointer arguments... */
  getbegyx(stdscr, top, left);
  getmaxyx(stdscr, bottom, right);

  if (top != 0 || left != 0)
    throw ConsoleError("getWidth: unexpected top/left screen coordinate");
  
  return right;
}

int Console::getHeight()
{
  int top, left, bottom, right __attribute__((unused));
  
  /* those are macro definitions, no pointer arguments... */
  getbegyx(stdscr, top, left);
  getmaxyx(stdscr, bottom, right);

  if (top != 0 || left != 0)
    throw ConsoleError("getHeight: unexpected top/left screen coordinate");
  
  return bottom;
}


void Console::setForegroundColor(color c)
{
   if (!_has_colors)
      throw ConsoleError("setForegroundColor: colors not available");

   if (c < 0 || c >= COLORS)
      throw ConsoleError("setForegroundColor: invalid color");
   
   _fg_color = c;
   
   const int pair = _fg_color + _bg_color * COLORS; 
   init_pair(pair, _fg_color, _bg_color);
   attrset(COLOR_PAIR(pair));
}

void Console::setBackgroundColor(color c)
{
   if (!_has_colors)
      throw ConsoleError("setBackgroundColor: colors not available");
   
   if (c < 0 || c >= COLORS)
      throw ConsoleError("setBackgroundColor: invalid color");
   
   _bg_color = c;
   
   const int pair = _fg_color + _bg_color * COLORS; 
   init_pair(pair, _fg_color, _bg_color);
   attrset(COLOR_PAIR(pair));
}

color Console::getForegroundColor()
{
   if (!_has_colors)
      throw ConsoleError("getForegroundColor: colors not available");

   return _fg_color;
}

color Console::getBackgroundColor()
{
   if (!_has_colors)
      throw ConsoleError("getBackgroundColor: colors not available");
   
   return _bg_color;
}
