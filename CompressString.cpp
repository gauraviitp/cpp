#include <cassert>
#include <iostream>
#include <string>

using namespace std;

unsigned int countCompress(string& s){
	char prev = s[0];
	unsigned int count = 2;
	for(unsigned int i = 1; i < s.size(); ++i){
		if(s[i] != prev){
			count += 2;
		}
		prev = s[i];
	}
	return count;
}

string compress(string& str){
	if (str.empty()
		|| countCompress(str) >= str.size()){ 
			return str;
	}
	string res;
	char prev = str[0];
	int count = 1;
	for(unsigned int i = 1; i < str.size(); ++i){
		if(str[i] == prev){
			count++;
		}
		else {
			res.push_back(prev);
			res.push_back(count + '0'); // do not forget to add '0' here
			prev = str[i];
			count = 1;
		}
	}
	res.push_back(prev);
	res.push_back(count + '0');
	return res;
}

int main(){
	string str = "aaabbbcc";
	assert(compress(str).compare("a3b3c2") == 0);
	str = "Bob";
	assert(compress(str).compare("Bob") == 0);
	str = "Johny";
	assert(compress(str).compare("Johny") == 0);
	str = "";
	assert(compress(str).compare("") == 0);
}
