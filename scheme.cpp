#include <iostream>
#include "Pair.h"
#include <exception>
#include <vector>
#include <set>
#include <string>
#include <numeric>
using namespace Pair_;

float eval_expr(const Pair &expr) {
    using std::cout, std::endl, std::vector;
    if (expr.get_type() != OPERATOR) {
        cout << "Syntax Error: invalid operator" << endl;
    }
    
    vector<float> arguments;
    const Pair *track = expr.get_next();
    for (; track->get_type()!=NIL;
        track = track->get_next()) {
        if (track->get_type() == LITERAL) {
            arguments.push_back(std::get<float>(track->get_item()));
        } else if (track->get_type() == SUBEXPR) {
            arguments.push_back(eval_expr(*std::get<Pair*>(track->get_item())));
        } else {
            cout << "Type Error" << endl;
        }       
    }

    switch (std::get<string>(expr.get_item()).at(0)) {
        case '+':
            return std::accumulate(arguments.begin(), arguments.end(), 0);
            break;
        case '-':
            return std::accumulate(arguments.begin()+1, arguments.end(), 
                            arguments[0], std::minus<float>());
            break;
        case '*':
            return std::accumulate(arguments.begin(), arguments.end(), 
                            1, std::multiplies<float>());
            break;
        case '/':
            return std::accumulate(arguments.begin()+1, arguments.end(), 
                            arguments[0], std::divides<float>());
            break;
        default:
            cout << "Invalid Operator1" << endl;
            return 0;
    }
}
