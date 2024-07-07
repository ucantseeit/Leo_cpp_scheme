#include "special_forms.hpp"

using std::next, std::get, std::list, SyntaxTree_::Proc;

std::unordered_set<Symbol> specialForms = {"define", "lambda", "if", "and", "or", "not"};

SyntaxTree handleDefine(const list<SyntaxTree>& items,
                        Frame& env);
SyntaxTree handleLambda(const list<SyntaxTree>& items,
                        Frame& env);

SyntaxTree handleIf(const list<SyntaxTree>& items,
                        Frame& env);

SyntaxTree handleAnd(const std::list<SyntaxTree> & items, Frame & env);
SyntaxTree handleOr(const std::list<SyntaxTree> & items, Frame & env);
SyntaxTree handleNot(const std::list<SyntaxTree> & items, Frame & env);

SyntaxTree handleSpecialForms(const list<SyntaxTree>& items,
                              Frame& env) {
    Symbol sym = get<Symbol>(items.front().value);
    
    if (sym == "define") {
        return handleDefine(items, env);
    } else if (sym == "lambda") {
        return handleLambda(items, env);
    } else if (sym == "if") {
        return handleIf(items, env);
    } else if (sym == "and") {
        return handleAnd(items, env);
    } else if (sym == "or") {
        return handleOr(items, env);
    } else if (sym == "not") {
        return handleNot(items, env);
    } else {
        std::cerr << "sth wrong beforehand" << std::endl;
        return SyntaxTree_::nil;
    }
}



SyntaxTree handleDefine(const list<SyntaxTree>& items,
                        Frame & env) {

    auto pitem = next(items.begin());

    // define a variable
    if (pitem->isSymbol()) {
        SyntaxTree value = eval_expr(SyntaxTree(*next(pitem)), env);
        env.insert(get<Symbol>(pitem->value), value);
    }

    // define a procedure
    else if (pitem->isSubexpr()) {
        Symbol sym = get<string>(pitem->items.front().value);

        list<Symbol> params;
        for (auto p = next(pitem->items.begin()); p != pitem->items.end(); p = next(p)) {
            params.emplace_back(get<Symbol>(p->value));
        }
        list<SyntaxTree> content = next(pitem)->items;
        SyntaxTree_::Lambda lamb(params, content, &env);

        SyntaxTree value(lamb, LAMBDA);
        env.insert(sym, value);
    }

    return SyntaxTree_::nil;
}

SyntaxTree handleLambda(const list<SyntaxTree> & items, Frame & env) {
    auto pitem = next(items.begin());

    list<Symbol> params;
    for(auto p = (pitem->items).begin(); p != (pitem->items).end(); p = next(p)) {
        params.emplace_back(get<Symbol>(p->value));
    }
    list<SyntaxTree> content = next(pitem)->items;
    SyntaxTree_::Lambda lamb(params, content, &env);
    
    return SyntaxTree(lamb, LAMBDA);
}



SyntaxTree handleIf(const list <SyntaxTree> & items,
                    Frame & env) {
    auto pitem = next(items.begin());

    SyntaxTree predicate = eval_expr(*pitem, env);
    SyntaxTree expr0 = *(++pitem);
    SyntaxTree expr1 = *(++pitem);

    if (!predicate.isBool() || get<Bool>(predicate.value) == true) {
        return eval_expr(expr0, env);
    } else {
        return eval_expr(expr1, env);
    }
}

SyntaxTree handleAnd(const std::list<SyntaxTree> & items, Frame & env) {
    for (auto parg = next(items.begin()); parg != items.end(); parg++) {
        auto res = eval_expr(*parg, env);
        if (res.isBool() && get<Bool>(res.value) == false) {
            return SyntaxTree(false, BOOL);
        }
    }

    return SyntaxTree(true, BOOL);
}

SyntaxTree handleOr(const std::list<SyntaxTree> & items, Frame & env) {
    for (auto parg = next(items.begin()); parg != items.end(); parg++) {
        auto res = eval_expr(*parg, env);
        if (!res.isBool() || get<Bool>(res.value) == true) {
            return SyntaxTree(true, BOOL);
        }
    }

    return SyntaxTree(false, BOOL);
}

SyntaxTree handleNot(const std::list<SyntaxTree> & items, Frame & env) {
    auto res = eval_expr(*next(items.begin()), env);
    if (!res.isBool() || get<Bool>(res.value) == true) {
        return SyntaxTree(false, BOOL);
    }

    return SyntaxTree(true, BOOL);
}


