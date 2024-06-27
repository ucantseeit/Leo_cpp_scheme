#include <exception>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <list>

#include "tokenize.hpp"
#include "types.hpp"

namespace SyntaxTree_ {
    using std::string, std::vector, std::variant, std::holds_alternative, std::get, std::list;
    using std::cout, std::endl;
    using tokens::token;

    typedef variant<Int, Float, Symbol> valueType;
    typedef std::vector<token>::iterator tokenptr;
    struct Nil {};
    

    class SyntaxTree{
    public:
        valueType value;
        list<SyntaxTree> items;

    public:
        SyntaxTree() = default;
        SyntaxTree(const valueType & t) : value(t) {}
        SyntaxTree(const list<SyntaxTree> & tl) : items(tl) {}

        bool isLeaf() const {return items.empty();}
        void display() const {
            using std::cout, std::endl;

            if(isLeaf()) {
                if (holds_alternative<Int>(value)) {
                    cout << get<Int>(value);
                } else if (holds_alternative<Float>(value)) {
                    cout << get<Float>(value);
                } else if (holds_alternative<Symbol>(value)) {
                    cout << get<Symbol>(value);
                }
            } else {
                cout << '(';
                for (auto p = items.begin(); p != items.end(); p++) {
                    p->display();
                    if (std::next(p) != items.end()) {
                        cout << ' ';
                    }
                }
                cout << ')';
            }
        }
    };
}

