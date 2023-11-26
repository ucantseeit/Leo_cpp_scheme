#ifndef PARSER_H__
#define PARSER_H__

#include "tokenizer.h"
#include "Pair.h"
#include <vector>

namespace Parser{
    typedef vector<Tokenizer::token>::iterator tokenptr;

    class parser {
    private:
        Pair_::Pair *help_cons_pair(tokenptr ptoken_b, tokenptr ptoken_e, tokenptr pnext=0);
        parser(const Tokenizer::tokenizer&);
        Pair_::Pair *expr;
    
    public:
        parser(const Tokenizer::tokenizer&);

        const Pair_::Pair &get_expr() const {return *expr;}

    };
}







#endif