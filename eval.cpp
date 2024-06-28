#include <exception>
#include <unordered_map>
#include <numeric>
#include "eval.hpp"

using namespace SyntaxTree_;

double eval_expr(const SyntaxTree expr) {
    using std::cout, std::endl, std::vector;
    if (expr.isLeaf()) {
        if (expr.isFloat()) {
            return get<Float>(expr.value);
        } else if (expr.isInt()) {
            return get<Int>(expr.value);
        } else {
            // TODO
            return -1;
        }
        
    }
    
    string op = std::get<string>(expr.items.front().value);

    vector<double> arguments;
    auto track = std::next(expr.items.begin());
    for (; track != expr.items.end();
        track = next(track)) {
        if (track->isInt()) {
            arguments.emplace_back(std::get<Int>(track->value));
        } else if (track->isFloat()) {
            arguments.emplace_back(std::get<Float>(track->value));
        } else if (track->isSubexpr() == SUBEXPR) {
            arguments.push_back(eval_expr(track->items));
        } else {
            cout << "Type Error" << endl;
        }       
    }

    std::unordered_set<string> buitin_operators = {"+", "-", "*", "/"};

    if (op == "+") {
        double result = std::accumulate(arguments.begin(), arguments.end(), 
                                        0.0, std::plus<double>());
        return result;
    } else if (op == "-") {
        return std::accumulate(arguments.begin()+1, arguments.end(), 
                            arguments[0], std::minus<double>());
    } else if (op == "*") {
        return std::accumulate(arguments.begin(), arguments.end(), 
                            1.0, std::multiplies<double>());
    } else if (op == "/") {
        return std::accumulate(arguments.begin()+1, arguments.end(), 
                            arguments[0], std::divides<double>());
    } else {
        cout << "Invalid Operator1" << endl;
        return -1;
    }
}


