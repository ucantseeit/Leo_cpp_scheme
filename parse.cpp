#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>
#include <iterator>
#include "tokenize.hpp"
#include "types.hpp"
#include "SList.cpp"

namespace parser {
    using tokens::token;
    using namespace SyntaxTree_;

    typedef vector<token>::iterator tokenptr;

    // SyntaxTree parse(const vector<token> & tokens) {
        
    // }

    // SyntaxTree parse(tokenptr & track) {
    //     SyntaxTree resultTree;

    //     while (holds_alternative<Symbol>(*track) && get<Symbol>(*track) != ")") {
    //         if (holds_alternative<Symbol>(*track) &&
    //             get<Symbol>(*track) == "(") {
    //             track++;
    //             SyntaxTree st;
    //             st = parse(track);
    //             resultTree.items.emplace_back(st);
    //         } else {
    //             token t = *track;
    //             resultTree.items.emplace_back(t);
    //             track++;
    //         }
    //     }

    //     track++;
    //     return resultTree;
    // }

    SyntaxTree parse(tokenptr & track) {
        if (*track == "(") {
            track++;
            list<SyntaxTree> subItems;
            while (*track != ")") {
                subItems.emplace_back(parse(track));
            }
            track++;
            return subItems;
        } else {
            auto item = *track;
            track++;
            return item;
        }
    }


    


}

int main() {
    using namespace parser;
    using namespace tokens;
    string str = "((1 1) 2 3)";
    vector<token> ts = tokenize(str);
    auto pts = ts.begin();
    SyntaxTree st = parse(pts);

    st;
}
