#ifndef TOKENIZER_H__
#define TOKENIZER_H__

#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <set>
namespace Tokenizer {
    using std::string, std::vector, std::variant;

    extern std::set<char> delimeter;

    enum token_type {INT_t, STR_t};
    typedef variant<int, string> token;

    class tokenizer {
    private:
        vector<token> tokens;

    public:
        explicit tokenizer(const string &);
        void display() const {
            for (token t : tokens) {
                if (t.index() == INT_t) {
                    std::cout << std::get<int>(t) << " ";
                } else {
                    std::cout << std::get<string>(t) << " ";
                }
            }
            std::cout << std::endl;
        }

        const vector<token> &get_tokens() const {
            return tokens;
        }
    };
}

#endif