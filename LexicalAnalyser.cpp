#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

using namespace std;

class Token{
public:
	string type;
	string value;
	Token(string ptype, string pvalue) : 
		  type(ptype), value(pvalue) {}
};

ostream & operator<<(ostream &os, const Token &token){
	return os << " {\n" 
			  << "  type: " << token.type << ",\n" 
			  << "  value: " << token.value << "\n"
			  << " }";
}

template <typename T>
ostream & operator<<(ostream &os, const vector<T *> list){
	os << "[\n";
	for(int pos = 0; pos < (int)list.size(); ++pos){
		os << *list[pos];
		if(pos != (int)list.size() - 1){
			cout << ",";
		}
		cout << "\n";
	}
	os << "]" << endl;
	return os;
}

typedef pair<int, Token*> Result;
typedef vector<Token *> Tokens;
typedef	Result (*Func) (string, int);

Result tokenizeChar(char value, string type, string input, int pos){
	if(value == input[pos]){
		return make_pair(1, new Token(type, string(1, value)));
	}
	else {
		return make_pair(0, nullptr);
	}
}

Result tokenizeLeftParan(string input, int pos){
	return tokenizeChar('(', "leftParan", input, pos);
}

Result tokenizeRightParan(string input, int pos){
	return tokenizeChar(')', "rightParan", input, pos);
}

Result tokenizeOperator(string input, int pos){
	vector<char> operatorList = {'*', '/', '+', '-'};
	for(auto op : operatorList){
		auto token = tokenizeChar(op, "operator", input, pos);
		if(token.first == 1){
			return token;
		}
	}
	return make_pair(0, nullptr);
}

Result tokenizePattern(string pattern, string type, string input, int pos){
	regex exp("^" + pattern);
	smatch m;
	if(regex_search(input.cbegin() + pos, input.cend(), m, exp)){
		return make_pair(m.length(), new Token(type, m.str()));
	}
	else {
		return make_pair(0, nullptr);
	}
}

Result tokenizeNumber(string input, int pos){
	return tokenizePattern("([0-9]+)*", "number", input, pos);
}

Result tokenizeString(string input, int pos){
	if(input[pos] == '\"'){
		int fpos = input.find('\"', pos + 1);
		if(fpos != (int)string::npos){
			return make_pair(fpos - pos + 1, new Token("string" ,input.substr(pos, fpos - pos + 1)));
		}
	}
	return make_pair(0, nullptr);
}

Result skipWhitespace(string input, int pos){
	if(input[pos] == ' '){
		return make_pair(1, nullptr);
	}
	else {
		return make_pair(0, nullptr);
	}
}

Tokens tokenize(string input){
	vector<Func> functions = {
			&skipWhitespace,
			&tokenizeLeftParan,
			&tokenizeOperator,
			&tokenizeNumber,
			&tokenizeString,
			&tokenizeRightParan
		};
	Tokens tokens;
	int pos = 0;
	bool matched = false;
	while(pos < (int)input.length()){
		for(auto func : functions){
			Result result = func(input, pos);
			if(result.first > 0){
				if(result.second != nullptr) {
					tokens.push_back(result.second);
				}
				pos += result.first;
				matched = true;
				break;
			}
		}
		if(!matched){
			cout << "Warning... Could not match - " << input[pos] << endl;
			++pos;
		}
		matched = false;
	}
	return tokens;
}

int main(){
	Tokens tokens = tokenize("(+ 100000 \"Gaurav\") * 2");
	cout << tokens;
}
