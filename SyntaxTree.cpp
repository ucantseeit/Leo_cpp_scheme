#include "SyntaxTree.hpp"

namespace SyntaxTree_ {
    void SyntaxTree::display() const {
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

    SyntaxTree nil = SyntaxTree();
}



