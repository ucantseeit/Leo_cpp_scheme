#include "parse.hpp"
#include "stack"

namespace parser {
    bool isMatchBracket(vector<token> & tokens) {
        std::stack<token> s;
        for (auto & p : tokens) {
            if (p == "(") {
                s.push(p);
            } else if (p == ")" && !s.empty()) {
                s.pop();
            } else if (p == ")" && s.empty()) {
                return false;
            }
        }

        return s.empty();
    }

    SyntaxTree parse(tokenptr & track) {
        if (*track == "(") {
            track++;
            list<SyntaxTree> subItems;
            while (*track != ")") {
                subItems.emplace_back(parse(track));
            }
            track++;
            return subItems;
        } else {
            valueType item;
            dataType t;
            if (isInt(*track)) {
                item = std::stoll(*track);
                t = INT;
            } else if (isFloat(*track)) {
                item = std::stod(*track);
                t = FLOAT;
            } else {
                item = *track;
                t = SYMBOL;
            }

            track++;
            return SyntaxTree(item, t);
        }
    }

    bool isInt(const string & word) {
        std::size_t pos;

        try {
            std::stoll(word, &pos);
            if (pos == word.length()) {
                return true;
            }
        } 
        // when the first char is not a number/+/-
        catch (std::invalid_argument const & ex) {
            return false;
        }
        catch (std::overflow_error const & ex) {
            std::cerr << ex.what() << " the input is too large." << std::endl;
            return false;
        }
        
        return false;   
    }

    bool isFloat(const string & word) {
        std::size_t pos;

        try {
            std::stod(word, &pos);
            if (pos == word.length()) {
                return true;
            }
        } 
        // when the first char is not a number/+/-
        catch (std::invalid_argument const & ex) {
            return false;
        }
        catch (std::out_of_range const & ex) {
            std::cerr << ex.what() << " the input is too large." << std::endl;
            return false;
        }
        
        return false;   
    }
}

// int main() {
//     using namespace parser;
//     using namespace tokens;
//     string str = "((1 1.1.1) 2.5 3e1)";
//     vector<token> ts = tokenize(str);
//     auto pts = ts.begin();
//     SyntaxTree st = parse(pts);

//     st.display();
//     cout << endl;
// }
