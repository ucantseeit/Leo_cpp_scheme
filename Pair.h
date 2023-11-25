#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum {NIL, OPERATOR, LITERAL, SUBEXPR} DataType;
class Pair {
private:
    union Item {
        char opr;
        int literal;
        Pair *subexpr;    
    };
    DataType type = NIL;
    Item item;
    Pair *next = nullptr;

    void help_display() const;
    
public:  
    Pair() = default;
    Pair(const Pair &);

    Pair(char ch) : type(OPERATOR) {item.opr = ch; next = new Pair();}
    Pair(int i) : type(LITERAL) {item.literal = i; next = new Pair();}
    Pair(int i, const Pair &_next) : Pair(i) {next = new Pair(_next);}
    Pair(char ch, const Pair &_next) : Pair(ch) {next = new Pair(_next);} 
    Pair(const Pair &_subexpr, const Pair &_next) {
        type = SUBEXPR;
        item.subexpr = new Pair(_subexpr);
        next = new Pair(_next);
    }   
    Item get_item() const {return item;}
    DataType get_type() const {return type;}
    Pair *get_next() {return next;};
    const Pair *get_next() const {return next;};

    void display() const;

};

int eval_expr(const Pair &expr);

#endif