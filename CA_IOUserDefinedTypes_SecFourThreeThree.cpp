#include <iostream>
#include <string>
using namespace std;
struct Entry{
  string name;
  int number;
};
ostream& operator<<(ostream& os, const Entry& e){
    return os << "{\"" + e.name << "\", " << e.number << "}";
}
int main() {
	Entry e{"Gaurav", 1};
	cout << e << '\n';
	return 0;
}
