#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Entry {
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
void print_book(const vector<Entry>& book){
    for(int i = 0; i < book.size(); ++i){
        cout << book[i] << '\n';
    }
}
int main() {
    vector<Entry> phone_book;
    phone_book.push_back(Entry{"Gaurav Choudhary", 12345});
    phone_book.push_back(Entry{"Megha Mallinath", 23456});
    print_book(phone_book);
    return 0;
}
