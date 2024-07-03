#ifndef BUILT_IN_H__
#define BUILT_IN_H__

#include "SyntaxTree.hpp"


SyntaxTree_::SyntaxTree add(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree minus(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree multiple(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree divide(const std::list<SyntaxTree_::SyntaxTree> & arguments);

SyntaxTree_::SyntaxTree equalNum(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree notEqual(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree greaterThan(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree lessThan(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree greaterEqual(const std::list<SyntaxTree_::SyntaxTree> & arguments);
SyntaxTree_::SyntaxTree lessEqual(const std::list<SyntaxTree_::SyntaxTree> & arguments);


#endif