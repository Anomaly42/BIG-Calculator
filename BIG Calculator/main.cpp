#include <iostream>
#include  "classes.h"
using namespace std;

int main() {
	Number num1;
	num1.number = "58858587696960.9697669696"; // Don't forget a ".0" after an integer!
	num1.sign = 0;
	// if 0 then number is positive , if 1 then number is negative
	num1.process();

	Number num2;
	num2.number = "86786796969769.9879869698";
	num2.sign = 0;
	num2.process();

	Number num3;

	num3 = num1 * num2;

	num1.show() ;
	cout << endl << "*" << endl;

	num2.show();
	cout << endl << "=" << endl;

	num3.show();

	return 0;
}
