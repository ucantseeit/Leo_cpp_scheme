#include "built_in.hpp"
#include <iterator>

using namespace SyntaxTree_;

SyntaxTree add(const list<SyntaxTree> & arguments) {
    long double result = 0;
    bool is_res_int = true;
    for (auto & arg : arguments) {
        if (arg.isInt()) {
            result += get<Int>(arg.value);
        } else if (arg.isFloat()) {
            is_res_int = false;
            result += get<Float>(arg.value);
        } else {
            cout << "Error argument type for +";
            return SyntaxTree(-1, INT);
        }
    }

    if (is_res_int) {
        return SyntaxTree((Int) result, INT);
    } else {
        return SyntaxTree((Float) result, FLOAT);
    }
}

SyntaxTree multiple(const list<SyntaxTree> & arguments) {
    long double result = 1;
    bool is_res_int = true;
    for (auto & arg : arguments) {
        if (arg.isInt()) {
            result *= get<Int>(arg.value);
        } else if (arg.isFloat()) {
            is_res_int = false;
            result *= get<Float>(arg.value);
        } else {
            cout << "Error argument type for *";
            return SyntaxTree(-1, INT);
        }
    }

    if (is_res_int) {
        return SyntaxTree((Int)result, INT);
    } else {
        return SyntaxTree((Float)result, FLOAT);
    }
}

SyntaxTree minus(const list<SyntaxTree> & arguments) {
    long double result = holds_alternative<Int>(arguments.front().value) ?
                         get<Int>(arguments.front().value) : 
                         get<Float>(arguments.front().value);
    bool is_res_int = true;
    for (auto parg = std::next(arguments.begin()); 
         parg != arguments.end(); parg++) {
        if (parg->isInt()) {
            result -= get<Int>(parg->value);
        } else if (parg->isFloat()) {
            is_res_int = false;
            result -= get<Float>(parg->value);
        } else {
            cout << "Error argument type for -";
            return SyntaxTree(-1, INT);
        }
    }

    if (is_res_int) {
        return SyntaxTree((Int)result, INT);
    } else {
        return SyntaxTree((Float)result, FLOAT);
    }
}

SyntaxTree divide(const list<SyntaxTree> & arguments) {
    long double result = holds_alternative<Int>(arguments.front().value)
                             ? get<Int>(arguments.front().value)
                             : get<Float>(arguments.front().value);
    bool is_res_int = true;
    for (auto parg = std::next(arguments.begin()); 
         parg != arguments.end(); parg++) {
        if (parg->isInt()) {
            result /= get<Int>(parg->value);
        } else if (parg->isFloat()) {
            is_res_int = false;
            result /= get<Float>(parg->value);
        } else {
            cout << "Error argument type for /";
            return SyntaxTree(-1, INT);
        }
    }

    return SyntaxTree((Float)result, FLOAT);
}