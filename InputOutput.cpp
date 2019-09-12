// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	freopen("Output.txt", "w+", stdout);
	// Output specific number of digits past decimal point
	cout.setf(ios::fixed); 
	cout << setprecision(5);
	cout << 100.0 / 7.0 << endl;
	cout.unsetf(ios::fixed);

	// Output the decimal point and trailing zeros
	cout.setf(ios::showpoint);
	cout << 100.000 << endl;
	cout.unsetf(ios::showpoint);

	// Output a '+' before positive values
	cout.setf(ios::showpos);
	cout << 100 << " " << -100 << endl;
	cout.unsetf(ios::showpos);

	// Output numerical values in hexadecimal
	cout << hex << 1000 << " " << dec << 1000 << endl;
}
