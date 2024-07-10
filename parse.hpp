#ifndef PARSE_H__
#define PARSE_H__


#include <iterator>
#include "tokenize.hpp"
#include "SyntaxTree.hpp"


namespace parser {
    using tokenizer::token, tokenizer::tokenptr;
    using namespace SyntaxTree_;

    bool isInt(const string & word);
    bool isFloat(const string & word);

    bool isMatchBracket(vector<token> & tokens);
    SyntaxTree parse(tokenptr & track);
}
#endif