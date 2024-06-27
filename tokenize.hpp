#ifndef TOKENIZER_H__
#define TOKENIZER_H__

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <variant>
#include "types.hpp"

namespace tokens {
    using std::string, std::vector, std::variant, std::holds_alternative, std::get;

    typedef string token;
    extern std::unordered_set<char> delimeter;

    vector<token> tokenize(const string & input);
}


#endif