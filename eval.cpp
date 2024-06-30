#include <exception>
#include <unordered_map>
#include <numeric>
#include "eval.hpp"
#include "special_forms.hpp"

using namespace SyntaxTree_;

SyntaxTree eval_expr(const SyntaxTree & expr, Frame & env) {
    using std::cout, std::endl, std::vector;

    if (expr.isLeaf()) {
        if (expr.isSymbol()) {
            SyntaxTree result = env.lookup(get<string>(expr.value));
            return eval_expr(result, env);
        } else {
            return expr;
        }
    }
    
    // TODO: the expr may also begins with subexpr / exception
    Symbol sym = get<Symbol>(expr.items.front().value);

    // handle special forms
    if (specialForms.find(sym) != specialForms.end()) {
        return handleSpecialForms(expr.items, env);
    }

    // handle the built-in procedures
    if (env.lookup(sym).isProc()) {
        const Proc op = get<Proc>(env.lookup(sym).value);
        list<SyntaxTree> arguments;
        auto track = std::next(expr.items.begin());
        for (; track != expr.items.end();
            track = next(track)) {
            if (track->isSubexpr() || track->isSymbol()) {
                arguments.emplace_back(eval_expr(*track, env));
            } else {
                arguments.emplace_back(*track);
            }       
        }

        return op(arguments);
    } 
    
    // handle the user-defined functions
    if (env.lookup(sym).isLambda()) {
        // create a new frame to evaluate the call
        Lambda lamb = get<Lambda>(env.lookup(sym).value);
        Frame newFrame(env);

        // get the arguments of the call
        list<SyntaxTree> arguments;
        auto track = std::next(expr.items.begin());
        for (; track != expr.items.end();
            track = next(track)) {
            if (track->isSubexpr() || track->isSymbol()) {
                arguments.emplace_back(eval_expr(*track, env));
            } else {
                arguments.emplace_back(*track);
            }       
        }

        if (lamb.params.size() != arguments.size()) {
            cout << "Too many/few arguments for the call to " << sym << endl;
        }

        // bind the arguments to the formal parameters
        auto parg = arguments.begin();
        for (auto & para : lamb.params) {
            newFrame.insert(para, *parg);
            parg = next(parg);
        }

        return eval_expr(lamb.content, newFrame);
    }
    
}


