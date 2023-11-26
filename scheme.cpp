#include <iostream>
#include "Pair.h"
#include <exception>
#include <vector>
#include <set>
#include <string>
#include <numeric>

namespace Pair_{
    int eval_expr(const Pair &expr) {
        using std::cout, std::endl, std::vector;
        if (expr.get_type() != OPERATOR) {
        cout << "Syntax Error: invalid operator" << endl;
        }
        
        vector<int> arguments;
        const Pair *track = expr.get_next();
        for (; track->get_type()!=NIL;
            track = track->get_next()) {
            if (track->get_type() == LITERAL) {
                arguments.push_back(track->get_item().literal);
            } else if (track->get_type() == SUBEXPR) {
                arguments.push_back(eval_expr(*track->get_item().subexpr));
            } else {
                cout << "Type Error" << endl;
            }       
        }

        switch (expr.get_item().opr) {
            case '+':
                return std::accumulate(arguments.begin(), arguments.end(), 0);
                break;
            case '-':
                return std::accumulate(arguments.begin()+1, arguments.end(), 
                                arguments[0], std::minus<int>());
                break;
            case '*':
                return std::accumulate(arguments.begin(), arguments.end(), 
                                1, std::multiplies<int>());
                break;
            case '/':
                return std::accumulate(arguments.begin()+1, arguments.end(), 
                                arguments[0], std::divides<int>());
                break;
            default:
                cout << "Invalid Operator1" << endl;
                return 0;
        }
    }
};
