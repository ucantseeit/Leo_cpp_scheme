#ifndef PARSER_H__
#define PARSER_H__

#include "tokenizer.h"
#include "Pair.h"
#include <vector>


namespace Parser{
    typedef std::vector<Tokenizer::token>::iterator tokenptr;

    class parser {
    private:
        Pair_::Pair *help_cons_pair(tokenptr ptoken, tokenptr ptoken_e);
        Pair_::Pair *expr;
    
    public:
        parser(const Tokenizer::tokenizer&);

        const Pair_::Pair &get_expr() const {return *expr;}

        

    };
}






#endif