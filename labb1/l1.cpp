#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;

int main(){

  // INMATNINGSDEL

  cout << "INMATNINGSDEL" << endl << "============" << endl;

  float first_val = -1;
  while(first_val < 0){
    cout << "Mata in första pris: ";
    cin >> first_val;
    cin.ignore(INT_MAX, '\n');
    if(first_val < 0){
      cerr << "FEL: Första pris måste vara minst 0 (noll) kronor" << endl;
    }
  }

  float last_val = -1;
  while(last_val <= first_val){
    cout << "Mata in sista pris : ";
    cin >> last_val;
    cin.ignore(INT_MAX, '\n');
    if(last_val < first_val){
      cerr << "FEL: Första pris måste vara minst lika stort som första pris"
	   << endl;
    }
  }

  float step = -1;
  float diff = last_val - first_val;
  while(step <= 0 || step > diff){
    cout << "Mata in steglängd  : ";
    cin >> step;
    cin.ignore(INT_MAX, '\n');
    if(step <= 0 || step > diff){
      cerr << "FEL: Steglängden måste vara större än noll och mindre än "
	   << "differensen av sista och första pris." << endl;
    }
  }

  float moms = -1;
  while(moms < 0){
    cout << "Mata in momsprocent: ";
    cin >> moms;
    cin.ignore(INT_MAX, '\n');
    if(moms < 0){
      cerr << "FEL: Momsprocenten måste vara minst 0 (noll)." << endl;
    }
  }
  cout << endl;

  // MOMSTABELLEN

  cout << fixed << setprecision (2);
  cout << "MOMSTABELLEN" << endl << "============" << endl;
  cout << setw(15) << right << "Pris"
       << setw(10) << right << "Moms"
       << setw(20) << right << "Pris med moms" << endl;
  cout << setw(45) << setfill('-') << "" << setfill(' ')<< endl;
  float new_moms = 0;
  for(float i = first_val; i <= last_val; i += step){
    new_moms = (i*moms)/100;
    cout << setw(15) << i
	 << setw(10) << new_moms
	 << setw(20) << i + new_moms << endl;
  }

  return 0;
}
