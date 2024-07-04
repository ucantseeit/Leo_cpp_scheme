#ifndef TOKENIZER_H__
#define TOKENIZER_H__

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <variant>

namespace tokens {
    using std::string, std::vector, std::variant, std::holds_alternative, std::get;

    typedef string token;
    extern std::unordered_set<char> delimeter;

    vector<token> tokenize(std::istream & input);
}


#endif