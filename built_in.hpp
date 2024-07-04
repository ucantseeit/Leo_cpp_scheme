#ifndef BUILT_IN_H__
#define BUILT_IN_H__

#include "SyntaxTree.hpp"

using SyntaxTree_::SyntaxTree;

SyntaxTree add(const std::list<SyntaxTree> & arguments);
SyntaxTree minus(const std::list<SyntaxTree> & arguments);
SyntaxTree multiple(const std::list<SyntaxTree> & arguments);
SyntaxTree divide(const std::list<SyntaxTree> & arguments);

SyntaxTree equalNum(const std::list<SyntaxTree> & arguments);
SyntaxTree notEqual(const std::list<SyntaxTree> & arguments);
SyntaxTree greaterThan(const std::list<SyntaxTree> & arguments);
SyntaxTree lessThan(const std::list<SyntaxTree> & arguments);
SyntaxTree greaterEqual(const std::list<SyntaxTree> & arguments);
SyntaxTree lessEqual(const std::list<SyntaxTree> & arguments);


#endif