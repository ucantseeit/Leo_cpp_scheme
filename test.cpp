#include <iostream>
#include "Pair.h"

using namespace std;

static void test_display() {
    Pair p(1);
    p.display();
    Pair p1 = Pair(1, Pair(2));
    p1.display();
    Pair p3 = Pair(Pair(1), Pair(2));
    p3.display();
}

static void test_calc() {
    Pair expr = Pair('+', Pair(1, Pair(2)));
    cout << eval_expr(expr) << endl;

    Pair expr1 = Pair('/', 
                        Pair(Pair('-', Pair(5, Pair(3))), Pair(2)));
    cout << eval_expr(expr1) << endl; 
}

int main() {
    test_display();
    test_calc();
}
