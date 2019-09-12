#include <cassert>
#include <string>

using namespace std;

/*
 * Checks if s2 is rotation of s1.
 */
bool isRotation(string& s1, string& s2){
	if(s1.length() == s2.length()){
		string s1s1 = s1 + s1;
		return s1s1.find(s2) != string::npos;
	}
	return false;
}

int main(){
	string a = "waterbottle", b = "erbottlewat";
	assert(isRotation(a, b));
	a = "", b = "";
	assert(isRotation(a, b));
}
