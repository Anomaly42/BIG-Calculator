#include <iostream>
#include  "classes.h"
using namespace std;

int main() {
	
	Number num1;
	num1.number = "675.978687"; 	// Don't forget a ".0" after an integer!
	num1.sign = 1;			// if 0 then number is positive , if 1 then number is negative
					
	num1.process();			//Does all the necessary conversions to store the number in array format

	Number num2;
	num2.number = "777.007";
	num2.sign = 0;
	num2.process();

	Number num3;

	num3 = num1 + num2;		// '+' Operator will add two numbers

	num1.show() ;			// displays number in cout
	cout << endl << "+" << endl;

	num2.show();
	cout << endl << "=" << endl;

	num3.show();

	return 0;
}
