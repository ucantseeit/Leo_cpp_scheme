#ifndef ENV_HPP__
#define ENV_HPP__

#include <unordered_map>
#include "SyntaxTree.hpp"

using std::unordered_map, std::string;
using SyntaxTree_::SyntaxTree;

class Frame {
private:
    unordered_map<string, SyntaxTree> symbolTable;
    const Frame * parentFrame = nullptr;
    typedef unordered_map<string, SyntaxTree>::const_iterator pItem;

public:
    void insert(const string & symbol, const SyntaxTree & content);
    pItem lookup(const string & symbol) const;
    pItem endOfFrame() const {return symbolTable.end();}

    Frame() = default;
    Frame(const Frame * pFrame) : parentFrame(pFrame) {}
};

Frame setGlobalFrame();
extern Frame global_env;


#endif