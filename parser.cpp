#include <iostream>
#include "tokenizer.h"
#include "Pair.h"
#include "parser.h"
#include <variant>
#include <vector>
#include <string>
#include <exception>

namespace Parser {
    using std::string, std::vector, std::variant;

    parser::parser(const Tokenizer::tokenizer &input) {
        auto tokens = input.get_tokens();
        expr = help_cons_pair(tokens.begin(), tokens.end());
    }

    const Pair_::Pair::Item get_item(const Tokenizer::token &token) {
        if (token.index() == Tokenizer::FLOAT_t) {
            return std::get<float>(token);
        } else {
            string str = std::get<string>(token);
            if (str == "NIL") {
                return Pair_::Nil();
            } else if (str == "(" || str == ")") {
                std::cerr << "Unexpected token" << std::endl;
                std::terminate();
            } else {
                return std::get<string>(token);
            }
        }
    }

    Pair_::Pair *parser::help_cons_pair(tokenptr ptoken, tokenptr ptoken_e) {
        using namespace Pair_;
        using namespace Tokenizer;

        static int left_bracket = 0;
        static tokenptr pnext = ptoken;
        Pair *result = new Pair();
        if (ptoken == ptoken_e) {
            return result;
        } else if (ptoken->index() == STR_t
                    && std::get<string>(*ptoken) == "(") {
            left_bracket++;
            result->put_item(help_cons_pair(++ptoken, ptoken_e));
            result->put_next(help_cons_pair(pnext, ptoken_e));
        } else if (ptoken->index() == STR_t 
                    && std::get<string>(*ptoken) == ")") {
            left_bracket--;
            pnext = ptoken+1;
            return result;
        } else if (left_bracket == 0) { 
            result->put_item(get_item(*ptoken));
            return result;
        } else {
            result->put_item(get_item(*ptoken));
            result->put_next(help_cons_pair(++ptoken, ptoken_e));          
            return result;
        }
        return result;
    }
}

