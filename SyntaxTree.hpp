#ifndef SLIST_H__
#define SLIST_H__

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
        void display() const;
    };
}


#endif