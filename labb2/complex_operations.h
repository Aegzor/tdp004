#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

struct COMPLEX_NUMBER
{
  double real_part = 0.0;
  double imaginary_part = 0.0;
};

COMPLEX_NUMBER read_complex_number()
{ 
  cout << "Mata in ett komplext tal: ";
  COMPLEX_NUMBER number;
  cin >> number.real_part;
  cin.ignore(INT_MAX, '+');
  cin >> number.imaginary_part;
  cin.ignore(INT_MAX, '\n');

  return number;

}

// Takes a complex number and prints it nicely formatted.
void show_complex_number(const COMPLEX_NUMBER& number)
{
  if (number.real_part == 0 && number.imaginary_part == 0){
    cout << '0' << endl;
  }
  else if ( number.imaginary_part < 0 ){
    if (number.real_part == 0){
      cout << -number.imaginary_part << 'i' << endl;
    }
    else if (number.imaginary_part == 0){
      cout << number.real_part << endl;
    }
    else{
      cout << number.real_part << " - " << -number.imaginary_part << 'i' << endl;
    }
  }
  else{
    if (number.real_part == 0){
      cout << number.imaginary_part << 'i' << endl;
    }
    else if (number.imaginary_part == 0){
      cout << number.real_part << endl;
    }
    else{
      cout << number.real_part << " + " << number.imaginary_part << 'i' << endl;
    }
  }
}

// 
COMPLEX_NUMBER sum_complex_numbers(const COMPLEX_NUMBER& number1, 
				   const COMPLEX_NUMBER& number2)
{
  COMPLEX_NUMBER res;
  res.real_part = number1.real_part + number2.real_part;
  res.imaginary_part = number1.imaginary_part + number2.imaginary_part;

  return res;
}

COMPLEX_NUMBER sub_complex_numbers(const COMPLEX_NUMBER& number1,
				   const COMPLEX_NUMBER& number2)
{
  COMPLEX_NUMBER res;
  res.real_part = number1.real_part - number2.real_part;
  res.imaginary_part = number1.imaginary_part - number2.imaginary_part;

  return res;
}

COMPLEX_NUMBER conjugate_complex_number(const COMPLEX_NUMBER& number)
{
  COMPLEX_NUMBER res;
  res.real_part = number.real_part;
  res.imaginary_part = -number.imaginary_part;
  
  return res;
}

COMPLEX_NUMBER divide_complex_number(const COMPLEX_NUMBER& complex, double real)
{
  COMPLEX_NUMBER res;
  res.real_part = complex.real_part/real;
  res.imaginary_part = complex.imaginary_part/real;

  return res;
}

COMPLEX_NUMBER multiply_complex_numbers(const COMPLEX_NUMBER& number1,
					const COMPLEX_NUMBER& number2)
{
  COMPLEX_NUMBER res;
  res.real_part = ((number1.real_part*number2.real_part)-(number1.imaginary_part*number2.imaginary_part));
  res.imaginary_part = ((number1.real_part*number2.imaginary_part)+(number1.imaginary_part*number2.real_part));
  
  return res;
}

COMPLEX_NUMBER divide_complex_number(const COMPLEX_NUMBER& number1,
				     const COMPLEX_NUMBER& number2)
{
  COMPLEX_NUMBER numerator, denominator, res;
  numerator = multiply_complex_numbers(number1,
				       conjugate_complex_number(number2));
  denominator = multiply_complex_numbers(number2,
					 conjugate_complex_number(number2));
  res = divide_complex_number(numerator, denominator.real_part);

  return res;
}

COMPLEX_NUMBER exponentiate_complex_number(const COMPLEX_NUMBER& base,
					   int exponent)
{
  COMPLEX_NUMBER res = base;
  
  for (int i = 0; i < exponent - 1; i++){
    res = multiply_complex_numbers(res, base);
  }

  return res;
}

double absolute_complex_number(const COMPLEX_NUMBER& number)
{
  double res;
  res = (pow(number.real_part, 2) + pow(number.imaginary_part, 2));
  res = sqrt(res);

  return res;
}
