#ifndef PAIR_H__
#define PAIR_H__
#include <variant>
#include <string>
#include <vector>
#include <variant>

namespace Pair_{
    using std::string, std::vector, std::variant;
    typedef enum {NIL, OPERATOR, LITERAL, SUBEXPR} DataType;
    struct Nil {
        
    };

    class Pair {
    public:
        typedef variant<Nil, std::string, float, Pair*> Item;

        Item item = Nil();
        Pair *next = nullptr;

        void help_display() const;
        
        
    public:  
        Pair() = default;

        explicit Pair(const Pair &);
        explicit Pair(const string &str) {item= str; next = new Pair();}
        explicit Pair(float i) {item = i; next = new Pair();}

        // handle int/char
        explicit Pair(int i) {item = float(i); next = new Pair();}
        explicit Pair(char ch) {item= string(1, ch); next = new Pair();}

        Pair(float i, const Pair &_next) : Pair(i) {next = new Pair(_next);}
        Pair(const string &str, const Pair &_next) : Pair(str) {next = new Pair(_next);} 
        Pair(const Pair &_subexpr, const Pair &_next) {
            item= new Pair(_subexpr);
            next = new Pair(_next);
        }   

        // handle int/char
        Pair(int i, const Pair &_next) : Pair(i) {next = new Pair(_next);}
        Pair(char ch, const Pair &_next) : Pair(ch) {next = new Pair(_next);} 
        
        Item get_item() const {return item;}
        DataType get_type() const {return static_cast<DataType>(item.index());}
        Pair *get_next() {return next;};
        const Pair *get_next() const {return next;};

        void display() const;
    };

    float eval_expr(const Pair &expr);
}

#endif