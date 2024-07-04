#include <iostream>
#include <string>
#include "tokenize.hpp"
#include "parse.hpp"
#include "eval.hpp"
#include "env.hpp"

int main(int, char**){
    using std::cin, std::cout, std::endl;
    using namespace tokens;
    using namespace parser;

    std::string input;
    do {
        cout << ">> ";
        std::getline(cin, input);

        vector<token> ts = tokenize(input);

        auto pts = ts.begin();
        SyntaxTree st = parse(pts);

        SyntaxTree result = eval_expr(st, global_env);

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

    } while (input != "exit()");
}
