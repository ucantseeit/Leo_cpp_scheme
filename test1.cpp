#include "tokenize.hpp"
#include "parse.hpp"
#include "SyntaxTree.hpp"
#include "eval.hpp"

using namespace std;

int main() {
    using namespace parser;
    using namespace tokens;
    string str = "(/ 1.1 2 1.22)";

    vector<token> ts = tokenize(str);

    auto pts = ts.begin();
    SyntaxTree st = parse(pts);

    cout << eval_expr(st) << endl;

    string str1 = "(+ 1 2)";
    ts = tokenize(str1);
    pts = ts.begin();
    st = parse(pts);
    cout << eval_expr(st) << endl;

}