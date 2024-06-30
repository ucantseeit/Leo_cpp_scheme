#ifndef BUILT_IN_H__
#define BUILT_IN_H__

#include "SyntaxTree.hpp"


SyntaxTree_::SyntaxTree add(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree minus(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree multiple(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree divide(const std::list<SyntaxTree_::SyntaxTree> & arguments);


#endif