#ifndef SLIST_H__
#define SLIST_H__

#include <list>

#include "tokenize.hpp"

typedef long long Int;
typedef double Float;
typedef std::string Symbol;

class Frame;


typedef enum {NIL, INT, FLOAT, PROC, LAMBDA, SYMBOL, SUBEXPR} dataType;

namespace SyntaxTree_ {
    using std::string, std::vector, std::variant, std::holds_alternative, std::get, std::list;
    using std::cout, std::endl;
    using tokens::token;



    typedef std::vector<token>::iterator tokenptr;


    class SyntaxTree{
    public:
        struct Lambda {
            list<Symbol> params;
            list<SyntaxTree> content;
            Frame * pLocalFrame;

            Lambda(const list<Symbol> & params_, const list<SyntaxTree> & content_, Frame * pl) :
                params(params_), content(content_), pLocalFrame(pl) {}
            Lambda(const Lambda & rhs) : 
                params(rhs.params), content(rhs.content), pLocalFrame(rhs.pLocalFrame) {};
        };
        typedef SyntaxTree (*Proc) (const list<SyntaxTree> &);
        typedef variant<Int, Float, Proc, Lambda, Symbol> valueType;

    public:
        valueType value;
        list<SyntaxTree> items;
        dataType type = NIL;

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
        bool isProc() const {return type == PROC;}
        bool isLambda() const {return type == LAMBDA;}
        bool isSymbol() const {return type == SYMBOL;}
        bool isSubexpr() const {return type == SUBEXPR;}
        


        void display() const;
    };

    typedef SyntaxTree (*Proc) (const list<SyntaxTree> &);
    typedef SyntaxTree::Lambda Lambda;
    typedef variant<Int, Float, Proc, Lambda, Symbol> valueType;
    extern SyntaxTree nil;
}


#endif