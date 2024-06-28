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


    class SyntaxTree{
    public:
        valueType value;
        list<SyntaxTree> items;
        dataType type;

    public:
        SyntaxTree() = default;
        SyntaxTree(const valueType & v, dataType t) : value(v), type(t) {}
        SyntaxTree(const list<SyntaxTree> & vl) : items(vl) {
            type = vl.empty() ? NIL : SUBEXPR ;
        }


        bool isLeaf() const {return type != SUBEXPR;}
        bool isNil() const {return type == NIL;}
        bool isInt() const {return type == INT;}
        bool isFloat() const {return type == FLOAT;}
        bool isSymbol() const {return type == SYMBOL;}
        bool isSubexpr() const {return type == SUBEXPR;}
        


        void display() const;
    };
}


#endif