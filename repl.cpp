#include <iostream>
#include <string>
#include "tokenize.hpp"
#include "parse.hpp"
#include "eval.hpp"

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

        cout << eval_expr(st) << endl;
    } while (input != "exit()");
}
