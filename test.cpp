#include <iostream>
#include "Pair.h"
#include "tokenizer.h"

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
                        Pair(Pair("-", Pair(5, Pair(3))), Pair(2)));
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
}

int main() {
    test_display();
    test_calc();
    test_tokenize();
}
