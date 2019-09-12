#include <cassert>
#include <cstdlib>
#include <cstring>

/*
 * Reverses the string of characters.
 * Input string can be readonly.
 * It allocates new memory for the reversed string
 * and returns the reversed string.
 */
char* reverse(char* s){
	int len = 0;
	char* ts = s;
	while(*ts) {
		++len; 
		++ts;
	}
	char* res = new char[len + 1];
	strcpy(res, s);
	for(int i = 0; i < len/2; ++i){
		char tc = res[i];
		res[i] = res[len - 1 - i];
		res[len - 1 - i] = tc;
	}
	res[len] = '\0';
	return res;
}

int main(){
	assert(strcmp(reverse("Gaurav"), "varuaG") == 0);
	assert(strcmp(reverse("Megha"), "ahgeM") == 0);
	assert(strcmp(reverse("Ryan"), "nayR") == 0);
	assert(strcmp(reverse(""), "") == 0);
}
