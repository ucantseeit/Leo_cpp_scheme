#include "env.hpp"
#include "built_in.hpp"

void Frame::insert(const string & symbol, const SyntaxTree & content) {
    symbolTable[symbol] = content;
}

SyntaxTree Frame::lookup(const string & symbol) const {
    return symbolTable.at(symbol);
}

Frame setGlobalFrame() {
    Frame gFrame;
    gFrame.insert("+", SyntaxTree(&add, PROC));


    return gFrame;
}
Frame global_env = setGlobalFrame();



