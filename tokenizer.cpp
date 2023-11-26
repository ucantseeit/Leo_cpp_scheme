#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <set>
#include "parser.h"
#include "tokenizer.h"

namespace Tokenizer {
    
std::set<char>delimeter = {' ', '\t'};

// return true if word is float, and float is the value
bool get_word(const std::string word, float &i) {
    std::size_t pos;

    try {
        i = std::stof(word, &pos);
    } 
    // when the first char is not a number/+/-
    catch(...) {
        return false;
    }
    if (pos == word.length()) {
        return true;
    }

    return false;   
}

tokenizer::tokenizer(const std::string &input) {
    std::string word;
    for (auto track : input) {
        // when meeting ( or )
        if (track == '(' || track == ')') {
            if (!word.empty()) {
                float i;
                if (get_word(word, i)) {
                    tokens.push_back(i);
                } else {
                    tokens.push_back(word);
                }
                word.clear();
            }
            tokens.push_back(string(1, track));
            continue;
        }

        // when meeting a delimeter
        if (delimeter.find(track)!=delimeter.end()) {
            // push back a word when the word is not empty
            if (!word.empty()) {
                float i;
                if (get_word(word, i)) {
                    tokens.push_back(i);
                } else {
                    tokens.push_back(word);
                }
                word.clear();
                continue;
            }
            // continue when the word is empty
            continue;
        }

        // when meeting a normal char
        word.push_back(track);
    }
}

}