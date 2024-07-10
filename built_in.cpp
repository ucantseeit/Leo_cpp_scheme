#include "built_in.hpp"
#include <iterator>
#include <functional>
#include <iostream>
#include <fstream>
#include <algorithm>

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

template <typename Comparator>
bool helpCmp(const list<SyntaxTree> & arguments, Comparator cmp) {
    auto arg0 = arguments.front();
    auto arg1 = *(++arguments.begin());
    if (arg0.isInt() && arg1.isInt()) {
        return cmp(get<Int>(arg0.value), get<Int>(arg1.value));
    } else if (arg0.isInt() && arg1.isFloat()) {
        return cmp(get<Int>(arg0.value), get<Float>(arg1.value));
    } else if (arg0.isFloat() && arg1.isInt()) {
        return cmp(get<Float>(arg0.value), get<Int>(arg1.value));
    } else if (arg0.isFloat() && arg1.isFloat()) {
        return cmp(get<Float>(arg0.value), get<Float>(arg1.value));
    }

    cout << "sth wrong in cmp" << endl;
    return false;
}


SyntaxTree equalNum(const list<SyntaxTree> & arguments) {
    std::equal_to<long double> eq;
    return SyntaxTree(helpCmp(arguments, eq), BOOL);
}

SyntaxTree_::SyntaxTree notEqual(const std::list<SyntaxTree_::SyntaxTree> & arguments) {
    std::equal_to<long double> eq;
    return SyntaxTree(!helpCmp(arguments, eq), BOOL);
}

SyntaxTree_::SyntaxTree greaterThan(const std::list<SyntaxTree_::SyntaxTree> & arguments) {
    std::greater<long double> gt;
    return SyntaxTree(helpCmp(arguments, gt), BOOL);
}

SyntaxTree_::SyntaxTree lessThan(const std::list<SyntaxTree_::SyntaxTree> & arguments) {
    std::less<long double> ls;
    return SyntaxTree(helpCmp(arguments, ls), BOOL);
}

SyntaxTree_::SyntaxTree greaterEqual(const std::list<SyntaxTree_::SyntaxTree> & arguments) {
    std::greater_equal<long double> ge;
    return SyntaxTree(helpCmp(arguments, ge), BOOL);
}

SyntaxTree_::SyntaxTree lessEqual(const std::list<SyntaxTree_::SyntaxTree> & arguments) {
    std::less_equal<long double> le;
    return SyntaxTree(helpCmp(arguments, le), BOOL);
}


// this function is defined in repl.cpp
void displayResult(const SyntaxTree & result);

SyntaxTree_::SyntaxTree load(const std::list<SyntaxTree_::SyntaxTree> & arguments) {
    using tokenizer::token, tokenizer::tokenptr;
    string fileName = get<Symbol>(arguments.front().value);
    fileName = fileName.substr(1, fileName.size()-2);
    
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        vector<token> ts = tokenizer::tokenize(inputFile);

        auto pts = ts.begin();
        while (pts != ts.end()) {
            SyntaxTree st = parser::parse(pts);
            SyntaxTree result = eval_expr(st, global_env);
            displayResult(result);
        }
    } else {
        cout << "cannot open the file" << endl;
    }

    return nil;
}


SyntaxTree cons(const std::list<SyntaxTree> & arguments) {
    SyntaxTree::Pair result = {arguments.front(), *std::next(arguments.begin())};
    return SyntaxTree(result, PAIR);
}


SyntaxTree car(const std::list<SyntaxTree> & arguments) {
    return get<SyntaxTree::Pair>(arguments.front().value)[0];
}
SyntaxTree cdr(const std::list<SyntaxTree> & arguments) {
    return get<SyntaxTree::Pair>(arguments.front().value)[1];
}

SyntaxTree list_t(const std::list<SyntaxTree> & arguments) {
    if (arguments.size() == 0) {
        return nil;
    }

    SyntaxTree item1 = arguments.front();
    SyntaxTree item2 = list_t(list(next(arguments.begin()), arguments.end()));
    return cons({item1, item2});
}





