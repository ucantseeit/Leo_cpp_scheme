#include "built_in.hpp"

using namespace SyntaxTree_;

SyntaxTree add(const list<SyntaxTree> & arguments) {
    long double result = 0;
    bool is_res_int = true;
    for (auto arg : arguments) {
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