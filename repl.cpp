#include <iostream>
#include <string>
#include "tokenize.hpp"
#include "parse.hpp"
#include "eval.hpp"
#include "env.hpp"

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
        }
    }
}

void displayResult(const SyntaxTree & result) {
    using std::cin, std::cout, std::endl, std::get;

    if (result.isFloat()) {
        cout << get<Float>(result.value) << endl;
    } else if (result.isInt()) {
        cout << get<Int>(result.value) << endl;
    } else if (result.isProc()) {
        cout << "it's a buit-in procedure" << endl;
    } else if (result.isLambda()) {
        cout << "it's a user-defined procedure" << endl;
    } else if (result.isBool()) {
        if (get<Bool>(result.value) == true) {
            cout << "#t" << endl;
        } else {
            cout << "#f" << endl;
        }
    }
}
