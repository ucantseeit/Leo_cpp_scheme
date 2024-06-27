#ifndef PARSE_H__
#define PARSE_H__


#include <iterator>
#include "tokenize.hpp"
#include "types.hpp"
#include "SyntaxTree.hpp"


namespace parser {
    using tokens::token;
    using namespace SyntaxTree_;

    bool isInt(const string & word);
    bool isFloat(const string & word);

    typedef vector<token>::iterator tokenptr;

    SyntaxTree parse(tokenptr & track);
}
#endif