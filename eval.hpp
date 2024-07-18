#ifndef EVAL_H__
#define EVAL_H__

#include "SyntaxTree.hpp"
#include "env.hpp"

SyntaxTree eval_expr(const SyntaxTree_::SyntaxTree & expr, Frame &);
SyntaxTree eval_sequence(const std::list<SyntaxTree> & exprs, Frame &);

#endif