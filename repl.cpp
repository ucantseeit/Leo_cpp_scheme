#include <iostream>
#include <string>
#include <vector>
#include "tokenize.hpp"
#include "parse.hpp"
#include "eval.hpp"
#include "env.hpp"
#include "SyntaxTree.hpp"


void displayResult(const SyntaxTree & st);

int main(int, char**){

    using namespace tokens;
    using namespace parser;

    std::istream & input = std::cin;
    while(true) {
        cout << ">> ";

        vector<token> ts = tokenize(input);

        auto pts = ts.begin();
        while (pts != ts.end()) {
            SyntaxTree st = parse(pts);

            SyntaxTree result = eval_expr(st, global_env);

            displayResult(result);
            cout << endl;
        }
    }
}



bool isQuote(const Symbol & sym);
bool isVariable(const Symbol & sym);
bool isString(const Symbol & sym);

typedef std::vector<SyntaxTree>::const_iterator itemptr;
itemptr getNext(itemptr pitem);

void displayResult(const SyntaxTree & result) {
    using std::cin, std::cout, std::endl, std::get;

    if (result.isFloat()) {
        cout << get<Float>(result.value);
    } else if (result.isInt()) {
        cout << get<Int>(result.value);
    } else if (result.isProc()) {
        cout << "it's a buit-in procedure";
    } else if (result.isLambda()) {
        cout << "it's a user-defined procedure";
    } else if (result.isBool()) {
        if (get<Bool>(result.value) == true) {
            cout << "#t";
        } else {
            cout << "#f";
        }
    } else if (result.isSymbol()) {
        string value = std::get<Symbol>(result.value);
        if (isQuote(value)) {
            cout << value.substr(1, value.length()-1); 
        } else if (isString(value)) {
            cout << value; 
        }
    } else if (result.isNil()){
        cout << "()";
    } else if (result.isPair()) {
        cout << '(';

        auto pitem = get<SyntaxTree::Pair>(result.value).begin();
        displayResult(*pitem);
        while ((pitem+1)->isPair()) {
            pitem = getNext(pitem);
            cout << " ";
            displayResult(*pitem);
        }
        if (!(pitem+1)->isNil()) {
            cout << " . ";
            displayResult(*(pitem+1));
        }

        cout << ')';
    }
}

itemptr getNext(itemptr pitem) {
    return std::get<SyntaxTree::Pair>((pitem+1)->value).begin();
}