#include <iostream>
#include <limits.h>
using namespace std;

struct COMPLEX_NUMBER{
  double real_part;
  double imaginary_part;
};

COMPLEX_NUMBER read_complex_number(){
  
  cout << "Mata in ett komplext tal: ";
  COMPLEX_NUMBER number;
  cin >> number.real_part;
  cin.ignore(INT_MAX, '+');
  cin >> number.imaginary_part;
  cin.ignore(INT_MAX, '\n');

  return number;

}

void show_complex_number(COMPLEX_NUMBER number){
  
  if ( number.imaginary_part < 0 ){
    cout << number.real_part << " - " << -number.imaginary_part << "i" << endl;
  }
  else{
    cout << number.real_part << " + " << number.imaginary_part << "i" << endl;
  }
}

COMPLEX_NUMBER sum_complex_numbers(COMPLEX_NUMBER number1, COMPLEX_NUMBER number2){

  COMPLEX_NUMBER res;
  res.real_part = number1.real_part + number2.real_part;
  res.imaginary_part = number1.imaginary_part + number2.imaginary_part;

  return res;
}

COMPLEX_NUMBER sub_complex_numbers(COMPLEX_NUMBER number1, COMPLEX_NUMBER number2){

  COMPLEX_NUMBER res;
  res.real_part = number1.real_part - number2.real_part;
  res.imaginary_part = number1.imaginary_part - number2.imaginary_part;

  return res;
}

COMPLEX_NUMBER conjugate_complex_number(COMPLEX_NUMBER number){

  COMPLEX_NUMBER res;
  res.real_part = number.real_part;
  res.imaginary_part = -number.imaginary_part;
  
  return res;
}

COMPLEX_NUMBER divide_complex_number(COMPLEX_NUMBER complex, double real){
  COMPLEX_NUMBER res;
  res.real_part = complex.real_part/real;
  res.imaginary_part = complex.imaginary_part/real;

  return res;
}

COMPLEX_NUMBER multiply_complex_numbers(COMPLEX_NUMBER number1, COMPLEX_NUMBER number2){
  COMPLEX_NUMBER res;
  res.real_part = ((number1.real_part*number2.real_part)-(number1.imaginary_part*number2.imaginary_part));
  res.imaginary_part = ((number1.real_part*number2.imaginary_part)+(number1.imaginary_part*number2.real_part));
  
  return res;
}

COMPLEX_NUMBER divide_complex_number(COMPLEX_NUMBER number1, COMPLEX_NUMBER number2){
  COMPLEX_NUMBER numerator, denominator, res;
  numerator = multiply_complex_numbers(number1, conjugate_complex_number(number2));
  denominator = multiply_complex_numbers(number2, conjugate_complex_number(number2));
  res = divide_complex_number(numerator, denominator.real_part);

  return res;
}
/* TODO: funktion för att exponentiera ett komplext tal.
 * ( Fråga: kan exponenten vara ett flyttal?)

COMPLEX_NUMBER exponentiate_complex_number(COMPLEX_NUMBER base, int exponent){
  COMPLEX_NUMBER res;
  
  res = multiply_complex_numbers(base, base)*exponent;
  
  return res;
}
*/
int main(){
  
  COMPLEX_NUMBER test_number, test_number2, res;
  test_number = read_complex_number();
  test_number2 = read_complex_number();
  //show_complex_number(test_number);
  res = divide_complex_number(test_number, test_number2);
  show_complex_number(res);
  res = conjugate_complex_number(res);
  show_complex_number(res);
  
  return 0;
}
