#include "special_forms.hpp"

using std::next, std::get, std::list, SyntaxTree_::Proc;

std::unordered_set<Symbol> specialForms = {"define", "if"};

SyntaxTree handleDefine(const list<SyntaxTree>& items,
                        Frame& env);
SyntaxTree handleIf(const list<SyntaxTree>& items,
                        Frame& env);

SyntaxTree handleSpecialForms(const list<SyntaxTree>& items,
                              Frame& env) {
    Symbol sym = get<Symbol>(items.front().value);
    
    if (sym == "define") {
        return handleDefine(items, env);
    } else if (sym == "if") {
        return handleIf(items, env);
    } else {
        std::cerr << "sth wrong beforehand" << std::endl;
        return SyntaxTree_::nil;
    }
}

void bind(const list<SyntaxTree> arguments, const list<SyntaxTree>::const_iterator paramsB, 
          const list<SyntaxTree>::const_iterator paramsE, Frame env) {

}

SyntaxTree handleDefine(const list<SyntaxTree>& items,
                        Frame & env) {

    auto pitem = next(items.begin());

    if (pitem->isSymbol()) {
        SyntaxTree value = eval_expr(SyntaxTree(*next(pitem)), env);
        env.insert(get<Symbol>(pitem->value), value);
    } else if (pitem->isSubexpr()) {
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