#include <iostream>
#include <iomanip>
#include <limits.h>
 
using namespace std;

int main()
{
//  Skriv in ett heltal:
//  Du skrev in talet:

  int i = 0;
  cout << "Skriv in ett heltal: ";
  cin >> i;
  cout << "Du skrev in talet: " << i << endl << endl;
  cin.ignore(INT_MAX, '\n');
//  Skriv in fem heltal:
//  Du skrev in talen:

  cout << "Skriv in fem heltal: ";
  cin >> i;
  cout << "Du skrev in talen: " << i << ", ";
  cin >> i;
  cout << i << ", ";
  cin >> i;
  cout << i << ", ";
  cin >> i;
  cout << i << ", ";
  cin >> i;
  cout << i << endl << endl;
  cin.ignore(INT_MAX,'\n');
//  Skriv in ett flyttal:
//  Du skrev in flyttalet:

  double d = 0.0;
  cout << fixed << setprecision (3);
  cout << "Skriv in ett flyttal: ";
  cin >> d;
  cin.ignore(INT_MAX, '\n');
  cout << "Du skrev in talet: " << d << endl << endl;

//  Skriv in ett heltal och ett flyttal:
//  Du skrev in heltalet:
//  Du skrev in flyttalet:

  cout << "Skriv in ett heltal och ett flyttal: ";
  cin >> i;
  cin.ignore(INT_MAX, ' ');
  cout << "Du skrev in heltalet: " << i << endl;
  cin >> d;
  cout << "Du skrev in flyttalet: " << d << endl << endl;
  cin.ignore(INT_MAX, '\n');

//  Skriv in ett tecken:
//  Du skrev in tecknet:

  char c;
  cout << "Skriv in ett tecken: ";
  cin >> c;
  cout << "Du skrev in tecknet: " << c << endl << endl; 
  cin.ignore(INT_MAX,'\n');

//  Skriv in en sträng:
//  Strängen '  ' har  tecken.
  string s;
  cout << "Skriv in en sträng: ";
  cin >> s;
  cin.ignore(INT_MAX, '\n');
  cout << "strängen '" << s << "' har " << s.length() << " tecken" << endl << endl;
  
//  Skriv in ett heltal och en sträng:
//  Du skrev in talet |  | och strängen |     |.

  cout << "Skriv in ett heltal och en sträng: ";
  cin >> i;
  cin.ignore(INT_MAX, ' ');
  cout << "Du skrev in talet | " << i;
  getline(cin, s);
  cout << " | och strängen | " << s << " |" << endl << endl;

//  Skriv in en sträng och ett flyttal:
//  Du skrev in "      " och "   ".

  cout << "Skriv in en sträng och ett flyttal: ";
  cin >> s;
  cin >> d;
  cout << "Du skrev in \"" << d << "\" och \"" << s << "\"." << endl << endl;
  cin.ignore(INT_MAX, '\n');

//  Skriv in en hel rad med text:
//  Du skrev in textraden: '   '
    
  cout << "Skriv en hel rad med text: ";
  getline(cin, s);
  cout << "Du skrev in textraden: '" << s << "'" << endl << endl;
//  Skriv in en textrad som slutar med ett negativt heltal:
//  Du skrev in textraden: '   ' och heltalet '   '

  cout << "Skriv in en textrad som slutar med ett negativt heltal: ";
  getline(cin, s, '-');
  cin >> i;
  cout << "Du skrev in textraden: '" << s << "' och heltalet '" << -i << "'"
  << endl << endl;

  return 0;
}
