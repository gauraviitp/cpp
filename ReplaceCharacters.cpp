#include <cassert>
#include <cstring>

char* ReplaceCharacters(char const *str){
	char const *tstr = str;
	int len = 0, whitespaces = 0;
	while(*tstr) {
		++len;
		if(*tstr == ' ') ++whitespaces;
		++tstr;
	}
	int nlen = len + whitespaces * 2;
	char *nstr = new char[nlen + 1];
	nstr[nlen--] = '\0';
	for(int i = len - 1; i >= 0; --i){
		if(str[i] == ' '){
			nstr[nlen--] = '0';
			nstr[nlen--] = '2';
			nstr[nlen--] = '%';
		} else {
			nstr[nlen--] = str[i];
		}
	}
	return nstr;
}

int main(){
	assert(strcmp(ReplaceCharacters("Johny Johny"), "Johny%20Johny") == 0);
	assert(strcmp(ReplaceCharacters(""), "") == 0);
	assert(strcmp(ReplaceCharacters(" "), "%20") == 0);
	assert(strcmp(ReplaceCharacters("Yes Papa "), "Yes%20Papa%20") == 0);
}
