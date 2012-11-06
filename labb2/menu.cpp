#include "complex_operations.h"

void menu_sum()
{
  COMPLEX_NUMBER num1, num2, res;
  num1 = read_complex_number();
  num2 = read_complex_number();
  res = sum_complex_numbers(num1, num2);
  cout << endl << "Summan av talen är: ";
  show_complex_number(res);
}

void menu_sub()
{
  COMPLEX_NUMBER num1, num2, res;
  num1 = read_complex_number();
  num2 = read_complex_number();
  res = sub_complex_numbers(num1, num2);
  cout << endl << "Differensen av talen är: ";
  show_complex_number(res);
}

void menu_div_float()
{
  COMPLEX_NUMBER numerator, res;
  double denominator;
  numerator = read_complex_number();
  cout << "Mata in nämnaren (flyttal): ";
  cin >> denominator;
  cin.ignore(INT_MAX, '\n');
  res = divide_complex_number(numerator, denominator);
  cout << endl << "Kvoten av talen är: ";
  show_complex_number(res);
}

void menu_div_complex()
{
  COMPLEX_NUMBER numerator, denominator, res;
  numerator = read_complex_number();
  denominator = read_complex_number();
  res = divide_complex_number(numerator, denominator);
  cout << endl << "Kvoten av talen är: ";
  show_complex_number(res);
}

void menu_mult()
{
  COMPLEX_NUMBER num1, num2, res;
  num1 = read_complex_number();
  num2 = read_complex_number();
  res = multiply_complex_numbers(num1, num2);
  cout << endl << "Produkten av talen är: ";
  show_complex_number(res);
}

void menu_exp()
{
  COMPLEX_NUMBER base, res;
  int exponent;
  base = read_complex_number();
  cout << "Mata in ett heltal som exponent: ";
  cin >> exponent;
  cin.ignore(INT_MAX, '\n');
  res = exponentiate_complex_number(base, exponent);
  cout << endl << "Resultatet av exponentieringen är: ";
  show_complex_number(res);
}

void menu_abs()
{
  COMPLEX_NUMBER number;
  double res;
  number = read_complex_number();
  res = absolute_complex_number(number);
  cout << endl << "Det absoluta värdet av talet är: " << res << endl;
}

int main()
{
  char menu_option;
  while (true)
  {
    cout << "----------------------------MENY----------------------------" << endl;
    cout << "Skriv tecknet för det du vill göra och tryck sedan på enter" 
	 << endl << endl;
    
    cout << "1. Summera två komplexa tal med varandra." << endl
	 << "2. Subtrahera två komplexa tal med varandra." << endl
	 << "3. Dividera ett komplext tal med ett flyttal." << endl
	 << "4. Dividera två komplexa tal med varandra." << endl
	 << "5. Multiplicera två komplexa tal med varandra." << endl
	 << "6. Exponentiera ett komplext tal med en exponent." << endl
	 << "7. Få ut ett komplext tals absoluta värde." << endl
	 << "q. Avsluta programmet." << endl << endl;
    cout << "Tecken: ";
    cin >> menu_option;
    cout << endl;
    cin.ignore(INT_MAX, '\n');
    switch(menu_option)
    {
    case '1':
      menu_sum();
      break;
    case '2':
      menu_sub();
      break;
    case '3':
      menu_div_float();
      break;
    case '4':
      menu_div_complex();
      break;
    case '5':
      menu_mult();
      break;
    case '6':
      menu_exp();
      break;
    case '7':
      menu_abs();
      break;
    case 'q':
    case 'Q':
      exit(-1);
      break;
    default:
      cout << "Tecknet finns inte med i menyn, var god försök igen." << endl;
      break;
    }
    cout << endl << "Tryck Enter för att fortsätta!";
    cin.ignore(INT_MAX, '\n');
    cout << endl;
  }
  return 0;
}
