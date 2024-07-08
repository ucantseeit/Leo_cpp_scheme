#ifndef PARSE_H__
#define PARSE_H__


#include <iterator>
#include "tokenize.hpp"
#include "SyntaxTree.hpp"


namespace parser {
    using tokens::token, tokens::tokenptr;
    using namespace SyntaxTree_;

    bool isInt(const string & word);
    bool isFloat(const string & word);

    SyntaxTree parse(tokenptr & track);
}
#endif