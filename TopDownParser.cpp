// Top down parser

// (* 2 (+ 3 4)) = 14

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
	operation,
	leftParanthesis,
	rightParanthesis,
	number
};

class Token{
public:
	TokenType type;
	string value;
	Token(TokenType ptype, string pvalue):
		  type(ptype), value(pvalue){}
};

typedef vector<Token *> Tokens;

int expression(Tokens &tokens, int &pos){
	int res = 0;
	// First production rule
	if(tokens[pos]->type == number){
		res = stoi(tokens[pos]->value);
		++pos;
	}
	// Second production rule
    else if (tokens[pos]->type == leftParanthesis){
		++pos; // op token
		if(tokens[pos]->type == operation){
			string op = tokens[pos]->value;
			++pos; // first expression
			int first = expression(tokens, pos);
			int second = expression(tokens, pos);
			if(op == "+"){
				res = first + second;
			}
			else if (op == "-"){
				res = first - second;
			}
			else if (op == "*"){
				res = first * second;
			}
			else if (op == "/"){
				res = first / second;
			}
			if(tokens[pos]->type == rightParanthesis){
				++pos;
			}
			else {
				cout << "Error while parsing. Expected: \")\", Actual: \"" << tokens[pos]->value << "\"" << endl;
				throw "Error";
			}
		}
		else {
			cout << "Error while parsing. Expected: \"operation\", Actual: \"" << tokens[pos]->value << "\"" << endl;
			throw "Error";
		}
	}
	else {
		cout << "Error while parsing. Expected: \"expression\", Actual: \"" << tokens[pos]->value << "\"" << endl;
		throw "Error";
	}
	return res;
}

int parse(Tokens &tokens){
	int pos = 0;
	return expression(tokens, pos);
}

int main(){
	Tokens tokens = {
			new Token(leftParanthesis, "("),
			new Token(operation, "*"),
			new Token(number, "2"),
			new Token(leftParanthesis, "("),
			new Token(operation, "+"),
			new Token(number, "3"),
			new Token(number, "4"),
			new Token(rightParanthesis, ")"),
			new Token(rightParanthesis, ")")
		};
	int result = parse(tokens);
	cout << result << endl;
	assert(result == 14);
}
