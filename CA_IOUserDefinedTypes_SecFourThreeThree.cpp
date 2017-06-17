#include <iostream>
#include <string>
using namespace std;
struct Entry{
  string name;
  int number;
};
// operator "put to"
ostream& operator<<(ostream& os, const Entry& e) {
    return os << "{\"" + e.name << "\", " << e.number << "}";
}
// operator "read from"
istream& operator>>(istream& is, Entry& e) {
    char c, c2;
    if(is >> c && c == '{' && is >> c2 && c2 == '"') {
        string name;
        while(is.get(c) && c!='"'){
            name += c;   
        }
        if(is >> c && c == ','){
            int number = 0;
            if(is >> number >> c && c=='}'){
                e = {name, number};
                return is;
            }
        }
    }
    is.setstate(ios_base::failbit);
    return is;
}
int main() {
	Entry e{"Gaurav", 1};
	cout << e << '\n';
	cout << "Enter name and number" << '\n';
	cin >> e;
	cout << e;
	return 0;
}
