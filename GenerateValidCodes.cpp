	// ConsoleApplication1.cpp : Defines the entry point for the console application.
	//

	/*	Time begin - 5:31 AM
		Time end -  AM
		Desc: Print possible decodings.
	*/

	#include "stdafx.h"
	#include <iostream>
	#include <string>
	#include <vector>

	using namespace std;

	void printDecodingsRecur(string& str, int pos, string& output) {
		if (pos == str.size()) {
			cout << output << " ";
			return;
		}
		// First case: Consider one char
		output.push_back('a' + atoi(str.substr(pos, 1).c_str()) - 1);
		// Recur for the first case
		printDecodingsRecur(str, pos + 1, output);
		// Remove the char for backtracking with second case
		output.pop_back();

		// Second case: Consider two chars
		// Check if two chars are available
		if (pos + 1 < str.size()) {
			int val = atoi(str.substr(pos, 2).c_str());
			if (val >= 1 && val <= 26) {
				// Insert into output string
				output.push_back('a' + val - 1);
				// Recur for the second case
				printDecodingsRecur(str, pos + 2, output);
				// Remove the char for backtracking
				output.pop_back();
			}
		}
	}

	void printAllDecodings(string& str) {
		string output;
		printDecodingsRecur(str, 0, output);
	}

	int main() {
		freopen("Input.txt", "r", stdin);
		freopen("Output.txt", "w+", stdout);
		string str;
		cin >> str;
		printAllDecodings(str);
	}
