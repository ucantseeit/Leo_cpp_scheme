#ifndef EVAL_H__
#define EVAL_H__

#include "SyntaxTree.hpp"
#include "types.hpp"
#include "env.hpp"

SyntaxTree eval_expr(const SyntaxTree_::SyntaxTree & expr, Frame &);

#endif