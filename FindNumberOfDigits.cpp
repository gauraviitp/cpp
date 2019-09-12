// find number of digits in nth number when numbers are made up of only
// digits 1, 2 and 3.

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;


ll findNumberOfDigits(ll n){
    ll k = 0;
	ll ct = 1;
	while(k + pow(3, ct) < n){
		k += pow(3, ct++);
	}
	return ct;
}

int main(){
  assert(findNumberOfDigits(1) == 1);
  assert(findNumberOfDigits(2) == 1);
  assert(findNumberOfDigits(3) == 1);
  assert(findNumberOfDigits(4) == 2);
  assert(findNumberOfDigits(5) == 2);
  assert(findNumberOfDigits(6) == 2);
  assert(findNumberOfDigits(7) == 2);
  assert(findNumberOfDigits(8) == 2);
  assert(findNumberOfDigits(9) == 2);
  assert(findNumberOfDigits(10) == 2);
  assert(findNumberOfDigits(11) == 2);
  assert(findNumberOfDigits(12) == 2);
  assert(findNumberOfDigits(13) == 3);
  assert(findNumberOfDigits(14) == 3);
  assert(findNumberOfDigits(15) == 3);
  assert(findNumberOfDigits(16) == 3);
  assert(findNumberOfDigits(17) == 3);
  assert(findNumberOfDigits(18) == 3);
  assert(findNumberOfDigits(19) == 3);
  assert(findNumberOfDigits(20) == 3);
  assert(findNumberOfDigits(21) == 3);
  assert(findNumberOfDigits(22) == 3);
  assert(findNumberOfDigits(23) == 3);
  assert(findNumberOfDigits(39) == 3);
  assert(findNumberOfDigits(40) == 4);
  /*int tt;
  cin >> tt;
  for(int caseno = 0; caseno < tt; ++caseno){
      ll n;
      cin >> n;
      cout << findNumberOfDigits(n) << "\n";
  }*/
}
