// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

bool validExpression(string exp) {
	int starCount = 0, openParCount = 0, closedParCount = 0;
	// check right to left whether openParanthesis exceed the closedParanthesis and stars
	for (int i = exp.size() - 1; i >= 0; --i) {
		char e = exp[i];
		if (e == '(') {
			openParCount++;
		}
		else if (e == ')') {
			closedParCount++;
		}
		else if (e == '*') {
			starCount++;
		}
		if (closedParCount + starCount < openParCount) {
			return false;
		}
	}
	// check left to right whether closedParanthesis exceed the openParanthesis and stars
	starCount = 0, openParCount = 0, closedParCount = 0;
	for (int i = 0; i < exp.size(); ++i) {
		char e = exp[i];
		if (e == '(') {
			openParCount++;
		}
		else if (e == ')') {
			closedParCount++;
		}
		else if (e == '*') {
			starCount++;
		}
		if (openParCount + starCount < closedParCount) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("output.txt", "w+", stdout);
	cout << "TC1: " << (validExpression("(*)") == true) << endl;
	cout << "TC2: " << (validExpression("((*)") == true) << endl;
	cout << "TC3: " << (validExpression("((*))") == true) << endl;
	cout << "TC4: " << (validExpression("((*)))") == true) << endl;
	cout << "TC5: " << (validExpression("((*))))") == false) << endl;
	cout << "TC6: " << (validExpression("*((*))))") == true) << endl;
	cout << "TC7: " << (validExpression("(*((*))))") == true) << endl;
	cout << "TC8: " << (validExpression("(*)(*)(**") == true) << endl;
	cout << "TC9: " << (validExpression("(*)(*)(***") == true) << endl;
	cout << "TC10: " << (validExpression("((*)(*)(***") == true) << endl;
	cout << "TC11: " << (validExpression("(()(*)(") == false) << endl;
	cout << "TC12: " << (validExpression("(()(*)(") == false) << endl;
	cout << "TC13: " << (validExpression("****()))))") == true) << endl;
	cout << "TC12: " << (validExpression("") == true) << endl;
	cout << "TC13: " << (validExpression("()") == true) << endl;
	cout << "TC14: " << (validExpression("(*)") == true) << endl;
	cout << "TC15: " << (validExpression("(*)(*)") == true) << endl;
	cout << "TC16: " << (validExpression("*") == true) << endl;
	cout << "TC17: " << (validExpression("**") == true) << endl;
	cout << "TC18: " << (validExpression("*)") == true) << endl;
	cout << "TC19: " << (validExpression("*(((()())()))())") == true) << endl;
	cout << "TC20: " << (validExpression("*()(") == false) << endl;
	cout << "TC21: " << (validExpression("**()(") == false) << endl;
	cout << "TC22: " << (validExpression("**(**)*(") == false) << endl;
	cout << "TC23: " << (validExpression(")**") == false) << endl;
	cout << "TC24: " << (validExpression("****()))))") == true) << endl;
	cout << "TC25: " << (validExpression("****())))") == true) << endl;
	cout << "TC26: " << (validExpression("****())))))") == false) << endl;
	cout << "TC27: " << (validExpression("***********************(((((()") == false) << endl;
	cout << "TC28: " << (validExpression("*(((()())())())") == true) << endl;
	cout << "TC29: " << (validExpression("(((()())()))())") == false) << endl;
	cout << "TC30: " << (validExpression("*(((()())())*())") == true) << endl;
	return 0;
}
