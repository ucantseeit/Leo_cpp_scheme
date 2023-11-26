#include <iostream>
#include "parser.h"
#include "tokenizer.h"
#include "Pair.h"
#include <variant>
#include <vector>
#include <string>
#include <exception>

namespace Parser {
    using std::string, std::vector, std::valarray;

    parser::parser(const Tokenizer::tokenizer &input) {
        auto tokens = input.get_tokens();
        expr = help_cons_pair(tokens.begin(), tokens.end());
    }

    Pair_::Pair &get_item(const Tokenizer::tokenizer &token) {

    }

    Pair_::Pair *parser::help_cons_pair(tokenptr ptoken_b, tokenptr ptoken_e, tokenptr pnext=0) {
        using namespace Pair_;
        using namespace Tokenizer;

        Pair *result = new Pair();

        

    }
}

