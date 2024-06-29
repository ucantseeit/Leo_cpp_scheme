#include <exception>
#include <unordered_map>
#include <numeric>
#include "eval.hpp"

using namespace SyntaxTree_;

SyntaxTree eval_expr(const SyntaxTree & expr, const Frame & env) {
    using std::cout, std::endl, std::vector;
    if (expr.isLeaf()) {
        // if (expr.isFloat()) {
        //     return get<Float>(expr.value);
        // } else if (expr.isInt()) {
        //     return get<Int>(expr.value);
        // } else if (expr.isProc()) {
        //     return 0
        // } else if (expr.isSymbol()){
        //     SyntaxTree result = env.lookup(get<string>(expr.value));
        //     return eval_expr(result, env);
        // } else {
        //     cout << "something strange in eval" << endl;
        //     return -1;
        // }
        if (expr.isSymbol()) {
            SyntaxTree result = env.lookup(get<string>(expr.value));
            return eval_expr(result, env);
        } else {
            return expr;
        }
    }
    
    Symbol sym = get<Symbol>(expr.items.front().value);
    const Proc op = get<Proc>(env.lookup(sym).value);

    list<SyntaxTree> arguments;
    auto track = std::next(expr.items.begin());
    for (; track != expr.items.end();
        track = next(track)) {
        if (track->isSubexpr() == SUBEXPR) {
            arguments.emplace_back(eval_expr(track->items, Frame(&env)));
        } else {
            arguments.emplace_back(*track);
        }       
    }

    return op(arguments);

    // std::unordered_set<string> buitin_operators = {"+", "-", "*", "/"};

    // if (op == "+") {
    //     double result = std::accumulate(arguments.begin(), arguments.end(), 
    //                                     0.0, std::plus<double>());
    //     return result;
    // } else if (op == "-") {
    //     return std::accumulate(arguments.begin()+1, arguments.end(), 
    //                         arguments[0], std::minus<double>());
    // } else if (op == "*") {
    //     return std::accumulate(arguments.begin(), arguments.end(), 
    //                         1.0, std::multiplies<double>());
    // } else if (op == "/") {
    //     return std::accumulate(arguments.begin()+1, arguments.end(), 
    //                         arguments[0], std::divides<double>());
    // } else {
    //     cout << "Invalid Operator1" << endl;
    //     return -1;
    // }
}


