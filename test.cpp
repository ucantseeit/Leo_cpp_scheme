#include <iostream>
#include "Pair.h"
#include "tokenizer.h"
#include "parser.h"

using namespace std;
using namespace Pair_;
using namespace Tokenizer;

static void test_display() {
    Pair p(1);
    p.display();
    Pair p1 = Pair(1, Pair(2));
    p1.display();
    Pair p3 = Pair(Pair(1), Pair(2));
    p3.display();
}

static void test_calc() {
    Pair expr = Pair("+", Pair(1, Pair(2)));
    cout << eval_expr(expr) << endl;

    Pair expr1 = Pair("/", 
                        Pair(Pair("-", Pair(5, Pair(4))), Pair(2)));
    cout << eval_expr(expr1) << endl; 
}

static void test_tokenize() {
    using namespace Tokenizer;
    string str = "(123 5 6)";
    tokenizer t(str);
    t.display();
    string str1 = "(+ (w3e 3) ((i)))";
    tokenizer t1(str1);
    t1.display();
    string str2 = "(2.5 3 3.654a k)";
    tokenizer t2(str2);
    t2.display();
}

static void test_parser() {
    using namespace Parser;
    using namespace Tokenizer;
    string str = "(+ 1 2)";
    tokenizer t = tokenizer(str);
    parser p = parser(t);
    p.get_expr().display();

    string str1 = "(- (+ 1 2) 3)";
    tokenizer t1 = tokenizer(str1);
    parser p1 = parser(t1);
    p1.get_expr().display();
}

int main() {
    test_display();
    test_calc();
    test_tokenize();
    test_parser();
}
