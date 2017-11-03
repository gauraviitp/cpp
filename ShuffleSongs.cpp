// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 1:41 PM
	Time end -  PM
	Desc: Shuffle a list of songs.
*/

#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;

void shuffle(VI& origlist, VI& shuffled) {
	VI toshuffle(origlist);
	srand(time(NULL));
	while (!toshuffle.empty()) {
		int randno = rand();
		int newSongIndex = randno % toshuffle.size();
		shuffled.push_back(toshuffle[newSongIndex]);
		toshuffle.erase(toshuffle.begin() + newSongIndex);
	}
}

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	// Read the input
	int n; // Number of songs
	cin >> n;
	VI v(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	VI shuffled;
	shuffle(v, shuffled);
	for (const auto& e : shuffled) {
		cout << e << " ";
	}
	cout << "\n";
	return 0;
}

/*
5
1 2 3 4 5
*/
